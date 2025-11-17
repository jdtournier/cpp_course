/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * (c) 2024 J-Donald Tournier (jdtournier@gmail.com)
 *
 * With inspiration from:
 * - for sixel protocol: https://vt100.net/shuford/terminal/all_about_sixels.txt
 */

#ifndef __TERMINAL_GRAPHICS_H__
#define __TERMINAL_GRAPHICS_H__


#include <iostream>
#include <string>
#include <sstream>
#include <format>
#include <string_view>
#include <vector>
#include <array>
#include <ranges>
#include <limits>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>


/**
 * \mainpage
 *
 * This header provides functionality for producing simple graphics on the
 * terminal.
 *
 * NOTE: the graphics are produced using the sixel protocol, which is not
 * supported by many terminals. At the time of writing, the following terminals
 * are known to have the necessary capabilities:
 *
 * - Linux: WezTerm, mlTerm, xterm
 * - macOS: WezTerm, iTerm2
 * - Windows: WezTerm, minTTY, Windows Terminal (Preview)
 *
 * To use in your code, place this file alongside your own code, and \#include
 * the file where necessary:
 *
 *     #include "terminal_graphics.h"
 *
 * At this point, you can make use of the functions. All functions are enclosed
 * in the TG namespace
 *
 * The main functions of interest are:
 *
 * - TG::imshow()  display a scalar image.
 * - TG::plot()    display a simple line plot for the data supplied
 *
 * For a more complete list of all of the available functionality, refer to the
 * TG namespace.
 *
 * By default, the colours are set up for use on a terminal with a dark
 * background. When using a light background, set the `WHITEBG` environment
 * variable. For example, in `bash`:
 * ```
 * $ export WHITEBG=1
 * ```
 *
 * Refer to the example code in `demo.cpp` (reproduced below) to see how to use
 * this functionality:
 *
 * \include demo.cpp
 */




//! The namespace within which all functionality is placed
namespace TG {

  //! the data type to use to store intensities:
  using ctype = unsigned char;

  //! The data structure used to hold a colourmap
  /**
   * A ColourMap is a way to associate an index with a colour. It can be
   * represented as a simple table with 3 columns per row, to represent the
   * red, green & blue components of each colour, one colour per row. When in
   * use, the colour to be used is retrieved by looking up the values in the
   * row at the specified index.
   *
   * Since this is a simple structure, we use existing C++ objects to store
   * this information, as a (dynamically-sized) vector of (fixed-sized) arrays
   * of 3 values. For convenience, we define the shorthand name 'ColourMap' for
   * this specific type.
   *
   * Note that the sixel protocol we rely on in this implementation expects
   * colourmap intensity values between 0 & 100.
   *
   * Defining a simple colourmap can be done by list initialisation, for
   * example:
   *
   *     const ColourMap my_cmap = {
   *                    { 0, 0, 100 },     // pure red
   *                    { 0, 100, 0 },     // pure green
   *                    { 100, 0, 0 }      // pure blue
   *                };
   *
   * More complex colourmaps can be generated if required, see implementation
   * of the gray() colourmap for inspiration.
   */
  using ColourMap = std::vector<std::array<ctype,3>>;

  //! convenience function to generate a ready-made grayscale colourmap
  ColourMap gray (int number = 101);

  //! convenience function to generate a ready-made hot colourmap
  ColourMap hot (int number = 101);

  //! convenience function to generate a ready-made jet colourmap
  ColourMap jet (int number = 101);



  //! VT100 code to set the cursor position to the top left of the screen
  /**
   * This can be used in conjuction with TG::Clear to provide running updates.
   * Simply feed the string to `std::cout` to issue the instruction, for example:
   * ```
   *   std::cout << TG::Clear;
   *   while (true) {
   *     std::cout << TG::Home << "Current progress:\n";
   *     TG::plot().add_line(...);
   *
   *     ...
   *     // perform computations, etc.
   *     ...
   *   }
   * ```
   * \sa TG::Clear
   */
  constexpr inline std::string_view Home = "\033[H";

  //! VT100 code to clear the screen
   /** \sa TG::Home
   */
  constexpr inline std::string_view Clear = "\033[2J";

  //! A simple class to hold a 2D image using datatype specified as `ValueType` template parameter
  template <typename ValueType>
    class Image {
      public:
        //! Instantiate an Image with the specified dimensions
        Image (int x_dim, int y_dim);

        //! query image dimensions
        int width () const;
        int height () const;

        //! query or set intensity at coordinates (x,y)
        ValueType& operator() (int x, int y);
        //! query intensity at coordinates (x,y)
        const ValueType& operator() (int x, int y) const;

        //! clear image, setting all intensities to 0
        void clear ();

      private:
        std::vector<ValueType> data;
        const int x_dim, y_dim;
    };




  //! Adapter class to rescale intensities of image to colourmap indices
  /**
   * Rescale intensities of image from (min, max) to the range of indices
   * in the specified colourmap, rounding to the nearest integer index, and
   * clamping the values to the [ min max ] range.
   */
  template <class ImageType>
    class Rescale {
      public:
        Rescale (const ImageType& image, double minval, double maxval, int cmap_size);

        int width () const;
        int height () const;
        ctype operator() (int x, int y) const;

      private:
        const ImageType& im;
        const double min, max;
        const int cmap_size;
    };



  //! Adapter class to magnify an image
  /**
   * This makes the image `factor` bigger than the original.
   */
  template <class ImageType>
    class magnify {
      public:
        magnify (const ImageType& image, int factor);

        int width () const;
        int height () const;
        decltype(std::declval<const ImageType>()(0,0)) operator() (int x, int y) const;

      private:
        const ImageType& im;
        const int factor;
    };





  //! Display an indexed image to the terminal, according to the colourmap supplied.
  /**
   * ImageType can be any object that implements the following methods:
   * - `int width() const`
   * - `int height() const`
   * - `integer_type operator() (int x, int y) const`
   *
   * Indexed images contain integer values that correspond to entries in the
   * associated ColourMap. Different image values can have completely different
   * colours, depending on the ColourMap used.
   *
   * The ColourMap must be specified via the `cmap` argument. See the
   * documentation for ColourMap for details.
   */
  template <class ImageType>
    void imshow (const ImageType& image, const ColourMap& cmap, const bool zero_is_transparent = false);


  //! Display a scalar image to the terminal, rescaled between (min, max)
  /**
   * ImageType can be any object that implements the following methods:
   * - `int width() const`
   * - `int height() const`
   * - `scalar_type operator() (int x, int y) const`
   *   (where scalar_type can be any integer or floating-point type)
   *
   * Note that as for most image formats, the x index rasters from left to
   * right, while the y index rasters from top to bottom.
   *
   * `min` & `max` specify how image values map to displayed intensities.
   * Values <= `min` will render as pure black, while values >= `max`
   * will render as pure white (assuming the default gray colourmap).
   *
   * A different colourmap can be specified via the `cmap` argument. See the
   * documentation for ColourMap for details on how to generate different
   * colourmaps if necessary.
   */
  template <class ImageType>
    void imshow (const ImageType& image, double min, double max, const ColourMap& cmap = gray(), const bool zero_is_transparent = false);





  //! A class to hold the information about the font used for text rendering
  /**
   * This is should not need to be used directly outside of this file.
   */
  class Font {
    public:
      constexpr Font (int width, int height, const std::span<const unsigned char>& data);

      constexpr int width () const;
      constexpr int height () const;
      bool get (int offset, int x, int y) const;

      template <typename ValueType>
        void render (Image<ValueType>& canvas, char c, int x, int y, int colour_index) const;

      static constexpr const Font get_font (int size = 16);

    private:
      const int w, h;
      const std::span<const unsigned char> data;
  };




  //! A class to provide plotting capabilities
  /**
   * This can be used stand-alone, but it is easier to use it via the
   * TG::plot() function, which essentially simply returns an (anonymous) TG::Plot
   * Object (refer to the documentation for TG::plot() for details).
   *
   * This class provides a canvas initialised to the desired size (in pixels),
   * with a default font size (6 pixels wide by default). The
   * `show_on_destruct` argument is `false` by default, but that be set to
   * `true` to ensure the class destructor calls show() when the class goes out
   * of scope (this is what the TG::plot() function relies on).
   *
   * By default, the colourmap is set to:
   *
   * | index |  red  | green | blue  | name     |
   * |:-----:|:-----:|:-----:|:-----:|----------|
   * |   0   |   0   |   0   |   0   | black    |
   * |   1   |  100  |  100  |  100  | white    |
   * |   2   |  100  |  100  |   0   | yellow   |
   * |   3   |  100  |   0   |  100  | magenta  |
   * |   4   |   0   |  100  |  100  | cyan     |
   * |   5   |  100  |   0   |   0   | red      |
   * |   6   |   0   |  100  |   0   | green    |
   * |   7   |   0   |   0   |  100  | blue     |
   *
   * Most methods return a reference to the current instance. This allows them
   * to be daisy-chained like this (again, this is what the TG::plot() syntax
   * relies on):
   *
   *     std::vector<float> data (10);
   *     ...
   *     Plot p (256, 128);
   *     p.set_xlim (0,10).set_ylim (-1,1).add_line(data).show();
   *
   * Many methods accept the following arguments:
   *
   * - `colour_index` specifies the colour to use (default: 2 - yellow)
   * - `stiple` specifies the length of dashes (in pixels) if a dashed line
   *   is desired. Set to zero (the default) for a full line.
   * - `stiple_frac` specific the fraction of the dash interval to be
   *   filled (default: 0.5).
   * */
  class Plot {
    public:
      Plot (int width, int height, bool show_on_destruct = false);
      ~Plot ();

      //! clear canvas and reset X & Y limits
      Plot& reset();
      //! display the plot to the terminal
      /** This is to be called after all rendering instructions have been
       * invoked and the plot is ready to be displayed.
       *
       * If the plot has been constructed with `show_on_destruct` set to
       * `true`, this will automatically be invoked by the destructor (this is
       * the default behaviour when using the TG::plot() function).
       */
      Plot& show();

      //! set the colourmap if the default is not appropriate
      Plot& set_colourmap (const ColourMap& colourmap);

      //! disable transparent background for plot
      Plot& disable_transparency ();

      //! add a single line connection point (x0,y0) to (x1,y1).
      /** If the X and/or Y limits have not yet been set (using set_xlim() or
       * set_ylim(), this will automatically set them to 10% wider than the
       * maximum range of the coordinates.
       *
       * See main class description for an explanation of the remaining
       * arguments.
       */
      Plot& add_line (float x0, float y0, float x1, float y1,
          int colour_index = 2, int stiple = 0, float stiple_frac = 0.5);

      //! plot the data series `y` along the x-axis
      /** The input `y` can be any class that provides `.size()` and
       * `operator[]()` methods (e.g. `std::vector`). This will plot the data
       * points at locations (0,y[0]), (1,y[1]), ... , (n,y[n]).
       *
       * If the X and/or Y limits have not yet been set (using set_xlim() or
       * set_ylim(), this will automatically set the X limit to (0,n), and the
       * Y limit to 10% wider than the maximum range of the data in `y`.
       *
       * See main class description for an explanation of the remaining
       * arguments.
       */
      template <class VerticesType>
        Plot& add_line (const VerticesType& y,
            int colour_index = 2, int stiple = 0, float stiple_frac = 0.5);

      //! plot the data series `y` against the data series `x`
      /** The inputs `x` & `y` can be any classes that provides `.size()` and
       * `operator[]()` methods (e.g. `std::vector`). This will plot the data
       * points at locations (x[0],[0]), (x[1],y[1]), ... , (x[n],y[n]).
       *
       * If the X and/or Y limits have not yet been set (using set_xlim() or
       * set_ylim(), these will automatically set them to 10% wider
       * than the maximum range of the data in `x` & `y` respectively.
       *
       * See main class description for an explanation of the remaining
       * arguments.
       */
      template <class VerticesTypeX, class VerticesTypeY>
        Plot& add_line (const VerticesTypeX& x, const VerticesTypeY& y,
            int colour_index = 2, int stiple = 0, float stiple_frac = 0.5);

      //! add text at the location specified
      /** This renders the text in `text` at ithe location (x,y). By default,
       * the text is centred on (x,y), but the location of the 'anchor' can be
       * set using the `anchor_x` & `anchor_y` parameters.
       *
       * See main class description for an explanation of the remaining
       * arguments.
       */
      Plot& add_text (const std::string& text, float x, float y,
          float anchor_x = 0.5, float anchor_y = 0.5, int colour_index = 1);

      //! set the range along the x-axis
      /** Note that this can only be done once, and if required, should be
       * invoked before any rendering commands.
       */
      Plot& set_xlim (float min, float max, float expand_by = 0.0);
      //! set the range along the y-axis
      /** Note that this can only be done once, and if required, should be
       * invoked before any rendering commands.
       */
      Plot& set_ylim (float min, float max, float expand_by = 0.0);
      //! set the interval of the gridlines, centered around zero
      Plot& set_grid (float x_interval, float y_interval);

    private:
      const bool show_on_destruct;
      const Font font;
      Image<ctype> canvas;
      ColourMap cmap;
      std::array<float,2> xlim, ylim;
      float xgrid, ygrid;
      int margin_x, margin_y;
      bool zero_is_transparent;

      template <class ImageType>
        static void line_x (ImageType& canvas, float x0, float y0, float x1, float y1,
            int colour_index, int stiple, float stiple_frac);

      float mapx (float x) const;
      float mapy (float y) const;

      static ColourMap default_cmap;
      static const ColourMap& get_default_cmap();
  };

  //! Convenience function to use for immediate rendering
  /**
   * This returns a (temporary) Plot object, which methods can be called on,
   * and daisy-chain to achieve the desired series of commands. The
   * Plot::show() method will implicitly be called when the temporary object is
   * destroyed, in other words immediately after the closing semicolon.
   *
   * For example:
   *
   *     std::vector x (10), y(10);
   *     ...
   *     TG::plot (256,128)
   *       .set_ylim (-1,2)
   *       .add_line (x, y, 3)
   *       .set_grid (2, 0.5)
   *       .add_text ("my plot", 5, 2);
   *
   * See methods in TG::Plot for details.
   */
  inline Plot plot (int width = 512, int height = 256)
  {
    return Plot (width, height, true);
  }








  // **************************************************************************
  // **************************************************************************
  //
  //              Implementation details from this point on
  //
  // **************************************************************************
  // **************************************************************************





  // **************************************************************************
  //                   ColourMap implementation
  // **************************************************************************

  namespace {
    inline ctype clamp (float val, int number) {
      return ctype (std::round (std::min (std::max ((100.0/number)*val, 0.0), static_cast<double>(number))));
    }
  }


  inline ColourMap gray (int number)
  {
    ColourMap cmap (number);
    for (int n = 0; n < number; ++n) {
      ctype c = clamp (n, number-1);
      cmap[n] = { c, c, c };
    }
    return cmap;
  }


  inline ColourMap hot (int number)
  {
    ColourMap cmap (number);
    for (int n = 0; n < number; ++n) {
      cmap[n] = {
        clamp (3*n, number-1),
        clamp (3*n-number, number-1),
        clamp (3*n-2*number, number-1)
      };
    }
    return cmap;
  }


  inline ColourMap jet (int number)
  {
    ColourMap cmap (number);
    for (int n = 0; n < number; ++n) {
      cmap[n] = {
        clamp (1.5*number-std::abs(4*n-3*number), number-1),
        clamp (1.5*number-std::abs(4*n-2*number), number-1),
        clamp (1.5*number-std::abs(4*n-1*number), number-1)
      };
    }
    return cmap;
  }




  // **************************************************************************
  //                   Image class implementation
  // **************************************************************************



  template <typename ValueType>
    inline Image<ValueType>::Image (int x_dim, int y_dim) :
      data (x_dim*y_dim, 0),
      x_dim (x_dim),
      y_dim (y_dim) { }

  template <typename ValueType>
    inline int Image<ValueType>::width () const
    {
      return x_dim;
    }

  template <typename ValueType>
    inline int Image<ValueType>::height () const
    {
      return y_dim;
    }

  template <typename ValueType>
    inline ValueType& Image<ValueType>::operator() (int x, int y)
    {
      return data[x+x_dim*y];
    }

  template <typename ValueType>
    inline const ValueType& Image<ValueType>::operator() (int x, int y) const
    {
      return data[x+x_dim*y];
    }


  template <typename ValueType>
    inline void Image<ValueType>::clear ()
    {
      for (auto& x : data)
        x = 0;
    }







  // **************************************************************************
  //                   Rescale implementation
  // **************************************************************************

  template <class ImageType>
    inline Rescale<ImageType>::Rescale (const ImageType& image, double minval, double maxval, int cmap_size) :
      im (image), min (minval), max (maxval), cmap_size (cmap_size) { }

  template <class ImageType>
    inline int Rescale<ImageType>::width () const { return im.width(); }

  template <class ImageType>
    inline int Rescale<ImageType>::height () const { return im.height(); }

  template <class ImageType>
    inline ctype Rescale<ImageType>::operator() (int x, int y) const {
      double rescaled = cmap_size * (im(x,y) - min) / (max - min);
      return std::round (std::min (std::max (rescaled, 0.0), cmap_size-1.0));
    }



  // **************************************************************************
  //                   magnify implementation
  // **************************************************************************

  template <class ImageType>
    inline magnify<ImageType>::magnify (const ImageType& image, int factor) :
      im (image), factor (factor) { }

  template <class ImageType>
    inline int magnify<ImageType>::width () const { return im.width() * factor; }

  template <class ImageType>
    inline int magnify<ImageType>::height () const { return im.height() * factor; }

  template <class ImageType>
    inline decltype(std::declval<const ImageType>()(0,0)) magnify<ImageType>::operator() (int x, int y) const {
      return im (x/factor, y/factor);
    }




  // **************************************************************************
  //                   imshow implementation
  // **************************************************************************




  // functions in anonymous namespace will remain private to this file:
  namespace {

    // helper functions for colourmap handling:

    inline std::string colourmap_specifier (const ColourMap& colours)
    {
      int n = 0;
      std::string specifier;
      for (const auto& c : colours)
        specifier += std::format ("#{};2;{};{};{}",
            n++, static_cast<int>(c[0]), static_cast<int>(c[1]),static_cast<int>(c[2]));
      return specifier;
    }




    inline void commit (std::stringstream& out, ctype current, int repeats)
    {
      if (repeats <=3) {
        for (int n = 0; n < repeats; ++n)
          out.put (63+current);
      }
      else
        out << std::format ("!{}{}", repeats, char(63+current));
    }


    template <class ImageType>
    inline std::string encode_row (const ImageType& im, int y0, int x_dim, int nsixels, const ctype intensity)
    {
      int repeats = 0;
      std::stringstream out;
      ctype current = std::numeric_limits<ctype>::max();

      for (int x = 0; x < x_dim; ++x) {
        ctype c = 0;
        for (int y = 0; y < nsixels; ++y) {
          if (im(x,y+y0) == intensity)
            c |= 1U<<y;
        }
        if (!repeats) {
          ++repeats;
          current = c;
          continue;
        }
        if (c == current) {
          ++repeats;
          continue;
        }
        commit (out, current, repeats);
        current = c;
        repeats = 1;
      }
      commit (out, current, repeats);

      return out.str();
    }


    template <class ImageType>
      inline std::string encode (const ImageType& im, int cmap_start, int cmap_end, int y0)
      {
        std::string out;
        const int nsixels = std::min (im.height()-y0, 6);

        bool first = true;
        for (ctype intensity = cmap_start; intensity < cmap_end; ++intensity) {
          std::string row = encode_row (im, y0, im.width(), nsixels, intensity);
          if (row.size()) {
            if (first) first = false;
            else out += '$';
            out += std::format ("#{}{}", static_cast<int>(intensity), row);
          }
        }
        out += '-';
        return out;
      }

  }







  template <class ImageType>
    inline void imshow (const ImageType& image, const ColourMap& cmap, const bool zero_is_transparent)
    {
      std::string out = "\033P9;1q" + colourmap_specifier (cmap);
      for (int y = 0; y < image.height(); y += 6)
        out += encode (image, ( zero_is_transparent ? 1 : 0 ), cmap.size(), y);
      out += "\033\\\n";
      std::cout.write (out.data(), out.size());
      std::cout.flush();
    }



  template <class ImageType>
    inline void imshow (const ImageType& image, double min, double max, const ColourMap& cmap, const bool zero_is_transparent)
    {
      Rescale<ImageType> rescaled (image, min, max, cmap.size());
      imshow (rescaled, cmap, zero_is_transparent);
    }








  // **************************************************************************
  //                   Plot implementation
  // **************************************************************************

  inline ColourMap Plot::default_cmap;

  inline const ColourMap& Plot::get_default_cmap()
  {
    if (default_cmap.empty()) {
      default_cmap = {
        {   0,   0,   0 },
        { 100, 100, 100 },
        { 100, 100,  20 },
        { 100,  20, 100 },
        {  20, 100, 100 },
        { 100,  20,  20 },
        {  20, 100,  20 },
        {  20,  20, 100 }
        };

    // disable deprecation warning for getenv() from Visual Studio
    // our usage should be safe given we only check whether variable is set
    // the value of the variable is never accessed
#ifdef _MSC_VER
#pragma warning(disable : 4996)
#endif
    if (std::getenv("WHITEBG") != nullptr)
      for (auto& x : default_cmap)
        for (auto& c : x)
          c = 100-c;
    }
    return default_cmap;
  }


  constexpr float lim_expand_by_factor = 0.1f;

  template <class ImageType>
    inline void Plot::line_x (ImageType& canvas, float x0, float y0, float x1, float y1,
        int colour_index, int stiple, float stiple_frac)
    {
      if (x0 > x1) {
        std::swap (x0, x1);
        std::swap (y0, y1);
      }

      float x_range = x1 - x0;
      float y_range = y1 - y0;

      int xmax = std::min (static_cast<int>(x1+1.0f), static_cast<int>(canvas.width()));
      for (int x = std::max (std::round (x0), 0.0f); x < xmax; ++x) {
        if (stiple > 0)
          if ( x%stiple >= stiple_frac*stiple)
            continue;
        int y = std::round (y0 + y_range*(x-x0)/x_range);
        if (y >= 0 && y < canvas.height())
          canvas(x,y) = colour_index;
      }
    }


  inline Plot::Plot (int width, int height, bool show_on_destruct) :
    show_on_destruct (show_on_destruct),
    font (Font::get_font()),
    canvas (width, height),
    cmap (get_default_cmap()),
    zero_is_transparent (true)
  {
    margin_x = 10*font.width();
    margin_y = 2*font.height();
    reset();
  }

  inline Plot::~Plot ()
  {
    if (show_on_destruct)
      show();
  }

  inline Plot& Plot::reset ()
  {
    xlim = { NAN, NAN };
    ylim = { NAN, NAN };
    xgrid = ygrid = NAN;
    canvas.clear();
    return *this;
  }

  inline Plot& Plot::show ()
  {
    if (std::isfinite (xgrid)) {
      for (float x = xgrid*std::ceil (xlim[0]/xgrid); x < xlim[1]; x += xgrid) {
        add_line (x, ylim[0], x, ylim[1], 1, ( x == 0.0 ? 0 : 10 ), 0.1);
        if (margin_y) {
          std::stringstream legend;
          legend << std::setprecision (3) << x;
          add_text (legend.str(), x, ylim[0], 0.5, 1.5);
        }
      }
    }
    if (std::isfinite (ygrid)) {
      for (float y = ygrid*std::ceil (ylim[0]/ygrid); y < ylim[1]; y += ygrid) {
        add_line (xlim[0], y, xlim[1], y, 1, ( y == 0.0 ? 0 : 10 ), 0.1);
        if (margin_x) {
          std::stringstream legend;
          legend << std::setprecision (3) << y << " ";
          add_text (legend.str(), xlim[0], y, 1.0, 0.5);
        }
      }
    }

    imshow (canvas, cmap, zero_is_transparent);

    return *this;
  }

  inline Plot& Plot::set_colourmap (const ColourMap& colourmap)
  {
    cmap = colourmap;
    return *this;
  }

  inline Plot& Plot::disable_transparency ()
  {
    zero_is_transparent = false;
    return *this;
  }

  inline Plot& Plot::set_xlim (float min, float max, float expand_by)
  {
    if (std::isfinite (xlim[0]) || std::isfinite (xlim[1]))
      throw std::runtime_error ("xlim already set (maybe implicitly by previous calls)");

    const float delta = expand_by * (max - min);
    xlim[0] = min - delta;
    xlim[1] = max + delta;
    if (!std::isfinite (xgrid))
      xgrid = (xlim[1] - xlim[0])/5.0;

    return *this;
  }

  inline Plot& Plot::set_ylim (float min, float max, float expand_by)
  {
    if (std::isfinite (ylim[0]) || std::isfinite (ylim[1]))
      throw std::runtime_error ("ylim already set (maybe implicitly by previous calls)");

    const float delta = expand_by * (max - min);
    ylim[0] = min - delta;
    ylim[1] = max + delta;
    if (!std::isfinite (ygrid))
      ygrid = (ylim[1] - ylim[0])/5.0;

    return *this;
  }

  inline Plot& Plot::set_grid (float x_interval, float y_interval)
  {
    xgrid = x_interval;
    ygrid = y_interval;
    return *this;
  }

  inline Plot& Plot::add_line (float x0, float y0, float x1, float y1,
      int colour_index, int stiple, float stiple_frac)
  {
    if (!std::isfinite (xlim[0]) || !std::isfinite (xlim[1]))
      set_xlim (std::min (x0, x1), std::max (x0, x1), lim_expand_by_factor);

    if (!std::isfinite (ylim[0]) || !std::isfinite (ylim[1]))
      set_ylim (std::min (y0, y1), std::max (y0, y1), lim_expand_by_factor);

    x0 = mapx (x0);
    y0 = mapy (y0);
    x1 = mapx (x1);
    y1 = mapy (y1);

    struct CanvasView {
      Image<ctype>& canvas;
      const int x_offset, y_offset;
      const bool transpose;
      int width () const { return transpose ? canvas.height()-y_offset : canvas.width()-x_offset; }
      int height () const { return transpose ? canvas.width()-x_offset : canvas.height()-y_offset; }
      ctype& operator() (int x, int y) { return transpose ? canvas(y+x_offset, x) : canvas(x+x_offset,y); }
    };

    bool transposed = std::abs (x1-x0) < std::abs (y1-y0);
    if (transposed) {
      std::swap (x0, y0);
      std::swap (x1, y1);
    }
    CanvasView view = { canvas, margin_x, margin_y, transposed };
    line_x (view, x0, y0, x1, y1, colour_index, stiple, stiple_frac);

    return *this;
  }


  template <class VerticesType>
    inline Plot& Plot::add_line (const VerticesType& y,
        int colour_index, int stiple, float stiple_frac)
    {
      if (!std::isfinite (xlim[0]) || !std::isfinite (xlim[1]))
        set_xlim (0, y.size()-1, 0.0);

      if (!std::isfinite (ylim[0]) || !std::isfinite (ylim[1]))
        set_ylim (std::ranges::min (y), std::ranges::max (y), lim_expand_by_factor);

      for (std::size_t n = 0; n < y.size()-1; ++n)
        add_line (n, y[n], n+1, y[n+1], colour_index, stiple, stiple_frac);

      return *this;
    }


  template <class VerticesTypeX, class VerticesTypeY>
    inline Plot& Plot::add_line (const VerticesTypeX& x, const VerticesTypeY& y,
        int colour_index, int stiple, float stiple_frac)
    {
      if (x.size() != y.size())
        throw std::runtime_error ("number of x & y vertices do not match");

      if (!std::isfinite (xlim[0]) || !std::isfinite (xlim[1]))
        set_xlim (std::ranges::min (x), std::ranges::max (x), lim_expand_by_factor);

      if (!std::isfinite (ylim[0]) || !std::isfinite (ylim[1]))
        set_ylim (std::ranges::min (y), std::ranges::max (y), lim_expand_by_factor);

      for (std::size_t n = 0; n < x.size()-1; ++n)
        add_line (x[n], y[n], x[n+1], y[n+1], colour_index, stiple, stiple_frac);

      return *this;
    }




  inline Plot& Plot::add_text (const std::string& text, float x, float y,
      float anchor_x, float anchor_y, int colour_index)
  {
    auto f = Font::get_font();
    const int text_width = f.width() * text.size();
    int posx = std::round (margin_x + mapx (x) - anchor_x * text_width);
    int posy = std::round (mapy (y) - (1.0-anchor_y) * f.height());

    for (std::size_t n = 0; n < text.size(); ++n) {
      f.render (canvas, text[n], posx+n*f.width(), posy, colour_index);
    }

    return *this;
  }




  inline float Plot::mapx (float x) const
  {
    return (canvas.width()-margin_x) * (x-xlim[0])/(xlim[1]-xlim[0]);
  }


  inline float Plot::mapy (float y) const
  {
    return (canvas.height()-margin_y) * (1.0 - (y-ylim[0])/(ylim[1]-ylim[0]));
  }









  // **************************************************************************
  //                   Font imlementation
  // **************************************************************************


  inline constexpr Font::Font (int width, int height, const std::span<const unsigned char>& data) :
    w (width), h (height), data (data) { }

  inline constexpr int Font::width() const { return w; }
  inline constexpr int Font::height() const { return h; }

  inline bool Font::get (int offset, int x, int y) const
  {
    offset = w*(y+h*offset) + x;
    int index = offset/8;
    int shift = offset-index*8;
    return data[index] & (1U<<shift);
  }

  template <typename ValueType>
    inline void Font::render (Image<ValueType>& canvas, char c, int x, int y, int colour_index) const
    {

      static constexpr char mapping [] = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14,
        15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32,
        33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50,
        51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68,
        69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86,
        87, 88, 89, 90, 91, 92, 93, 94, 0
      };

      c = mapping[static_cast<int>(c)];
      for (int j = std::max (0,-y); j < h - std::max (0,y+h-canvas.height()); ++j)
        for (int i = std::max (0,-x); i < w - std::max (0,w+x-canvas.width()); ++i)
          if (get(c,i,j))
            canvas(x+i,y+j) = colour_index;

    }



  namespace {
    // Font definitions

    // This is a straight bit-wise raster of the Unifont glyphs in the ASCII
    // visible range.

    constexpr std::array<const unsigned char,3420> unifont8x16= {
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,8,8,8,8,8,8,8,0,8,8,0,0,0,0,34,34,34,34,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,36,36,36,63,18,18,63,9,9,9,0,0,0,0,0,0,8,62,73,9,14,56,
      72,73,62,8,0,0,0,0,0,0,70,41,41,22,8,8,52,74,74,49,0,0,0,0,0,0,28,34,34,20,12,74,
      81,33,49,78,0,0,0,0,12,8,8,4,0,0,0,0,0,0,0,0,0,0,0,0,0,16,8,8,4,4,4,4,4,4,8,8,16,
      0,0,0,0,2,4,4,8,8,8,8,8,8,4,4,2,0,0,0,0,0,0,0,8,73,42,28,42,73,8,0,0,0,0,0,0,0,0,
      0,8,8,8,127,8,8,8,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,8,8,4,0,0,0,0,0,0,0,0,0,30,0,
      0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,12,12,0,0,0,0,0,0,32,32,16,8,8,4,4,2,1,1,0,0,0,
      0,0,0,12,18,33,49,41,37,35,33,18,12,0,0,0,0,0,0,8,12,10,8,8,8,8,8,8,62,0,0,0,0,0,
      0,30,33,33,32,24,4,2,1,1,63,0,0,0,0,0,0,30,33,33,32,28,32,32,33,33,30,0,0,0,0,0,
      0,16,24,20,18,17,17,63,16,16,16,0,0,0,0,0,0,63,1,1,1,31,32,32,32,33,30,0,0,0,0,0,
      0,28,2,1,1,31,33,33,33,33,30,0,0,0,0,0,0,63,32,32,16,16,16,8,8,8,8,0,0,0,0,0,0,30,
      33,33,33,30,33,33,33,33,30,0,0,0,0,0,0,30,33,33,33,62,32,32,32,16,14,0,0,0,0,0,0,
      0,0,12,12,0,0,0,12,12,0,0,0,0,0,0,0,0,0,12,12,0,0,0,12,8,8,4,0,0,0,0,0,0,32,16,8,
      4,2,4,8,16,32,0,0,0,0,0,0,0,0,0,63,0,0,0,63,0,0,0,0,0,0,0,0,0,1,2,4,8,16,8,4,2,1,
      0,0,0,0,0,0,30,33,33,32,16,8,8,0,8,8,0,0,0,0,0,0,28,34,41,53,37,37,37,57,2,60,0,
      0,0,0,0,0,12,18,18,33,33,63,33,33,33,33,0,0,0,0,0,0,31,33,33,33,31,33,33,33,33,31,
      0,0,0,0,0,0,30,33,33,1,1,1,1,33,33,30,0,0,0,0,0,0,15,17,33,33,33,33,33,33,17,15,
      0,0,0,0,0,0,63,1,1,1,31,1,1,1,1,63,0,0,0,0,0,0,63,1,1,1,31,1,1,1,1,1,0,0,0,0,0,0,
      30,33,33,1,1,57,33,33,49,46,0,0,0,0,0,0,33,33,33,33,63,33,33,33,33,33,0,0,0,0,0,
      0,62,8,8,8,8,8,8,8,8,62,0,0,0,0,0,0,124,16,16,16,16,16,16,17,17,14,0,0,0,0,0,0,33,
      17,9,5,3,3,5,9,17,33,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,63,0,0,0,0,0,0,33,33,51,51,45,
      45,33,33,33,33,0,0,0,0,0,0,33,35,35,37,37,41,41,49,49,33,0,0,0,0,0,0,30,33,33,33,
      33,33,33,33,33,30,0,0,0,0,0,0,31,33,33,33,31,1,1,1,1,1,0,0,0,0,0,0,30,33,33,33,33,
      33,33,45,51,30,96,0,0,0,0,0,31,33,33,33,31,9,17,17,33,33,0,0,0,0,0,0,30,33,33,1,
      6,24,32,33,33,30,0,0,0,0,0,0,127,8,8,8,8,8,8,8,8,8,0,0,0,0,0,0,33,33,33,33,33,33,
      33,33,33,30,0,0,0,0,0,0,65,65,65,34,34,34,20,20,8,8,0,0,0,0,0,0,33,33,33,33,45,45,
      51,51,33,33,0,0,0,0,0,0,33,33,18,18,12,12,18,18,33,33,0,0,0,0,0,0,65,65,34,34,20,
      8,8,8,8,8,0,0,0,0,0,0,63,32,32,16,8,4,2,1,1,63,0,0,0,0,0,56,8,8,8,8,8,8,8,8,8,8,
      56,0,0,0,0,0,1,1,2,4,4,8,8,16,32,32,0,0,0,0,0,7,4,4,4,4,4,4,4,4,4,4,7,0,0,0,12,18,
      33,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,127,0,0,0,8,4,4,12,0,0,0,0,
      0,0,0,0,0,0,0,0,0,0,0,0,30,33,32,62,33,33,49,46,0,0,0,0,0,1,1,1,29,35,33,33,33,33,
      35,29,0,0,0,0,0,0,0,0,30,33,1,1,1,1,33,30,0,0,0,0,0,32,32,32,46,49,33,33,33,33,49,
      46,0,0,0,0,0,0,0,0,30,33,33,63,1,1,33,30,0,0,0,0,0,24,4,4,4,31,4,4,4,4,4,4,0,0,0,
      0,0,0,0,32,46,17,17,17,14,2,30,33,33,30,0,0,0,1,1,1,29,35,33,33,33,33,33,33,0,0,
      0,0,0,8,8,0,12,8,8,8,8,8,8,62,0,0,0,0,0,16,16,0,24,16,16,16,16,16,16,16,9,6,0,0,
      0,1,1,1,17,9,5,3,5,9,17,33,0,0,0,0,0,12,8,8,8,8,8,8,8,8,8,62,0,0,0,0,0,0,0,0,55,
      73,73,73,73,73,73,73,0,0,0,0,0,0,0,0,29,35,33,33,33,33,33,33,0,0,0,0,0,0,0,0,30,
      33,33,33,33,33,33,30,0,0,0,0,0,0,0,0,29,35,33,33,33,33,35,29,1,1,0,0,0,0,0,0,46,
      49,33,33,33,33,49,46,32,32,0,0,0,0,0,0,29,35,33,1,1,1,1,1,0,0,0,0,0,0,0,0,30,33,
      1,6,24,32,33,30,0,0,0,0,0,0,4,4,4,31,4,4,4,4,4,24,0,0,0,0,0,0,0,0,33,33,33,33,33,
      33,49,46,0,0,0,0,0,0,0,0,33,33,33,18,18,18,12,12,0,0,0,0,0,0,0,0,65,73,73,73,73,
      73,73,54,0,0,0,0,0,0,0,0,33,33,18,12,12,18,33,33,0,0,0,0,0,0,0,0,33,33,33,33,33,
      50,44,32,32,30,0,0,0,0,0,0,63,32,16,8,4,2,1,63,0,0,0,0,0,24,4,4,8,8,4,2,4,8,8,4,
      4,24,0,0,8,8,8,8,8,8,8,8,8,8,8,8,8,8,0,0,0,6,8,8,4,4,8,16,8,4,4,8,8,6,0,0,0,70,73,
    };
  }

  inline constexpr const Font Font::get_font (int size)
  {
    switch (size) {
      case 16: return { 8, 16, unifont8x16 };
      default: throw std::runtime_error (std::format ("font size {} not supported", size));
    }
  }



}

#endif

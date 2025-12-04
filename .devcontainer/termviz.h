#pragma once

/*
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/.
 *
 * (c) 2025 J-Donald Tournier (jdtournier@gmail.com)
 *
 * With inspiration from:
 * - for sixel protocol: https://vt100.net/shuford/terminal/all_about_sixels.txt
 */

#include <iostream>
#include <cassert>
#include <array>
#include <limits>
#include <cmath>
#include <vector>
#include <span>
#include <format>
#include <sstream>
#include <iomanip>






//! The namespace within which all functionality is placed
namespace termviz {

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
   * This can be used in conjuction with termviz::Clear to provide running updates.
   * Simply feed the string to `std::cout` to issue the instruction, for example:
   * ```
   *   std::cout << termviz::Clear;
   *   while (true) {
   *     std::cout << termviz::Home << "Current progress:\n";
   *     termviz::plot().render_line(...);
   *
   *     ...
   *     // perform computations, etc.
   *     ...
   *   }
   * ```
   * \sa termviz::Clear
   */
  constexpr inline std::string_view Home = "\033[H";

  //! VT100 code to clear the screen
   /** \sa termviz::Home
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




  //! Render a line segment
  /** This renders a straight line element from (x0,y0) to (x1,y1).
   *
   * See main class description for an explanation of the remaining
   * arguments.
   */
  template <typename ImageType>
    void render_line (ImageType& canvas, float x0, float y0, float x1, float y1,
        int colour_index, int stiple = 0, float stiple_frac = 0.5);


  //! Render text at the location specified
  /** This renders the text in `text` at the location (x,y). By default,
   * the text is centred on (x,y), but the location of the 'anchor' can be
   * set using the `anchor_x` & `anchor_y` parameters.
   *
   * See main class description for an explanation of the remaining
   * arguments.
   */
  template <typename ImageType>
    inline void render_text (ImageType& canvas, const std::string& text, float x, float y,
        float anchor_x = 0.5, float anchor_y = 0.5, int colour_index = 1);


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

      template <typename ImageType>
        void render (ImageType& canvas, char c, int x, int y, int colour_index) const;

      static constexpr const Font get_font (int size = 16);

    private:
      const int w, h;
      const std::span<const unsigned char> data;
  };



  // **************************************************************************
  //                   Plot implementation
  // **************************************************************************

  namespace {

    constexpr auto inf = std::numeric_limits<float>::infinity();
    constexpr auto None = std::numeric_limits<float>::quiet_NaN();

    const ColourMap& get_default_cmap();

    struct End {
      mutable std::array<int,2> canvas_size = { 768, 512 };
      mutable ColourMap cmap = get_default_cmap();
      mutable bool zero_is_transparent = true;
      mutable bool done = false;
      mutable std::array<float,2> tick_spacing = { None, None };
      mutable std::array<bool,2> grid = { true, true };
      mutable std::array<float,2> xlim = { inf, -inf };
      mutable std::array<float,2> ylim = { inf, -inf };

      ColourMap& get_colourmap() const { return cmap; }
      bool& get_transparent () const { return zero_is_transparent; }

      bool already_rendered () const { if (done) return true; done = true; return false; }
      template <typename ImageType> void render (ImageType& canvas) const { }
      std::array<int,2>& get_canvas_size() const { return canvas_size; }
      std::array<float,2>& get_tick_spacing() const { return tick_spacing; }
      std::array<bool,2>& get_grid() const { return grid; }
      void update_lim (std::array<float,2>& xlim, std::array<float,2>& ylim) const { }
      std::array<float,2>& get_xlim() const { return xlim; }
      std::array<float,2>& get_ylim() const { return ylim; }
    };

    struct CanvasItem {
      template <typename ImageType> void render (ImageType& canvas) const { }
      void update_lim (std::array<float,2>& xlim, std::array<float,2>& ylim) const { }
    };

    struct TextItem {
      const std::string& text;
      std::array<float,2> pos, anchor;
      int colour_index;
      template <typename ImageType> void render (ImageType& canvas) const;
      void update_lim (std::array<float,2>& xlim, std::array<float,2>& ylim) const { }
    };

    template <typename VectorType>
      struct LineYItem {
        const VectorType& y;
        int colour_index, stiple;
        float stiple_frac;
        template <typename ImageType> void render (ImageType& canvas) const;
        void update_lim (std::array<float,2>& xlim, std::array<float,2>& ylim) const;
      };

    template <typename VectorTypeX, typename VectorTypeY>
      struct LineXYItem {
        const VectorTypeX& x;
        const VectorTypeY& y;
        int colour_index, stiple;
        float stiple_frac;
        template <typename ImageType> void render (ImageType& canvas) const;
        void update_lim (std::array<float,2>& xlim, std::array<float,2>& ylim) const;

      };





    template <typename Item, typename Previous>
      struct Entry {
        public:
          const Item item;
          const Previous prev;

          ~Entry() { if (!already_rendered()) main_render(); }

          template <typename VectorType>
            auto line (const VectorType& y, int colour_index = 2, int stiple = 0, float stiple_frac = 0.5) const
            -> Entry<LineYItem<VectorType>,decltype(*this)> { return { { y, colour_index, stiple, stiple_frac }, *this }; }

          template <typename VectorTypeX, typename VectorTypeY>
            auto line (const VectorTypeX& x, const VectorTypeY& y, int colour_index = 2, int stiple = 0, float stiple_frac = 0.5) const
            -> Entry<LineXYItem<VectorTypeX,VectorTypeY>,decltype(*this)> {
              if (x.size() != y.size())
                throw std::runtime_error ("X & Y dimensions do not match");
              return { { x, y, colour_index, stiple, stiple_frac }, *this };
            }

          auto text (const std::string& text, float x, float y, float anchor_x = 0.5, float anchor_y = 0.5, int colour_index = 1) const
            -> Entry<TextItem,decltype(*this)> { return { { text, { x, y }, { anchor_x, anchor_y} , colour_index }, *this }; }


          const Entry& xlim (float x_min, float x_max) const { get_xlim() = { x_min, x_max }; return *this; }
          const Entry& ylim (float y_min, float y_max) const { get_ylim() = { y_min, y_max }; return *this; }
          const Entry& ticks (float x_spacing, float y_spacing) const { get_tick_spacing() = { x_spacing, y_spacing }; return *this; }
          const Entry& grid (bool show_xgrid, bool show_ygrid) const { get_grid() = { show_xgrid, show_ygrid }; return *this; }
          const Entry& colourmap (const ColourMap& cmap) const { get_colourmap() = cmap; return *this; }
          const Entry& transparent (bool is_transparent) const { get_transparent() = is_transparent; return *this; }


        private:
          template <typename OtherItem, typename OtherPrevious> friend class Entry;

          ColourMap& get_colourmap () const { return prev.get_colourmap(); }
          bool& get_transparent () const { return prev.get_transparent(); }
          std::array<int,2>& get_canvas_size() const { return prev.get_canvas_size(); }
          std::array<float,2>& get_tick_spacing() const { return prev.get_tick_spacing(); }
          std::array<bool,2>& get_grid() const { return prev.get_grid(); }
          std::array<float,2>& get_xlim() const { return prev.get_xlim(); }
          std::array<float,2>& get_ylim() const { return prev.get_ylim(); }

          void update_lim (std::array<float,2>& xlim, std::array<float,2>& ylim) const {
            prev.update_lim (xlim, ylim);
            item.update_lim (xlim, ylim);
          }

          bool already_rendered () const { return prev.already_rendered(); }
          void main_render () const ;
          template <typename ImageType> void render (ImageType& canvas) const { prev.render (canvas); item.render (canvas); }

      };



  }


  inline Entry<CanvasItem,End> plot (int width = 900, int height = 300) { return { { } , { width, height } }; }















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
  //                   line drawing implementation
  // **************************************************************************

  namespace {


    inline const ColourMap& get_default_cmap()
    {
      static  ColourMap default_cmap;

      if (!default_cmap.empty())
        return default_cmap;


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

      return default_cmap;
    }



    template <class ImageType>
      inline void line_x (ImageType& canvas, float x0, float y0, float x1, float y1,
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

  }




  template <typename ImageType>
    inline void render_line (ImageType& canvas, float x0, float y0, float x1, float y1,
        int colour_index, int stiple, float stiple_frac)
    {
      struct CanvasView {
        ImageType& canvas;
        const bool transpose;
        int width () const { return transpose ? canvas.height() : canvas.width(); }
        int height () const { return transpose ? canvas.width() : canvas.height(); }
        ctype& operator() (int x, int y) { return transpose ? canvas(y,x) : canvas(x,y); }
      };

      bool transposed = std::abs (x1-x0) < std::abs (y1-y0);
      if (transposed) {
        std::swap (x0, y0);
        std::swap (x1, y1);
      }
      CanvasView view = { canvas, transposed };
      line_x (view, x0, y0, x1, y1, colour_index, stiple, stiple_frac);
    }




  template <typename ImageType>
    inline void render_text (ImageType& canvas, const std::string& text, float x, float y,
        float anchor_x, float anchor_y, int colour_index)
    {
      auto f = Font::get_font();
      const int text_width = f.width() * text.size();
      int posx = std::round (x - anchor_x * text_width);
      int posy = std::round (y - (1.0-anchor_y) * f.height());

      for (std::size_t n = 0; n < text.size(); ++n)
        f.render (canvas, text[n], posx+n*f.width(), posy, colour_index);
    }




  namespace {

    inline float compute_tick_spacing (const std::array<float,2>& lim, float init_spacing)
    {
      double tick = (lim[1]-lim[0])/init_spacing;
      double mult = std::pow(10.0, std::floor (std::log10 (tick)));
      double scaled = tick/mult;
      if (scaled < 2.0)
        return 2.0*mult;
      if (scaled < 5.0)
        return 5.0*mult;
      return 10.0*mult;
    }

    inline void refine_lim (std::array<float,2>& lim, float spacing)
    {
      lim[0] = spacing * std::floor (lim[0] / spacing);
      lim[1] = spacing * std::ceil (lim[1] / spacing);
    }

    template <typename Item, typename Previous>
      inline void Entry<Item,Previous>::main_render () const {
        auto canvas_size = get_canvas_size();
        auto tick_spacing = get_tick_spacing();
        auto grid = get_grid();

        Image<ctype> canvas (canvas_size[0], canvas_size[1]);

        std::array<float,2> xlim = { inf, -inf }, ylim = { inf, -inf };
        update_lim (xlim, ylim);

        auto xlim_set = get_xlim();
        auto ylim_set = get_ylim();

        const bool xlim_manual = std::isfinite (xlim_set[0]) && std::isfinite (xlim_set[1]);
        const bool ylim_manual = std::isfinite (ylim_set[0]) && std::isfinite (ylim_set[1]);

        const bool show_xticks = !( tick_spacing[0] <= 0.0 );
        const bool show_yticks = !( tick_spacing[1] <= 0.0 );

        if (xlim_manual) xlim = xlim_set;
        if (ylim_manual) ylim = ylim_set;

        auto font = Font::get_font();
        int margin_left = 10*font.width();
        int margin_bottom = 2*font.height();
        int margin_right = 3*font.width();
        int margin_top = 1*font.height();

        auto xtick_spacing = compute_tick_spacing (xlim, std::max (8.0f, (canvas.width()-margin_left)/(5.0f*font.height())));
        auto ytick_spacing = compute_tick_spacing (ylim, std::max (8.0f, (canvas.height()-margin_bottom)/(5.0f*font.height())));

        if (!xlim_manual) refine_lim (xlim, xtick_spacing);
        if (!ylim_manual) refine_lim (ylim, ytick_spacing);

        if (!std::isfinite (tick_spacing[0]) || tick_spacing[0] <= 0.0) tick_spacing[0] = xtick_spacing;
        if (!std::isfinite (tick_spacing[1]) || tick_spacing[1] <= 0.0) tick_spacing[1] = ytick_spacing;


        struct CanvasView {
          Image<ctype>& canvas;
          int margin_left, margin_bottom, margin_right, margin_top;
          std::array<float,2> xlim, ylim;
          int width () const { return canvas.width() - margin_left - margin_right; }
          int height () const { return canvas.height() - margin_bottom - margin_top; }
          float mapx (float x) const { return (width()-1) * (x-xlim[0])/(xlim[1]-xlim[0]); }
          float mapy (float y) const { return (height()-1) * (1.0 - (y-ylim[0])/(ylim[1]-ylim[0])); }
          ctype& operator() (int x, int y) { return canvas(x+margin_left,y+margin_top); }
        };

        CanvasView plot_area = { canvas, margin_left, margin_bottom, margin_right, margin_top, xlim, ylim };

        for (int n = std::ceil (xlim[0]/tick_spacing[0]); n <= xlim[1]/tick_spacing[0]; n++) {
          const float x = n*tick_spacing[0];
          if (grid[0])
            render_line (plot_area, plot_area.mapx(x), plot_area.mapy(ylim[0]), plot_area.mapx(x), plot_area.mapy(ylim[1]), 1, 10, ( n == 0 ? 0.7 : 0.1 ));

          if (show_xticks) {
            std::stringstream legend;
            legend << std::setprecision (3) << x;
            render_text (canvas, legend.str(), margin_left+plot_area.mapx(x), margin_top+plot_area.mapy (ylim[0]), 0.5, 1.5);
            render_line (plot_area, plot_area.mapx(x), plot_area.mapy(ylim[0]), plot_area.mapx(x), plot_area.mapy(ylim[0])-5, 1);
          }
        }

        for (int n = std::ceil (ylim[0]/tick_spacing[1]); n <= ylim[1]/tick_spacing[1]; n++) {
          const float y = n*tick_spacing[1];
          if (grid[1])
            render_line (plot_area, plot_area.mapx(xlim[0]), plot_area.mapy(y), plot_area.mapx(xlim[1]), plot_area.mapy(y), 1, 10, ( n == 0 ? 0.7 : 0.1 ));

          if (show_yticks) {
            std::stringstream legend;
            legend << std::setprecision (3) << y << " ";
            render_text (canvas, legend.str(), margin_left+plot_area.mapx(xlim[0]), margin_top+plot_area.mapy(y), 1.0, 0.5);
            render_line (plot_area, plot_area.mapx(xlim[0]), plot_area.mapy(y), plot_area.mapx(xlim[0])+5, plot_area.mapy(y), 1);

          }
        }

        prev.render (plot_area);
        item.render (plot_area);

        imshow (canvas, get_colourmap(), get_transparent());
      }


    template <typename VectorType>
      inline std::array<float,2> get_range (const VectorType& v)
      {
        std::array<float,2> lim = { inf, -inf };
        for (const auto& x : v) {
          lim[0] = std::min (lim[0], static_cast<float>(x));
          lim[1] = std::max (lim[1], static_cast<float>(x));
        }
        return lim;
      }


    inline void __update_lim (std::array<float,2>& current_lim, const std::array<float,2>& new_lim)
    {
      current_lim[0] = std::min (current_lim[0], new_lim[0]);
      current_lim[1] = std::max (current_lim[1], new_lim[1]);
    }



    template <typename VectorType>
      inline void LineYItem<VectorType>::update_lim (std::array<float,2>& xlim, std::array<float,2>& ylim) const
      {
        __update_lim (xlim, { 0.0f, static_cast<float>(y.size()) });
        __update_lim (ylim, get_range(y));
      }


    template <typename VectorTypeX, typename VectorTypeY>
      inline void LineXYItem<VectorTypeX,VectorTypeY>::update_lim (std::array<float,2>& xlim, std::array<float,2>& ylim) const
      {
        __update_lim (xlim, get_range(x));
        __update_lim (ylim, get_range(y));
      }


    template <typename ImageType>
      inline void TextItem::render (ImageType& canvas) const
      {
        render_text (canvas, text, canvas.mapx(pos[0]), canvas.mapy(pos[1]), anchor[0], anchor[1], colour_index);
      }

    template <typename VectorType> template <typename ImageType>
      inline void LineYItem<VectorType>::render (ImageType& canvas) const
      {
        for (std::size_t n = 0; n < y.size()-1; ++n)
          render_line (canvas, canvas.mapx(n), canvas.mapy(y[n]), canvas.mapx(n+1), canvas.mapy(y[n+1]), colour_index, stiple, stiple_frac);
      }

    template <typename VectorTypeX, typename VectorTypeY> template <typename ImageType>
      inline void LineXYItem<VectorTypeX,VectorTypeY>::render (ImageType& canvas) const
      {
        for (std::size_t n = 0; n < x.size()-1; ++n)
          render_line (canvas, canvas.mapx(x[n]), canvas.mapy(y[n]), canvas.mapx(x[n+1]), canvas.mapy(y[n+1]), colour_index, stiple, stiple_frac);
      }

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

  template <typename ImageType>
    inline void Font::render (ImageType& canvas, char c, int x, int y, int colour_index) const
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



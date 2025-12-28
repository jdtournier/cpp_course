#include <fstream>
#include <string>
#include <format>
#include <stdexcept>

#include "terminal_graphics.h"
#include "write_pgm.h"

void write_pgm (const std::string& filename, const TG::Image<float>& out, float scale_factor)
{
    // find max values:
    float max_val = 0.0;
    for (int y = 0; y < out.height(); y++)
        for (int x = 0; x < out.width(); x++)
            max_val = std::max (out(x,y), max_val);


    std::ofstream outstream (filename);
    if (!outstream)
        throw std::runtime_error ("failed to open output file \"" + filename + "\"");

    max_val *= scale_factor;
    outstream << std::format ("P2\n{} {}\n{}\n", out.width(), out.height(), std::round (max_val));


    for (int y = 0; y < out.height(); y++) {
        for (int x = 0; x < out.width(); x++)
            outstream << std::round (scale_factor * out(x,y)) << " ";
        outstream << "\n";
    }
}


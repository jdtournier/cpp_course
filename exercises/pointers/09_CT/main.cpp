#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#include "load_pgm.h"
#include "write_pgm.h"
#include "terminal_graphics.h"
#include "convert.h"

int main (int argc, char* argv[])
{
    std::vector<std::string> args (argv, argv+argc);
    if (args.size() < 2)
        throw std::runtime_error ("expected input PGM image as first argument");

    auto ct = load_pgm<int> (args[1]);
    TG::imshow (ct, -1000, 3000);

    auto ac = convert_HU_to_AC (ct);

    TG::imshow (ac, 0, 0.3);

    if (args.size() > 2)
        write_pgm (args[2], ac, 1000);

    return 0;
}

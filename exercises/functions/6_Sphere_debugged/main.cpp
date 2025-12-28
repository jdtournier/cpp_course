#include <iostream>
#include "sphere.h"

// The two errors were:
//
// - The prototype (in sphere.h) and function signature (in sphere.cpp) of the
//   sphere() function do not match. The argument to the function in sphere.cpp
//   should be double, not int.
//
// - The constant pi has local scope, i.e. it is only accessible from within
//   the main() function. Its definition should be moved to the sphere.cpp
//   file.  Or, alternatively, the built-in M_PI constant from the <cmath>
//   include file can be used.


int main () {

    double r;
    do {
        std::cout << "Enter radius (type -ve number to stop): ";
        std::cin >> r;

        if (r >= 0.0)
            std::cout << "V = " << sphere(r) << "\n";
    } while (r >= 0.0);
}

#include <iostream>
#include <cmath>

int main()
{
    { //(i)
      // No compilation error, although behaviour at run-time undefined due to division by zero.
        int a = 0;
        float b = 4;
        int c = b / a;
        std::cout << " c = " << c << "\n";
    }

    { //(ii)
      // No compilation error. the std::abs() function is a template function
      // and will return a value of the same type as its argument, i.e. an int in this case.
        int a = -2;
        float b = 4;
        int c = b / std::abs (a);
        std::cout << " c = " << c << "\n";
    }

    { //(iii)
      // Compilation error. The modulo operator will only work for integer values,
      // and this will be checked at compile-time as C++ uses static type checking.
        int a = 2;
        float b = 4;
        int c = b % a ;
        std::cout << " c = " << c << "\n";
    }

    return 0;
}

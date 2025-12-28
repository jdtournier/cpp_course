#include <iostream>
#include <cmath>

int main ()
{
    // trigonometry application
    int code;

    // loop until -1 entered as code
    do {
        // read numbers
        std::cout << "Enter value & code (1=sin, 2=cos, 3=tan, -1=exit): ";
        float value;
        std::cin >> value >> code;

        // validate code
        switch (code) {
            case 1:
                std::cout << "sin(" << value << ") = "
                     << sin(value) << "\n";
                break;
            case 2:
                std::cout << "cos(" << value << ") = "
                     << cos(value) << "\n";
                break;
            case 3:
                std::cout << "tan(" << value << ") = "
                     << tan(value) << "\n";
                break;
            case -1:
                std::cout << "exiting ...\n";
                break;
            default:
                std::cout << "invalid code - reenter\n";
        }
    } while (code != -1);

    return 0;
}


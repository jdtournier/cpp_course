#include <iostream>
#include <limits>

int main ()
{
    // program to output stats of sequence of integers
    int count = 0, minimum = std::numeric_limits<int>::max();
    int maximum = std::numeric_limits<int>::min();
    int sum = 0;
    int value;

    // iteration - must read at least one number
    do {
        // read number
        std::cout << "Enter integer: ";
        std::cin >> value;

        // if number is positive, update count, sum, min & max:
        if (value >= 0) {
            count++;
            sum += value;
            minimum = std::min (minimum, value);
            maximum = std::max (maximum, value);
        }
    } while (value >= 0);

    // display stats:
    std::cout << count << " numbers entered\n";
    std::cout << "  sum = " << sum << "\n";
    std::cout << "  range = " << maximum - minimum << "\n";
    std::cout << "  mean = " << static_cast<float>(sum) / count << "\n";

    return 0;
}

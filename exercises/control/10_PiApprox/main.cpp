#include <iostream>
#include <cmath>

int main ()
{
    // error in approximation
    double e;

    // test different values of N, the number
    // of terms in the series
    int N = 1;
    do {

        // use Euler 's approximation to N terms
        double sum = 0.0;
        for (int n = 1; n <= N; n++)
            sum += 1.0/(n*n);

        double approx = std::sqrt (6.0 * sum);

        std::cout << "N = " << N << ", pi ~ " << approx << "\n";

        // what 's the error in approximation?
        e = std::abs (M_PI - approx);

        // increase number of terms in series
        N++;
    } while (e > 0.001);

    // display answer
    std::cout << "Euler's approximation is correct to within 0.001 for N="
       << N << "\n";

    return 0;
}


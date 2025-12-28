#include <iostream>

#include "sample.h"

int main()
{
    std::vector<float> a { 18.44, 14.18, 19.79, 15.73, 15.36, 16.17, 13.91, 15.35 };
    Sample samp;
    samp.set_sample (a);
    samp.display();
    std::cout << "Sample mean = " << samp.mean() << "\n";
    std::cout << "Sample std dev = " << samp.std_dev() << "\n";
    return 0;
}

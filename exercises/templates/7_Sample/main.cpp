#include <iostream>
#include "sample.h"

int main()
{
    // float sample
    float a[8] = {18.44,14.18,19.79,15.73,15.36,16.17,13.91,15.35};
    Sample<float> samp1;
    samp1.set_sample(a, 8);
    samp1.display();
    std::cout << "Sample mean = " << samp1.mean() << std::endl;
    std::cout << "Sample std dev = " << samp1.std_dev() << std::endl;
    std::cout << "Sample std error of mean = " << samp1.s_e() << std::endl;
    std::cout << "Sample 95% conf intervals = " << samp1.lower_95() << " - " << samp1.upper_95() << std::endl;
    std::cout << "Sample median = " << samp1.median() << std::endl;
    std::cout << "Sample IQR = " << samp1.iqr() << std::endl;
    std::cout << "Sample skew = " << samp1.skew() << std::endl;

    // int sample
    int b[8] = {18,14,19,15,15,16,13,15};
    Sample<int> samp2;
    samp2.set_sample(b, 8);
    samp2.display();
    std::cout << "Sample mean = " << samp2.mean() << std::endl;
    std::cout << "Sample std dev = " << samp2.std_dev() << std::endl;
    std::cout << "Sample std error of mean = " << samp2.s_e() << std::endl;
    std::cout << "Sample 95% conf intervals = " << samp2.lower_95() << " - " << samp2.upper_95() << std::endl;
    std::cout << "Sample median = " << samp2.median() << std::endl;
    std::cout << "Sample IQR = " << samp2.iqr() << std::endl;
    std::cout << "Sample skew = " << samp2.skew() << std::endl;

    return 0;
}

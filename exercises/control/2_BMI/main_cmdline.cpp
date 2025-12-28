#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

int main (int argc, char* argv[])
{
    // read mass and height and
    // compute BMI classification

    std::vector<std::string> args (argv, argv+argc);
    if (args.size() < 3)
        throw std::runtime_error ("expected mass & height as arguments");

    float mass = std::stod (args[1]);
    float height = std::stod (args[2]);

    // compute and display BMI
    float bmi = mass / (height * height);
    std::cout << "Your BMI is " << bmi << "\n";

    // classify
    if (bmi < 18.5)
        std::cout << "Underweight\n";
    else {
        if (bmi < 25)
            std::cout << "Normal\n";
        else {
            if (bmi < 30)
                std::cout << "Overweight\n";
            else
                std::cout << "Obese\n";
        }
    }

    return 0;
}

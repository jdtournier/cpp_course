#include <iostream>

int main ()
{
    // read mass and height and
    // compute BMI classification

    // read mass and height
    std::cout << "Enter mass height (separated by space ): ";
    float mass, height;
    std::cin >> mass >> height;

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


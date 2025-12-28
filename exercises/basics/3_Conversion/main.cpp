#include <iostream>

int main ()
{
    // program to convert distances between miles and km
    float km, miles, km_in_miles ;

    // read distance in miles
    std::cout << "Enter distance in miles: ";
    std::cin >> miles ;

    // convert to km
    km_in_miles = (5.0/8.0); // one km in units of miles
    km = miles / km_in_miles;

    // display in km
    std::cout << "This equates to " << km << " km\n";

    return 0;
}


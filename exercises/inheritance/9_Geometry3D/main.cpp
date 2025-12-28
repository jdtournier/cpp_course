#include <iostream>

#include "shape.h"

int main()
{
    // square
    float l = 4.5;
    Square sq(l);
    sq.compute_area();
    sq.compute_perimeter();
    std::cout << "Square of side length " << l << ": \n";
    std::cout << "  Area = " << sq.get_area() << "\n";
    std::cout << "  Perimeter = " << sq.get_perimeter() << "\n";

    // circle
    float r = 2.7;
    Circle c(r);
    c.compute_area();
    c.compute_perimeter();
    std::cout << "Circle of radius " << r << ": \n";
    std::cout << "  Area = " << c.get_area() << "\n";
    std::cout << "  Perimeter = " << c.get_perimeter() << "\n";

    // sphere
    Sphere sp(r);
    sp.compute_volume();
    sp.compute_surface_area();
    std::cout << "Sphere of radius " << r << ":\n";
    std::cout << "  Volume = " << sp.get_volume() << "\n";
    std::cout << "  Surface area = " << sp.get_surface_area() << "\n";

    return 0;
}

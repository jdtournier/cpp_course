#include <iostream>
#include "triangle.h"
using namespace std;

int main()
{
    //read in three points
    float x, y;
    cout << "Enter x and y coords of 1st point: ";
    cin >> x >> y;
    Point p1(x, y);
    cout << "Enter x and y coords of 2nd point: ";
    cin >> x >> y;
    Point p2(x, y);
    cout << "Enter x and y coords of 3rd point: ";
    cin >> x >> y;
    Point p3(x, y);

    //calculate area
    Triangle t (p1, p2, p3);
    cout << "The area of the triangle is " << t.Area() << endl;
    return 0;
}

#include <iostream>
#include "sphere.h"
using namespace std;

int main () {
    const float pi = 3.14159265;
    float r;
    do {
        cout << "Enter radius (type -ve number to stop)\n";
        cin >> r;
        if (r >= 0.0)
            cout << "V =  " << sphere(r) << endl;
    } while (r >= 0.0);
}



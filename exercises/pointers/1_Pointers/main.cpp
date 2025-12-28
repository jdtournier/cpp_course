#include <iostream>

using namespace std;

// program to illustrate pointer use
int main()
{
    int *a, *b;

    a = new int;
    *a = 3;
    b = a;
    cout << "a->" << *a << ", b->" << *b << endl;

    *b = 4;
    cout << "a->" << *a << ", b->" << *b << endl;

    b = new int;
    *b = 6;
    cout << "a->" << *a << ", b->" << *b << endl;

    delete a;
    a = b;
    cout << "a->" << *a << ", b->" << *b << endl;

    return 0;
}

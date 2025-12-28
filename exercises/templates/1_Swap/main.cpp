#include <iostream>

// function prototype
template <class t> void swapvals (t&, t&);

int main()
{
    //integer values
    int x = 3, y = 5;
    std::cout << "Before swap: x = " << x << ", y = " << y << std::endl;
    swapvals (x, y);
    std::cout << "After swap: x = " << x << ", y = " << y << std::endl;

    // char values
    char a = 'p', b = 'k';
    std::cout << "Before swap: a = " << a << ", b = " << b << std::endl;
    swapvals (a, b);
    std::cout << "After swap: a = " << a << ", b = " << b << std::endl;

    return 0;
}

// function body
template <class t> void swapvals (t& val1, t& val2)
{
    t temp;
    temp = val1;
    val1 = val2;
    val2 = temp;
}

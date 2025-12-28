#include <iostream>
#include "stack.h"

int main()
{
    // push 5 characters onto stack
    Stack<char,100> s;
    char c;
    for (int i = 0; i < 5; i++) {
        std::cout << "Enter character: ";
        std::cin >> c;
        s.push(c);
        std::cout << "Pushing " << c << " ..." << std::endl;
    }

    // now pop them all off again ...
    for (int i = 0; i < 5; i++) {
        c = s.pop();
        std::cout << "Popped " << c << std::endl;
    }

    // push 5 integers onto stack
    Stack<int,100> si;
    int a;
    for (int i = 0; i < 5; i++) {
        std::cout << "Enter integer: ";
        std::cin >> a;
        si.push(a);
        std::cout << "Pushing " << a << " ..." << std::endl;
    }

    // now pop them all off again ...
    for (int i = 0; i < 5; i++) {
        a = si.pop();
        std::cout << "Popped " << a << std::endl;
    }

    return 0;
}

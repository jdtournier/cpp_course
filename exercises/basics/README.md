# Exercises: Basics of C++

## Exercise 1

Below are shown a number of variable and constant declarations/initialisations.
There are some bugs (errors) in the code. Identify the bugs and fix them.

```c++
#include <iostream>


int main ()
{
    int a;
    floaty;
    int z;
    long int p = 1000;
    const max = 100;
    const float e;
    char c
    short z;

    return 0;
}
```

<br>


## Exercise 2

Without writing any C++ code, decide what you think the results of the
following expressions would be in C++. After you have finished, test your
answers by writing a program that computes and prints out the answers. Remember
that in C++ expressions involving only integers are computed using integer
arithmetic.

- (7.0 * 3) / 5
- (7 * 3) / 5
- (7 * 3) % 5
- (7.0 * 3) % 5

<br>


## Exercise 3

The following program is intended to read a distance in miles from the user and
display its equivalent in km. However, the program does not currently work
correctly. Compile and run the program and then debug it so that it performs
the conversion correctly.

```c++
# include <iostream>

int main ()
{
    // program to convert distances between miles and km
    float km, miles, km_in_miles ;

    // read distance in miles
    std::cout << "Enter distance in miles: ";
    std::cin >> miles ;

    // convert to km
    km_in_miles = (5/8); // one km in units of miles
    km = miles / km_in_miles;

    // display in km
    std::cout << " This equates to " << km << " km\n";

    return 0; 
}
```


<br>


## Exercise 4

Write a C++ program which evaluates the result and remainder of the expression
(2 + 3 ∗ 3)/*n*, where *n* is an integer number entered by the user. The program
should use integer arithmetic to compute the result and should print out both
the result and the remainder.

<br>


## Exercise 5

Now modify the program you wrote in Exercise 4 to use floating point arithmetic
instead. Since the remainder operator is not defined for floating point
arithmetic, this time only the result of the expression should be printed.


<br>


## Exercise 6

Create a C++ project containing the following code:

```c++
#include <iostream>

int main ()
{
    int x=5, y=10;
    // ADD CODE HERE
    return 0;
}
```

Now replace the comment line with single statements to perform the following
tasks:

- Add 1 to x and then display the new value of x.
- Display the value of y and then subtract 1 from it.

<br>


## Exercise 7 

Which of the following C++ programs will lead to compilation errors?
Verify your answers by entering the code into a `.cpp` file and compiling.

### (a)

```c++
#include <iostream>

int main ()
{
    int a = 0;
    float b = 4;
    int c = b / a;
    std::cout << " c = " << c << "\n";
    return 0;
}
```

### (b)

```c++
#include <iostream>
#include <cmath>

int main ()
{
    int a = -2;
    float b = 4;
    int c = b / std::abs (a);
    std::cout << " c = " << c << "\n";
    return 0;
}
```

### (c)

```c++
#include <iostream>

int main ()
{
    int a = 2;
    float b = 4;
    int c = b % a ;
    std::cout << " c = " << c << "\n";
    return 0;
}
```

<br>


## Exercise 8

Write a C++ program to read in an integer value from the user (from the
terminal or as a command-line argument) and compute and display the square root
of its absolute value.


<br>


## Exercise 9

Write a C++ program which takes three command-line arguments, corresponding to
floating point numbers *x*, *y*, *z*, and then calculates and prints out the result
of evaluating:

$$
x^{y^z}
$$

<br>


## Exercise 10

Write a C++ program taking a single command-line argument, corresponding to an
integer number *i*, and then use floating point arithmetic to compute the value
of the following expression:

$$
((i + 3) \times (i + 2) \times (i + 1) \times i)^3
$$

<br>


## Exercise 11

Below is a code listing for a C++ program which is intended to compute the
roots of a quadratic equation of the form:

$$
ax^2 + bx + c = 0
$$

The formula for solving for *x* is:

$$
x = \frac{-b \pm \sqrt{b^2 - 4ac}}{2a}
$$

The following program currently does not compile. Modify it so that it compiles
correctly, then test it and remove any further bugs in the code if required.

```c++
#include <iostream>

int main ()
{
    // compute roots of quadratic equation of form ax^2 + bx + c = 0

    // declare variables for coefficients and roots
    float a, b, c, r1, r2;

    // read values of coefficients from user
    std::cout << "Enter a b c: ";
    std::cin >> a >> b << c;

    // compute roots
    r1 = -b + std::sqrt (b*b - 4.0*a*c) / (2.0*a);
    r2 = -b - std::sqrt (b*b - 4.0*a*c) / (2.0*a);

    // display answers
    std::cout << "Roots = " << r1 << ", " << r2 << "\n";
    return 0;
}
```

<br>


## Exercise 12

Write a program to read in three floating point values from the user (a, b and
c), which represent the lengths of three sides of a triangle. The program
should then compute the area of the triangle according to the equation:

$$
A = s (s − a) (s − b) (s − c)
$$

where *s* is half of the sum of the three sides.

<br>


## Exercise 13

Write a program to accept a single command-line argument, corresponding to a
floating point number representing a radius *r*, and then compute the surface
area *S* and volume *V* of a sphere of that radius, according to the following
equations: 

$$
S = 4\pi r^2
$$

$$
V = \pi r^3
$$

You can either define your own constant for *π*, or use the `M_PI` constant defined
in the `cmath` library.

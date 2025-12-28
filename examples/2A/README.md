### Using functions

Write a small C++ program to prompt the user for the value of $x$, then compute and display on the terminal the result of the expression:

$$ r = \sqrt{ \frac{2\pi}{|x|} } \exp{\left( 2 \sin^2{(0.1 x)}\right) }$$

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/using_functions/main.cpp)*

<br>


### Function names

We need to write a function to compute the area of a triangle, given the  coordinates of its three vertices. What would be a good name for this function?

What do you think of the following candidate names:
- `area()`
- `A()`
- `calculation()`
- `do_calculation()`
- `get_area()`
- `compute_area_of_triangle()`

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/function_names.md)*

<br>


### A function to get a value from the user

Write a C++ function to prompt the user for a floating-point value between 5 and 100, read this value from the terminal, validate it, and return the value if within the bounds specified. If out of bounds, the user should be prompted again using a suitable value is entered. 

Add a `main()` function to test and demonstrate your function.

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/function_to_get_value_from_user/main.cpp)*

<br>


### A function to square its input

Write a small C++ function called `pow2()` to compute the square of its input, assumed to be of type `double`. 

Add a `main()` function to test and demonstrate your function.

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/function_to_square_input/main.cpp)*

<br>


### A function to check whether a number is prime

Write a small C++ function to check whether its single integer argument is a prime number.

Add a `main()` function to identify and print out the first 50 prime numbers.

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/function_to_check_for_prime/main.cpp)*

<br>


### A function to compute sinc

Write a small C++ function to compute the sinc function of width *a*, evaluated at *x*:

$$ \text{sinc}_a (x) = \begin{cases}
\frac{\sin(\pi x/a)}{\pi x/a} & \text{if  } x \neq 0 \\
1 & \text{otherwise} 
\end{cases}
$$

Add a `main()` function to test and demonstrate your function.

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/function_to_compute_sinc/main.cpp)*

<br>


### A function to report the heart rate

Write a small C++ function to report the final result of a heart rate computation to the terminal. Your function should report the measured heart rate, the threshold against which it is being compared (a user-supplied parameter, which should be passed to the function as an argument) and note whether the heart rate exceeds that threshold.

Add a `main()` function to test and demonstrate your function.

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/function_to_report_heart_rate/main.cpp)*

<br>


### Pass by reference

Create a C++ program to meet the following requirements:
- write a function to prompt and read in 3 floating-point values from the user, representing the lengths of the 3 sides of a triangle.
- write a function to compute the area of a triangle using [Heron's formula](https://en.wikipedia.org/wiki/Heron%27s_formula):

$$ 
A = \sqrt{ s (s-a)(s-b)(s-c) } \textrm{      where      } s = \frac{1}{2}(a+b+c) 
$$

- write a `main()` that makes use of both functions to request these 3 values from the user and print the area of the corresponding triangle

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/pass_by_reference/main.cpp)*

<br>



### Function overloading: computing log(1+x)

Write a function `log_one_plus_x()` to approximate the value of *ln*(1+*x*) using its Maclaurin series:

$$ \ln(1+x) = \sum_{n=1}^\infty \frac{(-1)^{n+1} x^n}{n} \approx x - \frac{x^2}{2} + \frac{x^3}{3} - \frac{x^4}{4} +  \cdots $$

Your function should compute the value up to the first 10 elements in the series. Add a `main()` function making use of your program to verify that it provides the expected value for small values of *x* (for example, *ln*(1+0.1) = 0.0953101798). 

Now add another function, overloading the first one by adding a second argument to specify the number of elements to include in the series, allowing the user to control the level of precision. Verify that your function works as expected using different numbers of elements. 

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/function_overloading/main.cpp)*

<br>


### Default arguments: computing log (1+x)

Modify the code you wrote earlier to compute *ln*(1+*x*), to define a single `log_one_plus_x()` function, and relying on a *default argument* to achieve the same outcome. You should be able to achieve this without modifying the code in your `main()` function. 

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/default_arguments/main.cpp)*

<br>


### Compute factorial using recursion

Write a C++ program with a recursive function to compute the factorial of a number *n*:

$$ n! = n \times (n-1) \times (n-2) \times \cdots \times 1 $$

Use this function within `main()` to prompt the user for a number and display its factorial on the terminal.

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/factorial_using_recursion/main.cpp)*

<br>


### Compute Fibonacci sequence using recursion

Write a recursive function to compute and display the Fibonacci sequence, which consists of a series of numbers where each number is the sum of the two preceeding ones, with the first two numbers set to 0 & 1:

$$ F(n) = \begin{cases} 
  F(n-1) + F(n-2) & \text{if } n > 1 \\
  n & \text{otherwise}
\end{cases}
$$

Use this function within `main()` to prompt the user for the number of elements to display, and print out the corresponding sequence on the terminal.

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/fibonacci_using_recursion/main.cpp)*

<br>


### Compute factorial without recursion

Modify the code you wrote to compute the factorial of the number *n* so that it works *without recursion*.

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/factorial_without_recursion/main.cpp)*

<br>


### Compute Fibonacci sequence without recursion

Modify the code you wrote to compute the Fibonacci sequence so that it works *without recursion*.

*[🔍 check your answer](../../../../blob/2A_answers/examples/2A/fibonacci_without_recursion/main.cpp)*


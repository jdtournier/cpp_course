### Reading from standard input

Modify your code to read an integer value from the terminal, and store it in a variable `x`. For example:

```cpp
int x;
std::cin >> x;
std::cout << "We read the integer value " << x << "\n";
```

Compile and run your code. What does it do?

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/reading_from_standard_input/main.cpp)*


### Reading from standard input with prompt

▶️ Modify your code to *prompt* the user to type in an integer, to avoid them wondering why your program appears to have stalled. You can do this by adding a statement like this one:

```cpp
std::cout << "Please enter an integer value: ";
```
before the call to `std::cin`. Compile and run your code. Does this help to avoid unnecessary confusion?

Note that in the above, the prompt string does not end with a newline: this is deliberate, and means the user's input will appear *after* the prompt, on the same line. Try adding a newline at the end of the prompt. Whether you prefer the user's typed input to appear at the end of the line or on its own on the next line is a matter of personal preference!

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/reading_from_standard_input_with_prompt/main.cpp)*


### Reading two floating-point values from standard input

▶️ Modify your code to read two floating-point values, `x` & `y`, from the terminal, then print out their values and the result of their multiplication.  Make sure to *prompt* the user so they know they're expected to enter 2 numbers. Use a single use of `std::cin` to read both values. When reporting the values back to the user, make it clear which variable is which, and what computation was performed to get the final result. 

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/reading_two_values_from_standard_input/main.cpp)*


### Conditional operator 1

▶️ Modify your program to prompt the user to enter a floating-point value, read it from `std::cin`, then report to the user whether the square of the value entered exceeds a threshold of 50

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/conditional_operator_1/main.cpp)*


### Conditional operator 2

▶️ Modify the program you wrote in the previous example to report an error to the user if the value they entered is less than or equal to zero, and if not perform the same check as above.

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/conditional_operator_2/main.cpp)*


### BMI calculator

▶️ BMI calculator: modify your code to prompt the user to enter two
floating-point values, corresponding to weight (in kg) and height (in m).
Read these values from `std::cin`. Check that they fall within a reasonable
range (20 → 300 for weight, 0.50 → 2.5 for height), and produce a warning if
the values fall outside that range. Compute the BMI as weight divided by
height squared, and report that value to the user.  Then report to the user
which category the computed BMI falls into:
- BMI < 18.5: *underweight*
- 18.5 ≤ BMI < 25: *healthy*
- 25 ≤ BMI < 30: *overweight*
- BMI ≥ 30: *obese*

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/bmi_calculator/main.cpp)*



### BMI calculator with check

▶️ Modify the BMI computation code you produced above so that the initial
check for the values performs the following actions:
- notify the user that their values are out of the expected range (ideally
  telling them exactly which one)
- return immediately from `main()` with a non-zero exit code (i.e. `return
  1;`)

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/bmi_calculator_with_check/main.cpp)*



### Weekday

▶️ Write a C++ program to prompt the user for an integer corresponding to the
day of the week, with 1 → Monday, 2 → Tuesday, etc, then print out the
*name* of the corresponding day of the week (i.e. 'monday', 'tuesday', etc.).

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/weekday/main.cpp)*


### Factors of 462

▶️ Write a C++ program to print out all factors of the number 462.

Remember that a *factor* is a number (greater than 1) that divides the number
exactly, without leaving a remainder.

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/factors_of_462/main.cpp)*



### Primes to 100

▶️ Write a C++ program to print out all prime numbers up to 100

Remember that a prime number is a number that cannot be factorised: it cannot
be divided by any other integer (greater than 1) without leaving a remainder.

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/primes_to_100/main.cpp)*



### Approximate π

▶️ Write a C++ program to approximate the value of π using the infinite
series:

$$ \frac{\pi ^2}{6} = \sum_{n=1}^\infty \frac{1}{n^2} = 1 + \frac{1}{4} + \frac{1}{9} + \frac{1}{16} - \ldots $$

Use a `while` loop, until the size of the next term to be added falls below a
tolerance value of $10^{-15}$.

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/approximate_pi/main.cpp)*


### Solve quadratic equation by iteration

▶️ Write a C++ program to find the approximate solution to the equation:

$$ x^2 - 7x + 1 = 0 $$

using the iteration:

$$ x_{n+1} = \sqrt{7x_n-1} $$

Use a `do`-`while` loop, until $|x_{n+1}-x_n| < 10^{-12}$. 
Verify your answer does indeed (approximately) solve the problem by
substituting the value you obtained back into the original quadratic.

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/solve_quadratic_by_iteration/main.cpp)*


### Primes to 100 with break

▶️ Modify the code you wrote to print out all prime numbers up to 100, using
the `break` statement to avoid needlessly checking all remaining factors if
the number is already known not to be a prime.

*[🔍 check your answer](../../../../blob/1B_answers/examples/1B/primes_to_100_with_break/main.cpp)*


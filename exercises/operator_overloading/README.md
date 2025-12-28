# Exercises: operator overloading

## Exercise 1

Earlier in this section we discussed operator overloading using a class for `Rational` numbers, as part of a class hierarchy of different types of number. This code already has the `*`, `++` (prefix), `<<` and `=` operators overloaded.

   Modify this starting code to perform the following tasks in the `Rational` class:
   - Modify the overloading of the multiplication operator so that it **simplifies** the fraction after multiplying. To simplify the fraction you need to divide the numerator and denominator by their greatest common factor.
   - Add overloadings of the addition, subtraction and division operators. Each of these functions should also simplify the resulting fractions.

Skeleton code for this exercise is provided here: [Exercise 1 files](1_Numbers_skeleton/)

<br>


## Exercise 2

Continuing with the `Rational` class, now modify your code to overload the `>>` operator so that rational numbers can be input from the keyboard using the `cin` command. Write a driver program that reads in two rational numbers from the keyboard, computes the sum, difference, product and division of the pairs of numbers and displays the (simplified) results to the screen.

<br>


## Exercise 3

Numbers are stored in digital computers using the **binary** (i.e. base 2) representation. Binary numbers are sequences of `1`s and `0`s that represent increasing powers of 2: the rightmost binary digit (or **bit**) represents 1, the next bit represents 2, the next 4, and so on. For example, the number 14 would be represented in binary as `1110` (i.e. 8×1 + 4×1 + 2×1 + 1×0).

   Write a C++ class to store information about binary numbers. The class should be able to store any 8-bit number, i.e. between 0-255 in decimal. Implement the following requirements in your class:
   - There should be a default constructor and also a constructor that takes a single decimal number as input, which is then converted to binary for internal storage.
   - The `<<` and `>>` operators should be overloaded. Binary numbers should be displayed and input as a sequence of eight `1`s or `0`s, e.g. `00001110`.

<br>


## Exercise 4

Continuing with the binary numbers class from Exercise 3, now add the following functionality:
   - Overload the `%` operator to perform the XOR operation, i.e. for each bit, the result should be `1` if either of the corresponding input bits was `1` (but not both), and `0` otherwise.
   - Overload the `&&` operator to perform the AND operation, i.e. for each bit, the result should be `1` if both of the corresponding input bits was `1`, and `0` otherwise.
   - Overload the `||` operator to perform the OR operation, i.e. for each bit, the result should be `1` if either of the corresponding input bits was `1` (including both), and `0` otherwise.
   - Overload the `!` operator to perform the NOT operation, i.e. for each bit, the result should be `1` if the corresponding input bit was `0`, and `0` if the corresponding input bit was `1`.
   - Overload the `+` operator to implement binary addition. If 'overflow' occurs (i.e. the result would be greater than 255) a warning message should be displayed and the 'truncated' result returned (i.e. the true result minus 256).

<br>


## Exercise 5

Binary numbers are, of course, a type of number. Therefore, it seems logical that your binary numbers class from Exercises 3 and 4 should be incorporated into the `Number` class hierarchy that you worked with in Exercises 1 and 2. Write C++ code to extend the `Number` class hierarchy to include your binary numbers class.

   Now modify the class hierarchy so that the `Display()` pure virtual function in the `Number` class is no longer included (and hence all implementations of this function in derived classes are also removed). Instead, make each class derived from `Number` overload the input and output operators in a similar way to the overloadings you have implemented in the `Rational` class in Exercises 1 and 2.

<br>


## Exercise 6

Now overload the following operators in the `Real` class:
   - The prefix increment operator `++`.
   - The addition operator `+`.
   - The subtraction operator `-`.
   - The multiplication operator `*`.
   - The division operator `/`.

<br>


## Exercise 7

Now overload the following operators in the `Complex` class:
   - The prefix increment operator `++`: This should add one to the real part of the complex number.
   - The addition operator `+`: This should perform complex addition.
   - The subtraction operator `-`: This should perform complex subtraction.
   - The multiplication operator `*`: This should perform complex multiplication.
   - The division operator `/`: This should perform complex division. Complex division can be performed by multiplying the numerator and the denominator by the **conjugate** of the denominator (the product of the denominator and its conjugate is real).

<br>


## Exercise 8

Overload the assignment operator `=` in the `Complex`, `Real` and `Binary` classes. (Note that, in these cases, the default implementations of the class assignment operators would have been sufficient as none of the classes have pointer data members.)

<br>


## Exercise 9

Overload the comparison operator `==` in the `Complex`, `Real`, `Rational` and `Binary` classes. For the `Real` class, the comparison should return `true` if the absolute difference between the two numbers is less than 0.0001.

<br>


## Exercise 10

Overload the `+=` operator for the `Complex`, `Real`, `Rational` and `Binary` classes. This operator should perform the same calculation as the `+` operator but it should be applied to an existing instance of the class rather than creating and returning a new instance.

<br>



### 1D C-style array

Write a C++ program that:
1. declares an array of 9 integers,
2. initialises it using a braced initializer list with numbers {1..9},
3. uses a `for` loop to print each element and its index,
4. uses a range-based `for` loop to compute and print the sum of all elements.

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/1d_array/main.cpp)*

<br>


### 2D C-style array

Write a C++ program that:
1. declares a 3×3 array of integers,
2. initializes it with values from 1 to 9,
3. uses nested `for` loops to print the matrix in a 3×3 layout,
4. computes the sum and the average of all elements using a range-based `for` loop,
5. prints the average and sum on the terminal.

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/2d_array/main.cpp)*

<br>


### Pointers

Write a C++ program that:
1. declares an integer variable `x` and assigns it a value.
2. declares a pointer `p` that stores the address of `x`.
3. prints the value of `x`, the address stored in `p`, and the value obtained by dereferencing `p`

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/pointers/main.cpp)*

<br>


### Passing a C-style array to a function

Write a C++ function that computes the average of a 5x4 matrix of type `double`. 

Write a `main()` function declaring a 5x4 C-style array, initialise each element so that its value is the product of its (i,j) indices (i.e. M(i,j) = i×j), and use your function to compute and print out the average of the matrix.

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/passing_array_to_function/main.cpp)*

<br>


### Vector example

Write a `main()` function that declares a `std::vector` of `int`, prompts the user to enter a series of integers on the   terminal (with the value zero to stop), reads in these values using `std::cin`, and *appends* them to your vector using the   `push_back()` method until the value 0 is encountered. Your program should then report the number of elements in the vector,  their sum, and their product.

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/vector/main.cpp)*

<br>


### Passing a vector to a function

Write a function that returns the mean value of a `std::vector<int>`, and a `main()` function that declares a vector of   four integers initialised to {1, 2, 3, 4}, computes the mean, and prints the result.

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/passing_vector_to_function/main.cpp)*

<br>


### std::array

Write a function that computes and returns the [root mean square value](https://en.wikipedia.org/wiki/Root_mean_square)   of a `std::array<int,5>`. In `main()`, declare a `std::array<int,5>` initialised to {1, 2, 3, 4, 5}, call the function, and   print the result.

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/array/main.cpp)*

<br>



### Looping over std::vector

Write the following functions:
- A function that prompts the user to enter the size of the vector and each element, then stores the values in a vector,    and returns it.
- A function that takes a vector of integers as input and returns the product of its elements.
- A function that takes a vector of integers as input and returns the index of the minimum element in the vector.

Write a `main()` function that creates the vector using the input function, calls the other two functions above, and prints the product of the elements and the index of the minimum value.

**Use the appropriate form of the `for` loop depending on the task.**

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/looping_over_vector/main.cpp)*


### String initialization

Write a program that declare a string called `name`. Initialise it to your own name, then use it to print out the         greeting `Hello NAME!` (substituting NAME with your own name).

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/string_init/main.cpp)*

<br>


### String length

Write a program that declare a string called `name`. Set its value by reading from the terminal (with a suitable prompt!  ), then use a single `std::cout` line to print out a message of the form:
```
The word "INPUT" contains 5 characters.
```
where `INPUT` was the string entered by the user.

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/string_length/main.cpp)*

<br>


### String example

Write a program to prompt the user for a filename, then read the filename from standard input into a `std::string`. Check whether the file ends with a `.txt` extension, and print out the filename with the `.txt` suffix removed (i.e. without the    last 4 characters).

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/string_length/main.cpp)*

<br>


### String formatting

Write a program to declare the following variables:
```cpp
std::string name = "joe";
int age = 26;
float weight = 68.3;
double result = 0.02342;
```
Then print the information formatted so that it looks like this:
```cpp
Patient "joe" (age 26, weight 68.3kg): result = 0.02342
```
Do this using:
- `std::cout` directly
- by forming a `std::string`, using the concatenation operator and `std::to_string()`
- by forming a `std::string`, using the `std::format()` function

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/string_formatting/main.cpp)*

<br>


### Non-modifying STL algorithms

Write a C++ program that declares an empty `std::vector<int>` and repeatedly prompts the user to enter integer values     from the terminal. Input should continue until the user enters the character `q`, at which point input terminates.

Once the input phase is complete, the program should count how many times the value 4 appears in the vector and print the   result. Use an appropriate STL algorithm to perform this operation.

Next, the program should search for the first occurrence of the value 7 in the vector. If the value is found, print both    the value and its index within the vector; if it is not found, print an appropriate message indicating that the value does    not occur in the vector.

You should organise your program using functions where appropriate, pass vectors safely to functions, and use iterators to  traverse the container.

*[🔍 check your answer](../../../../blob/2B_answers/examples/2B/non-modifying_algorithms/main.cpp)*

<br>


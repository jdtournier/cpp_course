# Exercises

Perform the following tasks in C++:

## Exercise 1

Write a templated function called `swapvals` to swap the values of two variables.
   The function should take two arguments, and return no value. The arguments should be *pass-by-reference*, allowing the templated function to swap their values. For example, if the function received the `float` arguments `x=1.34` and `y=6.01`, the values of `x` and `y` after executing the function should be `x=6.01` and `y=1.34`.

   Write a simple driver program to test your function.

## Exercise 2

In Example (insertion_sort) we introduced an implementation of the insertion sort algorithm that used a templated function.** You will be provided with the code for this example through the KEATS system. Modify this starting code to add an extra templated function called `print_list` to display an array to the screen. Modify the `main` function to use your new function to display the unsorted and sorted arrays.

Skeleton code for this exercise is provided here: [Exercise 2 files](2_InsertionSort_skeleton/)

## Exercise 3

Continuing with the same code example as Exercise 2, now modify the code to add a templated function to search for a specific value in the array. If the value is found, the function should return the position in the array where it was found. If it is not found, it should return -1.

## Exercise 4

In previous exercises you wrote a C++ class called `Sample` to store information about, and process, statistical sample data. The class worked for `float` data only. You will be provided with a model solution for these exercises through the KEATS system. Modify this starting code to make the `Sample` class into a templated class. Expand the driver program to test the class using both `float` and `int` samples.

For what types will it be possible to create instances of the templated `Sample` class?

Skeleton code for this exercise is provided here: [Exercise 4 files](4_Sample_skeleton)

## Exercise 5

Continuing with your `Sample` class, now expand the code so that the class can handle non-symmetric data samples. You may recall from your Computational Statistics module that the mean and standard deviation are appropriate measures of central tendency and dispersion only if the sample is symmetrically distributed with no outliers. If this is not the case then the *median* and *inter-quartile range* should be used instead.

   These measures are defined as follows:
   - The **median** is the data value which has 50% of the values above it, and 50% of values below, i.e. the ½(n+1)th value (where n is the sample size)
   - The **upper quartile** is the data value which has 25% of values above it, and 75% of values below, i.e. the ¾(n+1)th value
   - The **lower quartile** is the data value which has 75% of values above it, and 25% of values below, i.e. the ¼(n+1)th value

   The inter-quartile range (IQR) is then calculated as:
   ```
   IQR = upper quartile - lower quartile
   ```

   In the above definitions, if the fraction (e.g. ¾(n+1)) is not an integer you should take the mean of the two adjacent values. For example, if n is 12, then ¾(n+1) = 9.75 so you should compute the mean of the 9th and 10th values.

   You can check your program's answers at [www.miniwebtool.com/median-calculator/](http://www.miniwebtool.com/median-calculator/) and [www.miniwebtool.com/interquartile-range-calculator/](http://www.miniwebtool.com/interquartile-range-calculator/).

## Exercise 6

One definition of the *skewness* of a data sample is:
   ```
   skewness = 3(x̄ - median) / s
   ```
   where x̄ is the sample mean and s the sample standard deviation. You should, by now, have member functions for computing the mean, standard deviation and median in your `Sample` class. Now add a further member function to compute the skewness using the equation given above.

## Exercise 7

In inferential statistics, the *standard error of the mean* is a measure of the reliability of estimates of the mean values of data samples. It can be computed as:
   ```
   se = s / √n
   ```
   where s is the sample standard deviation and n is the sample size.

   From this, it is possible to compute 95% *confidence intervals* of the mean, as follows:
   ```
   Lower 95% confidence interval = x̄ - 1.96 × se
   Upper 95% confidence interval = x̄ + 1.96 × se
   ```
   (Assuming the sample size is large, and therefore the distribution of mean values is normal.)

   Modify your `Sample` class to include member functions to compute the standard error of the mean, and the lower and upper 95% confidence intervals.

## Exercise 8

Write a templated C++ class to implement a `Stack` data structure. A stack is a sequence of data values in which two main operations are defined:
   - *Push*: a new data item is added to the 'top' of the stack
   - *Pop*: the 'top' data item from the stack is removed and returned as the result of the function

   Stacks implement what is known as a *LIFO* system of data storage/access (*LIFO = Last In First Out*).

   There should be two template parameters: a type parameter indicating the type of the data elements and a value parameter indicating the maximum size of the stack. Your class should implement the `Push` and `Pop` operations described above. For the moment, you do not need to worry about any bounds checking. That is, you don't need to check if the maximum stack size is reached when pushing and you don't need to check if the stack is empty before popping.

   Write a simple driver program to test your class for `char` and `int` data elements.

## Exercise 9

Continuing with the `Stack` class, now add bounds checking to the `Push` and `Pop` operations. Specifically, if a `Push` operation is attempted on a full stack, a warning message should be displayed and no push operation performed. If a `Pop` operation is attempted on an empty stack then a warning message should be displayed and the first element of the stack should be returned. (Since the first element may not have had a value assigned to it the warning message should state that the return value is undefined.)

   Update the driver program to test this new functionality.

## Exercise 10

Two further operations that are commonly defined for `Stack` data structures are:
    - *Clear*: remove all elements from the stack
    - *IsEmpty*: return a Boolean value indicating whether or not the stack is empty

Modify your `Stack` class to provide implementations of these two operations.

### Split the `compute_mean()` function

Our code currently also contains a function `compute_mean()`, which we have left in the main `compute_mean.cpp` file. As our code grows, we will probably find that we have many such functions (maybe to compute the standard deviation, or the median, etc). It would be a good idea to group these functions into their own header file & matching `cpp` file to allow them to be re-used in other parts of the project. 

Split off the `compute_mean()` function into another header file called `stats.h`, with a matching `stats.cpp` file, as shown above. Then compile each `cpp` file separately and link the resulting objects together to produce your final executable. Run it and verify it works as expected.

To get started, you'll find the [original code here](../../../../tree/main/examples/3B/process_patient_data).

*[🔍 check your answer](../../../../tree/3B_split_compute_mean_function/examples/3B/process_patient_data) (or check the [diff](../../../../commit/3B_split_compute_mean_function))*

<br>


### Split a single file  

We have a program that loads arrays of values from two separate text files, adds the values element-by-element to produce a new array of values, and stores the values produced in another text file. The program is currently written as a single file. Your task is to split it over multiple files in a suitable structure, as shown above.

**[Click here to access the initial project files](../../../../tree/main/examples/3B/split_single_file)**

*[🔍 check your answer](../../../../tree/3B_split_program/examples/3B/split_single_file) (or check the [diff](../../../../commit/3B_split_program))*

<br>


### Fix error: list prime numbers

We have been given a project to list prime numbers up to 100. The program doesn't work. Find out what is wrong, and apply any fixes required to make it work correctly.

**[Click here to access the initial project files](../../../../tree/main/examples/3B/fix_compile_error1)**

*[🔍 check your answer](../../../../tree/3B_primes/examples/3B/fix_compile_error1) (or check the [diff](../../../../commit/3B_primes))*

<br>


### Fix error: Babylonian square root

We have a program to compute the square root of a number using the Babylonian method. The program doesn't work. Find out what is wrong, and apply any fixes required to make it work correctly.

**[Click here to access the initial project files](../../../../tree/main/examples/3B/fix_compile_error2)**

*[🔍 check your answer](../../../../tree/3B_babylonian_sqrt/examples/3B/fix_compile_error2) (or check the [diff](../../../../commit/3B_babylonian_sqrt))*

<br>


### Fix error: compute log (1+x)

We have a program to compute $log(1+x)$ using its Maclaurin series. The program doesn't work. Find out what is wrong, and apply any fixes required to make it work correctly.

**[Click here to access the initial project files](../../../../tree/main/examples/3B/fix_compile_error3)**

*[🔍 check your answer](../../../../tree/3B_log_one_plus_x/examples/3B/fix_compile_error3) (or check the [diff](../../../../commit/3B_log_one_plus_x))*

<br>


### Fix error: evaluate Normal distribution

We have a program to evaluate the Normal distribution. The program doesn't work. Find out what is wrong, and apply any fixes required to make it work correctly.

**[Click here to access the initial project files](../../../../tree/3B_normal_with_error/fix_compile_error4)**

*[🔍 check your answer](../../../../tree/3B_normal_distribution/examples/3B/fix_compile_error4) (or check the [diff](../../../../commit/3B_normal_distribution))*

<br>


### Fix error: compute mean of command-line arguments

We have a program to compute the mean of its command-line arguments. The program doesn't work. Find out what is wrong, and apply any fixes required to make it work correctly.

**[Click here to access the initial project files](../../../../tree/main/examples/3B/fix_link_error1)**

*[🔍 check your answer](../../../../tree/3B_compute_argument_mean/examples/3B/fix_link_error1) (or check the [diff](../../../../commit/3B_compute_argument_mean))*

<br>


### Fix error: print arguments backwards

We have a program to print each of its arguments backwards in upper case. The program doesn't work. Find out what is wrong, and apply any fixes required to make it work correctly.

**[Click here to access the initial project files](../../../../tree/main/examples/3B/fix_link_error2)**

*[🔍 check your answer](../../../../tree/3B_reverse_args/examples/3B/fix_link_error2) (or check the [diff](../../../../commit/3B_reverse_args))*

<br>


### Using `pow2()` as a helper function

Starting from the current version of your `compute_mean()` program, write a function called `pow2()` to compute the square of a `float`. Place the declaration inside your `stats.h` file, and the definition inside your `stats.cpp` file.

Now write a function called `compute_stddev()` to compute the standard devation given an input `std::vector<float>`. Your function should make use of your existing `compute_mean()` function and your new `pow2()` function, and also be declared in the `stats.h` header file, and defined in the `stats.cpp` file. 

Modify your `main()` function to display both the mean and standard deviation for each patient in the input file.

*[🔍 check your answer](../../../../tree/3B_compute_std_dev/examples/3B/process_patient_data) (or check the [diff](../../../../commit/3B_compute_std_dev))*

<br>


### Declaring an inline function

Modify your previous code by moving the definition of your `pow2()` function within in the `stats.h` header file, and removing it from the `stats.cpp` file. Try to compile your project. What happens? 

Now add the `inline` keyword directly in front of the function signature for your `pow2()` function, as the first word on the same line. Can you compile your project now?

*[🔍 check your answer](../tree/3B_declare_pow2_inline/../../../process_patient_data) (or check the [diff](../../../../commit/3B_declare_pow2_inline))*

<br>


### Debugging cubic root program

**[Click here to access the initial project files](../../../../tree/main/examples/3B/find_roots)**

<br>

Create a new project folder for this code, copy the code above into it, compile it, and run it. Does it work as expected?

<br>

Add printing statements such as the one above to your code. Compile your program and test it. Does this help to figure out the problem?

<br>

Modify your code to halt the loop after 10 iterations. Can you see what the problem is? 

Modify your code to print out the values of $f(x)$ and $f'(x)$ in addition to $x$ and $\delta x$.

Now can you see what the problem is?

<br>

Having identified the issue, modify your code to detect when this issue is going to happen, in which case it should stop execution and provide a helpful error message to the user with some suggestion as to what to do.

*[🔍 check your answer](../../../../blob/3B_cubic_roots_check_zero_gradient/find_roots/main.cpp) (or check the [diff](../../../../commit/3B_cubic_roots_check_zero_gradient))*

<br>

Modify your code to allow the user to specify the initial guess as the first command-line argument. If unspecified, the initial guess should be left at zero. 

*[🔍 check your answer](../../../../blob/3B_cubic_roots_initial_guess_as_first_argument/find_roots/main.cpp) (or check the [diff](../../../../commit/3B_cubic_roots_initial_guess_as_first_argument))*

<br>

Use the `VAR()` macro as [suggested in the worksheet](../../../../wiki/(3B)-Multi-file-projects#defining-convenience-macro-functions), by copying its definition (the `#define` line above) near the top of your program (after the `#include` line, for example). Does this help to figure out what the problem is?

<br>

Modify the program to terminate when there is no difference between `x` and its previous value. Verify that this does resolve the issue.

*[🔍 check your answer](../../../../blob/3B_cubic_roots_update_convergence_check/find_roots/main.cpp) (or check the [diff](../../../../commit/3B_cubic_roots_update_convergence_check))*

<br>


### Adding a command-line option to activate verbose mode

Coming back to the previous `compute_mean` project, modify your code by [adding the `set_verbose_mode()` function to your project](../../../../wiki/(3B)-Multi-file-projects#checking-for-command-line-options), and make use of it within your `main()` function to check for the presence of the `-v` option. For now, the simplest approach is to place the function within the `compute_mean.cpp` file, along with the `verbose_mode` global variable definition. Later, we will move it to a more suitable location.

Verify that your project compiles and runs, and check that the program correctly identifies when it has been provided with the `-v` option. 

Spend some time to make sure you understand how this all works!

*[🔍 check your answer](../../../../tree/3B_check_for_cmdline_option/process_patient_data) (or check the [diff](../../../../commit/3B_check_for_cmdline_option))*

<br>

Create a new header file called `debug.h`, and move the definition of the `verbose_mode` variable and the declaration of the `set_verbose_mode()` function into it. Create a new matching `cpp` file called `debug.cpp` and place the *definition* of the `set_verbose_mode()` function into it. Include the `debug.h` header file in `compute_mean.cpp`. 

<br>

Modify your code to include the `debug.h` header file in your `load_data.cpp` file, and to print out information about the file you're about to load when in verbose mode. Also print out information about the file you have just loaded before returning from your data loading function. 

*[🔍 check your answer](../../../../tree/3B_add_verbose_mode/process_patient_data) (or check the [diff](../../../../commit/3B_add_verbose_mode))*

<br>

Add a function called `log()` to your `debug.h` header file taking a single argument of type `std::string`, which will print the text provided to `std::cerr` with a leading `[DEBUG]` prefix, but *only* if verbose mode is enabled. 
 
In this case, it makes sense to declare this function `inline`, since most of the time our program will not be running in debug mode, and the function should essentially do nothing. If the compiler can inline our function, the only runtime performance overhead will be a simple `if` statement, rather than a full-blown function call.

*[🔍 check your answer](../../../../tree/3B_add_logging_function/process_patient_data) (or check the [diff](../../../../commit/3B_add_logging_function))*

<br>


### Adding plotting capabilities to `compute_mean()`

Modify the `compute_mean()` code we have been working on so far to plot the data for the first patient in the file.

*[🔍 check your answer](../../../../tree/3B_plot_patient_data/process_patient_data) (or check the [diff](../../../../commit/3B_plot_patient_data))*

<br>

Modify the plotting call to also plot the data for all the other patients in the file.

*[🔍 check your answer](../../../../tree/3B_plot_all_patient_data/process_patient_data) (or check the [diff](../../../../commit/3B_plot_all_patient_data))*

<br>


### Add a `debug` namespace

Modify the `debug.h` header file for your current version of the `compute_mean()` project to declare all debugging and logging functionality within the `debug` namespace, [as suggested in the worksheet](../../../../wiki/(3B)-Multi-file-projects#declaring-namespaces). Now make any further changes to your code necessary for your program to compile and run correctly.

*[🔍 check your answer](../../../../tree/3B_add_debug_namespace/process_patient_data) (or check the [diff](../../../../commit/3B_add_debug_namespace))* 

<br>



### Using the `enum` type

Write a program to declare two `enum` using the legacy `enum` declaration: 
- The first one should represent `MaritalStatus`, with possible values `Single`, `Married`, `Divorced`, and `Widowed`. 
- The second one should represent `ProbeType`, with possible values `Twin`, `Complex`, and `Array`. 

Write code to create one instance of each of these, and to compare them in an `if` statement. What does the compiler say? Does the program run? Does the result of the comparison make sense? 

Amend your `ProbeType` to also list the type `Single`. Is this is a problem for your program? 

*[🔍 check your answer](../../../../blob/4A_enum_example/examples/4A/enum_example/enum.cpp)*

<br>


### Using the `enum class` type

Amend the code you wrote in the previous example to use `enum class` instead. Does this help to allow the code to compile? Does it help to avoid nonsense comparisons?  

*[🔍 check your answer](../../../../blob/4A_enum_class_example/examples/4A/enum_example/enum.cpp) (or check the [diff](../../../../commit/4A_enum_class_example))*

<br>

### Weekday (using type aliases)

A few sessions ago, we wrote a small program to output the days of the week, given a number from 1 to 7. Modify this example to use an enumeration type for the `Weekday`. Add a function to return the `Weekday` given an `int`, and another function to return a human-readable string given a `Weekday`. 

To get started, you'll find the [original code here](../../../../blob/main/examples/4A/weekday/weekday.cpp). 

*[🔍 check your answer](../../../../blob/4A_weekday_with_enum/examples/4A/weekday/weekday.cpp) (or check the [diff](../../../../commit/4A_weekday_with_enum))*

<br>



### Using type aliases

Amend your `compute_mean` project to make use of type aliases to declare the type used to hold the data values read from file, and the type used to represent the full set of patient data.

Try changing the type used to represent the data value to `double` instead of `float`. Check that your code still work as expected. 

*[🔍 check your answer](../../../../tree/4A_compute_mean_with_type_aliases/examples/4A/process_patient_data) (or check the [diff](../../../../commit/4A_compute_mean_with_type_aliases))*

<br>


### Area of triangle (using `struct`)

In a previous exercise, we wrote a function to request the length of the three sides of a triangle, with three separate values to be returned. Modify this function to return all three values together as a single `struct` type.

**[Click here to access the initial project files](../../../../blob/main/examples/4A/area_of_triangle/area_triangle.cpp)**

*[🔍 check your answer](../../../../blob/4A_area_of_triangle_with_struct/examples/4A/area_of_triangle/area_triangle.cpp) (or check the [diff](../../../../commit/4A_area_of_triangle_with_struct))*

<br>


### Compute the square root (using `struct`)

In a previous exercise, we wrote a function to compute the square root, with two separate values to be returned: the result of the calculation, and the number of iterations required to converge to this result. Modify this function to return both values together as a single `struct` type.

**[Click here to access the initial project files](../../../../blob/main/examples/4A/babylonian_sqrt/babylonian_sqrt.cpp)**

*[🔍 check your answer](../../../../blob/4A_babylonian_sqrt_with_struct/examples/4A/babylonian_sqrt/babylonian_sqrt.cpp) (or check the [diff](../../../../commit/4A_babylonian_sqrt_with_struct))*

<br>


### Compute mean (using `struct`)

Our `compute_mean` code to process patient data currently ignores the patient ID, which is listed as the first entry on each line in the input file. Modify your code by declaring a new `struct` to allow this information to be stored in the program and used to display the patient ID corresponding to each computed mean and standard deviation. 

*[🔍 check your answer](../../../../tree/4A_compute_mean_with_struct/examples/4A/process_patient_data) (or check the [diff](../../../../commit/4A_compute_mean_with_struct))*

<br>


### Student class (with getters)

Write code for the `Student` class, as [outlined in the worksheet](../../../../wiki/(4A)-User-defined-data-types:-struct,-enum,-type-aliases#how-to-use-classes). Add methods to access all member variables, using the approach shown. Use these methods to print all the information about the student to the terminal. 

*[🔍 check your answer](../../../../blob/4A_student_with_getters/examples/4A/student_class/student_records.cpp) (or check the [diff](../../../../commit/4A_student_with_getters))*

<br>


### Student class (with setters)

Modify your `Student` code to add *setter* methods to set all member variables, using the approach shown above. Use these methods to initialise all members of the class to sensible values, and print all the information about the student to the terminal. 

*[🔍 check your answer](../../../../blob/4A_student_with_setters/examples/4A/student_class/student_records.cpp) (or check the [diff](../../../../commit/4A_student_with_setters))*

<br>



### Student class (with `init()` method)

It might not make sense to allow basic properties of your class to be modified once they've been set. For example, the student ID should not modified after the student has been entered on the system, unless in exceptional circumstances (for example, an error was made when first registering the student). Other properties are expected to change more regularly (the grade point average, for example). 

Modify your code to remove the setter methods you added in the previous exercise, leaving only the `set_GPA()` setter. Instead, add a `init()` method to initialise your class, allowing the name, DOB and ID of the student to be set at the same time, with the option to also set the GPA (which should default to zero). 

Use this method to initialise all members of the class to sensible values, and print all the information about the student to the terminal. 

*[🔍 check your answer](../../../../blob/4A_student_with_init/examples/4A/student_class/student_records.cpp) (or check the [diff](../../../../commit/4A_student_with_init))*

<br>


### Student class (split over multiple files)

Modify your code [as suggested in the worksheet](../../../../wiki/(4A)-User-defined-data-types:-struct,-enum,-type-aliases#defining-methods-outside-the-class-declaration), placing the declaration of the `Student` class within its own `student.h` header, and the definition of the `Student::add_module_mark()` within the corresponding `student.cpp` file. 

Write the implementation for the `Student::add_module_mark()` to add the module marks to the list, and compute the updated GPA. 

*[🔍 check your answer](../../../../tree/4A_student_add_module_mark/examples/4A/student_class) (or check the [diff](../../../../commit/4A_student_add_module_mark))*

<br>


### Compute mean (using a class)

Go back to our `compute_mean` project, and modify your code to replace the `struct` we introduced earlier with a `class`, including methods to initialise its contents, and to return the mean and standard deviation of the data. Make use of these methods within the `load_data()` and `main()` functions.

*[🔍 check your answer](../../../../tree/4A_compute_mean_with_class/examples/4A/process_patient_data) (or check the [diff](../../../../commit/4A_compute_mean_with_class))*

<br>

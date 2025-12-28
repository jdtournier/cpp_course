### Compute mean from data in file

Modify the code below to compute and display the mean value of the data in the file:

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main()
{
  std::string filename = "data.txt";

  std::ifstream infile (filename);
  if (!infile) {
    std::cerr << "ERROR: failed to open file \"" << filename << "\" for reading - aborting\n";
    return 1;    // <- we return from main() with a non-zero exit code
  }

  std::cout << "File \"" << filename << "\" opened successfully\n";

  int n;
  while (infile >> n)
    std::cout << n << "\n";

  infile.close(); // <- unnecessary: infile is about to be destroyed when main returns

  return 0;
}
```

*[🔍 check your answer](../../../../blob/3A_answers/examples/3A/compute_mean_from_data_in_file/main.cpp)*

<br>



### Load data from file

Modify the code above to load the data into a vector, and report the size of the vector on the terminal.

*[🔍 check your answer](../../../../blob/3A_answers/examples/3A/load_data_from_file/main.cpp)*

<br>



### Load data from file using a function

Write a C++ function to load the data from the file, whose filename will be provided as an argument, and return the loaded data as a suitable data structure.

Modify your `main()` to make use of this function, and test it by loading a data file and reporting the number of entries in the file.

*[🔍 check your answer](../../../../blob/3A_answers/examples/3A/load_data_from_file_using_a_function/main.cpp)*

<br>



### Write modified data to file

Modify your code by adding in the data loading function you wrote in the exercise before the last one. Use it to load the data from the `data.txt` file, and then write back to the output file the pair-wise difference between the consecutive values in the input file (i.e. the output should consist of the $x_{n+1}-x{n}$ for $n = 1 \rightarrow N-1$).

*[🔍 check your answer](../../../../blob/3A_answers/examples/3A/write_modified_data_to_file/main.cpp)*

<br>


### Write modified data to file using a function

Write a C++ function to write a vector of data to file, whose filename will be provided as an argument.

Modify your `main()` to make use of this function, and test it by loading a data file (using your data loading function), computing the pairwise difference between the input values, then writing these values to file using your data writing function. 

*[🔍 check your answer](../../../../blob/3A_answers/examples/3A/write_data_to_file_using_a_function/main.cpp)*

<br>


### Read data line by line

Modify your code using the code snippet above, and extend it to count the number of measurements for each patient (the number of integers on the same line *after* the patient ID). Compile it and verify that it works as expected.

*[🔍 check your answer](../../../../blob/3A_answers/examples/3A/read_data_line_by_line/main.cpp)*

<br>


### Read data line by line using a function

Modify your code by moving all the code to read from the file into a dedicated function, which takes the name of the file to load as an argument, and returns the data in a suitable data structure. Your code can discard the patient IDs (we will see how to handle them in later sessions).

Now modify your `main()` function to make use of this function to compute and display the mean value of the measurements for each patient.

*[🔍 check your answer](../../../../blob/3A_answers/examples/3A/read_data_line_by_line_using_a_function/main.cpp)*

<br>


### Using command-line arguments to read a file

Modify your earlier program to read the patient data file, so that you can provide the filename via the commmand-line. Compile it and test it by providing it with the name of the patient data file as a command-line argument.

What happens if you run your program *without* an argument? For your program to be *robust*, it should be able to gracefully handle this case, which means it needs to check that it has *at least* the number of arguments required (you may also wish to ensure it has *exactly* the number of arguments expected, this depends on exactly what the program is intended to do). Modify your code to check this before trying to open the file. 

*[🔍 check your answer](../../../../blob/3A_answers/examples/3A/using_command_line_arguments_to_read_file/main.cpp)*

<br>


### Throwing exceptions

Modify the code you wrote earlier to load a simple file to throw an exception as shown above. Compile it and test it by providing an non-existent file. What happens? 

*[🔍 check your answer](../../../../blob/3A_answers/examples/3A/throwing_exceptions/main.cpp)*



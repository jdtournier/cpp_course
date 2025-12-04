#pragma once

#include <string>
#include <vector>

// Load an array of floating-point values from the text file 'filename'
// and return the data as a std::vector<float>.
// On error, this function may throw a std::runtime_error.
std::vector<float> load_array (const std::string& filename);

// Save the array of floating-point values provided in the argument 'data' (as
// a std::vector<float>) to the text file 'filename'
// On error, this function may throw a std::runtime_error.
void save_array (const std::string& filename, const std::vector<float>& data);

// Add two std::vector<float> arrays element-by-element, and return the result
// as a std::vector<float>.
// If the sizes don't match, this function will throw a std::runtime_error.
std::vector<float> add_arrays (const std::vector<float>& v1, const std::vector<float>& v2);


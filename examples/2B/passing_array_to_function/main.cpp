#include <iostream>


double compute_average (const double matrix[][4], int rows)
{
  double sum = 0.0;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < 4; ++j) {
      sum += matrix[i][j];
    }
  }

  return sum/(rows*4);
}


int main()
{
  double data[5][4];

  // initialise matrix contents:
  for (int i = 0; i < 5; i++)
    for (int j = 0; j < 4; j++)
      data[i][j] = i*j;

  // compute and print out average:
  std::cout << "Average of data matrix is " << compute_average (data, 5) << "\n";

  return 0;
}

#include <iostream>

int main()
{
  const int rows=3;
  const int columns=3;

  int matrix[rows][columns] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++)
      std::cout << matrix[i][j] << " ";
    std::cout << "\n";
  }

  int sum = 0;
  for (auto& row : matrix)
    for (int element : row)
      sum += element;
  float average = sum / (rows*columns);

  std::cout << "Sum = " << sum << ", average = " << average << "\n";

  return 0;
}

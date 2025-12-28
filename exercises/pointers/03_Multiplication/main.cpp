#include <iostream>
#include <format>

int main()
{
    // declare a 10x10 array
    const int num_rows = 10;
    const int num_cols = 10;
    int table[num_rows][num_cols];

    // calculate multiplication table
    for (int row = 0; row < num_rows; row++)
        for (int col = 0; col < num_cols; col++)
            table[row][col] = (row+1) * (col+1);

    // print table
    std::cout << "   | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|\n";
    std::cout << "---+---+---+---+---+---+---+---+---+---+---+\n";
    for (int row = 0; row < num_rows; row++) {
        std::cout << std::format ("{:2}:|", row+1);
        for (int col = 0; col < num_cols; col++)
            std::cout << std::format ("{:3}|", table[row][col]);
        std::cout << "\n---+---+---+---+---+---+---+---+---+---+---+\n";
    }

    return 0;
}

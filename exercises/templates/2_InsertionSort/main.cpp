#include <iostream>
#include "insertion_sort.h"

int main()
{
    // sort an integer array
	int x[5] = {2, 1, 5, 3, 7};
	std::cout << "Integer list before sorting\n";
	print_list(x, 5);
	sort (x, 5);
	std::cout << "Integer list after sorting\n";
	print_list(x, 5);

    //sort a char array
	char y[6] = {'c', 'e', 'a', 'd', 'b', 'f'};
	std::cout << "Char list before sorting\n";
	print_list(y, 6);
	sort (y, 6);
	std::cout << "Integer list after sorting\n";
	print_list(y, 6);

    return 0;
}

#include <iostream>
#include "insertion_sort.h"

int main()
{
	int i;

    // sort an integer array
	int x[5] = {2, 1, 5, 3, 7};
	std::cout << "Integer list before sorting\n";
	for (i = 0; i < 5; i++)
		std::cout << x[i] << " ";
	std::cout << std::endl;
	sort (x, 5);
	std::cout << "Integer list after sorting\n";
	for (i = 0; i < 5; i++)
		std::cout << x[i] << " ";
	std::cout << std::endl;

    //sort a char array
	char y[6] = {'c', 'e', 'a', 'd', 'b', 'f'};
	std::cout << "Char list before sorting\n";
	for (i = 0; i < 6; i++)
		std::cout << y[i] << " ";
	std::cout << std::endl;
	sort (y, 6);
	std::cout << "Integer list after sorting\n";
	for (i = 0; i < 6; i++)
		std::cout << y[i] << " ";
	std::cout << std::endl;

    return 0;
}

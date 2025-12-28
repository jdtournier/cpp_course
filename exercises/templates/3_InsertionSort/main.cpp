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

	// searching
    int sub = find (x, 5, 3);
    std::cout << "Does it contain the value 3?\n";
    if (sub >= 0)
        std::cout << "Yes, it is at " << sub << std::endl << std::endl;
    else
        std::cout << "No\n\n";

    //sort a char array
	char y[6] = {'c', 'e', 'a', 'd', 'b', 'f'};
	std::cout << "Char list before sorting\n";
	print_list(y, 6);
	sort (y, 6);
	std::cout << "Integer list after sorting\n";
	print_list(y, 6);

	// searching
    sub = find (y, 6, 'q');
    std::cout << "Does it contain the value 'q'?\n";
    if (sub >= 0)
        std::cout << "Yes, it is at " << sub << std::endl;
    else
        std::cout << "No\n";

    return 0;
}

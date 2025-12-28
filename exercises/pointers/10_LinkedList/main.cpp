#include <iostream>

#include "linked_list.h"

int main()
{
    // variable declarations
    List x = nullptr, n;

    // add 4 nodes to the list and print it out
    n = new Node;
    n->val = 12;
    add_node (x, n);

    n = new Node;
    n->val = 3;
    add_node (x, n);

    n = new Node;
    n->val = 34;
    add_node (x, n);

    n = new Node;
    n->val = 27;
    add_node (x, n);

    print_list (x);

    // delete 2nd node from list and print again
    List t = x->next;
    delete_node (x, t);
    print_list (x);

    // test new find_value() function
    std::cout << "27 is at position " << find_value (x, 27) << "\n";

    return 0;
}

#include <iostream>

#include "linked_list.h"

void add_node (List& m, List n)
{
    List t;
    // is current list empty?
    if (!m) { // yes , so just assign the new node
        m = n;
        m->next = nullptr;
    }
    else { // no , so go to the end of the list
        t = m;
        while (t->next)
            t = t->next;
        t->next = n;
        n->next = nullptr;
    }
}

void delete_node (List& m, List n)
{
    if (m == n) { // delete first node
        List t = m;
        m = m->next;
        delete t;
    }
    else { // delete a later node
        List t = m;
        while (t->next != n)
            t = t->next;
        List u = t->next;
        t->next = u->next;
        delete u;
    }
}

void print_list (List m)
{
    List t = m;
    std::cout << "List: [ ";
    // loop through all nodes:
    while (t) {
        std::cout << t->val << " ";
        t = t->next;
    }
    std::cout << "]\n";
}


int find_value (List m, int value)
{
    List t = m;
    int count = 0;
    while (t) {
        if (t->val == value)
            return count;
        t = t->next;
        count++;
    }
    return -1;
}

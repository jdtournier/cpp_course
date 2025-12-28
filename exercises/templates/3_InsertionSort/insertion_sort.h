#pragma once

#include <iostream>

template<class t>
void sort (t a[], int n)
{
    //look at every element apart from the first one
    for (int i = 1; i < n; i++) {
        //do we need to change this element's position?
        if (a[i] < a[i-1]) {
            //yes, so see where we should move it to
            t value_i = a[i];
            int j = i;
            //keep moving it back in the list until we have found the right position
            do {
                a[j] = a[j-1];
                j--;
            } while ((j > 0) && (value_i < a[j-1]));
            a[j] = value_i;
        }
    }
}

template<class t>
void print_list (t a[], int n)
{
    using namespace std;
    for (int i = 0; i < n; i++)
        std::cout << a[i] << " ";
    std::cout << std::endl;
}

template<class t>
int find (t a[], int n, t val)
{
    //look at every element
    for (int i = 0; i < n; i++) {
        //is this the value we're looking for?
        if (a[i] == val)
            //yes, so return subscript
            return i;
    }

    //not found, so return -1;
    return -1;
}
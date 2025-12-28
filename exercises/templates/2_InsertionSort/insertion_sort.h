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
        cout << a[i] << " ";
    std::cout << std::endl;
}

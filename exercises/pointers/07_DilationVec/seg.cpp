#include <iostream>

#include "image.h"
#include "seg.h"


void display_seg (const Image& seg)
{
    std::cout << "Image:\n";
    for (int y = 0; y < seg.size(1); y++) {
        for (int x = 0; x < seg.size(0); x++) {
            if (seg (x,y))
                std::cout << "*";
            else
                std::cout << ".";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}





Image dilate_seg (const Image& segin)
{
    Image segout (segin.size(0), segin.size(1));
    for (int y = 0; y < segin.size(1); y++) {
        for (int x = 0; x < segin.size(0); x++) {
            segout(x,y) = segin(x,y);
            if (
                ( (x > 0)               && segin(x-1,y) ) ||
                ( (x < segin.size(0)-1) && segin(x+1,y) ) ||
                ( (y > 0)               && segin(x,y-1) ) ||
                ( (y < segin.size(1)-1) && segin(x,y+1) ) )
                segout(x,y) = true;
        }
    }
    return segout;
}

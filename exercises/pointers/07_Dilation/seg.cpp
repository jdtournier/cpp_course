#include <iostream>

#include "seg.h"

void display_seg (bool seg[im_size][im_size])
{
  std::cout << "Image:\n";
    for (int y = 0; y < im_size; y++) {
        for (int x = 0; x < im_size; x++) {
            if (seg[x][y])
                std::cout << "*";
            else
                std::cout << ".";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
}



void dilate_seg (bool segin[im_size][im_size], bool segout[im_size][im_size])
{
    for (int y = 0; y < im_size; y++) {
        for (int x = 0; x < im_size; x++) {
            segout[x][y] = segin[x][y];
            if (
                ( (x > 0)         && segin[x-1][y] ) ||
                ( (x < im_size-1) && segin[x+1][y] ) ||
                ( (y > 0)         && segin[x][y-1] ) ||
                ( (y < im_size-1) && segin[x][y+1] ) )
                segout[x][y] = true;
        }
    }
}

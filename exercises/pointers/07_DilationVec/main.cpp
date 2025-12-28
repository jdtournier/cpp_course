#include <iostream>

#include "image.h"
#include "seg.h"

// Note this is a better solution to the problem, without using C-style arrays

int main ()
{
    const int im_size = 10;

    Image seg (im_size, im_size);

    // Image constructor already initialises contents to false (no need for
    // explicit reset to false
    seg(5,5) = seg(6,5) = seg(7,5) = true;
    seg(5,6) = seg(7,6) = true;
    seg(5,7) = seg(6,7) = seg(7,7) = seg(8,7) = true;

    // display initial 'segmentation'
    display_seg(seg);

    // dilate image
    auto dilated = dilate_seg (seg);

    // display dilated 'segmentation'
    display_seg(dilated);

    return 0;
}


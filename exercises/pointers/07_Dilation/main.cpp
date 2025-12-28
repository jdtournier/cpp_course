#include <iostream>

#include "seg.h"

// Note:
// Because the question asks for this to be implemented using 2D C-style
// arrays, the image size must be hard-coded, and the same size must be used
// throughout. Tnis is why the im_size variable has been moved to seg.h: to
// ensure the value is defined once and available everywhere it is required
//
// Note also that this example is for demonstration purposes. In practice, this
// code is very limited: it cannot be used for images of different sizes. In
// many ways, this example exists to demonstrate why you really should avoid
// C-style arrays!

int main()
{
    // define 'segmentation'
    bool seg[im_size][im_size], dilated[im_size][im_size];

    // initialise 'segmentation'
    for (int x = 0; x < im_size; x++)
        for (int y = 0; y < im_size; y++)
            seg[x][y] = false;

    seg[5][5] = seg[6][5] = seg[7][5] = true;
    seg[5][6] = seg[7][6] = true;
    seg[5][7] = seg[6][7] = seg[7][7] = seg[8][7] = true;

    // display initial 'segmentation'
    display_seg(seg);

    // dilate image
    dilate_seg(seg, dilated);

    //display dilated 'segmentation'
    display_seg(dilated);

    return 0;
}

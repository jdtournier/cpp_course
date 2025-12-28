#include <iostream>
using namespace std;

int main()
{
    // define 'segmentation'
    const int im_size = 10;
    bool seg[im_size][im_size], dilated[im_size][im_size];

    // initialise 'segmentation'
    for (int x = 0; x < im_size; x++)
        for (int y = 0; y < im_size; y++)
            seg[x][y] = false;
    seg[5][5] = seg[6][5] = seg[7][5] = true;
    seg[5][6] = seg[7][6] = true;
    seg[5][7] = seg[6][7] = seg[7][7] = seg[8][7] = true;

    // display seg
    // INSERT FUNCTION CALL TO display_seg HERE

    // dilate image
    // INSERT FUNCTION CALL TO dilate_seg HERE

    //display dilated
    // INSERT FUNCTION CALL TO display_seg HERE

    return 0;
}

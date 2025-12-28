#include <iostream>

#include "mri.h"
#include "us.h"
#include "xray.h"
#include "ct.h"

int main()
{
    MRI im1;
    im1.set_anatomy(Head);
    im1.display();

    US im2;
    im2.set_anatomy(Liver);
    im2.display();

    CT im3;
    im3.set_anatomy(Head);
    im3.display();

    Xray im4;
    im4.set_anatomy(Lung);
    im4.display();

    return 0;
}

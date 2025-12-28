#include <iostream>

#include "electricaldevice.h"

int main()
{
    Photocopier p;
    p.set_voltage(240);
    p.set_paper_trays(3);
    p.set_auto_feed(false);
    p.set_pix_per_mm(100);

    return 0;
}

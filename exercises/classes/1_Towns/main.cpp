#include <iostream>

#include "town.h"

int main()
{
    Town t1, t2;
    t1.set_name("London");
    t1.set_population(8174000);
    t1.set_airport(true);

    t2.set_name("Bath");
    t2.set_population(83992);
    t2.set_airport(false);

    t1.print();
    t2.print();

    return 0;
}

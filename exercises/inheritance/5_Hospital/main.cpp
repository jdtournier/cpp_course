#include <iostream>

#include "patient.h"

int main()
{
    UrgentPatient up("John", "Smith", "Ventricular tachycardia");
    Patient p("Jan", "Kowalski");

    up.print();
    p.print();

    return 0;
}

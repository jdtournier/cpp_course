#include <iostream>
#include <array>

#include "heart.h"

int main()
{
    // assign values
    std::array<Heart,4> p;

    p[0].set (180, 157, 95);
    p[1].set (196, 105, 74);
    p[2].set (163, 69, 86);
    p[3].set (228, 50, 103);

    // detect abnormals
    float ef;
    for (unsigned int i = 0; i < p.size(); i++) {
        // display parameters
        std::cout << "Patient " << i+1 << ":\n";
        std::cout << "  SV = " << p[i].SV() << "\n";
        std::cout << "  CO = " << p[i].CO() << "\n";
        std::cout << "  EF = " << p[i].EF() << "%\n";

        // check EF
        ef = p[i].EF();
        if ((ef < 40) || (ef > 75))
            std::cout << "Further tests required!\n";
        else
            std::cout << "No further tests required at this time\n";
    }
    return 0;
}

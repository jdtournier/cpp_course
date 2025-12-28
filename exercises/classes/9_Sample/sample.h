#ifndef SAMPLE_H
#define SAMPLE_H

#include <vector>

class Sample
{
    public:
        void SetSample (float val[], int n);
        float Mean() const;
        float StdDev() const;
        void Display() const;
        void Sort();
    private:
        std::vector<float> _x;
};

#endif // SAMPLE_H

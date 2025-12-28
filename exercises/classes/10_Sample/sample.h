#ifndef SAMPLE_H
#define SAMPLE_H

#include <vector>

class Sample
{
    public:
        void SetSample(float val[], int n);
        float Mean() const;
        float StdDev() const;
        void Display() const;
        void Sort();
        bool ShapiroWilk();
    private:
        std::vector<float> _x;
        static float _swcoeff[9][5];
        static float _swtab[8];
};

#endif // SAMPLE_H

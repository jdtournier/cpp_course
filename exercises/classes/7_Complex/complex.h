#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
    public:
        Complex(float r = 0.0, float i = 0.0) {_r = r; _i = i;}
        float GetR() { return _r; }
        void SetR(float val) { _r = val; }
        float GetI() { return _i; }
        void SetI(float val) { _i = val; }
        void Display();
        Complex Add(Complex c);
        Complex Multiply(Complex c);
    private:
        float _r;
        float _i;
};

#endif // COMPLEX_H

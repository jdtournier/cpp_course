#pragma once

#include <array>

class Matrix2x2
{
    public:
        Matrix2x2(float a = 1, float b = 0,
                float c = 0, float d = 1) // constructor
              : m_data { a, b, c, d } { }
        float coef (int i, int j) { return m_data[2*i+j]; }
        void set_coef (int i, int j, float val) { m_data[2*i+j] = val; }
        void display();
        Matrix2x2 multiply (Matrix2x2 m);
    private:
        std::array<float,4> m_data;
};


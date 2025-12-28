#pragma once

#include <iostream>

class Point {
    public:
        Point (float x = 0.0, float y = 0.0) : m_x (x), m_y (y) { }
        float get_x () const { return m_x; }
        float get_y () const { return m_y; }
    private:
        float m_x, m_y;
};



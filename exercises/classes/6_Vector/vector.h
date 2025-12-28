#pragma once

class Point {
    public:
        Point (float x = 0.0, float y = 0.0) : m_x (x), m_y (y) { }
        float get_x () const { return m_x; }
        float get_y () const { return m_y; }
    private:
        float m_x, m_y;
};



class Vector {
    public:
        Vector (Point s, Point e) :
            m_start (s), m_end (e) { }

        Point get_start() const { return m_start; }
        Point get_end() const { return m_end; }

        void print() const;
        float dot (const Vector& v2) const;
        float mag() const;
        float angle() const;

    private:
        Point m_start, m_end;
};

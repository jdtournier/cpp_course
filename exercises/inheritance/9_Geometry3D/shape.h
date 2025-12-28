#pragma once

class Shape
{
    public:
        float get_area() const { return m_area; }
        float get_perimeter() const { return m_perimeter; }
        virtual void compute_area() = 0; // pure virtual function
        virtual void compute_perimeter() = 0; // pure virtual function
    protected:
        float m_area;
        float m_perimeter;
};

class Circle: public Shape
{
    public:
        Circle(float r=0) {m_radius = r;};
        void compute_area();
        void compute_perimeter();
    protected:
        float m_radius;
};

class Square: public Shape
{
    public:
        Square(float s=0) {m_side = s;};
        void compute_area();
        void compute_perimeter();
    protected:
        float m_side;
};

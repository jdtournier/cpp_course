#pragma once

class Shape
{
    public:
        bool get_visible() const { return m_visible; }
        void set_visible(bool val) { m_visible =val; }
    protected:
        bool m_visible;
};

class Shape2D: public Shape
{
    public:
        Shape2D() {};
        float get_area() const { return m_area; }
        float get_perimeter() const { return m_perimeter; }
        virtual void compute_area() = 0; // pure virtual function
        virtual void compute_perimeter() = 0; // pure virtual function
    protected:
        float m_area;
        float m_perimeter;
};

class Shape3D: public Shape
{
    public:
        Shape3D() {};
        float get_volume() const { return m_volume; }
        float get_surface_area() const { return m_surface_area; }
        virtual void compute_volume() = 0; // pure virtual function
        virtual void compute_surface_area() = 0; // pure virtual function
    protected:
        float m_volume;
        float m_surface_area;
};

class Circle: public Shape2D
{
    public:
        Circle(float r=0) {m_radius = r;};
        void compute_area();
        void compute_perimeter();
    protected:
        float m_radius;
};

class Square: public Shape2D
{
    public:
        Square(float s=0) {m_side = s;};
        void compute_area();
        void compute_perimeter();
    protected:
        float m_side;
};

class Sphere: public Shape3D
{
    public:
        Sphere(float r=0) {m_radius = r;};
        void compute_volume();
        void compute_surface_area();
    protected:
        float m_radius;
};

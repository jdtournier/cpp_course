#pragma once

#include <iostream>

class Equation
{
    public:
        int get_order() const { return m_order; }
        void set_order(int val) { m_order = val; }
        virtual void display() const = 0;
    protected:
        int m_order;
};

class LinearEquation: public Equation
{
    public:
        LinearEquation() { m_order = 1; }
        void set_coeffs(float a, float b, float c) { m_a = a; m_b = b; m_c = c; }
        float get_a() const { return m_a; }
        float get_b() const { return m_b; }
        float get_c() const { return m_c; }
        void display() const {
            std::cout << m_a << "x + " << m_b << "y = " << m_c << std::endl;
        }
    protected:
        float m_a, m_b, m_c;
};

class SimultaneousEquations
{
    public:
        void set_equations(LinearEquation e1, LinearEquation e2) { m_e1 = e1; m_e2 = e2; }
        void display() const {m_e1.display(); m_e2.display(); }
        void solve() const;
    protected:
        LinearEquation m_e1, m_e2;
};

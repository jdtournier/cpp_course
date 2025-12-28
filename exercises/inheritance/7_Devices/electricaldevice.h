#pragma once

// virtual base class for electrical devices
class ElectricalDevice
{
    public:
        float get_voltage() const { return m_voltage; }
        void set_voltage(float val) { m_voltage = val; }
    protected:
        float m_voltage;
};

class Printer: public virtual ElectricalDevice
{
    public:
        int get_paper_trays() const { return m_paper_trays; }
        void set_paper_trays(int val) { m_paper_trays = val; }
    protected:
        int m_paper_trays;
};

class Scanner: public virtual ElectricalDevice
{
    public:
        int get_pix_per_mm() const { return m_pix_per_mm; }
        void set_pix_per_mm(int val) { m_pix_per_mm = val; }
    protected:
        int m_pix_per_mm;
};

class Photocopier: public Scanner, public Printer
{
    public:
        bool get_auto_feed() const { return m_auto_feed; }
        void set_auto_feed(bool val) { m_auto_feed = val; }
    protected:
        bool m_auto_feed;
};

#pragma once

class Heart
{
    public:
        Heart() : m_edv(0), m_esv(0), m_hr(0) { }
        void set (float edv, float esv, float hr) {
            m_edv = edv; m_esv = esv; m_hr = hr; }
        float SV() const { return m_edv - m_esv; }
        float CO() const { return (SV() * m_hr)/1000.0; }
        float EF() const { return 100.0 * SV() / m_edv; }
    private:
        float m_edv;
        float m_esv;
        float m_hr;
};

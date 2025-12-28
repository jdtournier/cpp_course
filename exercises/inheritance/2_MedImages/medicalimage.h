#pragma once

enum BodyPart {Lung, Heart, Liver, Head};

class MedicalImage
{
    public:
        MedicalImage() {};
        BodyPart get_anatomy() const { return m_anatomy; }
        void set_anatomy(BodyPart val) { m_anatomy = val; }
        virtual void display() const = 0;
    protected:
        BodyPart m_anatomy;
};

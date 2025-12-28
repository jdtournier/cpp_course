#pragma once

#include "disease.h"

enum LungDiseaseType {Bronchi, Alveoli, Interstitium};

class Lung : public Disease
{
    public:
        Lung() {};
        void set_lung_disease_type(LungDiseaseType val) {m_lung_disease_type = val;}
        LungDiseaseType get_lung_disease_type() const {return m_lung_disease_type;}
    protected:
        LungDiseaseType m_lung_disease_type;
};

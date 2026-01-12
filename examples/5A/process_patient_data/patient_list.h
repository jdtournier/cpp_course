#pragma once

#include <vector>

#include "patient.h"

class PatientDataList {
  public:
    PatientDataList (const std::vector<PatientData>& data) : m_data (data) { }

    unsigned int size () const { return m_data.size(); }
    bool operator! () const { return m_data.empty(); }
    const PatientData& operator[] (int i) const { return m_data[i]; }

  private:
    std::vector<PatientData> m_data;
};




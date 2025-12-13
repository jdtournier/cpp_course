#pragma once

#include <vector>
#include <string>

#include "types.h"
#include "stats.h"

class PatientData {
  public:
    void init (const std::string& ID, const std::vector<dtype>& data) {
      m_ID = ID;
      m_data = data;
    }

    const std::string& ID () const { return m_ID; }
    const std::vector<dtype>& data () const { return m_data; }

    float get_mean () const { return compute_mean (m_data); }
    float get_stddev () const { return compute_stddev (m_data); }

  private:
    std::string m_ID;
    std::vector<dtype> m_data;
};

using PatientDataList = std::vector<PatientData>;


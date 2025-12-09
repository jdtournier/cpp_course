#pragma once

#include <vector>
#include <string>

using dtype = float;

struct PatientData {
  std::string ID;
  std::vector<dtype> data;
};

using PatientDataList = std::vector<PatientData>;


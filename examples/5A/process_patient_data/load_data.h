#pragma once

#include <string>

#include "patient.h"
#include "patient_list.h"

PatientDataList load_patient_data (const std::string& filename);

#pragma once

#include <string>

enum class Treatment {
  BB,
  ARB
};

Treatment convert (const std::string& treatment_string);

std::string description (Treatment treatment);


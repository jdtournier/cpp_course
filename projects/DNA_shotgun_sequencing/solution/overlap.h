#pragma once

#include <string>

int compute_overlap (const std::string& sequence, const std::string& fragment);

void merge (std::string& sequence, const std::string& fragment, const int overlap);


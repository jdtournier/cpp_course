#pragma once

#include <string>

#include "fragments.h"

struct Overlap {
  int size;
  int fragment;
};


int compute_overlap (const std::string& sequence, const std::string& fragment);

Overlap find_biggest_overlap (const std::string& sequence, std::vector<std::string>& fragments);

void merge (std::string& sequence, const std::string& fragment, const int overlap);


#pragma once

#include <vector>
#include <string>

std::vector<std::string> load_fragments (const std::string& filename);

void fragment_statistics (const std::vector<std::string>& fragments);

void write_sequence (const std::string& filename, const std::string& sequence);

std::string extract_longest_fragment (std::vector<std::string>& fragments);


#include <string>
#include <cctype>

#include "string_utils.h"

std::string invert (const std::string& s)
{
  std::string s2 (s.size(), ' ');
  for (int n = 0; n < s.size(); n++)
    s2[n] = s[s.size()-1-n];

  return s2;
}


std::string capitalise (const std::string& s)
{
  std::string s2 = s;
  for (auto& c : s2)
    c = std::toupper (c);
  return s2;
}


#include <string>
#include <stdexcept>

#include "treatment.h"

Treatment convert (const std::string& treatment_string)
{
  if (treatment_string == "BB")
    return Treatment::BB;
  if (treatment_string == "ARB")
    return Treatment::ARB;

  throw std::runtime_error ("no such treatment group: \"" + treatment_string + "\"");
}




std::string description (Treatment treatment)
{
  switch (treatment) {
    case Treatment::BB:
      return "Beta blockers (BB)";
    case Treatment::ARB:
      return "Angiotensin II receptor blockers (ARB)";
  }
  return "invalid";
}

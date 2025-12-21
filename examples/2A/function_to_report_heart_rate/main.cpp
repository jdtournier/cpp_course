#include <iostream>

void report_heart_rate (double heart_rate, double threshold)
{
  std::cout << "measured heart rate: " << heart_rate << " - ";
  if (heart_rate > threshold)
    std::cout << "EXCEEDS";
  else
    std::cout << "does not exceed";
  std::cout << " user-specified threshold of " << threshold << "\n";
}

int main ()
{
  double rate = 72.0, critical_threshold = 120.0;

  report_heart_rate (rate, critical_threshold);

  return 0;
}

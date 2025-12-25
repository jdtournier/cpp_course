#include <iostream>
#include <stdexcept>

enum class Weekday {
  Monday,
  Tuesday,
  Wednesday,
  Thursday,
  Friday,
  Saturday,
  Sunday
};


std::string weekday_as_string (Weekday w)
{
  switch (w) {
    case Weekday::Monday:     return "Monday";
    case Weekday::Tuesday:    return "Tuesday";
    case Weekday::Wednesday:  return "Wednesday";
    case Weekday::Thursday:   return "Thursday";
    case Weekday::Friday:     return "Friday";
    case Weekday::Saturday:   return "Saturday";
    case Weekday::Sunday:     return "Sunday";
   default: throw std::invalid_argument ("invalid Weekday enum value");
  }
}

Weekday num_to_weekday (int d)
{
  switch (d) {
    case 1: return Weekday::Monday;
    case 2: return Weekday::Tuesday;
    case 3: return Weekday::Wednesday;
    case 4: return Weekday::Thursday;
    case 5: return Weekday::Friday;
    case 6: return Weekday::Saturday;
    case 7: return Weekday::Sunday;
    default: throw std::invalid_argument ("weekdays can only range from 1 to 7");
  }
}


int main()
{
  int d;
  std::cout << "Please enter the day of the week as a digit (1→7): ";
  std::cin >> d;

  Weekday w = num_to_weekday (d);

  std::cout << "day " << d << " maps to " << weekday_as_string (w) << "\n";

  return 0;
}

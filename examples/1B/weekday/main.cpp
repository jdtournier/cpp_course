#include <iostream>

int main()
{
  int d;
  std::cout << "Please enter the day of the week as a digit (1→7): ";
  std::cin >> d;
  switch (d) {
    case 1: 
      std::cout << "Monday\n"; 
      break;
    case 2: 
      std::cout << "Tuesday\n"; 
      break;
    case 3: 
      std::cout << "Wednesday\n"; 
      break;
    case 4: 
      std::cout << "Thursday\n"; 
      break;
    case 5: 
      std::cout << "Friday\n"; 
      break;
    case 6: 
      std::cout << "Saturday\n"; 
      break;
    case 7: 
      std::cout << "Sunday\n"; 
      break;
   default:
      std::cout << "ERROR: invalid number\n";
      return 1;
  }

  return 0;
}

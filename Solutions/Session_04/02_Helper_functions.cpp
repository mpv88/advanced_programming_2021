/* COMPILE WITH: c++ 02_Helper_functions.cpp -o 02_Helper_functions -Wall -Wextra -g -std=c++14
   DEBUG WITH: gdb ./02_Helper_functions core; (gdb) r; (gdb) quit;
   TEST WITH: g++ -g -fsanitize=address 02_Helper_functions.cpp -o 02_Helper_functions; ./02_Helper_functions.cpp;

Implement the following external helper functions (i.e., they are not part of the class):
- `bool operator==(const Date& lhs, const Date& rhs);`
- `bool operator!=(const Date& lhs, const Date& rhs);`
- `std::ostream& operator<<(std::ostream& os, const Date& d);`
- **optional** `bool is_leap(const int y);`

*Hints*:
- a year is a leap year if it is divisible by 4. If it is also divisible by 100 is not a leap year. However, it is a leap year if it is divisible by 400.
- try to avoid code duplication
*/
#include <iomanip>
#include <iostream>

int main() 
{

  return 0;
}

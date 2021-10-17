/*
- write a function `get_int` that reads from stdin until a valid number is fed
- write a function `get_double` that reads from stdin until a valid number is fed.
*Hints*: 
You can keep reading from stdin using one of two statements
```
while(std::cin >> i)
```
or
```
while(!(std::cin >> i))
```
what is the difference?
After that a wrong input has been parsed, you have to clear the error flag from `std::cin` calling
```
std::cin.clear();
```
and ignore what just read
```
std::cin.ignore();
```
*/
#include <iostream>

void get_int();
void get_double();

void get_int() 
{
  int number{};
  while(!(std::cin >> number)) {
    if (std::cin.fail() || sizeof(number)!=4) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "You have not provided an integer, retry" << std::endl;
	  		}
				}
std::cout << "The integer provided is: " << number << std::endl;
}

void get_double() 
{
  double number{};
  while(!(std::cin >> number || sizeof(number)!=8)) {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        std::cout << "You have not provided a double, retry" << std::endl;
	  		}
				}
std::cout << "The double provided is: " << number << std::endl;
}

int main() {
  std::cout << "Insert your number:\n";
  get_int(); // call get_int
  //get_double(); // call get_double
}

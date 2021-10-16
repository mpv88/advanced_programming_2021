/* 
- Take a simple program (e.g., the hello world one) and put one at a time the following errors. Compile it and try to understand the error 	  	messages. If you have different compilers compare the messages from the compilers.
- do not put the `main` function	->
- typos in function name (e.g., `c0ut`) ->
- typos in variable name		->
- forget to put `;`			->
- forget to `#include <iostream>`	->
- declare a variable with illegal name like `int double {0};`->
*/
  
#include <iostream>
#include <string>

int main() {
  std::cout << "Insert your name and age:\n";
  std::string name;
  unsigned int age;
  std::cin >> name >> age;
  std::cout << "Hello, " << name << " [" << age << "]\n";
  return 0;
}


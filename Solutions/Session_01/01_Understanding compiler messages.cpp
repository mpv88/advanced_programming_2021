/* 
- Take a simple program (e.g., the hello world one) and put one at a time the following errors. Compile it and try to understand the error 	  	messages. If you have different compilers compare the messages from the compilers.
- do not put the `main` function	->error: (.text+0x24): undefined reference to `main'
- typos in function name (e.g., `c0ut`) ->error: ‘c0ut’ is not a member of ‘std’; did you mean ‘cout’?
- typos in variable name		->error: ‘mame’ was not declared in this scope; did you mean ‘name’?
- forget to put `;`			->error: expected ‘;’ before ‘std’
- forget to `#include <iostream>`	->error: ‘cout’ is not a member of ‘std’, note: ‘std::cout’ is defined in header ‘<iostream>’; did you forget to ‘#include <iostream>’?
- declare a variable with illegal name like `int double {0};`->error: expected unqualified-id before ‘{’ token
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


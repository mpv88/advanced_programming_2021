/* COMPILE WITH: c++ 05_Avoid_repeated_words.cpp -o 05_Avoid_repeated_words -Wall -Wextra -g -std=c++14
   DEBUG WITH: gdb ./05_Avoid_repeated_words core; (gdb) r; (gdb) quit;
   TEST WITH: g++ -g -fsanitize=address 05_Avoid_repeated_words.cpp -o 05_Avoid_repeated_words; ./05_Avoid_repeated_words;
- Read from stdin a sequence of words. Store each word in a `std::vector<std::string>`. Then, print the words without repetitions.

*Hints*:
- you can print the words in any order you want (i.e., you are not required to print the words in the order you have read them)
*/
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() 
{
 std::string line;
 std::vector<std::string> v{};
 std::cout << "Please insert one input for each line:" << std::endl;
 while(std::getline(std::cin,line))
 {
  if(line==".") break;
  v.push_back(line);
 }
 std::sort(v.begin(),v.end());
 for(std::size_t i=0; i<v.size(); i++)
  if(v[i]==v[i+1])
   continue;
  else
   std::cout << v[i] << std::endl;
}

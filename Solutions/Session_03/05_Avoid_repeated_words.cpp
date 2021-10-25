/* c++ 05_Avoid_repeated_words.cpp -o 05_Avoid_repeated_words -Wall -Wextra -g -std=c++14
- Read from stdin a sequence of words. Store each word in a `std::vector<std::string>`. Then, print the words without repetitions.

*Hints*:
- you can print the words in any order you want (i.e., you are not required to print the words in the order you have read them)
*/
#include <iostream>
#include <string>

template <typename ia>
ia * init(const ia input[], std::size_t n)
{ 
  ia * ar{new ia[n]};
  for (std::size_t i=0; i<n; i++)
    *(ar+i) = *(input+i);
  return ar;
}

template <typename rv>
void reverse(const rv * ar, std::size_t n)
{ 
  for (int i=n; i>=0; --i)
    std::cout << ar[i] << std::endl;
  delete[] ar;
}

int main ()
{
  std::string input;
  std::size_t n{};
  std::cout << "Please insert your integers on one line: ";
  std::getline(std::cin, input);
  n=input.length();
  auto * ptr=init<char>(input.c_str(), n);  
  reverse<char>(ptr, n);
  return 0;
}


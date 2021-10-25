/* c++ 07_Game_of_Life.cpp -o 07_Game_of_Life -Wall -Wextra -g -std=c++14
- Implement the [Game of Life](https://www.wikidata.org/wiki/Q244615#sitelinks-wikipedia)
- You can slow down your code by forcing a "nap".
```c++
#include <chrono>
#include <thread>
...
std::this_thread::sleep_for (std::chrono::milliseconds(50));
```
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


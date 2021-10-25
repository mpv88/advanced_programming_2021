/* c++ 06_Use_Std_Map.cpp -o 06_Use_Std_Map -Wall -Wextra -g -std=c++14
- Read the `LittleWomen.txt` and then print all the read words (without repetitions) followed by the number of repetitions of that word. Compare the time to do the same using `std::vector`, `std::map`, `std::unordered_map`. The order in which the words are printed is **not** relevant.

- You can measure the elapsed time as follows:
```c++
#include <chrono>

auto t0 = std::chrono::high_resolution_clock::now();
...
auto t1 = std::chrono::high_resolution_clock::now();

auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;
```

- You can avoid to repeat `std::chrono::` if you write
```c++

using namespace std::chrono;

auto t0 = high_resolution_clock::now();
```
- Compile with the flag `-O3` (is a capital O, not a zero)
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


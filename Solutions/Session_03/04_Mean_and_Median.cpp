/* c++ 04_Mean_and_Median.cpp -o 04_Mean_and_Median -Wall -Wextra -g -std=c++14
- Store the numbers contained in file `temperatures.txt` into a `std::vector<double>` and compute:
  - the mean
  - the median

*Hints*:
- use `emplace_back()`
- you can increment a variable using `+=` operator
- you can **sort** the elements of a vector `v` as follows
```c++
#include <algorithm>

std::vector<double> v;
...
std::sort( v.begin(), v.end() );
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


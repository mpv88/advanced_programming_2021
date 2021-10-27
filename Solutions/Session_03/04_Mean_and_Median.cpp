/* COMPILE WITH: c++ 04_Mean_and_Median.cpp -o 04_Mean_and_Median -Wall -Wextra -g -std=c++14
   DEBUG WITH: gdb ./04_Mean_and_Median core; (gdb) r; (gdb) quit;
   TEST WITH: g++ -g -fsanitize=address 04_Mean_and_Median.cpp; ./04_Mean_and_Median;
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
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
T mean(const std::vector<T>& input)
{
  T sum{0};
  for (std::size_t i=0; i<input.size(); i++)
    sum += input[i];
  return sum/input.size();
}

template <typename T>
T median(std::vector<T>& input) //no const to sort
{ 
  std::sort(input.begin(),input.end());
  if (input.size() % 2 == 0)
   return (input[input.size()/2-1]+input[input.size()/2])/2; //even v
  else return input[input.size()/2+1]; //odd v
}

template <typename T>
void read_file(const std::string file_name, std::vector<T>& v) //no const to fill
{ 
  T number{};
  std::ifstream input_file(file_name, std::ios::in);
  if (!input_file) 
  {
   std::cerr << "Can't open " << file_name << " file!" << std::endl;
   exit(1); //exits file
  }
  while (input_file >> number) //read lines as doubles
   v.emplace_back(number);
}

int main ()
{
  std::string file_name = "temperatures.txt"; 
  std::vector<double> v{};
  read_file(file_name, v);
  std::cout << "The mean temperature is " << mean(v) << " C°" << std::endl;
  std::cout << "The median temperature is " << median(v) << " C°" << std::endl;
  return 0;
}

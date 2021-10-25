/* c++ 03_Dutch_national_flag.cpp -o 03_Dutch_national_flag -Wall -Wextra -g -std=c++14
- Edsger Dijkstra proposed the famous Dutch national flag problem. The same algorithm can be applied in the partition step of quicksort. Given an array (or vector) of integers, select a pivot element. Then, the array elements can be divided into three groups (the flag's three colors): less than, equal to, and greater than the pivot element. 
Sort the array elements such that elements "of the same color" are together, and their collective color groups are in the correct order. Do not sort elements within each group.
For example, given this array `3 1 4 1 5 9 2 6 5 3`, if we choose 3 as the pivot value, the program could give the following output  `1 1 2 3 3 9 6 5 5 4`. 
If we choose 4, the outcome could be `3 1 1 3 2 4 6 5 9 5`. Try to solve it without extra memory (i.e., without allocating a new vector) and in a single pass (i.e., you loop over the elements once).

*Hints*:
 - You can first solve the problem by means of a brute-force approach.
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


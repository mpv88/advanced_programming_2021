/* c++ 01_Matrix_transpose.cpp -o 01_Matrix_transpose -Wall -Wextra -g -std=c++14
- Write a function that computes the transpose of a matrix. The matrix is represented by a simple `std::array<double,N>` where N is the total size of the matrix 
(i.e., number of rows times number of columns). The original array must be modified inside the function `transpose`. 

*Hints*:
- In C/C++, the matrices are accessed row-wise
- You are not required to do the transpose *in place*
- Test with both square and rectangular matrices.
- Use `std::swap` defined in header `<utility>`
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


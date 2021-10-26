/* COMPILE WITH: c++ 01_Matrix_transpose.cpp -o 01_Matrix_transpose -Wall -Wextra -g -std=c++14
   DEBUG WITH: gdb ./02_Argv_2_types core; (gdb) r; (gdb) quit;
   TEST WITH: g++ -g -fsanitize=address 01_Matrix_transpose.cpp; ./01_Matrix_transpose;
- Write a function that computes the transpose of a matrix. The matrix is represented by a simple `std::array<double,N>` where N is the total size of the matrix 
(i.e., number of rows times number of columns). The original array must be modified inside the function `transpose`. 

*Hints*:
- In C/C++, the matrices are accessed row-wise
- You are not required to do the transpose *in place*
- Test with both square and rectangular matrices.
- Use `std::swap` defined in header `<utility>`
*/
#include <iomanip>
#include <iostream>

template<const std::size_t N>
std::array<double, N> transpose(std::array<double,N> input_matrix, int row, int col)
{
  std::array<double,N> output_matrix{};
  double tmp;
  for (int i=0; i<row; ++i)
    for (int j=0; j<col; ++j) 
    {
      tmp=input_matrix[col*i+j];
      std::swap(i, j);
      output_matrix[row*i+j]=tmp;
      std::swap(i, j);
    }
return output_matrix;
}

template<const std::size_t N>
void print_matrix(std::array<double,N> matrix, int row, int col) 
{
  for (int i=0; i<row; ++i) 
  {
    for (int j=0; j<col; ++j)
      std::cout << std::setw(2) << matrix[col*i+j]  << " ";
    std::cout << std::endl;
  }
}

int main() 
{
  const unsigned int rows=3;
  const unsigned int columns=2;
  const unsigned int N=(rows*columns); //initialize (rxc) matrix
  std::array<double,N> matrix{1.1,2.2,
  			      3.3,4.4,
  			      5.5,6.6}; //declare matrix
  print_matrix(matrix, rows, columns);  //print input	
  		      
  std::array<double,N> transposed = transpose(matrix, rows, columns); //transpose matrix
  print_matrix(transposed, columns, rows); //print transposed matrix
  return 0;
}

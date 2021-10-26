/* COMPILE WITH: c++ 02_Argv_2_types.cpp -o 02_Argv_2_types -Wall -Wextra -g -std=c++14
   DEBUG WITH: gdb ./02_Argv_2_types core; (gdb) r; (gdb) quit;
   TEST WITH: g++ -g -fsanitize=address 02_Argv_2_types.cpp; ./02_Argv_2_types;
- Modify the above program such that the number of rows and columns are read from command line arguments.

*Hints*:
 - Yout might need to change a type...
*/
#include <iomanip>
#include <iostream>
#include <vector>

std::vector<double> transpose(std::vector<double>& input_matrix, int row, int col)
{
  std::vector<double> output_matrix(row*col);
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

void print_matrix(std::vector<double>& matrix, int row, int col) 
{
  for (int i=0; i<row; ++i) 
  {
    for (int j=0; j<col; ++j)
      std::cout << std::setw(2) << matrix[col*i+j]  << " ";
    std::cout << std::endl;
  }
}

int main(int argc, char* argv[]) 
{ 
  if(argc<3) std::cout << "You have inserted less than 2 args required, try again" << std::endl;
  const int rows = std::stoi(argv[1]);
  const int columns = std::stoi(argv[2]);
  
  std::vector<double> matrix(rows*columns); //declare matrix
  for(auto i=0; i<(rows*columns); i++)      //fill matrix with doubles
    matrix[i]=1.1*(1+i);
  print_matrix(matrix, rows, columns);  //print input	
 
  std::vector<double> transposed = transpose(matrix, rows, columns); //transposed matrix
  print_matrix(transposed, columns, rows); //print transposed matrix
  return 0;
}

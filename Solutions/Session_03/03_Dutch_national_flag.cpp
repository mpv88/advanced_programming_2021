/* COMPILE WITH: c++ 03_Dutch_national_flag.cpp -o 03_Dutch_national_flag -Wall -Wextra -g -std=c++14
   DEBUG WITH: gdb ./03_Dutch_national_flag core; (gdb) r; (gdb) quit;
   TEST WITH: g++ -g -fsanitize=address 03_Dutch_national_flag.cpp; ./03_Dutch_national_flag;
- Edsger Dijkstra proposed the famous Dutch national flag problem. The same algorithm can be applied in the partition step of quicksort. Given an array (or vector) of integers, select a pivot element. Then, the array elements can be divided into three groups (the flag's three colors): less than, equal to, and greater than the pivot element. 
Sort the array elements such that elements "of the same color" are together, and their collective color groups are in the correct order. Do not sort elements within each group.
For example, given this array `3 1 4 1 5 9 2 6 5 3`, if we choose 3 as the pivot value, the program could give the following output  `1 1 2 3 3 9 6 5 5 4`. 
If we choose 4, the outcome could be `3 1 1 3 2 4 6 5 9 5`. Try to solve it without extra memory (i.e., without allocating a new vector) and in a single pass (i.e., you loop over the elements once).

*Hints*:
 - You can first solve the problem by means of a brute-force approach.
*/
#include <array>
#include <iostream>

template <typename T, std::size_t N>
void sorting_the_flag(std::array<T,N>& unsorted, T pivot)
{ 
  std::size_t i{0}, j{0}, k{N-1};
  while(j<=k)
  {
   if(unsorted[j]<pivot) 
    {
     std::swap(unsorted[i],unsorted[j]);//< put on top of array
     i++;//1 right shift for the top
     j++;//1 right shift for the mid
    }
   else if (unsorted[j]>pivot)
    {
     std::swap(unsorted[j],unsorted[k]);//> put on bottom of array
     k--;//1 left shift for the bottom
    }
   else j++;//1 right shift for the mid
  }
}

template <typename T, std::size_t N>
void print_array(const std::array<T,N>& arr)
{ 
  for(auto& element : arr)
    std::cout << element << " ";
}

int main()  
{ 
  int pivot_point{4}; //pivot of choice
  std::array<int,10> unsorted {3,1,4,1,5,9,2,6,5,3}; //unsorted array given
  
  std::cout << "Array given in input is: ";  
  print_array(unsorted);   
  sorting_the_flag(unsorted, pivot_point);  
  std::cout << "\nSorted array following Dutch Flag is: ";
  print_array(unsorted);  
  return 0;
}

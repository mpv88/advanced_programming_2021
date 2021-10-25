/* c++ 01_Reverse_Order.cpp -o 01_Reverse_Order -Wall -Wextra -g -std=c++14
- Write a program that reads from stdin the length of an array and then stores in it the numbers given from stdin. 
  The program should then print the numbers in **reverse order**. Remember to free the used memory properly. Divide the problem into two parts:
  1. Write one **template** function that allocates on the *heap* one array of a given size, initializes its elements, and returns the pointer to the first element.
  2. Write a **template** function that prints the elements of an array in the reverse order.
- Test with integers and doubles.
- Use `std::size_t`.

*Hints*: 
- If you have to pass an array to a function, pass the pointer to its first element and the size of the array itself.
- Remember to check your code with `valgrind`. If you have a MAC, you might have nasty surprises. 
Run `valgrind` on a **Linux**  system. Alternatively, compile and link your code with the following flags `-g -fsanitize=address`  and then run your executable. If it runs fine, you have no memory leaks. If it doesn't, you have some.
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


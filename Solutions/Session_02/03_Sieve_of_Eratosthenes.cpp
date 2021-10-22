/*
- Implement the Sieve of Eratosthenes algorithm. Write a code that prints on screen the first prime numbers up to `N` **included**, where `N` is read from stdin.
- The first printed number is `2`.
*Hints*:
- https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
- the function `std::sqrt`, which computes the square root of a number, is defined in `<cmath>`
```c++
#include <cmath>
...
std::cout << std::sqrt(4) << std::endl;
```
algorithm Sieve of Eratosthenes is
    input: an integer n > 1. ok
    output: all prime numbers from 2 through n. ok

    let A be an array of Boolean values, indexed by integers 2 to n,
    initially all set to true. ok
    
    for i = 2, 3, 4, ..., not exceeding √n do
        if A[i] is true
            for j = i2, i2+i, i2+2i, i2+3i, ..., not exceeding n do
                A[j] := false

    return all i such that A[i] is true.
*/
#include <iostream>
#include <cmath>

int main()
{
  std::size_t n{};
  std::cout << "Please insert number >1: ";
  std::cin >> n;
  bool* primes{new bool[n]}; //index from 2 (skip 0 1)

  for(std::size_t i=2; i<n; i++)
  primes[i]=true;

  for(std::size_t i=2; i<=std::sqrt(n); i++)
  {
    if (primes[i]==true)
    {
      for(std::size_t j=(i*i); j<=n; j+=i)
        primes[j]=false;
    }
  }

  std::cout << "Prime numbers up to " << n << " are:" << std::endl; // printing output
  for (std::size_t i=2; i<=n; i++)
    if (primes[i]==true) 
      std::cout << i << " ";
  delete[] primes;
  return 0;
}







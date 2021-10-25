/*
Re-implement the exercise *Sieve of Eratosthenes* using `std::vector` instead of built-in arrays. `std::vector` is defined in the header `<vector>`.
*/

#include <iostream>
#include <cmath>
#include <vector>

int main()
{
  std::size_t n{};
  std::cout << "Please insert number >1: ";
  std::cin >> n;
  std::vector<bool> primes(n);//init std::vector

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
  return 0;
}

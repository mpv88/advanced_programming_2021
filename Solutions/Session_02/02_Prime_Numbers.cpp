/*
- Populate an array named `primes` containing the first prime numbers smaller than 100. Consider 2 as the first prime (i.e. `primes[0] == 2`).
  - you are free to choose the design and the implementation.
  - please comment and motivate your choices (e.g., allocate one big array, or every time I find a new prime number I increase the size of
    the previous `primes` array
*Hints*:
- The remainder of a division between two integers is computed as follows:
```c++
unsigned int remainder = 6%3;
```
- Inside a for loop, you can use `continue` to immediately go to the next iteration, `break` to exit the loop. 
Note that if you have two or more nested loops, the statements affect only the innermost loop.
*/
#include <iostream>

bool prime(std::size_t n);

int main()
{
	std::size_t n{}, k{};
	std::cout << "Please insert number: ";
	std::cin >> n;
	int* primes{new int[n]}; // as I do not know size of primes[] in advance

	for(std::size_t i=2; i<n; i++) 
	{
		if(prime(i)==true)
		{
			primes[k] = i;
			k++;
		}
	}

	std::cout << "Prime numbers up to " << n << " are:" << std::endl;
	for (std::size_t i=0; i<k; i++)
	std::cout << primes[i] << " ";
	delete[] primes;
	return 0;
}

bool prime(std::size_t n) 
{
	bool is_prime=true;
	for(std::size_t i=2; i*i<=n; i++) 
		{
			if (n%i==0) 
			{
				is_prime=false;
				break;
			}
		}  
	return is_prime;
}

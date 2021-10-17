/*
- Write a code that reads a number with its proper unit of measure, and prints back that number according to the SI units, e.g.

```
1 inch
0.0254 m
```
*/
#include <iostream>

int main() 
{
double insert {};
constexpr double i2m{0.0254};
std::cout << "Please insert the n° of inch(es) you want to convert to meter(s)\n";
std::cin >> insert;

std::cout << insert << " inch(es) is/are equal to " << (insert*i2m) << " meter(s)" << std::endl;
}

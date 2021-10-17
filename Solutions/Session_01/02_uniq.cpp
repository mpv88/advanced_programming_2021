/*
- Write a simple version of the Unix program `uniq -c`, which, when fed with a text, outputs the same text with **consecutive** identical lines collapsed into one prepended with the number of repetitions. 

You can scan the stdin as follows
```
std::string line;
while(std::getline(std::cin,line))
{...}
```
or
```
for(std::string line; std::getline(std::cin,line);)
{...}
```
What do you think it is better? Why? --> I do not know in advance n° of lines to scan, so better to stop at given condition
Remember that if you type directly from stdin, you should press `Ctr+D` to close the stdin without interrupting the program. 
Moreover, you can redirect the content of a text to stdin trough the `<` operator
```
./a.out <a_file
```
You can compare strings with the `==` operator
```
std::string s1;
std::string s2;
...
if(s1 == s2)
if(s1 != s2)
```
`std::string` and `std::getline` are defined in the header `<string>`, so, remember to include it!
*/

#include <iostream>
#include <string>

int main() 
{
std::string line;
unsigned int i{};
std::string s1{};
std::string s2{};
while(std::getline(std::cin,line)) 
	{
	s1 = line;
	if(!s2.empty() && s1 != s2) {
		std::cout << i << " " << s2 << std::endl;
		i=1;		    }
	else ++i;
	s2 = s1;
	}
std::cout << i << " " << s1 << std::endl;
}




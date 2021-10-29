/* COMPILE WITH: c++ 06_Use_Std_Map.cpp -o 06_Use_Std_Map -Wall -Wextra -g -std=c++14 -O3
   DEBUG WITH: gdb ./06_Use_Std_Map core; (gdb) r; (gdb) quit;
   TEST WITH: g++ -g -fsanitize=address 06_Use_Std_Map.cpp -o 06_Use_Std_Map; ./06_Use_Std_Map;
- Read the `LittleWomen.txt` and then print all the read words (without repetitions) followed by the number of repetitions of that word. Compare the time to do the same using `std::vector`, `std::map`, `std::unordered_map`. The order in which the words are printed is **not** relevant.

- You can measure the elapsed time as follows:
```c++
#include <chrono>

auto t0 = std::chrono::high_resolution_clock::now();
...
auto t1 = std::chrono::high_resolution_clock::now();

auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl;
```

- You can avoid to repeat `std::chrono::` if you write
```c++

using namespace std::chrono;

auto t0 = high_resolution_clock::now();
```
- Compile with the flag `-O3` (is a capital O, not a zero)
*/
#include <algorithm>
#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <regex>
#include <string>
#include <vector>

template <typename T>
void file_to_map(const T file_name, std::map<T, unsigned int>& m)
{ 
  const std::regex re{ "\\w+" };
  std::string line;
  std::ifstream input_file(file_name, std::ios::in);
  if (!input_file) 
  {
   std::cerr << "Can't open " << file_name << " file!" << std::endl;
   exit(1); //exits file
  }
  while (input_file >> line)
  {
   for(auto word{ std::sregex_token_iterator(line.begin(),line.end(),re) }; word != std::sregex_token_iterator(); ++word)
    m[*word]++;

   for(const auto& [word, count] : m) 
    std::cout << std::setw(20) << word << "\toccurred\t" << count << " times\n";
  }
}

template <typename T>
void file_to_vector(const T file_name, std::vector<T>& v)
{ 
  auto t0 = std::chrono::high_resolution_clock::now();
  std::size_t counter{1};
  std::string line;
  std::ifstream input_file(file_name, std::ios::in);
  if (!input_file) 
  {
   std::cerr << "Can't open " << file_name << " file!" << std::endl;
   exit(1); //exits file
  }
  while (input_file >> line)
  {
   line.erase(std::remove_if(line.begin(), line.end(), ispunct), line.end());
   v.emplace_back(line);
  }

  std::sort(v.begin(),v.end());
  for(std::size_t i=0; i<v.size(); i++)
   {
    if(v[i]==v[i+1])
    {
     counter++;
     continue;
    }
    else
    {
     std::cout << counter << " " << v[i] << std::endl;
     counter=1;
    }
   }
  auto t1 = std::chrono::high_resolution_clock::now();
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
  std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl; 
}

int main ()
{
  std::string file_name = "LittleWomen.txt"; 
  std::vector<std::string> v{};
  std::map<std::string, unsigned int> m {};
  //file_to_vector(file_name, v);
  file_to_map(file_name, m);
  return 0;
}


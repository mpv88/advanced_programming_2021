/* COMPILE WITH: c++ 06_Use_Std_Map.cpp -o 06_Use_Std_Map -Wall -Wextra -g -std=c++14 -O3
   DEBUG WITH: gdb ./06_Use_Std_Map core; (gdb) r; (gdb) quit;
   TEST WITH: g++ -g -fsanitize=address 06_Use_Std_Map.cpp -o 06_Use_Std_Map; ./06_Use_Std_Map;
   TEST WITH: valgrind --leak-check=full --track-origins=yes ./06_Use_Std_Map;
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
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

template <typename T>
void file_to_map(std::ifstream& input_file, std::map<T,unsigned int>& m)
{ 
  auto t0 = std::chrono::high_resolution_clock::now();//starts clock
  
  for (std::string line; input_file>>line;)
   {
    line.erase(std::remove_if(line.begin(), line.end(), ispunct), line.end());//cleans text
    ++m[line];
   }
  for (const auto& element : m)
   std::cout << element.first << " " << element.second << std::endl;//prints key-value pairs
  
  auto t1 = std::chrono::high_resolution_clock::now();//stops clock
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
  std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl; 
}

template <typename T>
void file_to_unordered_map(std::ifstream& input_file, std::unordered_map<T,unsigned int>& u_m)
{ 
  auto t0 = std::chrono::high_resolution_clock::now();//starts clock
  
  for (std::string line; input_file>>line;)
   {
    line.erase(std::remove_if(line.begin(), line.end(), ispunct), line.end());//cleans text
    ++u_m[line];
   }
  for (const auto& element : u_m)
   std::cout << element.first << " " << element.second << std::endl;//prints key-value pairs
  
  auto t1 = std::chrono::high_resolution_clock::now();//stops clock
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
  std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl; 
}

template <typename T>
void file_to_vector(std::ifstream& input_file, std::vector<T>& v)
{ 
  auto t0 = std::chrono::high_resolution_clock::now();//starts clock
  std::size_t counter{};
  std::string line;
  while (input_file >> line)
  {
   line.erase(std::remove_if(line.begin(), line.end(), ispunct), line.end());//cleans text 
   v.emplace_back(line);//fills vector
  }
  std::sort(v.begin(),v.end());//sorts vector
  for(std::size_t i=0; i<v.size(); i++)
   {
    if(v[i]==v[i+1])
     ++counter;
    else
    {
     std::cout << counter << " " << v[i] << std::endl;
     counter=1;
    }
  }
  auto t1 = std::chrono::high_resolution_clock::now();//stops clock
  auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
  std::cout << "Elapsed " << elapsed.count() << " [milliseconds]" << std::endl; 
}

int main ()
{
  std::string file_name {"LittleWomen.txt"};//.txt source
  std::vector<std::string> v{}; //target vector
  std::map<std::string,unsigned int> m {}; //target map
  std::unordered_map<std::string,unsigned int> u_m {};//target unordered map

  std::ifstream input_file(file_name, std::ios::in);//opens file for input ops
  if (!input_file) 
  {
   std::cerr << "Can't open " << file_name << " file!" << std::endl;
   exit(1); //exits file
  }
  else
  {
  file_to_map(input_file, m);//1_read to map
  	//
  input_file.clear(); //clear stream flags & error state
  input_file.seekg(0, std::ios::beg);//back to the beginning of .txt
	//
  file_to_unordered_map(input_file, u_m);//2_read to unordered map
	//
  input_file.clear(); //clear stream flags & error state
  input_file.seekg(0, std::ios::beg);//back to the beginning of .txt
	//
  file_to_vector(input_file, v);//3_read to vector
  	//
  input_file.close();//closes file
  }
  return 0;
}


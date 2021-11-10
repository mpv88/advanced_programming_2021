//$ c++ 03_vector_as.cpp -o 03_vector_as -Wall -Wextra -g -std=c++14

//$ valgrind --leak-check=full --track-origins=yes ./a.out

#include <iostream>

template <typename T>
class Vector{
	T* data;
	std::size_t _size;
public: 
    Vector(const std::size_t size): data{new T[size]}, _size{size} {}
    ~Vector() {delete[] data; } //RAII

 auto size() const {return _size; }
 
 T& operator[](const std::size_t i) { return data[i]; }
 const T& operator[](const std::size_t i) const { return data[i];}
 
 T* begin() {return data; }
 const T* begin() const {return data; }
 
 T* end() {return data + _size; }
 const T* end() const {return data + _size; }
 

 friend std::ostream& operator<<(std::ostream& os, const Vector& v){//I can omit template
    os << v.data << ": ";
	for(const auto& x : v)
		os << x << " ";
	os <<  std::endl;
	return os;
 }
};
template <typename T>
void foo(const Vector<T>& v){
	//v[0]=88;	// does not compile
	std::cout << v[0] << std::endl; //const operator
	// v.operator[](0);
}
 
 int main(){
	 Vector<int> v{7};
	 
	 v[5] = 99;
	 std::cout << v;	
	 
 }

#include "pch.h"
#include "save.h"

// [Q1] Do not make change in main funtion, make "Change" function
// [Q2] Find Maximum in array c
// [Q3] Randomly 100 number of int, find max int and print 
// [Q4] A's data that number of 100, write this data to "intValue.txt" 
// [Q5] file, "intValue.txt" has numerous count of int data, print how count of data exist, and find Max number
template <typename T>
void change(T&, T&);

int maximum(const int*,int);

class Dog {
public:
	Dog(int i) : id{ i } {};
	Dog& operator=(const Dog& other) {
		id = other.id;
		return *this;
	}
	operator int() { return id; }
	int id{};
};

std::default_random_engine dre;
std::uniform_int_distribution uid{ 1000,99999 };

int main(void){

	std::array<int, 10000> newarr{};

	std::ifstream in{ "intValues.txt",std::ios::app };

	

	std::cout << *std::max_element(std::istream_iterator<int>{in}, {}) << std::endl;

	save("Source\\main.cpp");
}

template<typename T>
void change(T& a, T& b){
	T temp{ a };
	a = b;
	b = temp;
}


int maximum(const int* intarr,int size) {
	int max{ std::numeric_limits<int>::min() };
	
	for (auto i = 0; i < size; ++i) {
		if (max < intarr[i]) {
			max = intarr[i];
		}
	}

	return max;
}
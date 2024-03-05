#include "pch.h"
#include "save.h"

// [Q1] Do not make change in main funtion, make "Change" function
// [Q2] Find Maximum in array c
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
std::uniform_int_distribution uid{ 1000,9999 };

int main(void) {
	save("Source\\main.cpp");

	Dog a{ 1 }, b{ 2 };
	std::cout << a << " , " << b << std::endl;
	change(a, b);
	std::cout << a << " , " << b << std::endl;
	
	int c[10000];

	for (int& num : c) num = uid(dre);

	for (int num : c) std::cout << std::format("{:8}", num);

	std::cout << std::endl << maximum(c, 10000);

}

template<typename T>
void change(T& a, T& b){
	T temp{ a };
	a = b;
	b = temp;
}


int maximum(const int* intarr,int size) {
	int max{ 0 };

	for (auto i = 0; i < size; ++i) {
		if (max < intarr[i]) {
			max = intarr[i];
		}
	}

	return max;
}
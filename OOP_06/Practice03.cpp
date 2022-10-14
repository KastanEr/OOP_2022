#include <iostream>
#include <exception>

class A {
public:
	A() {
		std::cout << "Constructor()\n";
	}
	~A() {
		std::cout << "Destructor()\n";
	}

	int exception() {
		return 10;
	}
};

int main() {
	try {
		A a;
		throw a.exception();
	}
	catch(int i) {
		std::cout << "Catch" << i << std::endl;
	}
}
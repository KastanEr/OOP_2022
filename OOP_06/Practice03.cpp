#include <iostream>
#include <exception>

class A : std::exception{
public:
	A() {
		std::cout << "Constructor()\n";
	}
	~A() {
		std::cout << "Destructor()\n";
	}
	const char* what() { return "10"; }
};

int main() {
	try {
		A a();
		throw a;
	}
	catch(A a) {
		std::cout << "Catch " << a.what() << std::endl;
	}
}
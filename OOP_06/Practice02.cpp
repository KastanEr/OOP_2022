#include <iostream>
#include <string>
#include <exception>

class MyException : public std::exception {
public:
	const char* what() { return "New Exception"; }
};

int main() {
	try {
		throw MyException();
	}
	catch(MyException e) {
		std::cout << "My exception is ";
		std::cout << e.what() << std::endl;
	}
	return 0;
}
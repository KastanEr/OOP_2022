#include <iostream>
#include <string>
#include <exception>

class MyException : public std::exception { // 사용자 정의 Exception
public:
	const char* what() { return "New Exception"; } // 전달할 에러 메세지
};

int main() {
	try {
		throw MyException(); // 예외 throw
	}
	catch(MyException e) {
		std::cout << "My exception is ";
		std::cout << e.what() << std::endl; // 에러 메세지 출력
	}
	return 0;
}
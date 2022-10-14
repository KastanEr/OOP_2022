#include <iostream>

class A {
public:
	A() {
		std::cout << "Constructor()\n"; // 생성자
	}
	~A() {
		std::cout << "Destructor()\n"; // 소멸자
	}
	int exception() { // 10을 리턴하는 메소드
		return 10;
	}
};

int main() {
	try {
		A a; // A 객체 생성
		throw a.exception(); // 함수가 리턴하는 값을 throw
	}
	catch(int i) {
		std::cout << "Catch" << i << std::endl; // throw 한 값을 전달받아 출력
	}
}
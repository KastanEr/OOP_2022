#include <iostream>

class BaseClass { // Base 클래스

public:
	virtual int what() { // Base 클래스를 구분하기위해 0을 리턴하는 함수
		return 0;
	}
};

class DerivedClass : public BaseClass { // Derived 클래스
public:
	int what() { // Derived 클래스를 구분하기위해 1을 리턴하는 함수
		return 1;
	}
};

int main() {
	BaseClass* base = new DerivedClass(); // DerivedClass 객체를 생성하여 BaseClass* 포인터에 할당(다운캐스팅)
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base); // dynamic_cast를 통해 base를 DerivedClass*로 형변환
	if (base != nullptr) { // base 포인터에 객체가 생성되어 할당되있는지 검사
		if (derived != nullptr) { // derived 포인터에 객체가 정상적으로 cast되어 할당되있는지 검사
			std::cout << "Everything is OKAY" << std::endl;
		}
		else {
			std::cout << "Everything is NOT OKAY" << std::endl;
		}
	}
}
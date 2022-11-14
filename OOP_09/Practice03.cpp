#include <iostream>

class BaseClass {

public:
	virtual int what() {
		return 0;
	}
};

class DerivedClass : public BaseClass {
public:
	int what() {
		return 1;
	}
};

int main() {
	BaseClass* base = new DerivedClass();
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base);
	if (base != nullptr) {
		if (derived != nullptr) {
			std::cout << "Everything is OKAY" << std::endl;
		}
		else {
			std::cout << "Everything is NOT OKAY" << std::endl;
		}
	}
}
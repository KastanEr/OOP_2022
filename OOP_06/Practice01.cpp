#include <iostream>

class Class {
private:
	int i;
public:
	Class() : i(5) {}
	int getI() {
		return i;
	}
	int operator ++() {
		i += 1;
		return i;
	}
	int operator ++(int) {
		int tmp = i;
		i += 1;
		return tmp;
	}
};

int main() {
	Class a;
	std::cout << a.getI() << " (초기값),";
	a++;
	std::cout << a.getI() << " (a++ 결과), ";
	++a;
	std::cout << a.getI() << " (++a 결과)" << std::endl;
}
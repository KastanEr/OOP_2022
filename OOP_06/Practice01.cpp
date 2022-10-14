#include <iostream>

class Class {
private:
	int i;
public:
	Class() : i{ 5 } { std::cout << i << " (초기값), "; }
	void operator ++() {
		++i;
		std::cout << i << " (++a 결과), ";
	}
	void operator ++(int) {
		i++;
		std::cout << i << " (a++ 결과), ";
	}
};

int main() {
	Class a;
	a++;
	++a;
}
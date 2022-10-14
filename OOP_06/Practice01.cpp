#include <iostream>

class Class {
private:
	int i;
public:
	Class() : i{ 5 } { std::cout << i << " (�ʱⰪ), "; }
	void operator ++() {
		++i;
		std::cout << i << " (++a ���), ";
	}
	void operator ++(int) {
		i++;
		std::cout << i << " (a++ ���), ";
	}
};

int main() {
	Class a;
	a++;
	++a;
}
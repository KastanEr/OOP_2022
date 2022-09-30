#include <iostream>
class Test {
public:
	Test(int num1, int num2) : num1(num1), num2(num2) {}
	int num1;
	int num2;
	void print() {
		std::cout << "num1 : " << num1 << std::endl;
		std::cout << "num2 : " << num2 << std::endl;
	}
};

int main() {
	Test a = Test(1, 3);
	a.print();
}
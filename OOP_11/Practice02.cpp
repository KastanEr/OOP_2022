#include <iostream>
#include <string>

template <typename T>
void templateSwap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <>
void templateSwap<std::string>(std::string& a, std::string& b) {
	std::string temp = a;
	a = b;
	b = temp;
}

int main() {
	int a = 1;
	int b = 2;
	float c = 3.3;
	float d = 4.4;
	std::string e = "World";
	std::string f = "Hello";
	templateSwap<int>(a, b);
	templateSwap<float>(c, d);
	templateSwap<std::string>(e, f);
	std::cout << "a: " << a << ", b: " << b << std::endl;
	std::cout << "c: " << c << ", d: " << d << std::endl;
	std::cout << "e: " << e << ", f: " << f << std::endl;
	return 0;
}
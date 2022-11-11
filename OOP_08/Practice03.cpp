#include <vector>
#include <string>
#include <iostream>

class Base1 {
public:
	Base1(int n) : vector_(n, 3) { std::cout << "Base1\n";  }
	//.....
private:
	std::vector<char> vector_;
};

class Base2 {
public:
	Base2(int n) : vector_(n, 3) { std::cout << "Base2\n";  }
	//.....
private:
	std::vector<char> vector_;
};

class Derived : public Base2, Base1 {
public:
	Derived(const std::string& str) : Base2(1024), Base1(512)
	{
		i = 0;
		std::cout << "Derived\n";
	}
	// ...
private:
	std::string str_;
	int i = 0;
};
int main() {
	Derived drv("1");
	return 0;
}
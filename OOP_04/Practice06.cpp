#include <iostream>

using namespace std;

class A {
public:
	A() {
		cout << "Constructor A\n";
	}
};

class B {
private:
	A m_a;
public:
	B() {
		cout << "Constructor B";
	}
};

int main() {
	B b;
	return 0;
}
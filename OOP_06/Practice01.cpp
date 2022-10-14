#include <iostream>

class Class {
private:
	int i;
public:
	Class() : i(5) {} // 기본생성자 i값을 5로 초기화
	friend std::ostream& operator <<(std::ostream& out, const Class& a) { // ostream으로 객체의 i값을 전달
		out << a.i;
		return out;
	}
	int operator ++() { // ++i 수행
		i += 1;
		return i;
	}
	int operator ++(int) { // i++ 을 수행
		int tmp = i;
		i += 1;
		return tmp;
	}
};

int main() {
	Class a;
	std::cout << a << " (초기값), ";
	a++;
	std::cout << a << " (a++ 결과), ";
	++a;
	std::cout << a << " (++a 결과)" << std::endl;
}
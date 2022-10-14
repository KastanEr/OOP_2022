#include <iostream>

class Class {
private:
	int i;
public:
	Class() : i(5) {} // �⺻������ i���� 5�� �ʱ�ȭ
	friend std::ostream& operator <<(std::ostream& out, const Class& a) { // ostream���� ��ü�� i���� ����
		out << a.i;
		return out;
	}
	int operator ++() { // ++i ����
		i += 1;
		return i;
	}
	int operator ++(int) { // i++ �� ����
		int tmp = i;
		i += 1;
		return tmp;
	}
};

int main() {
	Class a;
	std::cout << a << " (�ʱⰪ), ";
	a++;
	std::cout << a << " (a++ ���), ";
	++a;
	std::cout << a << " (++a ���)" << std::endl;
}
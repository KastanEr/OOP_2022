#include <iostream>

class A {
public:
	A() {
		std::cout << "Constructor()\n"; // ������
	}
	~A() {
		std::cout << "Destructor()\n"; // �Ҹ���
	}
	int exception() { // 10�� �����ϴ� �޼ҵ�
		return 10;
	}
};

int main() {
	try {
		A a; // A ��ü ����
		throw a.exception(); // �Լ��� �����ϴ� ���� throw
	}
	catch(int i) {
		std::cout << "Catch" << i << std::endl; // throw �� ���� ���޹޾� ���
	}
}
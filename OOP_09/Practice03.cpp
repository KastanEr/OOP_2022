#include <iostream>

class BaseClass { // Base Ŭ����

public:
	virtual int what() { // Base Ŭ������ �����ϱ����� 0�� �����ϴ� �Լ�
		return 0;
	}
};

class DerivedClass : public BaseClass { // Derived Ŭ����
public:
	int what() { // Derived Ŭ������ �����ϱ����� 1�� �����ϴ� �Լ�
		return 1;
	}
};

int main() {
	BaseClass* base = new DerivedClass(); // DerivedClass ��ü�� �����Ͽ� BaseClass* �����Ϳ� �Ҵ�(�ٿ�ĳ����)
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base); // dynamic_cast�� ���� base�� DerivedClass*�� ����ȯ
	if (base != nullptr) { // base �����Ϳ� ��ü�� �����Ǿ� �Ҵ���ִ��� �˻�
		if (derived != nullptr) { // derived �����Ϳ� ��ü�� ���������� cast�Ǿ� �Ҵ���ִ��� �˻�
			std::cout << "Everything is OKAY" << std::endl;
		}
		else {
			std::cout << "Everything is NOT OKAY" << std::endl;
		}
	}
}
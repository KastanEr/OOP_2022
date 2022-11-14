#include <iostream>
#include <cassert>

class CEO { // rank�� 1�� Ŭ����
public:
	virtual int rank() { // rank�� ��ȯ�ϴ� �Լ�
		return 1;
	}
};

class CPO { // rank�� 2�� ��ü
public:
	virtual int rank() { // rank�� ��ȯ�ϴ� �Լ�
		return 2;
	}
};

class Manager : public CEO, public CPO { // rank�� 3�� Ŭ����
public:
	int rank() { // rank�� ��ȯ�ϴ� �Լ�
		return 3;
	}
};

class Staff : public CPO{ // rank�� 4�� Ŭ����
public:
	int rank() { // rank�� ��ȯ�ϴ� �Լ�
		return 4;
	}
};

int main() {
	CPO* cpo = new Manager(); // Manager ��ü�� �����Ͽ� CPO* ������ cpo�� �Ҵ�(�ٿ�ĳ����)
	Staff* staff = dynamic_cast<Staff*>(cpo); // dynamic_cast�� ���� cpo�� Staff*�� ����ȯ
	Manager* manager = dynamic_cast<Manager*>(cpo); // dynamic_cast�� ���� cpo�� Manager*�� ����ȯ
	CEO* ceo = dynamic_cast<CEO*>(cpo); // dynamic_cast�� ���� cpo�� CEO*�� ����ȯ
	assert(typeid(cpo) == typeid(Staff*)); // cpo�� Staff*�� typeid�� ��
	delete cpo; // �����Ҵ�� �޸� ����
	return 0;
}
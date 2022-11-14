#include <iostream>
#include <cassert>

class CEO {
public:
	virtual int rank() {
		return 1;
	}
};

class CPO {
public:
	virtual int rank() {
		return 2;
	}
};

class Manager : public CEO, public CPO {
public:
	int rank() {
		return 3;
	}
};

class Staff : public CPO{
public:
	int rank() {
		return 4;
	}
};

int main() {
	CPO* cpo = new Manager();
	Staff* staff = dynamic_cast<Staff*>(cpo);
	Manager* manager = dynamic_cast<Manager*>(cpo);
	CEO* ceo = dynamic_cast<CEO*>(cpo);
	assert(typeid(cpo) == typeid(Staff*));
	delete cpo;
	return 0;
}
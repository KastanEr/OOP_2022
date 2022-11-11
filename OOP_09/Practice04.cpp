#include <iostream>
#include <cassert>

class CEO {
	int typeID;
public:
	CEO() : typeID(1) {}
	virtual int rank() {
		return typeID;
	}
};

class CPO {
	int typeID;
public:
	CPO() : typeID(2) {}
	virtual int rank() {
		return typeID;
	}
};

class Manager : public CEO, public CPO{
	int typeID;
public:
	Manager() : typeID(3) {}
};

class Staff : public CPO{
	int typeID;
public:
	Staff() : typeID(4) {}
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
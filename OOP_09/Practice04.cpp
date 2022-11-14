#include <iostream>
#include <cassert>

class CEO { // rank가 1인 클래스
public:
	virtual int rank() { // rank를 반환하는 함수
		return 1;
	}
};

class CPO { // rank가 2인 객체
public:
	virtual int rank() { // rank를 반환하는 함수
		return 2;
	}
};

class Manager : public CEO, public CPO { // rank가 3인 클래스
public:
	int rank() { // rank를 반환하는 함수
		return 3;
	}
};

class Staff : public CPO{ // rank가 4인 클래스
public:
	int rank() { // rank를 반환하는 함수
		return 4;
	}
};

int main() {
	CPO* cpo = new Manager(); // Manager 객체를 생성하여 CPO* 포인터 cpo에 할당(다운캐스팅)
	Staff* staff = dynamic_cast<Staff*>(cpo); // dynamic_cast를 통해 cpo를 Staff*로 형변환
	Manager* manager = dynamic_cast<Manager*>(cpo); // dynamic_cast를 통해 cpo를 Manager*로 형변환
	CEO* ceo = dynamic_cast<CEO*>(cpo); // dynamic_cast를 통해 cpo를 CEO*로 형변환
	assert(typeid(cpo) == typeid(Staff*)); // cpo와 Staff*의 typeid값 비교
	delete cpo; // 동적할당된 메모리 해제
	return 0;
}
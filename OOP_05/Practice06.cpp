#include <iostream>

using namespace std;

int returnInt(int a) {
	a += 3;
	cout << "[returnInt]\n&a adress: " << &a << "\na value: " << a << endl;
	return a;
}
int* returnPtInt(int a) {
	return new int[a];
}
int& returnRefInt(int a) {
	int b = 10;
	cout << "[returnRefInt]\n&b adress: " << &b << "\nb value: " << b << endl;
	return b;
}

int i;

class A {
public:
	~A() {
		i = 10;
		cout << "destructor() &i: " << &i << "<< i:" << i << endl;
	}
	/*
	A() {
		i = 10;
		cout << "constructor() &i: " << &i << "<< i: " << i << endl;
	}
	*/
};
int main() {
	int val = returnInt(3);
	cout << "Example 01=========================================\n";
	A ob;
	cout << "인스턴스를 생성했다. \n" << " i : " << i << " & i : " << &i << endl;
	cout << "===================================================\n";
	cout << "Example 01=========================================\n";
	cout << "&val : " << &val << " val : " << val << endl;
	cout << "===================================================\n";

	int* ptVal = returnPtInt(3);
	cout << "Example *==========================================\n";
	cout << "*val : " << ptVal << endl;
	cout << "===================================================\n";

	int refVal = returnRefInt(3);
	cout << "Example 02=========================================\n";
	cout << "&refVal (참조되는 주소값): " << &refVal << endl;
	cout << "refVal : " << refVal << endl;
	cout << "refVal : " << refVal << endl;
	cout << "===================================================\n";

	int& refVal2 = returnRefInt(3);
	cout << "&refVal2 (exam02): " << &refVal2 << " revVal2 : " << refVal2 << endl;
	cout << "===================================================\n";
	val = returnInt(5);
	cout << "&val : " << &val << " val(exam01) : " << val << endl;
	cout << "===================================================\n";
	return 0;
}
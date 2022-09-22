#include<iostream>

class SetValue
{
public:
	int x, y;
};

int main()
{
	SetValue obj; // 클래스이름 객체이름
	obj.x = 33;
	obj.y = 44;
	std::cout << "X= " << obj.x << " , Y= " << obj.y << std::endl;
	system("pause");
	return 0;
}
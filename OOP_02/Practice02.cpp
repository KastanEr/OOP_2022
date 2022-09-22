#include<iostream>

class SetValue
{
	int x, y;
public:
	void setXY(int x, int y) {
		this->x = x;
		this->y = y;
	}

	void show() {
		std::cout << "X = " << x << ", Y = " << y << std::endl;
	}
};

int main()
{
	SetValue obj;
	obj.setXY(33, 44);
	obj.show(); // X, Y 출력 함수 (X 는 x 값, Y 는 y 값)
	system("pause");
	return 0;
}
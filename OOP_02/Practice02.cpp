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
	obj.show(); // X, Y ��� �Լ� (X �� x ��, Y �� y ��)
	system("pause");
	return 0;
}
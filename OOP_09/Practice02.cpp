#include <iostream>

class DrawAPI { // ���� �׸��� �Լ��� ������ Ŭ����
public:
	virtual void drawCircle(int radius, int x, int y) = 0; // drawCircle �Լ� ����
};

class RedCircle : public DrawAPI { // color�� Red�� Circle Ŭ����
public:
	void drawCircle(int radius, int x, int y) { // RedCircle�� �´� �޼����� ����ϵ��� �������̵��� drawCircle �Լ�
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << " ]" << std::endl;
	}
};

class GreenCircle : public DrawAPI { // color�� Green�� Circle Ŭ����
public:
	void drawCircle(int radius, int x, int y) { // GreenCircle�� �´� �޼����� ����ϵ��� �������̵��� drawCircle �Լ�
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << " ]" << std::endl;
	}
};

class Shape { // DrawAPI�� ����ϱ� ���� Ŭ����
protected:
	DrawAPI* drawAPI; // DrawAPI�� ��ü�� ����Ű�� ���� ������
	Shape(DrawAPI* drawAPI) {
		this->drawAPI = drawAPI;
	}
	~Shape() {
		delete drawAPI;
	}
public:
	virtual void draw() = 0; // draw �Լ��� ����
};

class Circle : public Shape { // Circle�� ��Ÿ���� Ŭ����
private:
	int x, y, radius; // ������ ��ǥ, ������

public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI){
		this->x = x;
		this->y = y;
		this->radius = radius;
	}

	void draw() { // DrawAPI�� ���ؼ� Circle�� �׸��� �Լ�
		drawAPI->drawCircle(radius, x, y);
	}
};

int main() {
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle()); // RedCircle�� ���ڷ� �����Ͽ� Shape ��ü�� ����
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle()); // GreenCircle�� ���ڷ� �����Ͽ� Shape ��ü�� ����

	// draw �Լ��� ȣ���Ͽ� �޼��� ���
	redCircle->draw();
	greenCircle->draw();
}
#include <iostream>
#include <memory>

using namespace std;

/* Shape�� �����ϴ� �������̽� */
struct Shape {
	virtual void draw() = 0; // ������ �׸��� �Լ�
};

/* Shape�� �����ϴ� Rectangle Ŭ���� */
class Rectangle : public Shape { 
public:
	void draw() override { // Rectangle Ŭ������ �°� draw�� �������̵�
		cout << "Shape: Rectangle\n";
	}
};

/* Shape�� �����ϴ� Circle Ŭ���� */
class Circle : public Shape {
public:
	void draw() override { // Circle Ŭ������ �°� draw�� �������̵�
		cout << "Shape: Circle\n";
	}
};

/* ���� ��ü�� ���ο� ����� �߰��ϱ� ���� Decorator Ŭ���� */
class ShapeDecorator : public Shape {
protected:
	unique_ptr<Shape> decoratedShape; // ���� ��ü�� ����Ű�� ������
public:
	ShapeDecorator(Shape* decoratedShape) { // ������
		this->decoratedShape = unique_ptr<Shape>(decoratedShape);
	}

	void draw() { // ���� ��ü�� draw �Լ��� ȣ��
		decoratedShape->draw();
	}
};

/* ShapeDecorator�� ��ӹ޾Ƽ� ���� ��ü�� ���� ������ �߰��ϴ� Ŭ���� */
class RedShapeDecorator : public ShapeDecorator { 
private:
	void setRedBorder(Shape* decoratedShape) { // �� ������ ���������� ����
		cout << "Border Color: Red\n";
	}
public:
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) { } // ������

	void draw() override { // ShapeDecorator�� draw �Լ��� �������̵�
		decoratedShape->draw(); // ���� ��ü�� draw �Լ��� ȣ��
		setRedBorder(decoratedShape.get()); // ���� ��ü�� �߰��� ���ο� ����� ����
	}
};

int main() {
	/* Shape ��ü ���� */
	Shape* circle = new Circle(); // �Ϲ� Circle ��ü
	Shape* redCircle = new RedShapeDecorator(new Circle()); // Red border�� ������ Circle ��ü
	Shape* redRectangle = new RedShapeDecorator(new Rectangle()); // Red border�� ������ Rectangle ��ü
	cout << "Circle with normal border\n";
	circle->draw();
	cout << "\nCircle of red border\n";
	redCircle->draw();
	cout << "\nRectangle of red border\n";
	redRectangle->draw();
	/* �޸� ȸ�� */
	delete circle;
	delete redCircle;
	delete redRectangle;
}

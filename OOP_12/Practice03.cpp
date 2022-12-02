#include <iostream>
#include <memory>

using namespace std;

struct Shape {
	virtual void draw() = 0;
};

class Rectangle : public Shape {
public:
	void draw() override {
		cout << "Shape: Rectangle\n";
	}
};

class Circle : public Shape {
public:
	void draw() override {
		cout << "Shape: Circle\n";
	}
};

class ShapeDecorator : public Shape {
protected:
	shared_ptr<Shape> decoratedShape;
public:
	ShapeDecorator(Shape* decoratedShape) {
		this->decoratedShape = shared_ptr<Shape>(decoratedShape);
	}

	void draw() {
		decoratedShape->draw();
	}
};

class RedShapeDecorator : public ShapeDecorator {
private:
	void setRedBorder(Shape* decoratedShape) {
		cout << "Border Color: Red\n";
	}
public:
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) { }

	void draw() override {
		decoratedShape->draw();
		setRedBorder(decoratedShape.get());
	}
};

int main() {
	Shape* circle = new Circle();
	Shape* redCircle = new RedShapeDecorator(new Circle());
	Shape* redRectangle = new RedShapeDecorator(new Rectangle());
	cout << "Circle with normal border\n";
	circle->draw();
	cout << "\nCircle of red border\n";
	redCircle->draw();
	cout << "\nRectangle of red border\n";
	redRectangle->draw();
	delete circle;
	delete redCircle;
	delete redRectangle;
}

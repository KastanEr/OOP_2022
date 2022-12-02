#include <iostream>
#include <memory>

using namespace std;

/* Shape를 정의하는 인터페이스 */
struct Shape {
	virtual void draw() = 0; // 도형을 그리는 함수
};

/* Shape를 구현하는 Rectangle 클래스 */
class Rectangle : public Shape { 
public:
	void draw() override { // Rectangle 클래스에 맞게 draw를 오버라이딩
		cout << "Shape: Rectangle\n";
	}
};

/* Shape를 구현하는 Circle 클래스 */
class Circle : public Shape {
public:
	void draw() override { // Circle 클래스에 맞게 draw를 오버라이딩
		cout << "Shape: Circle\n";
	}
};

/* 기존 객체에 새로운 기능을 추가하기 위한 Decorator 클래스 */
class ShapeDecorator : public Shape {
protected:
	unique_ptr<Shape> decoratedShape; // 기존 객체를 가리키는 포인터
public:
	ShapeDecorator(Shape* decoratedShape) { // 생성자
		this->decoratedShape = unique_ptr<Shape>(decoratedShape);
	}

	void draw() { // 기존 객체의 draw 함수를 호출
		decoratedShape->draw();
	}
};

/* ShapeDecorator를 상속받아서 기존 객체에 선의 색깔을 추가하는 클래스 */
class RedShapeDecorator : public ShapeDecorator { 
private:
	void setRedBorder(Shape* decoratedShape) { // 선 색깔을 빨간색으로 설정
		cout << "Border Color: Red\n";
	}
public:
	RedShapeDecorator(Shape* decoratedShape) : ShapeDecorator(decoratedShape) { } // 생성자

	void draw() override { // ShapeDecorator의 draw 함수를 오버라이딩
		decoratedShape->draw(); // 기존 객체의 draw 함수를 호출
		setRedBorder(decoratedShape.get()); // 기존 객체에 추가한 새로운 기능을 수행
	}
};

int main() {
	/* Shape 객체 생성 */
	Shape* circle = new Circle(); // 일반 Circle 객체
	Shape* redCircle = new RedShapeDecorator(new Circle()); // Red border를 가지는 Circle 객체
	Shape* redRectangle = new RedShapeDecorator(new Rectangle()); // Red border를 가지는 Rectangle 객체
	cout << "Circle with normal border\n";
	circle->draw();
	cout << "\nCircle of red border\n";
	redCircle->draw();
	cout << "\nRectangle of red border\n";
	redRectangle->draw();
	/* 메모리 회수 */
	delete circle;
	delete redCircle;
	delete redRectangle;
}

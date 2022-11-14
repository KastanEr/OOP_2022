#include <iostream>

class Shape { // 도형을 나타내는 인터페이스
public:
	virtual void draw() = 0; // 도형 출력
};

class RoudedRectangle : public Shape { // RoundedRactangle 클래스
public:
	void draw() { // RoundedRactangle에 맞는 맞는 메세지를 출력하는 draw 함수
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape { //RoundedSquare 클래스
public:
	void draw() { // RoundedSquare에 맞는 맞는 메세지를 출력하는 draw 함수
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class Rectangle : public Shape { // Rectangle 클래스
public:
	void draw() { // Rectangle에 맞는 메세지를 출력하는 draw 함수
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape { // Square 클래스
public:
	void draw() { // Square에 맞는 메세지를 출력하는 draw 함수
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class AbstractFactory { // Shape를 만들어내는 가상 Factory클래스
public:
	virtual Shape* getShape(const char* shapeType) = 0; // getShape 함수의 원형
};

class ShapeFactory : public AbstractFactory { // 일반 Shape 클래스를 위한 Factory 클래스
public:
	Shape* getShape(const char* shapeType) { // shapeType에 따라 Ractangle, Square 객체를 반환하는 함수
		if (!_stricmp(shapeType, "RECTANGLE")) {
			return new Rectangle;
		}
		else if (!_stricmp(shapeType, "SQUARE")) {
			return new Square;
		}
		return NULL;
	}
};

class RoundedShpaeFactory : public AbstractFactory { // RoundedShape 클래스를 위한 Factory 클래스
public:
	Shape* getShape(const char* shapeType) { // shapeType에 따라 RoundedRactangle, RoundedSquare 객체를 반환하는 함수
		if (!_stricmp(shapeType, "RECTANGLE")) {
			return new RoudedRectangle;
		}
		else if (!_stricmp(shapeType, "SQUARE")) {
			return new RoundedSquare;
		}
		return NULL;
	}
};

class FactoryProducer { // Factory 객체를 만들어내는 클래스
public:
	static AbstractFactory* getFactory(bool rounded) { // rounded 인자에 따라 RoundedShpaeFactory, ShapeFactory 객체를 반환하는 함수
		if (rounded) {
			return new RoundedShpaeFactory;
		}
		else {
			return new ShapeFactory;
		}
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false); // rounded가 false 인 AbstractFactory 객체 생성

	Shape* shape1 = shapeFactory->getShape("RECTANGLE"); //shapeType이 "RECTANGLE"인 객체를 생성
	shape1->draw(); // Ractangle 출력

	Shape* shape2 = shapeFactory->getShape("SQUARE"); //shapeType이 "SQUARE"인 객체를 생성
	shape2->draw(); // Square 출력

	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true); // rounded가 true 인 AbstractFactory 객체 생성

	Shape* shape3 = shapeFactory1->getShape("RECTANGLE"); //shapeType이 "RECTANGLE"인 객체를 생성
	shape3->draw(); // RoundedRactangle 출력

	Shape* shape4 = shapeFactory1->getShape("SQUARE"); //shapeType이 "SQUARE"인 객체를 생성
	shape4->draw(); // RoundedSquare 출력

	// 동적할당한 메모리 해제
	delete shapeFactory;
	delete shapeFactory1;
	delete shape1;
	delete shape2;
	delete shape3;
	delete shape4;

	return 0;
}

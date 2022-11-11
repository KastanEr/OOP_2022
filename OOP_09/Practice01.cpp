#include <iostream>
#include <string>

class Shape {
public:
	virtual void draw() = 0;
};

class RoudedRectangle : public Shape {
public:
	void draw() {
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape {
public:
	void draw() {
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class Rectangle : public Shape {
public:
	void draw() {
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape {
public:
	void draw() {
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class AbstractFactory {
public:
	virtual Shape* getShape(const char* shapeType) = 0;
};

class ShapeFactory : public AbstractFactory {
public:
	Shape* getShape(const char* shapeType) {
		if (!strcmp(shapeType, "RECTANGLE")) {
			return new Rectangle;
		}
		else if (!strcmp(shapeType, "SQUARE")) {
			return new Square;
		}
		return NULL;
	}
};

class RoundedShpaeFactory : public AbstractFactory {
public:
	Shape* getShape(const char* shapeType) {
		if (!strcmp(shapeType, "RECTANGLE")) {
			return new RoudedRectangle;
		}
		else if (!strcmp(shapeType, "SQUARE")) {
			return new RoundedSquare;
		}
		return NULL;
	}
};

class FactoryProducer {
public:
	static AbstractFactory* getFactory(bool rounded) {
		if (rounded) {
			return new RoundedShpaeFactory;
		}
		else {
			return new ShapeFactory;
		}
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false);

	Shape* shape1 = shapeFactory->getShape("RECTANGLE");
	shape1->draw();

	Shape* shape2 = shapeFactory->getShape("SQUARE");
	shape2->draw();

	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true);

	Shape* shape3 = shapeFactory1->getShape("RECTANGLE");
	shape3->draw();

	Shape* shape4 = shapeFactory1->getShape("SQUARE");
	shape4->draw();

	delete shapeFactory;
	delete shapeFactory1;
	delete shape1;
	delete shape2;
	delete shape3;
	delete shape4;

	
	return 0;
}

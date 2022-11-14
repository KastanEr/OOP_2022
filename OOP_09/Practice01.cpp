#include <iostream>

class Shape { // ������ ��Ÿ���� �������̽�
public:
	virtual void draw() = 0; // ���� ���
};

class RoudedRectangle : public Shape { // RoundedRactangle Ŭ����
public:
	void draw() { // RoundedRactangle�� �´� �´� �޼����� ����ϴ� draw �Լ�
		std::cout << "Inside RoundedRectangle::draw() method." << std::endl;
	}
};

class RoundedSquare : public Shape { //RoundedSquare Ŭ����
public:
	void draw() { // RoundedSquare�� �´� �´� �޼����� ����ϴ� draw �Լ�
		std::cout << "Inside RoundedSquare::draw() method." << std::endl;
	}
};

class Rectangle : public Shape { // Rectangle Ŭ����
public:
	void draw() { // Rectangle�� �´� �޼����� ����ϴ� draw �Լ�
		std::cout << "Inside Rectangle::draw() method." << std::endl;
	}
};

class Square : public Shape { // Square Ŭ����
public:
	void draw() { // Square�� �´� �޼����� ����ϴ� draw �Լ�
		std::cout << "Inside Square::draw() method." << std::endl;
	}
};

class AbstractFactory { // Shape�� ������ ���� FactoryŬ����
public:
	virtual Shape* getShape(const char* shapeType) = 0; // getShape �Լ��� ����
};

class ShapeFactory : public AbstractFactory { // �Ϲ� Shape Ŭ������ ���� Factory Ŭ����
public:
	Shape* getShape(const char* shapeType) { // shapeType�� ���� Ractangle, Square ��ü�� ��ȯ�ϴ� �Լ�
		if (!_stricmp(shapeType, "RECTANGLE")) {
			return new Rectangle;
		}
		else if (!_stricmp(shapeType, "SQUARE")) {
			return new Square;
		}
		return NULL;
	}
};

class RoundedShpaeFactory : public AbstractFactory { // RoundedShape Ŭ������ ���� Factory Ŭ����
public:
	Shape* getShape(const char* shapeType) { // shapeType�� ���� RoundedRactangle, RoundedSquare ��ü�� ��ȯ�ϴ� �Լ�
		if (!_stricmp(shapeType, "RECTANGLE")) {
			return new RoudedRectangle;
		}
		else if (!_stricmp(shapeType, "SQUARE")) {
			return new RoundedSquare;
		}
		return NULL;
	}
};

class FactoryProducer { // Factory ��ü�� ������ Ŭ����
public:
	static AbstractFactory* getFactory(bool rounded) { // rounded ���ڿ� ���� RoundedShpaeFactory, ShapeFactory ��ü�� ��ȯ�ϴ� �Լ�
		if (rounded) {
			return new RoundedShpaeFactory;
		}
		else {
			return new ShapeFactory;
		}
	}
};

int main() {
	AbstractFactory* shapeFactory = FactoryProducer::getFactory(false); // rounded�� false �� AbstractFactory ��ü ����

	Shape* shape1 = shapeFactory->getShape("RECTANGLE"); //shapeType�� "RECTANGLE"�� ��ü�� ����
	shape1->draw(); // Ractangle ���

	Shape* shape2 = shapeFactory->getShape("SQUARE"); //shapeType�� "SQUARE"�� ��ü�� ����
	shape2->draw(); // Square ���

	AbstractFactory* shapeFactory1 = FactoryProducer::getFactory(true); // rounded�� true �� AbstractFactory ��ü ����

	Shape* shape3 = shapeFactory1->getShape("RECTANGLE"); //shapeType�� "RECTANGLE"�� ��ü�� ����
	shape3->draw(); // RoundedRactangle ���

	Shape* shape4 = shapeFactory1->getShape("SQUARE"); //shapeType�� "SQUARE"�� ��ü�� ����
	shape4->draw(); // RoundedSquare ���

	// �����Ҵ��� �޸� ����
	delete shapeFactory;
	delete shapeFactory1;
	delete shape1;
	delete shape2;
	delete shape3;
	delete shape4;

	return 0;
}

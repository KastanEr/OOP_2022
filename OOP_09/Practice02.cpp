#include <iostream>

class DrawAPI { // 원을 그리는 함수를 선언한 클래스
public:
	virtual void drawCircle(int radius, int x, int y) = 0; // drawCircle 함수 선언
};

class RedCircle : public DrawAPI { // color가 Red인 Circle 클래스
public:
	void drawCircle(int radius, int x, int y) { // RedCircle에 맞는 메세지를 출력하도록 오버라이딩한 drawCircle 함수
		std::cout << "Drawing Circle[ color: red, radius: " << radius << ", x: " << x << ", " << y << " ]" << std::endl;
	}
};

class GreenCircle : public DrawAPI { // color가 Green인 Circle 클래스
public:
	void drawCircle(int radius, int x, int y) { // GreenCircle에 맞는 메세지를 출력하도록 오버라이딩한 drawCircle 함수
		std::cout << "Drawing Circle[ color: green, radius: " << radius << ", x: " << x << ", " << y << " ]" << std::endl;
	}
};

class Shape { // DrawAPI를 사용하기 위한 클래스
protected:
	DrawAPI* drawAPI; // DrawAPI형 객체를 가리키기 위한 포인터
	Shape(DrawAPI* drawAPI) {
		this->drawAPI = drawAPI;
	}
	~Shape() {
		delete drawAPI;
	}
public:
	virtual void draw() = 0; // draw 함수를 선언
};

class Circle : public Shape { // Circle을 나타내는 클래스
private:
	int x, y, radius; // 중점의 좌표, 반지름

public:
	Circle(int x, int y, int radius, DrawAPI* drawAPI) : Shape(drawAPI){
		this->x = x;
		this->y = y;
		this->radius = radius;
	}

	void draw() { // DrawAPI를 통해서 Circle을 그리는 함수
		drawAPI->drawCircle(radius, x, y);
	}
};

int main() {
	Shape* redCircle = new Circle(100, 100, 10, new RedCircle()); // RedCircle을 인자로 전달하여 Shape 객체를 생성
	Shape* greenCircle = new Circle(100, 100, 10, new GreenCircle()); // GreenCircle을 인자로 전달하여 Shape 객체를 생성

	// draw 함수를 호출하여 메세지 출력
	redCircle->draw();
	greenCircle->draw();
}
#include <vector>
#include <iostream>

/* Factory 패턴 미적용 */
//class Car
//{
//public:
//	virtual void echoName() = 0;
//};
//
//class Sonata : public Car
//{
//public:
//	void echoName()
//	{
//		std::cout << "I'm Sonata!" << std::endl;
//	}
//};
//
//class Malibu : public Car
//{
//public:
//	void echoName()
//	{
//		std::cout << "I'm Malibu!" << std::endl;
//	}
//};
//
//class Spark : public Car
//{
//public:
//	void echoName()
//	{
//		std::cout << "I'm Spark!" << std::endl;
//	}
//};
//
//int main() //클라이언트 프로그램
//{
//	std::vector<Car*> carCollection;
//	int choice;
//	while (true)
//	{
//		std::cout << "Choice: (Sonata:1, Malibu:2, Sparck:3, Done:0): ";
//		std::cin >> choice;
//		if (choice == 0)
//			break;
//		else if (choice == 1)
//			carCollection.push_back(new Sonata);
//		else if (choice == 2)
//			carCollection.push_back(new Malibu);
//		else
//			carCollection.push_back(new Spark);
//	}
//	for (int i = 0; i < carCollection.size(); i++)
//		carCollection[i]->echoName();
//	for (int i = 0; i < carCollection.size(); i++)
//		delete carCollection[i];
//	return 0;
//}

/* Factory 패턴 적용 */
// 객체를 만들어 반환하는 함수를 제공하여 초기화 과정을 외부에서 보지 못하게 숨기고 반환 타입을 제어
class Car
{
public:
	static Car* produceCar(int choice); // Factory Method
	virtual void echoName() = 0;
};

class Sonata : public Car
{
public:
	void echoName()
	{
		std::cout << "I'm Sonata!" << std::endl;
	}
};

class Malibu : public Car
{
public:
	void echoName()
	{
		std::cout << "I'm Malibu!" << std::endl;
	}
};

class Spark : public Car
{
public:
	void echoName()
	{
		std::cout << "I'm Spark!" << std::endl;
	}
};

Car* Car::produceCar(int choice) {
	if (choice == 1)
		return new Sonata;
	else if (choice == 2)
		return new Malibu;
	else
		return new Spark;
}

int main()
{
	std::vector<Car*> carCollection;
	int choice;
	while (true)
	{
		std::cout << "Choice: (Sonata:1, Malibu:2, Sparck:3, Done:0): ";
		std::cin >> choice;
		if (choice == 0)
			break;
		carCollection.push_back(Car::produceCar(choice));
	}
	for (int i = 0; i < carCollection.size(); i++)
		carCollection[i]->echoName();
	for (int i = 0; i < carCollection.size(); i++)
		delete carCollection[i];
	return 0;
}
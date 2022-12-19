#include <vector>
#include <iostream>

/* Factory ���� ������ */
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
//int main() //Ŭ���̾�Ʈ ���α׷�
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

/* Factory ���� ���� */
// ��ü�� ����� ��ȯ�ϴ� �Լ��� �����Ͽ� �ʱ�ȭ ������ �ܺο��� ���� ���ϰ� ����� ��ȯ Ÿ���� ����
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
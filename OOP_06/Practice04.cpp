#include <iostream>
#include <string>

using namespace std;

class Person { // base class
private:
	string name; // �̸�
	int age; // ����
	string address; // �ּ�
public:
	Person(string name, int age, string address) : name(name), age(age), address(address) {} // �̸�, ����, �ּҸ� �ʱ�ȭ�ϴ� ������
	string getName() { // �̸��� ��ȯ
		return this->name;
	}
	string getAddress() { // �ּҸ� ��ȯ
		return this->address;
	}
	int getAge() { // ���̸� ��ȯ
		return this->age;
	}
};

class Student : public Person { // Person�� ��ӹ޴� drive class
private:
	int studentID; // �й�
public:
	Student(string name, int age, string address, int studentID) : Person(name, age, address), studentID(studentID) {} // �̸�, ����, �ּ�, �й��� �ʱ�ȭ�ϴ� ������
	int getStudentID() { // �й��� ��ȯ
		return studentID;
	}
};

int main() {
	Student s("������", 23, "deajeon", 201902672);
	cout << "Student Information\nName : " << s.getName() << "\nAge : " << s.getAge() << "\nAddress : " << s.getAddress() << "\nStudent ID : " << s.getStudentID() << endl;
}
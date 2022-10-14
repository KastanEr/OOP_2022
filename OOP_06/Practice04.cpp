#include <iostream>
#include <string>

using namespace std;

class Person { // base class
private:
	string name; // 이름
	int age; // 나이
	string address; // 주소
public:
	Person(string name, int age, string address) : name(name), age(age), address(address) {} // 이름, 나이, 주소를 초기화하는 생성자
	string getName() { // 이름을 반환
		return this->name;
	}
	string getAddress() { // 주소를 반환
		return this->address;
	}
	int getAge() { // 나이를 반환
		return this->age;
	}
};

class Student : public Person { // Person을 상속받는 drive class
private:
	int studentID; // 학번
public:
	Student(string name, int age, string address, int studentID) : Person(name, age, address), studentID(studentID) {} // 이름, 나이, 주소, 학번을 초기화하는 생성자
	int getStudentID() { // 학번을 반환
		return studentID;
	}
};

int main() {
	Student s("김윤섭", 23, "deajeon", 201902672);
	cout << "Student Information\nName : " << s.getName() << "\nAge : " << s.getAge() << "\nAddress : " << s.getAddress() << "\nStudent ID : " << s.getStudentID() << endl;
}
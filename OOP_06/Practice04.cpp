#include <iostream>
#include <string>

using namespace std;

class Person {
private:
	string name;
	int age;
	string address;
public:
	Person(string name, int age, string address) : name(name), age(age), address(address) {}
	string getName() {
		return this->name;
	}
	string getAddress() {
		return this->address;
	}
	int getAge() {
		return this->age;
	}
};

class Student : public Person {
private:
	int studentID;
public:
	Student(string name, int age, string address, int studentID) : Person(name, age, address) {
		this->studentID = studentID;
	}
	int getStudentID() {
		return studentID;
	}
};

int main() {
	Student s("±Ë¿±º∑", 23, "¡ﬂ±∏", 201902672);
	cout << "Name : " << s.getName() << "\nAge : " << s.getAge() << "\nAddress : " << s.getAddress() << "\nStudent ID : " << s.getStudentID() << endl;
}
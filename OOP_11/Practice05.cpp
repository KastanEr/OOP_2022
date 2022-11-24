#include <iostream>
#include <string>

using namespace std;


class Student {
	string rollNo;
	string name;
public:
	string getRollNo() const {
		return this->rollNo;
	}
	void setRollNo(string rollNo) {
		this->rollNo = rollNo;
	}
	string getName() const {
		return this->name;
	}
	void setName(string name) {
		this->name = name;
	}
};

class StudentView {
public:
	void printStudentDetails(string studentName, string studentRollNo) const {
		cout << "Student: " << endl;
		cout << "Name: " << studentName << endl;
		cout << "Roll No :" << studentRollNo << endl;
	}
};

class StudentController {
	Student model;
	StudentView view;
public:
	StudentController(Student model, StudentView view) {
		this->model = model;
		this->view = view;
	}
	void setStudentName(string name) {
		model.setName(name);
	}
	string getStudentName() const {
		return model.getName();
	}
	void setStudnetRollNo(string rollNo) {
		model.setRollNo(rollNo);
	}
	string getStudnetRollNo() const {
		return model.getRollNo();
	}
	void updateView() const {
		view.printStudentDetails(model.getName(), model.getRollNo());
	}
};

Student retriveStudentFromDatabase() {
	Student student;
	student.setName("Robert");
	student.setRollNo("10");
	return student;
}

int main() {
	Student model = retriveStudentFromDatabase();
	StudentView view;
	StudentController controller(model, view);
	controller.updateView();
	controller.setStudentName("John");
	controller.updateView();
}
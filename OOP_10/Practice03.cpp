#include <iostream>
#include <vector>
#include <bitset>
#include <string>

using namespace std;

string toBinary(int n)
{
	string r;
	while (n != 0) {
		r = (n % 2 == 0 ? "0" : "1") + r;
		n /= 2;
	}
	return r;
}
class Observer;

class Subject {
	vector<Observer*> observers;
	int state;
public:
	int getState() const {
		return state;
	}
	void setState(int state) {
		this->state = state;
		notifyAllObservers();
	}
	void attach(Observer* observer) {
		observers.push_back(observer);
	}

	void notifyAllObservers();
};

class Observer {
protected:
	Subject* subject;
public:
	virtual void update() = 0;
};

void Subject::notifyAllObservers() {
	for (vector<Observer*>::iterator itr = observers.begin(); itr != observers.end(); ++itr) {
		(*itr)->update();
	}
}

class BinaryObserver : public Observer {
public:
	BinaryObserver(Subject* subject) {
		this->subject = subject;
		this->subject->attach(this);
	}
	void update() override {
		cout << "Binary String: " << toBinary(subject->getState()) << endl;
	}
};

class OctalObserver : public Observer {
public:
	OctalObserver(Subject* subject) {
		this->subject = subject;
		this->subject->attach(this);
	}
	void update() override {
		cout << oct;
		cout << "Octal String: " << subject->getState() << endl;
	}
};

class HexaObserver : public Observer {
public:
	HexaObserver(Subject* subject) {
		this->subject = subject;
		this->subject->attach(this);
	}
	void update() override {
		cout << hex;
		cout << "Hex String: " << subject->getState() << endl;
	}
};

int main() {
	Subject subject;

	HexaObserver hex(&subject);
	OctalObserver oct(&subject);
	BinaryObserver bin(&subject);

	cout << "Frist state change: 15" << endl;
	subject.setState(15);
	cout << "Second state change: 10" << endl;
	subject.setState(10);
}


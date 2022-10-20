#include <iostream>

#define interface struct

interface Strategy {
	virtual int doOperation(int num1, int num2) = 0;
};

class OperationAdd : public Strategy {
public:
	int doOperation(int num1, int num2) {
		return (num1 + num2);
	}
};

class OperationSubstract : public Strategy {
public:
	int doOperation(int num1, int num2) {
		return (num1 - num2);
	}
};

class OperationMultiply : public Strategy {
public:
	int doOperation(int num1, int num2) {
		return (num1 * num2);
	}
};

class Context {
	Strategy* strategy;
public:
	Context(Strategy* strategy) {
		this->strategy = strategy;
	}
	~Context() {
		delete strategy;
	}
	int excuteStrategy(int num1, int num2) {
		return strategy->doOperation(num1, num2);
	}
};

int main() {
	Context* context = new Context(new OperationAdd);
	std::cout << "10 + 5 = " << context->excuteStrategy(10, 5) << std::endl;
	delete context;
	context = new Context(new OperationSubstract);
	std::cout << "10 - 5 = " << context->excuteStrategy(10, 5) << std::endl;
	delete context;
	context = new Context(new OperationMultiply);
	std::cout << "10 * 5 = " << context->excuteStrategy(10, 5) << std::endl;
	delete context;
	return 0;
}
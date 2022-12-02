#include <iostream>

using namespace std;

/* T Ÿ�� ���ڸ� �޾Ƽ� int������ �����ϴ� �Լ� */
template <typename T>
int sum(T x) {
	return x;
}

/* ���ø��� �̿��� �������ڸ� �޾Ƽ� ��������� ���� ����ϴ� �Լ� */
template <typename T, typename... Args>
int sum(T x, Args... args) {
	return x + sum(args...); // sum(args...)���� int sum(T x, Args... args) �Լ��� ��������� ȣ��
}

/* ���ø��� �̿��� �������ڸ� �޾Ƽ� sum �Լ��� �հ踦 ����Ͽ� ������ ������ ������ ����� ��� */
template<typename... Args>
double average(Args... args) {
	return (double)sum(args...) / sizeof...(args);
}

int main() {
	cout << average(1, 2, 3, 4, 10, 10) << std::endl;
	return 0;
}
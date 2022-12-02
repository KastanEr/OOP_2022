#include <iostream>

using namespace std;

/* T 타입 인자를 받아서 int형으로 리턴하는 함수 */
template <typename T>
int sum(T x) {
	return x;
}

/* 템플릿을 이용해 다중인자를 받아서 재귀적으로 합을 계산하는 함수 */
template <typename T, typename... Args>
int sum(T x, Args... args) {
	return x + sum(args...); // sum(args...)으로 int sum(T x, Args... args) 함수를 재귀적으로 호출
}

/* 템플릿을 이용해 다중인자를 받아서 sum 함수로 합계를 계산하여 인자의 개수로 나누어 평균을 계산 */
template<typename... Args>
double average(Args... args) {
	return (double)sum(args...) / sizeof...(args);
}

int main() {
	cout << average(1, 2, 3, 4, 10, 10) << std::endl;
	return 0;
}
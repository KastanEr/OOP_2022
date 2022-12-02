#include <iostream>
#include <algorithm>
#include <forward_list>

/* 버블 정렬을 수행하는 함수 */
template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	auto end = last; // 정렬을 수행할 구간의 끝을 나타냄
	for (auto i = first; i != last; ++i) {
		for (auto j = first; j != end; ++j) {
			auto prev = j++; // 이전 원소의 포인터를 저장하고 j값을 증가
			if (j == end) { // 한 스테이지를 끝냈을 경우 진입
				end = prev; // 정렬을 수행할 구간을 한칸 줄임
				break;
			}
			if (comp(*prev, *j)) {
				std::iter_swap(prev, j); // prev가 가리키는 값이 더 크면 둘의 위치를 스왑
			}
			j = prev; // for문에 의해서 반복자가 두번 증가하는 것을 방지
		}
	}
}

class compGreater { // 오름차순 정렬에 사용하는 Functor
public:
	/* () 연산자를 오버로딩해 x > y의 결과를 리턴*/
	bool operator() (int x, int y) const {
		return x > y;
	}
};

class compLess { // 내림차순 정렬에 사용하는 Functor
public:
	/* () 연산자를 오버로딩해 x > y의 결과를 리턴*/
	bool operator() (int x, int y) const {
		return x < y;
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 }; // 정렬할 리스트 생성

	std::cout << "오름차순 정렬" << std::endl;
	std::forward_list<int>::iterator itf = values.begin(); // 리스트의 처음을 가리키는 반복자
	std::forward_list<int>::iterator itl = values.end(); // 리스트의 끝을 가리키는 반복자
	/* forward_list 반복자와 오름차순으로 정렬하는 버블 정렬 실행 */
	bubble_sort<std::forward_list<int>::iterator, compGreater>(itf, itl, compGreater());
	/* 정렬된 리스트의 원소 출력 */
	for (auto i = itf; i != itl; ++i) {
		std::cout << " " << *i;
	}
	std::cout << std::endl;

	std::cout << "내림차순 정렬" << std::endl;
	/* forward_list 반복자와 내림차순으로 정렬하는 버블 정렬 실행 */
	bubble_sort<std::forward_list<int>::iterator, compLess>(itf, itl, compLess());
	/* 정렬된 리스트의 원소 출력 */
	for (auto i = itf; i != itl; ++i) {
		std::cout << " " << *i;
	}
	std::cout << std::endl;
	return 0;
}
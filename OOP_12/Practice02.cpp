#include <iostream>
#include <algorithm>
#include <forward_list>

/* ���� ������ �����ϴ� �Լ� */
template <typename ForwardIterator, typename Compare>
void bubble_sort(ForwardIterator first, ForwardIterator last, Compare comp) {
	auto end = last; // ������ ������ ������ ���� ��Ÿ��
	for (auto i = first; i != last; ++i) {
		for (auto j = first; j != end; ++j) {
			auto prev = j++; // ���� ������ �����͸� �����ϰ� j���� ����
			if (j == end) { // �� ���������� ������ ��� ����
				end = prev; // ������ ������ ������ ��ĭ ����
				break;
			}
			if (comp(*prev, *j)) {
				std::iter_swap(prev, j); // prev�� ����Ű�� ���� �� ũ�� ���� ��ġ�� ����
			}
			j = prev; // for���� ���ؼ� �ݺ��ڰ� �ι� �����ϴ� ���� ����
		}
	}
}

class compGreater { // �������� ���Ŀ� ����ϴ� Functor
public:
	/* () �����ڸ� �����ε��� x > y�� ����� ����*/
	bool operator() (int x, int y) const {
		return x > y;
	}
};

class compLess { // �������� ���Ŀ� ����ϴ� Functor
public:
	/* () �����ڸ� �����ε��� x > y�� ����� ����*/
	bool operator() (int x, int y) const {
		return x < y;
	}
};

int main() {
	std::forward_list<int> values{ 7, 0, 6, 1, 5, 2, 4, 3 }; // ������ ����Ʈ ����

	std::cout << "�������� ����" << std::endl;
	std::forward_list<int>::iterator itf = values.begin(); // ����Ʈ�� ó���� ����Ű�� �ݺ���
	std::forward_list<int>::iterator itl = values.end(); // ����Ʈ�� ���� ����Ű�� �ݺ���
	/* forward_list �ݺ��ڿ� ������������ �����ϴ� ���� ���� ���� */
	bubble_sort<std::forward_list<int>::iterator, compGreater>(itf, itl, compGreater());
	/* ���ĵ� ����Ʈ�� ���� ��� */
	for (auto i = itf; i != itl; ++i) {
		std::cout << " " << *i;
	}
	std::cout << std::endl;

	std::cout << "�������� ����" << std::endl;
	/* forward_list �ݺ��ڿ� ������������ �����ϴ� ���� ���� ���� */
	bubble_sort<std::forward_list<int>::iterator, compLess>(itf, itl, compLess());
	/* ���ĵ� ����Ʈ�� ���� ��� */
	for (auto i = itf; i != itl; ++i) {
		std::cout << " " << *i;
	}
	std::cout << std::endl;
	return 0;
}
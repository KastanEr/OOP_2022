#include <iostream>
#include <vector>

int main() {
	int input, min, max;
	std::vector<int> vector;
	for (int i = 0; i < 10; i++) {
		std::cout << "vec[" << i << "] : ";
		std::cin >> input;
		vector.push_back(input);
	}
	std::cout << "--------------------------------------------------\n" << std::endl;
	min = vector.at(0);
	max = vector.at(0);
	for (std::vector<int>::iterator itr = vector.begin() + 1; itr != vector.end(); ++itr) {
		if (*itr > max) {
			max = *itr;
		}
		if (*itr < min) {
			min = *itr;
		}
	}
	std::cout << "max : " << max << "\nmin : " << min << std::endl;
}
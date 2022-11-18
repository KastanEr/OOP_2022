#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Rect {
	int w, h;
public:
	Rect() : w(0), h(0) { }
	Rect(int w, int h) : w(w), h(h) { }
	int area() { return w * h; }
	void print() {
		cout << "(" << w << ", " << h << ", " << area() << ")" << endl;
	}
	bool operator <(Rect& const rect) {
		return this->area() < rect.area();
	}
};

int main() {
	vector<Rect> vec;
	int inputNum, inputW, inputH;
	cout << "사각형의 개수: ";
	cin >> inputNum;
	for (int i = 0; i < inputNum; i++) {
		cout << "사각형의 폭: ";
		cin >> inputW;
		cout << "사각형의 높이: ";
		cin >> inputH;
		vec.push_back(Rect(inputW, inputH));
	}
	sort(vec.begin(), vec.end());
	for (vector<Rect>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
		itr->print();
	}
}
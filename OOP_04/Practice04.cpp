class Animal {
public:
	Animal(int numberOfLeg) {
		this->numberOfLeg = numberOfLeg;
	}
private:
	int numberOfLeg;
};
int main() {
	Animal a(4);
	return 0;
}
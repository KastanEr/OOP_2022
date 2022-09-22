#include <iostream>
#include <ctime>
#include <cstdlib>

class Dice
{
	int value; // 주사위 값
public:
	void set_dice_value() // 주사위 값을 난수로 받을 수 있도록
	{
		srand(time(NULL));
		value = rand() % 6 + 1;
	}
	int get_dice_value()
	{
		return value;
	}
};
int main()
{
	srand(time(NULL));
	Dice dice1;
	Dice dice2;
	dice1.set_dice_value();
	dice2.set_dice_value();
	std::cout << "두 주사위 합=" << dice1.get_dice_value() + dice2.get_dice_value() << std::endl;
	return 0;
}
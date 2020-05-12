#pragma once
#include <iostream>
#include <time.h>
using namespace std;
class Dice
{
public:
	int diceno[3] = { 0 };
	void reset();
	void rolladice();
	int randomgen();

	int DiceNoAtIndex(int i)
	{
		return diceno[i];
	}
};
void Dice::reset()
{
	for (auto a : diceno)
		*diceno = 0;
}
int Dice::randomgen()
{
	srand(time(0));
	int dice = (int)(1 + rand() % 6);
	return dice;

}
void Dice::rolladice()
{
	int Baazi = 0;
	for (int i = 0; i < 3; i++)
	{
		Baazi = randomgen();
		diceno[i] = Baazi;
		if (Baazi < 6)
			break;
	}
}




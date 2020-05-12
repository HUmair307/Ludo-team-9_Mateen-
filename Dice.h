#pragma once
#include <time.h>
#include "Cell.h"
using namespace std;
class Dice
{
public:
	
	int diceno[3] = { 0 };

	void reset()
	{
		for (auto a : diceno)
			*diceno = 0;
	}
	int randomgen()
	{
		srand(time(0));
		int dice = (int)(1 + rand() % 6);
		return dice;

	}
	void rolladice()
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

	int DiceNoAtIndex(int i)
	{
		return diceno[i];
	}
};





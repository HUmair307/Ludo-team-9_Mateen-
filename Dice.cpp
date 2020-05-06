#include "Dice.h"
#include <iostream>
#include <time.h>
#include <vector>
void Dice::reset()
{
	diceno.clear();
}
int Dice::randomgen()
{
	srand(time(0));
	int dice = (int)(1 + rand() % 6);
	return dice;

}
void Dice::rolladice()
{
	randomgen();
	diceno.push_back(randomgen());
	if (randomgen() == 6)
	{
		randomgen();
		diceno.push_back(randomgen());
		if (randomgen() == 6)
		{
			randomgen();
			diceno.push_back(randomgen());
			if (randomgen() == 6)
			{
				reset();
				//turnchange();

			}
		}
		else
		{
			reset();
			//turnchange();
		}
	}
	else
	{
		reset();
		//turnchange();
	}
}
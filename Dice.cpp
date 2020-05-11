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
	int Baazi = 0;
	do
	{
		Baazi = randomgen();
		diceno.push_back(Baazi);
	} while (Baazi == 6 && diceno.size()<3);
}

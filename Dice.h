

#pragma once
#include <iostream>
#include <vector>
#include <time.h>
using namespace std;
class Dice
{
public:
	vector<int>diceno;
	void reset();
	void rolladice();
	int randomgen();

	int DiceNoAtIndex(int i)
	{
		return diceno[i];
	}

};


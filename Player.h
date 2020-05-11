#pragma once
#include"Token.h"
#include "Dice.h"
using namespace std;
class Player
{
public:
	colors color;
	int TokenReachDest;
	Player()
	{

	}
	Player(colors c):color(c)
	{
		TokenReachDest = 0;
	}
	colors getColor()
	{
		return color;
	}

};


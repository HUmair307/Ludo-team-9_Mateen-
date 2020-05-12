#pragma once
#include"Token.h"
#include "Dice.h"
using namespace std;
class Player
{
public:
	colors color;
	int TokenReachDest;
	Token* PlayerTokens;
	Player()
	{

	}
	Player(colors c):color(c)
	{
		TokenReachDest = 0;
		PlayerTokens = new Token[4];
	}
	colors getColor()
	{
		return color;
	}

};


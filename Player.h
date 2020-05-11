#pragma once
#include"Token.h"
#include "Dice.h"
using namespace std;
class Player :public Token
{
public:
	// char** GridPointer;
	Token* TokenArray;
	int NoToken;// number of token
	//GrowA<int> DiceNo;    // growable array is template
	Dice DICE;
	Token tokenSelected;
	colors color;
	int InitialLocation;
public:

	Player()
	{

	}
	Player(colors c,int initiallocation):color(c),InitialLocation(initiallocation)
	{
		TokenArray = new Token[4];
	}
	

	void PlayingSelectedToken(Token T)
	{

	}

	void ChoosingTokken()
	{

	}
	
	colors getColor()
	{
		return color;
	}

};


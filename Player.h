#pragma once
#include"Token.h"
#include "Dice.h"
using namespace std;
class Player :public Token
{
protected:
	// char** GridPointer;
	Token* TokenArray;
	int NoToken;// number of token
	//GrowA<int> DiceNo;    // growable array is template
	Dice DICE;
	Token tokenSelected;
	char color;
	int InitialLocation;
public:

	Player()
	{

	}
	Player(Color c,int initiallocation){}
	

	void PlayingSelectedToken(Token T)
	{

	}

	void ChoosingTokken()
	{

	}

};


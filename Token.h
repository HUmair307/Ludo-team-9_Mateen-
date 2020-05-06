#pragma once
#include"Dice.h"
enum Color { Red, Blue, Green, Yellow, White, Black };

// as sarfaraz said.....max players can be 6

class Token :public Dice
{
public:
	char color;
	int initialLocation;
	int NoOfStepsTaken;
	int TokenLocationOnBoard;
	int TokenReachDest;
	char status;


public:

	Token()
	{

	}
	virtual void DrawToken()
	{

	}
	void SetStatus(char s)
	{

	}



};


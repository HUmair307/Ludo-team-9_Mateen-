#pragma once
#include"Dice.h"
#include "graphics.h"
#include "Position.h"
enum Color { Red, Blue, Green, Yellow, White, Black };

// as sarfaraz said.....max players can be 6

class Token :public Dice
{
public:
	colors color;
	int initialLocation;
	int HomeCell;
	int NoOfStepsTaken;
	int TokenLocationOnBoard;
	// int TokenReachDest;
	// char status;


public:

	Token()
	{

	}
	
	Token(colors C, int HomeIndex, int IntialCell)
	{
		color = C;
		NoOfStepsTaken = 0;
		HomeCell = HomeIndex;
		initialLocation = IntialCell;
		TokenLocationOnBoard = HomeIndex;
	}
	
	virtual void DrawToken(Position P)
	{

	}
	virtual void SetStatus(char s)
	{
	
	}
	
	colors getColor()
	{
		return color;
	}


};


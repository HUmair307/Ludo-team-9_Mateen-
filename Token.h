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
	bool Homestatus;


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
		Homestatus = true;
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
	
	bool isAtHome()
	{
		return HomeStatus;
	}

	int StepsTaken()
	{
		return NoOfStepsTaken;
	}
	
	void Killed()
	{
		NoOfStepsTaken = 0;
		TokenLocationOnBoard = HomeIndex;
		HomeStatus = true;
	}
};


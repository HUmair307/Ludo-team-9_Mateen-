#pragma once
#include "Token.h"
#include "Player.h"
#include "Position.h"
#include "graphics.h"
class Cell
{
public:
	Position TopLeft, ButtomRight;
	bool Issave = false;
	colors Cl;// colors is a enum in graphics.h
	int index=0;
	Cell() { TopLeft.x = ButtomRight.x = TopLeft.y = ButtomRight.y = 0; }
	Cell(Position T,Position B,colors C) :TopLeft(T),ButtomRight(B),Cl(C){}
	Position getTL() { return TopLeft; }
	Position getBR() { return ButtomRight; }
	void setcellPos(Position T, Position B, colors c)
	{
		TopLeft = T, ButtomRight = B, Cl = c;
	}

	~Cell() {}
};




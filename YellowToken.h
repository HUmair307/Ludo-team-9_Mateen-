#pragma once

#include"Token.h"
#include"Position.h"
class YellowToken :public Token
{

public:
	YellowToken(colors C, int HomeIndex, int IntialCell) :Token(C, HomeIndex, IntialCell) {}
	virtual void DrawToken(Position p)
	{
		setfillstyle(SOLID_FILL, DARKGRAY);
		fillellipse(p.x, p.y, 18, 18);

	}

};


#pragma once

#include"Token.h"
#include"Position.h"
class BlueToken :public Token
{

public:
	BlueToken(colors C, int HomeIndex, int IntialCell) :Token(C, HomeIndex, IntialCell) {}

	virtual void DrawToken(Position p)
	{

		setfillstyle(SOLID_FILL, BLUE);
		fillellipse(p.x, p.y, 18, 18);
	}

};


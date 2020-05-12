#pragma once

#include"Token.h"
#include"Position.h"
class RedToken :public Token
{

public:
	RedToken(colors C, int HomeIndex, int IntialCell) :Token(C, HomeIndex, IntialCell) {}

	virtual void DrawToken(Position p)
	{

		setfillstyle(SOLID_FILL, RED);
		fillellipse(p.x, p.y, 18, 18);

	}
};


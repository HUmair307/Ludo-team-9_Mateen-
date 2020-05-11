#pragma once

#include"Token.h"
#include"Position.h"
class YellowToken :public Token
{

public:
	virtual void draw(Position p)
	{

		setfillstyle(SOLID_FILL, DARKGRAY);
		circle(p.x, p.y, 18);
	}

};


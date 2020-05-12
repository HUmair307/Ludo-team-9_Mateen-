#pragma once

#include"Token.h"
#include"Position.h"
class BlueToken :public Token
{

public:
	virtual void draw(Position p)
	{

		setfillstyle(SOLID_FILL, BLUE);
		circle(p.x, p.y, 18);
	}

};


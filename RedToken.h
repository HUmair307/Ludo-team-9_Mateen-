#pragma once

#include"Token.h"
#include"Position.h"
class RedToken :public Token
{

public:
	virtual void draw(Position p)
	{

		setfillstyle(SOLID_FILL, RED);
		circle(p.x, p.y, 18);
	}
};


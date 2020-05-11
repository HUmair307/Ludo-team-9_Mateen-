#pragma once

#include"Token.h"
#include"Position.h"
class GreenToken:public Token
{

public:
	virtual void draw(Position p)
	{

		setfillstyle(SOLID_FILL, GREEN);
		circle(p.x, p.y, 18);
	}

};


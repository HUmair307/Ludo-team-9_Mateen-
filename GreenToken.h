#pragma once

#include"Token.h"
#include"Position.h"
class GreenToken:public Token
{

public:
	virtual void Draw(Position P)
	{
		setfillstyle(SOLID_FILL, 2);
		circle(P.x, P.y, 18);
	}

};


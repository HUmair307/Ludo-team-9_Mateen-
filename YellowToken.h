#pragma once

#include"Token.h"
#include"Position.h"
class YellowToken :public Token
{

public:
	virtual void Draw(Position P)
	{
		setfillstyle(SOLID_FILL, DARKGRAY);
		circle(P.x, P.y, 18);
	}

};


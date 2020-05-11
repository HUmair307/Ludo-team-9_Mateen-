#pragma once

#include"Token.h"
#include"Position.h"
class BlueToken :public Token
{

public:
	virtual void Draw(Position P)
	{
		setfillstyle(SOLID_FILL, BLUE);
		circle(P.x, P.y, 18);
	}

};


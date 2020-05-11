#pragma once

#include"Token.h"
#include"Position.h"
class RedToken :public Token
{

public:
	virtual void Draw(Position P)
	{
		setfillstyle(SOLID_FILL, RED);
		circle(P.x, P.y, 18);
	}

};


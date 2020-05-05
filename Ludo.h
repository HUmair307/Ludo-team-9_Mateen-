#pragma once

#include "Player.h"
#include "Token.h"
#include "Dice.h"
#include "graphics.h"
using namespace std;
class Ludo :public Player
{
protected:
	char** Grid;
	Player* Players;
	//Player Players[MaxPlayers];
	int NoOfPlayers, Turn, MaxNoSteps, WC;

public:
	Ludo(){}
	
	void InitBoard()
	{

	}

	Ludo(int NOP)
	{
		Players = new Player[NOP];
		Grid = nullptr;
	}

	void UpdateBoard(Token T)
	{

	}

	void ChangeTurn()
	{

	}

	void DisplayPlayerMsg()
	{

	}

	void UpdatePlayerList(int Turn)
	{

	}

	void DisplayResult()
	{

	}

	void DisplayBoard()
	{
		initwindow(800, 800, "LUDO");
		int a[10]= { 0,0,276,0,276,276,0,276,0,0};
		setfillstyle(SOLID_FILL, 2);
		fillpoly(5, a);

		int b[10] = { 414,0,690,0,690,276,414,276,414,0 };
		setfillstyle(SOLID_FILL, 14);
		fillpoly(5, b);
		

		int c[10] = { 0,414,276,414,276,690,0,690,0,414};
		setfillstyle(SOLID_FILL, 4);
		fillpoly(5, c);

		int d[10] = { 414,414,690,414,690,690,414,690,414,414 };
		setfillstyle(SOLID_FILL, 1);
		fillpoly(5, d);

		int e[10] = { 276,276,414,276,414,414,276,414,276,276 };
		setfillstyle(SOLID_FILL, 15);
		fillpoly(5, e);

		setfillstyle(SOLID_FILL, 9);

		for (int x = 0,i=0; x < 138; x += 46,i++)
		{
			for (int y = 0,k=0; y < 276; y += 46,k++)
			{
				int a[10] = { 276+x,0 + y,322 + x,0 + y,322 + x,46 + y,276 + x,46+y,276 + x,0+y };
				if(i==0&&k==2)
					setfillstyle(SOLID_FILL, 14);
				else if(i==1&&k>0)
					setfillstyle(SOLID_FILL, 14);
				else if(i==2&&k==1)
					setfillstyle(SOLID_FILL, 14);
				fillpoly(5, a);
				setfillstyle(SOLID_FILL, 9);
			}
		}

		for (int x = 0, i = 0; x < 138; x += 46, i++)
		{
			for (int y = 0, k = 0; y < 276; y += 46, k++)
			{
				int a[10] = { 276 + x,414 + y,322 + x,414 + y,322 + x,460 + y,276 + x,460 + y,276 + x,414 + y };
				if (i == 0 && k == 4)
					setfillstyle(SOLID_FILL, 4);
				else if (i == 1 && k < 5)
					setfillstyle(SOLID_FILL, 4);
				else if (i == 2 && k == 3)
					setfillstyle(SOLID_FILL, 4);
				fillpoly(5, a);
				setfillstyle(SOLID_FILL, 9);
			}
		}

		

		for (int y = 0,i = 0; y < 138; y += 46,i++)
		{
			for (int x = 0,k = 0; x < 276; x += 46,k++)
			{
				int g[10] = { 0 + x,276 + y,46 + x,276 + y,46 + x,322 + y,0 + x,322 + y,0 + x,276 + y };

				if(i==0&&k==1)
					setfillstyle(SOLID_FILL, 2);
				else if(i==1&&k>0)
					setfillstyle(SOLID_FILL, 2);
				else if(i==2&&k==2)
					setfillstyle(SOLID_FILL, 2);
				fillpoly(5, g);
				setfillstyle(SOLID_FILL, 9);

			}
		}


		for (int y = 0, i = 0; y < 138; y += 46, i++)
		{
			for (int x = 0, k = 0; x < 276; x += 46, k++)
			{
				int g[10] = { 414 + x,276 + y,460 + x,276 + y,460 + x,322 + y,414 + x,322 + y,414+ x,276 + y };

				if (i == 0 && k == 3)
					setfillstyle(SOLID_FILL, 1);
				else if (i == 1 && k < 5)
					setfillstyle(SOLID_FILL, 1);
				else if (i == 2 && k == 4)
					setfillstyle(SOLID_FILL, 1);
				fillpoly(5, g);
				setfillstyle(SOLID_FILL, 9);

			}
		}





	}

	bool isWin()
	{
		return true;
	}

	void StartGame()
	{

	}

	void init()
	{
		//cin number of players
		// will initialize the Player*;
	}
	void Play()
	{
		init();
		StartGame();
		DisplayBoard();
		DisplayPlayerMsg();
		Players[Turn].RollaDice();
		Players[Turn].ChoosingTokken();
		Players[Turn].PlayingSelectedToken(tokenSelected);
		UpdateBoard(tokenSelected);
		Players[Turn].DrawToken();
		if (isWin())
		{
			UpdatePlayerList(Turn);
			WC++;
		}
		ChangeTurn();
		while (WC < NoOfPlayers - 1)
		{
			DisplayResult();
		}

	}



};


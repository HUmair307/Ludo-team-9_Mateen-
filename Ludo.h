#pragma once

#include "Player.h"
#include "Token.h"
#include "Dice.h"
#include "graphics.h"
#include "Grid.h"
#include "Position.h"
#include "Cell.h"
using namespace std;
class Ludo :public Player,public Cell
{
protected:
	char** Grid;
	Player* Players;
	//Player Players[MaxPlayers];
	int NoOfPlayers, Turn, MaxNoSteps, WC;
	int DU;
	int NOC=0;// number of cells
	Cell C[76];

	colors cc = WHITE;

	/*
	 YELLOW
									          
											  0 6  12 
											  1 7  13 S
											S 2 8  14 
											  3 9  15 
						G					  4 10 16
						R		S			  5 11 17           S			B
						E	36 37 38 39 40 41	 72	   18 19 20 21 22 23	L
						E	42 43 44 45 46 47 75	73 24 25 26 27 28 29	U
						N	48 49 50 51 52 53	 74	   30 31 32 33 34 35	E
							      S           54 60 66             S
											  55 61 67
											  56 62 68
											  57 63 69 S
											S 58 64 70
											  59 65 71
											  
											  R  E  D
	*/
	

public:
	Ludo(){}
	void AssignIndex()
	{
		NOC = 5;
		for (int i = 0; i < 2; i++)
		{
			if (i == 1)
				NOC = 6;
			for (int k = 0; k < 5; k++)
			{
				C[NOC].index++;
				if (i == 0)
					NOC--;
				else
					NOC++;
				if (i == 1 && k == 1)
					break;
			}
		}
		//BLUE
		for (int y = 0, i = 0; y < 138; y += 46, i++)
		{
			for (int x = 0, k = 0; x < 276; x += 46, k++)
			{
				int g[10] = { 414 + x,276 + y,460 + x,276 + y,460 + x,322 + y,414 + x,322 + y,414 + x,276 + y };

				if ((i == 0 && k == 3) || (i == 1 && k < 5) || (i == 2 && k == 4))
				{
					cc = BLUE; C[NOC].Issave = true;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
				fillpoly(5, g);
				setfillstyle(SOLID_FILL, WHITE);
				cc = WHITE;
				NOC++;
			}
		}

		// GREEN


		for (int y = 0, i = 0; y < 138; y += 46, i++)
		{
			for (int x = 0, k = 0; x < 276; x += 46, k++)
			{
				int g[10] = { 0 + x,276 + y,46 + x,276 + y,46 + x,322 + y,0 + x,322 + y,0 + x,276 + y };
				if ((i == 0 && k == 1) || (i == 1 && k > 0) || (i == 2 && k == 2))
				{
					cc = GREEN; C[NOC].Issave = true;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
				fillpoly(5, g);
				setfillstyle(SOLID_FILL, WHITE);
				cc = WHITE;
				NOC++;
			}
		}
		//RED
		for (int x = 0, i = 0; x < 138; x += 46, i++)
		{
			for (int y = 0, k = 0; y < 276; y += 46, k++)
			{
				int a[10] = { 276 + x,414 + y,322 + x,414 + y,322 + x,460 + y,276 + x,460 + y,276 + x,414 + y };
				if ((i == 0 && k == 4) || (i == 1 && k < 5) || (i == 2 && k == 3))
				{
					cc = RED; C[NOC].Issave = true;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
				fillpoly(5, a);
				setfillstyle(SOLID_FILL, WHITE);
				cc = WHITE;
				NOC++;
			}
		}

	}
	void InitBoard()
	{
			// We don't really need this?
			// yes we do not need it
	}

	Ludo(int NOP)
	{
		Players = new Player[NOP];
		Grid = new char*[1];
		Grid[0] = new char[100]; // How many total boxes are there? Please specify according to the NOP.
	}

	void UpdateBoard(Token T)
	{
		Grid[0][T.TokenLocationOnBoard] = '-';
		Grid[0][T.TokenLocationOnBoard + Players[Turn].DICE.DiceNoAtIndex(DU)];
	}

	void ChangeTurn()
	{
		++Turn;
		if (Turn == NoOfPlayers)
			Turn = 0;
	}

	void DisplayPlayerMsg()
	{
		// Where should we display the which player's turn is it right now?
	}

	void UpdatePlayerList(int Turn)
	{
		Player* NewPlayer = new Player[NoOfPlayers - WC]; // Provided WC has already been updated. Please take note
		int z = 0;
		for (int i = 0; i < NoOfPlayers - WC; i++)
		{
			if (i == Turn)
				continue;
			NewPlayer[z] = Players[i];
			++z;
		}
		delete[]Players;
		Players = NewPlayer;
	}

	void DisplayResult()
	{
		//Should we display "Player Blue Won"???? And at which place?
		// we can increase the init window size and can show both dice roll and win msg there.
	}

	void DisplayBoard()
	{
		initwindow(800, 800, "LUDO");
		int a[10]= { 0,0,276,0,276,276,0,276,0,0};
		setfillstyle(SOLID_FILL, GREEN);
		fillpoly(5, a);
		int a1[10] = { 0+30,0+30,276-30,0+30,276-30,276-30,0+30,276-30,0+30,0+30 };
		setfillstyle(SOLID_FILL, LIGHTGREEN);
		fillpoly(5, a1);
		setfillstyle(SOLID_FILL, GREEN);
		fillellipse(60, 60, 20, 20);
		fillellipse(216, 60, 20, 20);
		fillellipse(60, 216, 20, 20);
		fillellipse(216, 216, 20, 20);

		int b[10] = { 414,0,690,0,690,276,414,276,414,0 };
		setfillstyle(SOLID_FILL, DARKGRAY);
		fillpoly(5, b);


		int b1[10] = { 414+30,0+30,690-30,0+30,690-30,276-30,414+30,276-30,414+30,0+ 30};
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		fillpoly(5, b1);
		setfillstyle(SOLID_FILL, DARKGRAY);

		fillellipse(474, 60, 20, 20);
		fillellipse(630, 60, 20, 20);
		fillellipse(474, 216, 20, 20);
		fillellipse(630, 216, 20, 20);



		int c[10] = { 0,414,276,414,276,690,0,690,0,414};
		setfillstyle(SOLID_FILL, RED);
		fillpoly(5, c);

		
		
		int c1[10] = { 0+30,414+30,276-30,414+30,276-30,690-30,0+30,690-30,0+30,414+30 };
		setfillstyle(SOLID_FILL, LIGHTRED);
		fillpoly(5, c1);
		setfillstyle(SOLID_FILL, RED);
		fillellipse(216, 474, 20, 20);
		fillellipse(216, 630, 20, 20);
		fillellipse(60, 474, 20, 20);
		fillellipse(60, 630, 20, 20);

		int d[10] = { 414,414,690,414,690,690,414,690,414,414 };
		setfillstyle(SOLID_FILL, BLUE);
		fillpoly(5, d);





		int d1[10] = { 414+30,414+30,690-30,414+30,690-30,690-30,414+30,690-30,414+30,414+30 };
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		fillpoly(5, d1);
		setfillstyle(SOLID_FILL, BLUE);
		fillellipse(474, 474, 20, 20);
		fillellipse(474, 630, 20, 20);
		fillellipse(630, 474, 20, 20);
		fillellipse(630, 630, 20, 20);
		int T1[8] = {276,276,414,276,345,345,276,276 };
		setfillstyle(SOLID_FILL, DARKGRAY);
		fillpoly(4, T1);

		int T2[8] = { 414,276,414,414,345,345,414,276 };
		setfillstyle(SOLID_FILL, BLUE);
		fillpoly(4, T2);
		int T3[8] = { 345,345,414,414,276,414,345,345 };
		setfillstyle(SOLID_FILL, RED);
		fillpoly(4, T3);
		int T4[8] = { 276,276,345,345,276,414,276,276 };
		setfillstyle(SOLID_FILL, GREEN);
		fillpoly(4, T4);




/*


									BOX INDEX IN THE ARRAY. BETTER SEQUENCE CAN'T BE MAKE
									==> Position of every box is saved ( TopLeft and ButtonRight + color)
									==> box with color are declared as safe spot and their position are saved
									S===> SAFE SPOT, TOTAL BOXES===> 76
											  YELLOW

											  0 6  12
											  1 7  13 S
											S 2 8  14
											  3 9  15
						G					  4 10 16
						R		S			  5 11 17           S			B
						E	36 37 38 39 40 41	 72	   18 19 20 21 22 23	L
						E	42 43 44 45 46 47 75	73 24 25 26 27 28 29	U
						N	48 49 50 51 52 53	 74	   30 31 32 33 34 35	E
								  S           54 60 66             S
											  55 61 67
											  56 62 68
											  57 63 69 S
											S 58 64 70
											  59 65 71

											  R  E  D

*/
		cc = LIGHTCYAN;

		// GRAY
		for (int x = 0,i=0; x < 138; x += 46,i++)
		{
			for (int y = 0,k=0; y < 276; y += 46,k++)
			{
				int a[10] = { 276+x,0 + y,322 + x,0 + y,322 + x,46 + y,276 + x,46+y,276 + x,0+y };
				if ((i == 0 && k == 2) || (i == 1 && k > 0) || (i == 2 && k == 1))
				{
					cc = DARKGRAY; C[NOC].Issave = true;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 0 + y), Position(322 + x, 46 + y), cc);
				fillpoly(5, a);
				setfillstyle(SOLID_FILL, LIGHTCYAN);
				cc = LIGHTCYAN;
				NOC++;
			}
		}
		//blue
		for (int y = 0, i = 0; y < 138; y += 46, i++)
		{
			for (int x = 0, k = 0; x < 276; x += 46, k++)
			{
				int g[10] = { 414 + x,276 + y,460 + x,276 + y,460 + x,322 + y,414 + x,322 + y,414 + x,276 + y };

				if ((i == 0 && k == 3) || (i == 1 && k < 5) || (i == 2 && k == 4))
				{
					cc = BLUE; C[NOC].Issave = true;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
				fillpoly(5, g);
				setfillstyle(SOLID_FILL, LIGHTCYAN);
				cc = LIGHTCYAN;
				NOC++;
			}
		}
		//
		//// GREEN
		//

		for (int y = 0,i = 0; y < 138; y += 46,i++)
		{
			for (int x = 0,k = 0; x < 276; x += 46,k++)
			{
				int g[10] = { 0 + x,276 + y,46 + x,276 + y,46 + x,322 + y,0 + x,322 + y,0 + x,276 + y };
				if ((i == 0 && k == 1) || (i == 1 && k > 0) || (i == 2 && k == 2))
				{
					cc = GREEN; C[NOC].Issave = true;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
				fillpoly(5, g);
				setfillstyle(SOLID_FILL, LIGHTCYAN);
				cc = LIGHTCYAN;
				NOC++;
			}
		}
		////RED
		for (int x = 0, i = 0; x < 138; x += 46, i++)
		{
			for (int y = 0, k = 0; y < 276; y += 46, k++)
			{
				int a[10] = { 276 + x,414 + y,322 + x,414 + y,322 + x,460 + y,276 + x,460 + y,276 + x,414 + y };
				if ((i == 0 && k == 4) || (i == 1 && k < 5) || (i == 2 && k == 3))
				{
					cc = RED; C[NOC].Issave = true;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
				fillpoly(5, a);
				setfillstyle(SOLID_FILL, LIGHTCYAN);
				cc = LIGHTCYAN;
				NOC++;
			}
		}
		




	}

	bool isWin()
	{
		if (Players[Turn].TokenReachDest==4)
			return true;
		else
			return false;
	}

	void StartGame()
	{
		// Why do we need this function when we already have init..?
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
		do
		{
			DisplayBoard();
			DisplayPlayerMsg();
			Players[Turn].rolladice();
			Players[Turn].ChoosingTokken();
			Players[Turn].PlayingSelectedToken(tokenSelected);
			UpdateBoard(tokenSelected);
			Players[Turn].DrawToken();
			if (isWin())
			{
				WC++;
				UpdatePlayerList(Turn);	
			}
			ChangeTurn();
			if (WC == NoOfPlayers - 1)
			{
				DisplayResult();
				break;
			}
		}while(true);

	}



};


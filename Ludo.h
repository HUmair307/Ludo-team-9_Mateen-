#pragma once
#include<vector>
#include "Dice.h"
#include "Grid.h"
#include<string.h>
#include"GreenToken.h"
#include"RedToken.h"
#include"YellowToken.h"
#include<iostream>
#include"BlueToken.h"
using namespace std;
class Ludo :public Player,public Cell
{
protected:
	Token** Grid;
	Player** Players;
	//Player Players[MaxPlayers];
	int NoOfPlayers, Turn, MaxNoSteps, WC;
	colors turncolor;
	int DU;
	int NOC=0;// number of cells
	Cell C[95];
	Position P;
	colors cc = WHITE;
	Dice dice;
	int HCN = 76;
	vector <int> WinPlayers;
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
	


	void InitBoard()
	{
			// We don't really need this?
			// yes we do not need it
	}

	//Ludo(int NOP)
	//{
	//	Players = new Player[NOP];
	//	Grid = new char*[1];
	//	Grid[0] = new char[100]; // How many total boxes are there? Please specify according to the NOP.
	//}

	//void UpdateBoard(Token T)
	//{
	//	Grid[0][T.TokenLocationOnBoard] = '-';
	//	//Grid[0][T.TokenLocationOnBoard + Players[Turn].DICE.DiceNoAtIndex(DU)];
	//}

	void ChangeTurn()
	{
		do
		{
			++Turn;
			if (Turn == NoOfPlayers)
				Turn = 0;
			for(int i=0;i<WinPlayers.size();i++)
			{
				if (Turn==WinPlayers[i])
					continue;
			}
			break;
		}while(true);
		inttocolor();
	}

	void DisplayPlayerMsg()
	{
		if (Turn == 0)
		{
			outtextxy(750, 50, "Green's turn");
		}
		else if (Turn == 1)
		{
			outtextxy(750, 50, "Gray's turn");
		}
		else if (Turn == 2)
		{
			outtextxy(750, 50, "Blue's turn");
		}
		else 
		{
			outtextxy(750, 50, "Red's turn");
		}
		// Where should we display the which player's turn is it right now?
	}

	/*void UpdatePlayerList(int Turn)
	{
		Player** NewPlayer = new Player*[NoOfPlayers - WC]; // Provided WC has already been updated. Please take note
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
	}*/
	
	void DisplayResult()
	{
		//Should we display "Player Blue Won"???? And at which place?
		// we can increase the init window size and can show both dice roll and win msg there.
	}
	void mouseclick(Position& p)
	{
		int Dim = 80; while (!ismouseclick(WM_LBUTTONDOWN)) {} getmouseclick(WM_LBUTTONDOWN, p.x, p.y); 
	}
	void DisplayBoard()
	{
		initwindow(1300, 800, "LUDO");
		int a[10]= { 0,0,276,0,276,276,0,276,0,0};
		setfillstyle(SOLID_FILL, GREEN);
		fillpoly(5, a);
		int a1[10] = { 0+30,0+30,276-30,0+30,276-30,276-30,0+30,276-30,0+30,0+30 };
		int h[10] = { 37,37,83,37,83,83,37,83,37,37 };// points of home cell of green 
		C[HCN].setcellPos(Position(37, 37), Position(83, 83), GREEN); HCN++;
		drawpoly(5, h);
		int j[10] = { 193,37,239,37,239,83,193,83,193,37 };// points of home cell of green 
		C[HCN].setcellPos(Position(193,37), Position(239,83), GREEN); HCN++;
		drawpoly(5, j);
		int k[10] = { 37,193,83,193,83,239,37,239,37,193};// points of home cell of green 
		C[HCN].setcellPos(Position(37, 193), Position(83, 239), GREEN); HCN++;
		drawpoly(5, k);
		int l[10] = { 193,193,239,193,239,239,193,239,193,193};// points of home cell of green 
		C[HCN].setcellPos(Position(193, 193), Position(239, 239), GREEN); HCN++;
		drawpoly(5, l);
		setfillstyle(SOLID_FILL, LIGHTGREEN);
		fillpoly(5, a1);
		//setfillstyle(SOLID_FILL, GREEN);
		//fillellipse(60, 60, 20, 20);
		//fillellipse(216, 60, 20, 20);
		//fillellipse(60, 216, 20, 20);
		//fillellipse(216, 216, 20, 20);
/// GREEN IS ENDED.

		int b[10] = { 414,0,690,0,690,276,414,276,414,0 };
		setfillstyle(SOLID_FILL, DARKGRAY);
		fillpoly(5, b);



		int m[10] = { 451,37,497,37,497,83,451,83,451,37 };// points of home cell of green 
		C[HCN].setcellPos(Position(451, 37), Position(497, 83), DARKGRAY); HCN++;
		drawpoly(5, m);
		int n[10] = { 607,37,653,37,653,83,607,83,607,37 };// points of home cell of green 
		C[HCN].setcellPos(Position(607, 37), Position(653, 83), DARKGRAY); HCN++;
		drawpoly(5, n);
		int o[10] = { 451,193,497,193,497,239,451,239,451,193 };// points of home cell of green 
		C[HCN].setcellPos(Position(451, 193), Position(497, 239), DARKGRAY); HCN++;
		drawpoly(5, o);
		int p[10] = { 607,193,653,193,653,239,607,239,607,193 };// points of home cell of green 
		C[HCN].setcellPos(Position(607, 193), Position(653, 239), DARKGRAY); HCN++;
		drawpoly(5, p);
		
		int b1[10] = { 414 + 30,0 + 30,690 - 30,0 + 30,690 - 30,276 - 30,414 + 30,276 - 30,414 + 30,0 + 30 };
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		fillpoly(5, b1);


		/*setfillstyle(SOLID_FILL, DARKGRAY);

		fillellipse(474, 60, 20, 20);
		fillellipse(630, 60, 20, 20);
		fillellipse(474, 216, 20, 20);
		fillellipse(630, 216, 20, 20);*/
/// DARKGRAY HAS ENDED




		int d[10] = { 414,414,690,414,690,690,414,690,414,414 };
		setfillstyle(SOLID_FILL, BLUE);
		fillpoly(5, d);




		
		int A[10] = { 451,451,497,451,497,497,451,497,451,451 };// points of home cell of green 
		C[HCN].setcellPos(Position(451, 451), Position(497, 497), BLUE); HCN++;
		drawpoly(5, A);
		int B[10] = { 607,451,653,451,653,497,607,497,607,451 };// points of home cell of green 
		C[HCN].setcellPos(Position(607, 451), Position(653, 497), BLUE); HCN++;
		drawpoly(5, B);
		int y[10] = { 451,607,497,607,497,653,451,653,451,607 };// points of home cell of green 
		C[HCN].setcellPos(Position(497, 653), Position(451, 607), BLUE); HCN++;
		drawpoly(5, y);
		int z[10] = { 607,607,653,607,653,653,607,653,607,607 };// points of home cell of green 
		C[HCN].setcellPos(Position(607, 607), Position(653, 653), BLUE); HCN++;
		drawpoly(5, z);
		
		int d1[10] = { 414 + 30,414 + 30,690 - 30,414 + 30,690 - 30,690 - 30,414 + 30,690 - 30,414 + 30,414 + 30 };
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		fillpoly(5, d1);
		//setfillstyle(SOLID_FILL, BLUE);
		//fillellipse(474, 474, 20, 20);
		//fillellipse(474, 630, 20, 20);
		//fillellipse(630, 474, 20, 20);
		//fillellipse(630, 630, 20, 20);

//BLUE HAS ENDED


		int c[10] = { 0,414,276,414,276,690,0,690,0,414};
		setfillstyle(SOLID_FILL, RED);
		fillpoly(5, c);

		int r[10] = { 37,451,83,451,83,497,37,497,37,451 };// points of home cell of green 
		C[HCN].setcellPos(Position(37, 450), Position(83, 496), RED); HCN++;
		drawpoly(5, r);
		int X[10] = { 193,451,239,451,239,497,193,497,193,451 };// points of home cell of green 
		C[HCN].setcellPos(Position(193, 450), Position(239, 496), RED); HCN++;
		drawpoly(5, X);
		int Y[10] = { 37,606,83,606,83,652,37,652,37,606 };// points of home cell of green 
		drawpoly(5, Y);
		C[HCN].setcellPos(Position(37, 606), Position(83, 652), RED); HCN++;
		int Z[10] = { 193,606,239,606,239,652,193,652,193,606 };// points of home cell of green 
		drawpoly(5, Z);
		C[HCN].setcellPos(Position(193, 606), Position(239, 652), RED); HCN++;

		
		int c1[10] = { 0+30,414+30,276-30,414+30,276-30,690-30,0+30,690-30,0+30,414+30 };
		setfillstyle(SOLID_FILL, LIGHTRED);
		fillpoly(5, c1);
		/*setfillstyle(SOLID_FILL, RED);
		fillellipse(216, 474, 20, 20);
		fillellipse(216, 630, 20, 20);
		fillellipse(60, 474, 20, 20);
		fillellipse(60, 630, 20, 20);*/



// RED HAS ENDED
		


		int T1[8] = {276,276,414,276,345,345,276,276 };
		C[73].setcellPos(Position(345*2, 282*2), Position(0, 0), DARKGRAY);

		setfillstyle(SOLID_FILL, DARKGRAY);
		fillpoly(4, T1);
		int T2[8] = { 414,276,414,414,345,345,414,276 };
		C[74].setcellPos(Position(395*2, 345*2), Position(0, 0), BLUE);

		setfillstyle(SOLID_FILL, BLUE);
		fillpoly(4, T2);
		int T3[8] = { 345,345,414,414,276,414,345,345 };
		C[75].setcellPos(Position(345*2, 395*2), Position(0, 0), RED);

		setfillstyle(SOLID_FILL, RED);
		fillpoly(4, T3);
		int T4[8] = { 276,276,345,345,276,414,276,276 };
		C[72].setcellPos(Position(282*2, 345*2), Position(0, 0), GREEN);
		setfillstyle(SOLID_FILL, GREEN);

		fillpoly(4, T4);




/*


									BOX INDEX IN THE ARRAY. BETTER SEQUENCE CAN'T BE MAKE
									==> Position of every box is saved ( TopLeft and ButtonRight + color)
									==> box with color are declared as safe spot and their position are saved
									S===> SAFE SPOT, TOTAL BOXES===> 76

											  5 6 7
											  4   8  52
											  3   9  53
											  2   10 54
											  1   11 55
											  0   12 56
							46 47 48 49	50 51 	73  13 14 15 16 17 18
							45 67 68 69 70 71 72 74 61 60 59 58 57 19                    
							44 43 42 41 40 39  75   25 24 23 22 21 20
											38 62 26
											37 63 27	
											36 64 28
											35 65 29
											34 66 30
                                            33 32 31
													
													*/
		cc = BLACK ;


		// GRAY
		NOC = 0;
		int SBN = 52;
		for (int y = 0, k = 0; y < 276; y += 46, k++)
		{
			int a[10] = { 276,230-y,322,230 - y,322,276 - y,276,276 - y,276,230 - y };
			if (k==3)
			{
				cc = DARKGRAY; C[NOC].Issave = true;
			}
			setfillstyle(SOLID_FILL, cc);
			C[NOC].setcellPos(Position(276 , 230 - y), Position(322, 276 - y), cc);
			fillpoly(5, a);
			setfillstyle(SOLID_FILL, BLACK);
			cc = BLACK;
			NOC++;
		}
		
		for (int x = 46,i=1; x < 138; x += 46,i++)
		{
			for (int y = 0,k=0; y < 276; y += 46,k++)
			{
				int a[10] = { 276+x,0 + y,322 + x,0 + y,322 + x,46 + y,276 + x,46+y,276 + x,0+y };
				if ((i == 1 && k > 0))
				{
					cc = DARKGRAY; 
					C[SBN].setcellPos(Position(276 + x, 0 + y), Position(322 + x, 46 + y), cc);
					setfillstyle(SOLID_FILL, cc);

					fillpoly(5, a);

					SBN++;
					cc = BLACK;
					continue;
				}
				if ((i == 2 && k == 1))
				{
					cc = DARKGRAY;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 0 + y), Position(322 + x, 46 + y), cc);
				fillpoly(5, a);
				setfillstyle(SOLID_FILL, BLACK);
				cc = BLACK;
				NOC++;
			}
		}
		
		//blue
		
		for (int x = 0, k = 0; x < 276; x += 46, k++)
		{
			int g[10] = { 414 + x,276,460 + x,276,460 + x,322,414 + x,322,414 + x,276 };

			if ( k == 3 )
			{
				cc = BLUE; C[NOC].Issave = true;
			}
			setfillstyle(SOLID_FILL, cc);
			C[NOC].setcellPos(Position(414 + x, 276), Position(460 + x, 322), cc);
			fillpoly(5, g);
			setfillstyle(SOLID_FILL, BLACK);
			cc = BLACK;
			NOC++;
		}
		cc = BLACK;
		for (int y = 46, i = 1; y < 138; y += 46, i++)
		{
			for (int x = 230, k = 0; x >= 0; x -= 46, k++)
			{
				int g[10] = { 414 + x,276 + y,460 + x,276 + y,460 + x,322 + y,414 + x,322 + y,414 + x,276 + y };

				if ((i == 1 && k != 0))
				{
					cc = BLUE; C[SBN].Issave = true;
					C[SBN].setcellPos(Position(414 + x, 276 + y), Position(460 + x, 322 + y), cc);
					setfillstyle(SOLID_FILL, cc);

					fillpoly(5, g);
					cc = BLACK;
					SBN++;
					continue;
				}
				if ((i == 2 && k == 1))
				{
					cc = BLUE; C[NOC].Issave = true;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(414 + x, 276 + y), Position(460 + x, 322 + y), cc);
				fillpoly(5, g);
				setfillstyle(SOLID_FILL, BLACK);
				cc = BLACK;
				NOC++;
			}
		}
		////RED
		SBN = 66;
		for (int x = 92, i = 0; x > 0; x -= 46, i++)
		{
			for (int y = 0, k = 0; y < 276; y += 46, k++)
			{
				int a[10] = { 276 + x,414 + y,322 + x,414 + y,322 + x,460 + y,276 + x,460 + y,276 + x,414 + y };
				if ((i == 0 && k == 3))
				{
					cc = RED; C[NOC].Issave = true;
				}
				if ((i == 1 && k < 5))
				{
					cc = RED; C[SBN].Issave = true;
					C[SBN].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
					setfillstyle(SOLID_FILL, cc);
					fillpoly(5, a);
					cc = BLACK;
					SBN--;
					continue;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(276 + x, 414 + y), Position(322 + x, 460 + y), cc);
				fillpoly(5, a);
				setfillstyle(SOLID_FILL, BLACK);
				cc = BLACK;
				NOC++;
			}
		}
		NOC = 38;
		for (int y = 0, k = 0; y < 276; y += 46, k++)
		{
			int t[10] = { 276 ,414 + y,322 ,414 + y,322 ,460 + y,276 ,460 + y,276 ,414 + y };
			if (k == 4)
			{
				C[NOC].Issave = true; cc = RED;
			}
			setfillstyle(SOLID_FILL, cc);
			C[NOC].setcellPos(Position(276 , 414+y), Position(322 , 460+y), cc);
			fillpoly(5, t);
			setfillstyle(SOLID_FILL, BLACK);
			cc = BLACK;
			NOC--;
		}


		////
		////// GREEN
		////
		NOC = 39;
		SBN = 71;
		for (int y = 92, i = 0; y >=46; y -= 46, i++)
		{
			for (int x = 230, k = 0; x >= 0; x -= 46, k++)
			{
				int g[10] = { 0 + x,276 + y,46 + x,276 + y,46 + x,322 + y,0 + x,322 + y,0 + x,276 + y };
				if ((i == 0 && k == 3))
				{
					cc = GREEN; C[NOC].Issave = true;
				}
				if ((i == 1 && k < 5))
				{
					cc = GREEN; C[SBN].Issave = true;

					C[SBN].setcellPos(Position(0 + x, 276 + y), Position(46 + x, 322 + y), cc);
					setfillstyle(SOLID_FILL, cc);

					fillpoly(5, g);
					SBN--;
					cc = BLACK;
					continue;
				}
				setfillstyle(SOLID_FILL, cc);
				C[NOC].setcellPos(Position(0 + x, 276 + y), Position(46 + x, 322 + y), cc);
				fillpoly(5, g);


				setfillstyle(SOLID_FILL, BLACK);
				cc = BLACK;
				NOC++;
			}
		}

		for (int x = 0, k = 0; x <= 230; x+=46,k++)
		{
			if (k == 1)
			{
				cc = GREEN; C[NOC].Issave = true;
			}
			int g[10] = { 0 + x,276 ,46 + x,276 ,46 + x,322 ,0 + x,322 ,0 + x,276 };
			C[NOC].setcellPos(Position(0 + x, 276), Position(46 + x, 322),cc);
			setfillstyle(SOLID_FILL, cc);
			fillpoly(5, g);
			cc = BLACK;
			NOC++;
		}

		// arraay ka index for dice cell is 92,93,94;
		int K = 92;
		int db1[10] = { 800,150,846,150,846,196,800,196,800,150 };
		drawpoly(5, db1);
		C[K].setcellPos(Position(800, 150), Position(846, 196), BLACK); K++;

		int db2[10] = { 846,150,892,150,892,196,846,196,846,150 };
		drawpoly(5, db2);
		C[K].setcellPos(Position(846, 150), Position(892, 196), BLACK); K++;

		int db3[10] = { 892,150,938,150,938,196,892,196,892,150 };
		drawpoly(5, db3);
		C[K].setcellPos(Position(892, 150), Position(938, 196), BLACK); 

		
	}

	

	void DisplayDiceNo()
	{
		int diceindex = 92;
		dice.rolladice();
		
		for (int d = 0; d < 3; d++)
		{
			Position t1 = C[diceindex+d].getTL(), t2 = C[diceindex+d].getBR();
			Position P = C[diceindex+d].getcellcenter(t1, t2);
			int k = dice.diceno[d];
			stringstream strs;
			strs << k;
			string temp_str = strs.str();
			char* char_type = (char*)temp_str.c_str();
			outtextxy(P.x, P.y, char_type);
		}

		


	}

	bool isWin()
	{
		if (Players[Turn]->TokenReachDest==4)
			return true;
		else
			return false;
	}
	void inttocolor()
	{
		/*
				Players[3] = new Player(RED);
		Players[0]= new Player(GREEN);
		Players[1]= new Player(DARKGRAY);
		Players[2]= new Player(BLUE);
		*/
		if (Turn == 0)
		{
			turncolor = GREEN;
		}
		else if(Turn==1)
		{
			turncolor = DARKGRAY;
		}
		else if (Turn == 2)
		{
			turncolor = BLUE;
		}
		else
		{
			turncolor = RED;
		}
		
	}
	void StartGame()
	{
		// Why do we need this function when we already have init..?
	}

	void init()
	{
		Grid = new Token*[92];
		for(int i=0;i<92;++i)
			Grid[i]=nullptr;
		NoOfPlayers = 4;
		Turn = 0;
		turncolor = GREEN;
		MaxNoSteps = 55;
		Players = new Player*[4];
		Players[3] = new Player(RED);
		Players[0]= new Player(GREEN);
		Players[1]= new Player(DARKGRAY);
		Players[2]= new Player(BLUE);
		
		/*
		
											  5 6 7
											  4   8  52
											  3   9  53
											  2   10 54
											  1   11 55
											  0   12 56
							46 47 48 49	50 51 	    13 14 15 16 17 18
							45 67 68 69 70 71       61 60 59 58 57 19                    
							44 43 42 41 40 39       25 24 23 22 21 20
											38 62 26
											37 63 27	
											36 64 28
											35 65 29
											34 66 30
                                            33 32 31
													
		
		*/


			for (int i = 0; i < 4; i++)
			{
				Players[2]->PlayerTokens[i] = new BlueToken(BLUE, 84 + i, 21,57);
				Players[3]->PlayerTokens[i] = new RedToken(RED, 88+i, 34,62);
				Players[0]->PlayerTokens[i] = new GreenToken(GREEN, 76 + i, 47,67);
				Players[1]->PlayerTokens[i] = new YellowToken(DARKGRAY, 80 + i, 8,52);
			}
			int m = 0;
			for (int  i = 0; i < 4; i++)
			{
				for (int k = 0; k < 4; k++)
				{
					Grid[76 + m] = Players[i]->PlayerTokens[k];
					m++;
				}
			}


	}
	
	int choosingtoken()
	{
		Position p;
		mouseclick(p);
		for (int i = 0; i < 92; i++)
		{
			if (C[i].BoxConfirmation(p.x, p.y))
				return i;
		}
		return -1;
	}
	
	
	bool isValidSelection(int CellIndex, int DiceNo)
	{
		if (Grid[CellIndex] != NULL && Grid[CellIndex]->getColor() == turncolor)
		{
			if (Grid[CellIndex]->isAtHome())
			{
				if (DiceNo == 6)
					return true;
				else
					return false;
			}
			if (Grid[CellIndex]->StepsTaken() + DiceNo <= 55)
				return true;
			return false;
		}
		return false;
	}
	
	bool canContinue()
	{
		for(int i=0;i<4;++i)
		{
			if (Players[Turn]->PlayerTokens[i]->isAtHome())
			{
				if (dice.DiceNoAtIndex(0)==6)
					return true;
			}
			else if (Players[Turn]->PlayerTokens[i]->StepsTaken() + dice.DiceNoAtIndex(0) <= 55)
				return true;
		}
		return false;
	}
	void DrawToken()
	{
		for (int  i = 0; i < 92; i++)
		{
			if (Grid[i]!=NULL)
			{
				Position P = C[i].getcellcenter(C[i].getTL(), C[i].getBR());
				Grid[i]->DrawToken(P);
			}
		}
	}
	
	void updateBoard(int TokenIndex, int DiceNo)
	{
		if (Grid[TokenIndex]->isAtHome())
		{
			Grid[Grid[TokenIndex]->getInitialLocation()]=Grid[TokenIndex];
			// Draw Token at Grid[TokenIndex]->getInitialLocation()
			Grid[Grid[TokenIndex]->getInitialLocation()];
			Position P=C[Grid[TokenIndex]->getInitialLocation()].getcellcenter(C[Grid[TokenIndex]->getInitialLocation()].getTL(),
				C[Grid[TokenIndex]->getInitialLocation()].getBR());
			Grid[TokenIndex]->DrawToken(P);
			Grid[TokenIndex]->changeHomeStatus();
			Grid[TokenIndex]= nullptr;
			// Draw Cell[TokenIndex]
		}
		else
		{
			int Des = TokenIndex+DiceNo;
			if (Des>75)
			{
				Des-=76;
			}
			Grid[TokenIndex]->addSteps(DiceNo);
			if (Grid[TokenIndex]->StepsTaken() > Grid[TokenIndex]->getJumpStep())
			{
				Des = Grid[TokenIndex]->JumpIndex+(Grid[TokenIndex]->StepsTaken()-Grid[TokenIndex]->getJumpStep()-1);
			}
			else if (Grid[Des]!=nullptr)
			{
				Grid[Grid[Des]->getHomeIndex()] = Grid[Des];
				// Draw Token at Grid[Des]->getHomeIndex()
				Position P = C[Grid[Des]->getHomeIndex()].getcellcenter(C[Grid[Des]->getHomeIndex()].getTL(),
					C[Grid[Des]->getHomeIndex()].getBR());
				Grid[Des]->DrawToken(P);
				Grid[Des]->changeHomeStatus();
			}
			Grid[Des]=Grid[TokenIndex];
			// Draw Token at Des;
			Position P = C[Des].getcellcenter(C[Des].getTL(),C[Des].getBR());
			Grid[Des]->DrawToken(P);
			Grid[TokenIndex]=nullptr;
			// Draw Cell[TokenIndex]
			if (Grid[Des]->StepsTaken()==55)
			 	Players[Turn]->TokenReachDest++;
		}
	}
	void Displayindexofcell()
	{
		Position P;
		for (int i = 0; i < 92; i++)
		{
			P=C[i].getcellcenter(C[i].getTL(), C[i].getBR());
			stringstream strs;
			strs << i;
			string temp_str = strs.str();
			char* char_type = (char*)temp_str.c_str();
			outtextxy(P.x, P.y, char_type);
		}
	}

	void Play()
	{
		init();
		//StartGame();
		DisplayBoard();
		DrawToken();


		Displayindexofcell();



		do
		{
			DisplayPlayerMsg();
			DisplayDiceNo();
			int SelectBoxIndex;
			if (!canContinue())
			{
				ChangeTurn();
				dice.reset();
				continue;
			}
			int kuchb = 0;
			do 
			{
				do
				{
					do
					{
						SelectBoxIndex = choosingtoken();
					} while (SelectBoxIndex == -1);
					if (isValidSelection(SelectBoxIndex, dice.diceno[kuchb]) == false)
						outtextxy(750, 65, "oye sahi km kr bhai");

				} while (isValidSelection(SelectBoxIndex, dice.diceno[kuchb]) == false);
				kuchb++;
				updateBoard(SelectBoxIndex, dice.diceno[kuchb]);
			} while (dice.diceno[kuchb]==6);
			outtextxy(750, 65, "                       ");
			if (isWin())
			{
				WC++;
				WinPlayers.push_back(Turn);
				//UpdatePlayerList(Turn);
				// We have to find a way in which this player's turn does not come again.....?
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


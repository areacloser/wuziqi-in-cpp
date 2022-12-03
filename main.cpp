#include <graphics.h>
#include <conio.h>
#include <cmath>

int mp[19][19] = {0};
int rd = 1;
int over = 0;

int main()
{
	initgraph(780, 780);
	setbkcolor(RGB(211,211,211)); //light grey
	SetWindowText(GetHWnd(), "五子棋 V1.0.5 -- By lanlan2_    状态：黑方行子");
	cleardevice();
	
	setfillcolor(RGB(218,165,32)); //Golden rod
	setlinecolor(BLACK);
	
	//draw chessboard
	for (int i = 0; i < 18; i++)
	{
		for(int j = 0; j < 18; j++)
		{
			fillrectangle(j*40+30, i*40+30, j*40+70, i*40+70);
		}
	}
	
	setfillcolor(BLACK);
	
	for (int m = 0; m < 3; m++)
	{
		for (int n =0; n < 3; n++)
		{
			fillcircle(240*n+150, 240*m+150, 3);
		}
	}
	
	MOUSEMSG msg;
	while (true)
	{
		if (MouseHit() && over == 0)
		{
			msg = GetMouseMsg();
			switch (msg.uMsg)
			{
			case WM_LBUTTONDOWN:
				if (msg.x <= 770 && msg.x >= 10 && msg.y <= 770 && msg.y >= 10)
				{
					int x = floor((msg.x - 10) / 40);
					int y = floor((msg.y - 10) / 40);
					
					if (mp[y][x] == 0)
					{
						if (rd % 2 == 1)
						{
							setfillcolor(BLACK);
							mp[y][x] = 1;
							solidcircle(x*40+30, y*40+30, 20);
							
						}
						else
						{
							setfillcolor(WHITE);
							mp[y][x] = 2;
							solidcircle(x*40+30, y*40+30, 20);
						}
						rd++;
						
						//judge start
						int tr = rd % 2 + 1;
						int c1, c2, c3, c4 = 0;
						
						//horizontal
						for (int i = x - 4; i < x + 6; i++)
						{
							if (c1 == 5)
							{
								over = 1;
								break;
							}
							else
							{
								if (i <= 18 && i >= 0)
								{
									if (mp[y][i] == tr)
									{
										c1++;
									}
									else
									{
										c1 = 0;
									}
								}
							}
						}
						
						//vertical
						for (int i = y - 4; i < y + 6; i++)
						{
							if (c2 == 5)
							{
								over = 1;
								break;
							}
							else
							{
								if (i <= 18 && i >= 0)
								{
									if (mp[i][x] == tr)
									{
										c2++;
									}
									else
									{
										c2 = 0;
									}
								}
							}
						}
						
						//left-up and right-down
						for (int i = y - 4, j = x - 4; i < y + 6 && j < x + 6; i++, j++)
						{
							if (c3 == 5)
							{
								over = 1;
								break;
							}
							else
							{
								if (i <= 18 && i >= 0 && j <= 18 && j >= 0)
								{
									if (mp[i][j] == tr)
									{
										c3++;
									}
									else
									{
										c3 = 0;
									}
								}
							}
						}
						
						//right-up and left-down
						for (int i = y - 4, j = x + 4; i < y + 6 && j > x - 6; i++, j--)
						{
							if (c4 == 5)
							{
								over = 1;
								break;
							}
							else
							{
								if (i <= 18 && i >= 0 && j <= 18 && j >= 0)
								{
									if (mp[i][j] == tr)
									{
										c4++;
									}
									else
									{
										c4 = 0;
									}
								}
							}
						}
						
						HWND hnd = GetHWnd();
						if (over == 1)
						{
							if (tr == 1)
							{
								SetWindowText(hnd, "五子棋 V1.0.5 -- By lanlan2_    状态：黑方获胜");
								MessageBox(hnd, "黑方获胜！", "提示", MB_OK);
							}
							else
							{
								SetWindowText(hnd, "五子棋 V1.0.5 -- By lanlan2_    状态：白方获胜");
								MessageBox(hnd, "白方获胜！", "提示", MB_OK);
							}
						}
						else
						{
							if (tr == 1)
							{
								SetWindowText(hnd, "五子棋 V1.0.5 -- By lanlan2_    状态：白方行子");
							}
							else
							{
								SetWindowText(hnd, "五子棋 V1.0.5 -- By lanlan2_    状态：黑方行子");
							}
						}
					}
				}
				break;
			}
		}
	}
	
	getch();
	closegraph();
	
	return 0;
}

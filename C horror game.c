#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#pragma warning(disable:4996)

#define MAP_MAXSIZE_X 45
#define MAP_MAXSIZE_Y 45

int MID_X = 16; //중앙 정렬
int MID_Y = 10; //중앙 정렬

#define TRUE 1
#define FALSE 0


struct entity {
	int x, y;
	int isMove;
	int eraseForAfterImage;
	int entitySizeX, entitySizeY;
};

int map[MAP_MAXSIZE_Y][MAP_MAXSIZE_X] = { 0, };

int theRoom[MAP_MAXSIZE_Y][MAP_MAXSIZE_X] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

int playerImage[2][1] = {
	{1},
	{1}
};




enum colorName
{
	BLACK,
	D_BLUE,
	D_GREEN,
	D_SKYBLUE,
	D_RED,
	D_VIOLET,
	D_YELLOW,
	GRAY,
	D_GRAY,
	BLUE,
	GREEN,
	SKYBLUE,
	RED,
	VIOLET,
	YELLOW,
	WHITE,
};

void color(int bgColor, int textColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bgColor * 16 + textColor);
}

int gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void CursorView(int show) // 입력 커서 제거
{
	HANDLE hConsole;
	CONSOLE_CURSOR_INFO ConsoleCursor;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	ConsoleCursor.bVisible = show;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}

void printEntity(struct entity *Entity, int isPlayer)
{
	for (int i = Entity->entitySizeY - 1; i >= 0; i--)
	{
		for (int j = 0; j < Entity->entitySizeX; j++)
		{
			gotoxy((Entity->x + j + MID_X) * 2, Entity->y - i + MID_Y);

			if (isPlayer == TRUE)
			{
				switch (playerImage[i][j])
				{
				case 0:
					color(WHITE, WHITE);
					break;
				case 1:
					color(D_GREEN, GREEN);
					i == 1 ?
					puts("US"):
					puts("ER");
					break;
				}
				//puts("  ");
			}
		}
	}
}

void mapBackup(struct entity* Entity, int direction)
{
	for (int i = Entity->entitySizeY - 1; i >= 0; i--)
	{
		for (int j = 0; j < Entity->entitySizeX; j++)
		{
			gotoxy((Entity->x + j + MID_X) * 2, Entity->y - i + MID_Y);
			switch (theRoom[Entity->y - i][Entity->x + j])
			{
			case 0:
				color(D_GRAY, GRAY);
				break;
			case 1:
				color(BLACK, BLACK);
				break;
			case 2:
				color(WHITE, WHITE);
				break;
			}
			puts("  ");
		}
	}
}

int fullScreen()
{
	//int width = GetSystemMetrics(SM_CXSCREEN);
	//int height = GetSystemMetrics(SM_CXSCREEN);

	//HWND hwnd = CreateWindow(szWindowClass, szTitle, WS_EX_TOPMOST | WS_POPUP,
	//	0, 0, width, height, NULL, NULL, hInstance, NULL);

	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

int main(void)
{
	struct entity player;

	int hasKey = 0;

	fullScreen();
	Sleep(250);
	CursorView(0);

	player.entitySizeX = 1;
	player.entitySizeY = 2;
	player.x = 4;//(MAP_MAXSIZE_X - 1) / 2;
	player.y = (MAP_MAXSIZE_Y - 1) / 2;


	for (int i = 0; i < MAP_MAXSIZE_Y;i++)
	{
		for (int j = 0; j < MAP_MAXSIZE_X; j++)
		{
			gotoxy((j + MID_X) * 2, i + MID_Y);

			switch (theRoom[i][j])
			{
			case 0:
				color(D_GRAY, GRAY);
				break;
			case 1:
				color(BLACK, BLACK);
				break;
			case 2:
				color(WHITE, WHITE);
				break;
			}
			puts("  ");
		}
	}

	/*player printing*/
	printEntity(&player, TRUE);
	while (1)
	{
		if (kbhit())
		{
			player.isMove = getch();
			/*erase player afterImage*/
			mapBackup(&player, player.isMove);
			switch (player.isMove)
			{
			case 'w':
				if (player.y > 1 && theRoom[player.y - 2][player.x] != 1)
				{
					if (theRoom[player.y - 2][player.x] == 2)
					{
						if (hasKey == 1)
						{
							theRoom[player.y - 2][player.x] = 0;
							player.y--;
						}
						else
						{
							gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
							color(BLACK, WHITE);
							puts("열쇠가 필요합니다.");
						}
					}
					else
						player.y--;
				}
				break;
			case 'a':
				if (player.x > 0 && (theRoom[player.y][player.x - 1] != 1 && theRoom[player.y - 1][player.x - 1] != 1))
				{
					if (theRoom[player.y][player.x - 1] == 2 && theRoom[player.y - 1][player.x - 1] == 2)
					{
						if (hasKey == 1)
						{
							theRoom[player.y - 1][player.x - 1] = 0;
							theRoom[player.y][player.x - 1] = 0;
							player.x--;
						}
						else
						{
							gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
							color(BLACK, WHITE);
							puts("열쇠가 필요합니다.");
						}
					}
					else
						player.x--;
				}
				break;
			case 's':
				if (player.y  < MAP_MAXSIZE_Y -1 && theRoom[player.y + 1][player.x] != 1)
				{
					if (theRoom[player.y + 1][player.x] == 2)
					{
						if (hasKey == 1)
						{
							theRoom[player.y + 1][player.x] = 0;
							player.y++;
						}
						else
						{
							gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
							color(BLACK, WHITE);
							puts("열쇠가 필요합니다.");
						}
					}
					else
						player.y++;
				}
				break;
			case 'd':
				if (player.x  < MAP_MAXSIZE_X -1 && (theRoom[player.y][player.x + 1] != 1 && theRoom[player.y - 1][player.x + 1] != 1))
				{
					if (theRoom[player.y][player.x + 1] == 2 && theRoom[player.y - 1][player.x + 1] == 2)
					{
						if (hasKey == 1)
						{
							theRoom[player.y - 1][player.x + 1] = 0;
							theRoom[player.y][player.x + 1] = 0;
							player.x++;
						}
						else
						{
							gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
							color(BLACK, WHITE);
							puts("열쇠가 필요합니다.");
						}
					}
					else
						player.x++;
				}
				break;
			case 27: //esc
				return 0;
			case 'e':
				hasKey = 1;
				gotoxy((MAP_MAXSIZE_X / 2 - 5 + MID_X) * 2, MAP_MAXSIZE_Y + 1 + MID_Y);
				color(BLACK, WHITE);
				puts("                    ");
				break;
			case 'f':
				hasKey = 0;
				break;
			}
			/*player printing*/
			printEntity(&player, TRUE);
		}
	}
}

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#pragma warning(disable:4996)

#define MAP_MAXSIZE_X 10
#define MAP_MAXSIZE_Y 10
#define TRUE 1
#define FALSE 1


struct entity {
	int x, y;
	int isMove;
	int eraseForAfterImage;
	int entitySizeX, entitySizeY;
};

int map[MAP_MAXSIZE_Y][MAP_MAXSIZE_X] = { 0, };

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
			gotoxy((Entity->x + j) * 2, Entity->y - i);

			if (isPlayer == TRUE)
			{
				switch (playerImage[i][j])
				{
				case 0:
					color(WHITE, WHITE);
					break;
				case 1:
					color(BLACK, BLACK);
				}
				puts("  ");
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
			gotoxy((Entity->x + j) * 2, Entity->y - i);
			switch (map[Entity->y][Entity->x])
			{
			case 0:
				color(WHITE, WHITE);
				break;
			case 1:
				color(BLACK, BLACK);
			}
			puts("  ");
		}
	}
}

int main(void)
{
	struct entity player;

	CursorView(0);

	player.entitySizeX = 1;
	player.entitySizeY = 2;
	player.x = (MAP_MAXSIZE_X - 1) / 2;
	player.y = (MAP_MAXSIZE_Y - 1) / 2;


	for (int i = 0; i < MAP_MAXSIZE_Y;i++)
	{
		for (int j = 0; j < MAP_MAXSIZE_X; j++)
		{
			gotoxy(j * 2, i);

			switch (map[i][j])
			{
			case 0:
				color(WHITE, WHITE);
				break;
			case 1:
				color(BLACK, BLACK);
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
				if (player.y > 1)
				{
					player.y--;
				}
				break;
			case 'a':
				if (player.x > 0)
				{
					player.x--;
				}
				break;
			case 's':
				if (player.y  < MAP_MAXSIZE_Y -1)
				{
					player.y++;
				}
				break;
			case 'd':
				if (player.x  < MAP_MAXSIZE_X -1)
				{
					player.x++;
				}
				break;
			case 27: //esc
				return 0;
			}
			/*player printing*/
			printEntity(&player, TRUE);
		}
	}
}

#include <iostream>
#include <Windows.h>
#include "ScrollGame.h"
#include <unordered_map>

using namespace std;

int px = startX;
int py = startY;
int jumpCount = 0;
int maxpx = startScroll;
int coin = 0;
bool jumping = false;
bool gaming = true;
bool coinFront = true;
char screen[screenHeight][screenWidth];
char collisionMap[height][width];
char startMap[height][width];

std::unordered_set<char> airBlock = { ' ', 'c', 'm', 'f', 'g', 's', 'w', 'x', 'j' };
std::unordered_set<char> breakbleBlock = { 'd', 'r' };

void setColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD coord = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void setPlayer()
{
	map[startY][startX] = 'p';
}

void draw()
{
	unordered_map<char, string> symbols = {
		{'p', "足"},
		{'d', "田"},
		{'b', "■"},
		{'y', "■"},
		{'x', "■"},
		{'w', "▲"},
		{'j', "■"},
		{'r', "？"},
		{'l', "｜"},
		{'n', "▲"},
		{'c', "++"},
		{'g', "Ｗ"},
		{'m', "へ"},
		{'q', "□"},
		{'f', coinFront ? "Ｏ" : "ｌ"},
		{'s', ". "},
		{' ', "  "}
	};

	unordered_map<char, int> colors = {
		{'p',  3},
		{'d',  4},
		{'b',  6},
		{'y',  2},
		{'x', 15},
		{'w',  4},
		{'j',  1},
		{'r', 14},
		{'l', 15},
		{'n',  3},
		{'c',  7},
		{'g',  2},
		{'m', 10},
		{'q', 10},
		{'f', 14},
		{'s', 14},
		{' ', 15}
	};

	gotoxy(0, 0);
	for (int i = 0; i < screenHeight; i++) {
		for (int j = 0; j < screenWidth; j++) {
			setColor(colors[screen[i][j]]);
			cout << symbols[screen[i][j]];
		}
		cout << '\n';
	}

	if (coinFront)
		coinFront = false;
	else
		coinFront = true;
}

void hideCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

inline void swap(char& a, char& b)
{
	char n = a;
	a = b;
	b = n;
}

void setLayer()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			if (airBlock.count(collisionMap[i][j])) {
				if (!(map[i][j] == 'p'))
					map[i][j] = collisionMap[i][j];
			}
		}
}

void moveLeft()
{
	if (airBlock.count(map[py][px - 1]) && px - (maxpx - startScroll) > 0)
	{
		swap(map[py][px], map[py][px - 1]);
		px--;
	}
}

void moveRight()
{
	if (airBlock.count(map[py][px + 1] ))
	{
		swap(map[py][px], map[py][px + 1]);
		px++;
	}
}

void jump()
{
	if (jumping)
	{
		if (airBlock.count(map[py - 1][px]) && jumpCount < jumpPower)
		{
			swap(map[py][px], map[py - 1][px]);
			jumpCount++;
			py--;
		}
		else
		{
			jumping = false;
			jumpCount = 0;
		}
	}
}

void fall()
{
	if (!jumping)
	{
		if (airBlock.count(map[py + 1][px]))
		{
			swap(map[py][px], map[py + 1][px]);
			py++;
		}
	}
}

void restart()
{
	system("cls");

	//マップリセット
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			map[i][j] = startMap[i][j];
			collisionMap[i][j] = startMap[i][j];
		}

	setPlayer();
	px = startX;
	py = startY;
	maxpx = startScroll;
	jumping = false;
	coin = 0;
	gaming = true;
}

void gameOver()
{
	gaming = false;
	gotoxy(0, 21);
	setColor(7);
	cout << "gameover!";
}

void gameclear()
{
	gaming = false;
	gotoxy(0, 21);
	setColor(7);
	cout << "gameclear!";
}

void breakBlock()
{
	jumping = false;
	jumpCount = 0;

	if (map[py - 1][px] == 'r') {
		collisionMap[py - 1][px] = 'f';
	}
	else {
		map[py - 1][px] = ' ';
	}
}

void saveStartMap()
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++) {
			collisionMap[i][j] = map[i][j];
			startMap[i][j] = map[i][j];
		}
}

void scroll()
{
	for (int i = 0; i < screenHeight; i++)
		for (int j = 0; j < screenWidth; j++) {
			if (px > maxpx)
				screen[i][j] = map[i][j + (maxpx - startScroll) + 1];
			else if (j + (maxpx - startScroll) < width)
				screen[i][j] = map[i][j + (maxpx - startScroll)];
			else if ((j + (maxpx - startScroll)) >= width)
				;
			else
				screen[i][j] = map[i][j];
		}
}
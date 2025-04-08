#include <iostream>
#include <Windows.h>
#include "ScrollGame.h"

int main()
{
	/*const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_FONT_INFOEX info = { sizeof info };
	info.dwFontSize.X = 15;
	info.dwFontSize.Y = 30;
	SetCurrentConsoleFontEx(hConsole, 0, &info);*/
	hideCursor();
	saveStartMap();
	setPlayer();

	while (true)
	{
		draw();

		if (gaming)
		{
			if (GetAsyncKeyState(VK_LEFT) || GetAsyncKeyState('A'))
				moveLeft();

			if (GetAsyncKeyState(VK_RIGHT) || GetAsyncKeyState('D'))
				moveRight();

			if ((GetAsyncKeyState(VK_UP) || GetAsyncKeyState('W')) && !(airBlock.count(map[py + 1][px])))
				jumping = true;

			jump();

			fall();
		}
		else
		{
			gotoxy(0, 22);
			setColor(7);
			std::cout << "もう一度プレイ : R";
			if (GetAsyncKeyState('R'))
				restart();
		}

		if (breakbleBlock.count(map[py - 1][px]))
			breakBlock();

		if (collisionMap[py][px] == 'f')
		{
			collisionMap[py][px] = ' ';
			coin++;
		}

		setLayer();

		scroll();
	
		if (px > maxpx)
			maxpx = px;

		if (py == height - 1)
			gameOver();

		if (screen[py][px - (maxpx - startScroll) + 1] == 'l' || screen[py][px - (maxpx - startScroll) + 1] == 'n')
			gameclear();

		gotoxy(0, 20);
		setColor(7);
		std::cout << "X:" << px << " Y:" << py << " coin:" << coin;

		Sleep(100);
	}
}
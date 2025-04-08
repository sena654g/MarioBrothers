#include <iostream>
#include <unordered_set>

#ifndef FUNCTION
#define FUNCTION

void gotoxy(int x, int y);
void draw();
void hideCursor();
void swap(char& a, char& b);
void moveLeft();
void moveRight();
void jump();
void fall();
void restart();
void gameOver();
void gameclear();
void breakBlock();
void saveStartMap();
void setColor(int Color);
void setLayer();
void scroll();
void setPlayer();

const int jumpPower = 3;
const int startScroll = 10;
const int startX = 3;
const int startY = 14;
const int height = 20;
const int width = 201;
const int screenHeight = 20;
const int screenWidth = 21;

extern int px;
extern int py;
extern int jumpCount;
extern int maxpx;
extern int coin;
extern bool jumping;
extern bool gaming;
extern bool coinFront;
extern char screen[screenHeight][screenWidth];
extern char collisionMap[height][width];
extern char map[height][width];
extern char startMap[height][width];
extern std::unordered_set<char> airBlock, breakbleBlock;

#endif
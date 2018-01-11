#ifndef VGADRAW_H_
#define VGADRAW_H_

void drawPixel(int x_pos, int y_pos, int turn,int page);

void drawLine(int x_pos, int y_pos, int turn,int page);
void drawLine2(int x_pos, int y_pos, int turn,
               int page,int num0,int num1, int num2,int num3, int num4,
               int num5, int num6,int num7);

void drawLetter (char letter, int x_pos, int y_pos, int turn, int page);

void DrawNumber(int number, int x_pos, int y_pos, int turn,int page);

void drawFood(int color);
void drawBuy (int cursor0);

void drawDie(int x_pos, int y_pos, int color, int page);
void drawWin(int x_pos, int y_pos, int color, int page);

void drawWelcome();

void DrawNumbers(int number, int x_pos, int y_pos, int turn, int page);

void drawFoodNum(int pig, int food, int hp, int money, int grownPig);

//void drawFrame (void);

void DrawBoard (void);

void DrawChess (int x_pos, int y_pos, int turn);

void EraseCursor (int x_pos, int y_pos);

void DrawTime(int time, int turn);

void DrawWinning(int x_pos, int y_pos, int turn);

void drawP(int x_pos, int y_pos, int turn);
void drawC(int x_pos, int y_pos, int turn);

void DrawStatus(int x_pos, int y_pos, int turn,int status);

void DrawBack(int x_pos, int y_pos,int turn);

#endif

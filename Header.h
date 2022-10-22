/*This game rule is 
1.when the snake eat '¡Ø' the game is over
2. when it eat '¡×' , it becomes score lose -10. and when socre becomes minus, the game is over
3.when it eat '¡Ù', speed becomes slow to +5 for 10 seconds.So snake can eat easily food.
(I used clock(); )
4.when the score becomes 100 points, Level2 game is start=> start screen is drawn. and 10 bombs are made 
After it becomes 200 points, Level 3 game is start => start screen is drawn, and 15 bombs are made.
(I used array to make bombs)*/


#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>


#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define PAUSE 112
#define ESC 27

#define MAP_ADJ_X 3
#define MAP_ADJ_Y 2
#define MAP_X 30
#define MAP_Y 20

void gotoxy(int x, int y, char* s);
void title(void);
void reset(void);
void draw_map(void);
void move(int dir);
void pause(void);
void game_over(void);
void food(void);
void bomb(void);
void status(void);
void reset1(void);
void Init();

typedef struct Snake {
	int x[100], y[100];
	int food_x, food_y;
	int bomb_x[15];
	int bomb_y[15];
	int length;
	int speed;
	int score;
	int best_score;//
	int last_score;//
	int dir;
	int key;
	int status_on;//
	int n;
	int p;//variable for startime 
	int q;//condition when snake eat star.

}snake;
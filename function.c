#include "Header.h"

extern snake s1;

void bomb(void) {
	int i;
	int bomb_crush_on = 0;
	int k;
	int s;
	int r = 0;
	int j = s1.n;

	while (1) {
		int bomb_crush_on = 0;//need for initialize

		srand((unsigned)time(NULL) + r);
		for (i = 0; i < s1.n; i++) {
			s1.bomb_x[i] = (rand() % (MAP_X - 2)) + 1;
			s1.bomb_y[i] = (rand() % (MAP_Y - 2)) + 1;
		}
		for (i = 0; i < s1.length; i++) {
			for (k = 0; k < s1.n; k++) {
				if (s1.bomb_x[k] == s1.x[i] && s1.bomb_y[k] == s1.y[i]) {
					bomb_crush_on = 1;
					r++;
					s = 1;
					break;
				}
			}
			if (s = 1) break;

		}
	
		//should not same location with food
		for (i = 0; i < s1.n; i++) {
			if (s1.bomb_x[i] == s1.food_x &&s1.bomb_y[i] == s1.food_y)
			{
				bomb_crush_on = 1;;
				r++;

				break;
			}
		}
		//should not same location with bombs
		for (i = 0; i < s1.n - 1; i++) {
			for (k = 1; k < j; k++) {
				if (s1.bomb_x[i] == s1.bomb_x[i + k] && s1.bomb_y[i] == s1.bomb_y[i + k])
				{
					bomb_crush_on = 1;
					r++;
					s = 1;
					break;
				}	j--;

			}
			if (s = 1)break;
		}

		if (bomb_crush_on == 1) continue;

		if (s1.n == 5 || s1.n == 15) {
			for (i = 0; i < s1.n / 2; i++) {
				gotoxy(MAP_ADJ_X + s1.bomb_x[2 * i], MAP_ADJ_Y + s1.bomb_y[2 * i], "『");
			}
			for (i = 0; i < s1.n / 2; i++) {
				gotoxy(MAP_ADJ_X + s1.bomb_x[2 * i + 1], MAP_ADJ_Y + s1.bomb_y[2 * i + 1], "」");
			}
			gotoxy(MAP_ADJ_X + s1.bomb_x[s1.n - 1], MAP_ADJ_Y + s1.bomb_y[s1.n - 1], "』");
		}
		if (s1.n == 10) {
			for (i = 0; i < s1.n / 2; i++) {
				gotoxy(MAP_ADJ_X + s1.bomb_x[2 * i], MAP_ADJ_Y + s1.bomb_y[2 * i], "『");
			}
			for (i = 0; i < (s1.n / 2) - 1; i++) {
				gotoxy(MAP_ADJ_X + s1.bomb_x[2 * i + 1], MAP_ADJ_Y + s1.bomb_y[2 * i + 1], "」");
			}
			gotoxy(MAP_ADJ_X + s1.bomb_x[s1.n - 1], MAP_ADJ_Y + s1.bomb_y[s1.n - 1], "』");
		}

		break;
	}
}

void food(void) {
	int i;


	int food_crush_on = 0;
	int r = 0;
	gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y, " YOUR SCORE: ");
	printf("%3d, LAST SCORE: %3d, BEST SCORE: %3d", s1.score, s1.last_score, s1.best_score);

	while (1) {
		food_crush_on = 0;
		srand((unsigned)time(NULL) + r);
		s1.food_x = (rand() % (MAP_X - 2)) + 1;
		s1.food_y = (rand() % (MAP_Y - 2)) + 1;

		for (i = 0; i<s1.length; i++) {
			if (s1.food_x == s1.x[i] && s1.food_y == s1.y[i]) {
				food_crush_on = 1;
				r++;
				break;
			}
		}
		if (food_crush_on == 1) continue;

		gotoxy(MAP_ADJ_X + s1.food_x, MAP_ADJ_Y + s1.food_y, "∪");
		if (s1.score < 100)
		{
			s1.speed -= 3;
		}
		if (100 <= s1.score && s1.score < 200) {// <= or >= and < or > can't use together.
			s1.speed -= 5;
		}
		if (s1.score >= 200) {
			s1.speed -= 7;
		}
		break;

	}
}

void status(void) {
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y, "head= ");
	printf("%2d,%2d", s1.x[0], s1.y[0]);
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 1, "food= ");
	printf("%2d,%2d", s1.food_x, s1.food_y);
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 2, "leng= ");
	printf("%2d", s1.length);
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 3, "key= ");
	printf("%3d", s1.key);
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 4, "spd= ");
	printf("%3d", s1.speed);
	gotoxy(MAP_ADJ_X + MAP_X + 1, MAP_ADJ_Y + 6, "score= ");
	printf("%3d", s1.score);
}
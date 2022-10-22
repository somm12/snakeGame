#include "Header.h"

extern snake s1;


void move(int dir) {
	int i, t;
	int startime;
	int endtime;

	if (s1.x[0] == s1.food_x && s1.y[0] == s1.food_y) {
		s1.score += 10;
		for (i = 0; i < s1.n; i++) {
			gotoxy(MAP_ADJ_X + s1.bomb_x[i], MAP_ADJ_Y + s1.bomb_y[i], "  ");
		}

		gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y, " YOUR SCORE: ");
		printf("%3d, LAST SCORE: %3d, BEST SCORE: %3d", s1.score, s1.last_score, s1.best_score);
		if (s1.score < 100)
			s1.n = 5;
		if (s1.score >= 100 && s1.score < 200)
			s1.n = 10;
		if (s1.score >= 200)
			s1.n = 15;

		if (s1.score == 100) {
			reset1();
		}
		if (s1.score == 200) {
			reset1();
		}

		food();
		bomb();

		
		s1.length++;
		s1.x[s1.length - 1] = s1.x[s1.length - 2];
		s1.y[s1.length - 1] = s1.y[s1.length - 2];

	}


	if (s1.x[0] == 0 || s1.x[0] == MAP_X - 1 || s1.y[0] == 0 || s1.y[0] == MAP_Y - 1) {
		game_over();
		return;
	}
	for (i = 1; i<s1.length; i++) {
		if (s1.x[0] == s1.x[i] && s1.y[0] == s1.y[i]) {
			game_over();
			return;
		}
	}
	if (s1.n == 5 || s1.n == 15) {
		for (i = 0; i < s1.n / 2; i++) {
			if (s1.bomb_x[2 * i] == s1.x[0] && s1.bomb_y[2 * i] == s1.y[0])
			{
				game_over();
				return;
			}
		}
	}
	if (s1.n == 10) {
		for (i = 0; i < s1.n / 2; i++) {
			if (s1.bomb_x[2 * i] == s1.x[0] && s1.bomb_y[2 * i] == s1.y[0])
			{
				game_over();
				return;
			}
		}

	}

	endtime = clock();
	t = (endtime - s1.p) / 1000;
	if (t >= 10 && s1.q == 1)
	{
		s1.speed -= 5;
		s1.p = 0;
		s1.q = 0;
		t = 0;

	}
	if (s1.bomb_x[s1.n - 1] == s1.x[0] && s1.bomb_y[s1.n - 1] == s1.y[0])
	{
		s1.speed += 5;
		startime = clock();
		s1.q = 1;
		if (s1.p == 0) {
			s1.p = startime;
		}
	}
	if (s1.n == 10) {
		for (i = 0; i < (s1.n / 2) - 1; i++) {
			if (s1.bomb_x[2 * i + 1] == s1.x[0] && s1.bomb_y[2 * i + 1] == s1.y[0]) {
				s1.speed += 3;
				s1.score -= 10;
				gotoxy(MAP_ADJ_X + s1.x[s1.length - 1], MAP_ADJ_Y + s1.y[s1.length - 1], "  ");
				gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y, " YOUR SCORE: ");
				printf("%3d, LAST SCORE: %3d, BEST SCORE: %3d", s1.score, s1.last_score, s1.best_score);
				s1.length--;
				if (s1.length < 3 || s1.score < 0) {
					game_over();

					return;
				}

				if (s1.speed == 82) {
					game_over();

					return;
				}
			}
		}
	}
	if (s1.n == 5 || s1.n == 15) {
		for (i = 0; i <s1.n / 2; i++) {
			if (s1.bomb_x[2 * i + 1] == s1.x[0] && s1.bomb_y[2 * i + 1] == s1.y[0]) {
				s1.speed += 3;
				s1.score -= 10;
				gotoxy(MAP_ADJ_X + s1.x[s1.length - 1], MAP_ADJ_Y + s1.y[s1.length - 1], "  ");
				gotoxy(MAP_ADJ_X, MAP_ADJ_Y + MAP_Y, " YOUR SCORE: ");
				printf("%3d, LAST SCORE: %3d, BEST SCORE: %3d", s1.score, s1.last_score, s1.best_score);																   //(어? 이미 길이가 5네? 그냥 그러고 있는거얌.)해결된거지
				s1.length--;
						
				if (s1.length < 3 || s1.score < 0) {
					game_over();

					return;
				}

				if (s1.speed == 82) {
					game_over();

					return;
				}
			}
		}
	}
	gotoxy(MAP_ADJ_X + s1.x[s1.length - 1], MAP_ADJ_Y + s1.y[s1.length - 1], "  ");
	for (i = s1.length - 1; i>0; i--) {
		s1.x[i] = s1.x[i - 1];
		s1.y[i] = s1.y[i - 1];
	}
	gotoxy(MAP_ADJ_X + s1.x[0], MAP_ADJ_Y + s1.y[0], "ㅇ");
	if (dir == LEFT) --s1.x[0];
	if (dir == RIGHT) ++s1.x[0];
	if (dir == UP) --s1.y[0];
	if (dir == DOWN) ++s1.y[0];
	gotoxy(MAP_ADJ_X + s1.x[0], MAP_ADJ_Y + s1.y[0], "ㅎ");


}

void pause(void) {
	while (1) {
		if (s1.key == PAUSE) {
			gotoxy(MAP_ADJ_X + (MAP_X / 2) - 9, MAP_ADJ_Y, "< PAUSE : PRESS ANY KEY TO RESUME > ");
			Sleep(400);
			gotoxy(MAP_ADJ_X + (MAP_X / 2) - 9, MAP_ADJ_Y, "                                    ");
			Sleep(400);
		}
		else {
			draw_map();
			return;
		}
		if (_kbhit()) {

			do {
				s1.key = _getch();
			} while (s1.key == 224);
		}

	}
}

#include "Header.h"

extern snake s1;

void Init()
{
	s1.best_score = 0;
	s1.last_score = 0;
	s1.status_on = 0;
	s1.p = 0;
	s1.q = 0;
}
void reset(void) {
	int i;
	system("cls");
	draw_map();
	while (_kbhit()) _getch();

	s1.dir = LEFT;
	s1.speed = 100;
	s1.length = 5;
	s1.score = 0;
	for (i = 0; i<s1.length; i++) {
		s1.x[i] = MAP_X / 2 + i;
		s1.y[i] = MAP_Y / 2;
		gotoxy(MAP_ADJ_X +s1.x[i], MAP_ADJ_Y + s1.y[i], "¤·");
	}
	gotoxy(MAP_ADJ_X + s1.x[0], MAP_ADJ_Y + s1.y[0], "¤¾");
	food();
	s1.n = 5;
	bomb();
}

void reset1(void) {

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 5, "+--------------------------+");
	if (s1.score == 100) {
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 6, "|     S N A K E Level2     |");
	}
	if (s1.score == 200) {
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 6, "|     S N A K E Level3     |");
	}
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 7, "+--------------------------+");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 11, "   ¡Þ ¡ç,¡æ,¡è,¡é : Move    ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 12, "   ¡Þ P : Pause             ");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 13, "   ¡Þ ESC : Quit              ");

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 17, "  iThings Lab");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, " < PRESS ANY KEY TO START > ");
	Sleep(400);
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, "                            ");
	Sleep(400);
	while (1) {
		
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, " < PRESS ANY KEY TO START > ");
		Sleep(400);
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 9, "                            ");
		Sleep(400);
		if (_kbhit()) {
			_getch();
			draw_map();
			do {
				s1.key = _getch();
			} while (s1.key == 224);

			break;
		}

	}
	system("cls");
	draw_map();

}

void game_over(void) {
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 5, "+----------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 6, "|      GAME OVER..     |");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 7, "+----------------------+");
	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 6, MAP_ADJ_Y + 8, " YOUR SCORE : ");
	printf("%d", s1.last_score = s1.score);

	gotoxy(MAP_ADJ_X + (MAP_X / 2) - 7, MAP_ADJ_Y + 12, " Press any keys to restart.. ");

	if (s1.score>s1.best_score) {
		s1.best_score = s1.score;
		gotoxy(MAP_ADJ_X + (MAP_X / 2) - 4, MAP_ADJ_Y + 10, "¡Ù BEST SCORE ¡Ù");
	}
	Sleep(500);
	while (_kbhit()) _getch();
	s1.key = _getch();
	title();
}
#include "Header.h"

snake s1;

////////////////////////////MAIN START//////////////////////////////
int main() {
	title();

	while (1) {
		if (_kbhit()) do { s1.key = _getch(); } while (s1.key == 224);
		Sleep(s1.speed);

		switch (s1.key) {
		case LEFT:
		case RIGHT:
		case UP:
		case DOWN:
			if ((s1.dir == LEFT && s1.key != RIGHT) || (s1.dir == RIGHT && s1.key != LEFT) || (s1.dir == UP && s1.key != DOWN) ||
				(s1.dir == DOWN && s1.key != UP))
				s1.dir = s1.key;
			s1.key = 0;
			break;
		case PAUSE:
			pause();
			break;
		case 115:
			if (s1.status_on == 0) s1.status_on = 1;
			else s1.status_on = 0;
			s1.key = 0;
			break;
		case ESC:
			exit(0);

		}
		move(s1.dir);
		if (s1.status_on == 1) status();
	}

}
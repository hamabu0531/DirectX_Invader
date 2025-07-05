#include "DXLib.h"
#include "Enemy.h"
#include "Shot.h"
#include "keyboard.h"
#include "Game.h"
#include <stdlib.h>

// ������������
void Enemy_Initialize(Enemy_t* Enemy, int x, int y) {
	Enemy->Image = LoadGraph("images/ufo.png");
	Enemy->x = x;
	Enemy->y = y;
	Enemy->state = 0;
	Enemy->e_count = 0;
	Enemy->rl = 0;
}

// �������v�Z����
int Enemy_Calc(Enemy_t* Enemy, Shot_t* Shot) {
	int step = 10;

	// ����
	if (Enemy->state == 0) {
		if (Enemy->e_count > step + rand() % 5) {
			Enemy->y++;
			Enemy->rl++;
			Enemy->e_count = 0;
		}
		else if (Enemy->rl % 2 == 0) {
			Enemy->x++;
			if (Enemy->x > WIDTH) {
				Enemy->x = WIDTH - 1;
			}
			Enemy->e_count++;
		}
		else if (Enemy->rl % 2 != 0) {
			Enemy->x--;
			if (Enemy->x < 0) {
				Enemy->x = 0 + 1;
			}
			Enemy->e_count++;
		}
	}

	// Hit
	if (Enemy->state == 0) {
		if (Enemy->x < Shot->x + 6 && Shot->x + 7 < Enemy->x + 28 && Enemy->y < Shot->y + 5 && Shot->y + 5 < Enemy->y + 16
			&& Enemy->x > 0 && Enemy->x < WIDTH && Enemy->y > 0 && Enemy->y < HEIGHT) {
			Shot->flag = 0;
			Enemy->Image = LoadGraph("images/hit.png");
			Enemy->state = 1;
		}
	}
	// bom
	if (Enemy->state > 0 && Enemy->state < 10) {
		Enemy->state++;
		if (Enemy->state == 10) {
			Enemy->Image = LoadGraph("images/black.png");
			Enemy->state = 11;
		}
	}
	// line over
	if (Enemy->state == 0 && Enemy->y > HEIGHT) {
		Enemy->state = 12;
	}
	return Enemy->state;
}

// �`�悷��
void Enemy_Graph(Enemy_t Enemy) {
	DrawGraph(Enemy.x, Enemy.y, Enemy.Image, TRUE);
}

// �I������������
void Enemy_Finalize(Enemy_t Enemy) {
	DeleteGraph(Enemy.Image);
}
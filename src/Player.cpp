#include "DXLib.h"
#include "Player.h"
#include "keyboard.h"
#include "Game.h"

int speed = 5;

// ������������
void Player_Initialize(Player_t* Player, int x, int y) {
	Player->Image = LoadGraph("images/bar.png");
	Player->x = x;
	Player->y = y;
}

// �������v�Z����(���͂ɉ����č��E�Ɉړ�)
int Player_Calc(Player_t* Player) {
	if (Keyboard_Get(KEY_INPUT_RIGHT) > 0) {
		if (Player->x < WIDTH-25) {
			Player->x += speed;
		}
	}
	if (Keyboard_Get(KEY_INPUT_LEFT) > 0) {
		if (Player->x > 0) {
			Player->x -= speed;
		}

	}
	return Player->x;
}

// �`�悷��
void Player_Graph(Player_t Player) {
	DrawGraph(Player.x, Player.y, Player.Image, TRUE);
}

// �I������������
void Player_Finalize(Player_t Player) {
	DeleteGraph(Player.Image);
}
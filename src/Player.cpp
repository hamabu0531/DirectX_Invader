#include "DXLib.h"
#include "Player.h"
#include "keyboard.h"
#include "Game.h"

int speed = 5;

// 初期化をする
void Player_Initialize(Player_t* Player, int x, int y) {
	Player->Image = LoadGraph("images/bar.png");
	Player->x = x;
	Player->y = y;
}

// 動きを計算する(入力に応じて左右に移動)
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

// 描画する
void Player_Graph(Player_t Player) {
	DrawGraph(Player.x, Player.y, Player.Image, TRUE);
}

// 終了処理をする
void Player_Finalize(Player_t Player) {
	DeleteGraph(Player.Image);
}
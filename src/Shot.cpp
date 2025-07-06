#include "DXLib.h"
#include "keyboard.h"
#include "Shot.h"
#include "Player.h"
#include "Game.h"

int offset = 10;

void Shot_Initialize(Shot_t* Shot, int x, int y) {
	// 初期化処理
	Shot->Image = LoadGraph("images/shot00.png");
	Shot->x = x;
	Shot->y = y;
	Shot->flag = 0; // 飛んでいないことを示すグラフ=0
}

// 動きを計算する
int Shot_Calc(Shot_t* Shot, int player_x) {
	if (Keyboard_Get(KEY_INPUT_SPACE) > 0 && !Shot->flag) {
		Shot->x = player_x + offset;
		Shot->y = PLAYER_POS_Y;
		Shot->flag = 1;
	}
	else if (Shot->flag) {
		Shot->y -= 5;
	}
	else if (!Shot->flag) {
		Shot->x = player_x + offset;
		Shot->y = PLAYER_POS_Y;
	}
	if (Shot->y == 0) {
		Shot->flag = 0;
	}
	return Shot->x, Shot->y;
}

// 描画する
void Shot_Graph(Shot_t Shot) {
	if (Shot.flag) {
		DrawGraph(Shot.x, Shot.y, Shot.Image, TRUE);
	}
}

// 終了処理をする
void Shot_Finalize(Shot_t Shot) {
	DeleteGraph(Shot.Image);
}
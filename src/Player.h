#pragma once

typedef struct {
	int Image;
	int x;
	int y;
} Player_t;

// 初期化をする
void Player_Initialize(Player_t* Player, int x, int y);

// 動きを計算する
int Player_Calc(Player_t* Player);

// 描画する
void Player_Graph(Player_t Player);

// 終了処理をする
void Player_Finalize(Player_t Player);
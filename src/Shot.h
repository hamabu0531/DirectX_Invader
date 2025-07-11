#pragma once

typedef struct {
	int Image;
	int x;
	int y;
	int flag;
} Shot_t;

// 初期化をする
void Shot_Initialize(Shot_t* Shot, int x, int y);

// 動きを計算する
int Shot_Calc(Shot_t* Shot, int player_x);

// 描画する
void Shot_Graph(Shot_t Shot);

// 終了処理をする
void Shot_Finalize(Shot_t Shot);
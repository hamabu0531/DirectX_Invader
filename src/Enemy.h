#pragma once
#include "Shot.h"

typedef struct {
	int Image;
	int x;
	int y;
	int state; // 0=通常, 1-10=被弾(アニメーションの時間), 11=消滅済, 12=ゲームオーバー
	int rl; // 動く方向(偶数で右、奇数で左)
	int e_count; // direction counter
} Enemy_t;

// 初期化をする
void Enemy_Initialize(Enemy_t* Enemy, int x, int y);

// 動きを計算する
int Enemy_Calc(Enemy_t* Enemy, Shot_t* s);

// 描画する
void Enemy_Graph(Enemy_t Enemy);

// 終了処理をする
void Enemy_Finalize(Enemy_t Enemy);
#pragma once
#include "Shot.h"

typedef struct {
	int Image;
	int x;
	int y;
	int state; // 0=normal, 1-10=hit, 11=black, 12=gameover
	int rl; // “®‚­•ûŒü
	int e_count; // direction counter
} Enemy_t;

// ‰Šú‰»‚ğ‚·‚é
void Enemy_Initialize(Enemy_t* Enemy, int x, int y);

// “®‚«‚ğŒvZ‚·‚é
int Enemy_Calc(Enemy_t* Enemy, Shot_t* s);

// •`‰æ‚·‚é
void Enemy_Graph(Enemy_t Enemy);

// I—¹ˆ—‚ğ‚·‚é
void Enemy_Finalize(Enemy_t Enemy);
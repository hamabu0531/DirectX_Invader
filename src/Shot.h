#pragma once

typedef struct {
	int Image;
	int x;
	int y;
	int flag;
} Shot_t;

// ‰Šú‰»‚ğ‚·‚é
void Shot_Initialize(Shot_t* Shot, int x, int y);

// “®‚«‚ğŒvZ‚·‚é
int Shot_Calc(Shot_t* Shot, int player_x);

// •`‰æ‚·‚é
void Shot_Graph(Shot_t Shot);

// I—¹ˆ—‚ğ‚·‚é
void Shot_Finalize(Shot_t Shot);
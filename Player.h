#pragma once

typedef struct {
	int Image;
	int x;
	int y;
} Player_t;

// ‰Šú‰»‚ğ‚·‚é
void Player_Initialize(Player_t* Player, int x, int y);

// “®‚«‚ğŒvZ‚·‚é
int Player_Calc(Player_t* Player);

// •`‰æ‚·‚é
void Player_Graph(Player_t Player);

// I—¹ˆ—‚ğ‚·‚é
void Player_Finalize(Player_t Player);
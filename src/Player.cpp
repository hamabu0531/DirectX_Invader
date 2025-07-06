#include "DXLib.h"
#include "Player.h"
#include "keyboard.h"
#include "Game.h"

int speed = 5;

// ‰Šú‰»‚ğ‚·‚é
void Player_Initialize(Player_t* Player, int x, int y) {
	Player->Image = LoadGraph("images/bar.png");
	Player->x = x;
	Player->y = y;
}

// “®‚«‚ğŒvZ‚·‚é(“ü—Í‚É‰‚¶‚Ä¶‰E‚ÉˆÚ“®)
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

// •`‰æ‚·‚é
void Player_Graph(Player_t Player) {
	DrawGraph(Player.x, Player.y, Player.Image, TRUE);
}

// I—¹ˆ—‚ğ‚·‚é
void Player_Finalize(Player_t Player) {
	DeleteGraph(Player.Image);
}
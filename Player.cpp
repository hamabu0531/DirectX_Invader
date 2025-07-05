#include "DXLib.h"
#include "Player.h"
#include "keyboard.h"

// ‰Šú‰»‚ğ‚·‚é
void Player_Initialize(Player_t* Player, int x, int y) {
	Player->Image = LoadGraph("images/bar.png");
	Player->x = x;
	Player->y = y;
}

// “®‚«‚ğŒvZ‚·‚é(“ü—Í‚É‰‚¶‚Ä¶‰E‚ÉˆÚ“®)
int Player_Calc(Player_t* Player) {
	if (Keyboard_Get(KEY_INPUT_RIGHT) > 0) {
		Player->x += 3;
	}
	if (Keyboard_Get(KEY_INPUT_LEFT) > 0) {
		Player->x -= 3;
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
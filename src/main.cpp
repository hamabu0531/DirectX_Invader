#include "DXLib.h"
#include "keyboard.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"

SCENE gameMenu(int flag) {
	int FontTitle = CreateFontToHandle("メイリオ", 60, 3, DX_FONTTYPE_ANTIALIASING_EDGE);
	int FontSub = CreateFontToHandle("メイリオ", 50, 3, DX_FONTTYPE_ANTIALIASING_EDGE);

	int sel = 0;
	while (!ScreenFlip() && !ClearDrawScreen()) {
		Keyboard_Update();
		DrawStringToHandle(50, 100, "INVADERS GAME", GetColor(255, 255, 255), FontTitle);
		if (flag == 0) {
			DrawString(300, 240, "Play", 255);
			DrawString(300, 256, "Exit", 255);
		}
		else if (flag == 1) {
			DrawStringToHandle(150, 350, "GAME CLEAR!", GetColor(255, 255, 255), FontSub);
			DrawString(300, 240, "Retry", 255);
			DrawString(300, 256, "Exit", 255);
		}
		else if (flag == -1) {
			DrawStringToHandle(150, 350, "GAME OVER!", GetColor(255, 0, 0), FontSub);
			DrawString(300, 240, "Retry", 255);
			DrawString(300, 256, "Exit", 255);

		}
		if (Keyboard_Get(KEY_INPUT_UP) == 1) sel = 0;
		if (Keyboard_Get(KEY_INPUT_DOWN) == 1) sel = 1;
		if (Keyboard_Get(KEY_INPUT_SPACE) == -1) break;
		DrawBox(0, sel * 16 + 240, 640, (sel + 1) * 16 + 240, 256 * 255, false);
		if (ProcessMessage() == -1) return end;
	}
	DeleteFontToHandle(FontTitle);
	DeleteFontToHandle(FontSub);
	return sel ? SCENE::end : SCENE::play;
}

SCENE gamePlay() {
	bool status = false;
	Enemy_t Enemy[Enemy_Number_x * Enemy_Number_y];
	Player_t Player;
	Shot_t Shot;

	static int counter;

	// 敵の初期化
	for (int i = 0; i < Enemy_Number_x; ++i) {
		for (int j = 0; j < Enemy_Number_y; ++j) {
			Enemy_Initialize(Enemy + i + Enemy_Number_x * j, i * 80 + 20, j * 80 - 480);
		}
	}
	Player_Initialize(&Player, 280, 450);
	Shot_Initialize(&Shot, 280, 450);

	// 処理
	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {
		Keyboard_Update();

		int px = Player_Calc(&Player);
		Player_Graph(Player);
		Shot_Calc(&Shot, px);
		Shot_Graph(Shot);
		bool exist = true;
		for(int i=0; i<SIZE(Enemy); ++i) {
			int e_stat = Enemy_Calc(Enemy + i, &Shot);
			if (e_stat == 12) {
				status = true;
			}
			else {
				exist &= e_stat;
			}
			Enemy_Graph(Enemy[i]);
		}

		// GameClear
		if (exist == true) break;
		if (status == true) break;

	}

	Shot_Finalize(Shot);
	for (int i = 0; i < SIZE(Enemy); ++i) {
		Enemy_Finalize(Enemy[i]);
	}
	Player_Finalize(Player);
	if (status == false)
		return SCENE::clear;
	else
		return SCENE::over;
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE);
	DxLib_Init();
	SetDrawScreen(DX_SCREEN_BACK);
	SCENE s = menu;
	while (s != SCENE::end) {
		switch (s) {
		case SCENE::menu:
			s = gameMenu(0); break;
		case SCENE::play:
			s = gamePlay(); break;
		case SCENE::clear:
			s = gameMenu(1); break;
		case SCENE::over:
			s = gameMenu(-1); break;
		}
	}
	DxLib_End();

	return 0;
}

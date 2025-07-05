#pragma once

#define SIZE(array) (sizeof(array) / sizeof(array[0]))
#define Enemy_Number_x 8
#define Enemy_Number_y 8
#define PLAYER_POS_Y 450
#define WIDTH 640
#define HEIGHT 480

enum SCENE
{
	menu,
	clear,
	over,
	play,
	end
};
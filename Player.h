#pragma once

typedef struct {
	int Image;
	int x;
	int y;
} Player_t;

// ������������
void Player_Initialize(Player_t* Player, int x, int y);

// �������v�Z����
int Player_Calc(Player_t* Player);

// �`�悷��
void Player_Graph(Player_t Player);

// �I������������
void Player_Finalize(Player_t Player);
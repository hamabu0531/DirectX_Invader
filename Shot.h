#pragma once

typedef struct {
	int Image;
	int x;
	int y;
	int flag;
} Shot_t;

// ������������
void Shot_Initialize(Shot_t* Shot, int x, int y);

// �������v�Z����
int Shot_Calc(Shot_t* Shot, int player_x);

// �`�悷��
void Shot_Graph(Shot_t Shot);

// �I������������
void Shot_Finalize(Shot_t Shot);
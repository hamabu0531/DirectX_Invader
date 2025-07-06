#pragma once
#include "Shot.h"

typedef struct {
	int Image;
	int x;
	int y;
	int state; // 0=�ʏ�, 1-10=��e(�A�j���[�V�����̎���), 11=���ō�, 12=�Q�[���I�[�o�[
	int rl; // ��������(�����ŉE�A��ō�)
	int e_count; // direction counter
} Enemy_t;

// ������������
void Enemy_Initialize(Enemy_t* Enemy, int x, int y);

// �������v�Z����
int Enemy_Calc(Enemy_t* Enemy, Shot_t* s);

// �`�悷��
void Enemy_Graph(Enemy_t Enemy);

// �I������������
void Enemy_Finalize(Enemy_t Enemy);
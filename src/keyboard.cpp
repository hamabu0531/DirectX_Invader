#include "DXLib.h"
#include "keyboard.h"

static char nowKey[256];
static char prevKey[256];

void Keyboard_Update() {
    for (int i = 0; i < 256; i++) {
        prevKey[i] = nowKey[i];
    }
    GetHitKeyStateAll(nowKey);
}

int Keyboard_Get(int keyCode) {
    // 1: �������u��, 2: ���������Ă���, -1: �������u��, 0: �������ĂȂ�
    if (nowKey[keyCode] != 0 && prevKey[keyCode] == 0) return 1;  // �������u��
    if (nowKey[keyCode] != 0 && prevKey[keyCode] != 0) return 2;  // ���������Ă���
    if (nowKey[keyCode] == 0 && prevKey[keyCode] != 0) return -1; // �������u��
    return 0; // �������Ă��Ȃ�
}

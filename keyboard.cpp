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
    // 1: ‰Ÿ‚µ‚½uŠÔ, 2: ‰Ÿ‚µ‘±‚¯‚Ä‚¢‚é, -1: —£‚µ‚½uŠÔ, 0: ‰½‚à‚µ‚Ä‚È‚¢
    if (nowKey[keyCode] != 0 && prevKey[keyCode] == 0) return 1;  // ‰Ÿ‚µ‚½uŠÔ
    if (nowKey[keyCode] != 0 && prevKey[keyCode] != 0) return 2;  // ‰Ÿ‚µ‘±‚¯‚Ä‚¢‚é
    if (nowKey[keyCode] == 0 && prevKey[keyCode] != 0) return -1; // —£‚µ‚½uŠÔ
    return 0; // ‰½‚à‚µ‚Ä‚¢‚È‚¢
}

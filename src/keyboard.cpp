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
    // 1: 押した瞬間, 2: 押し続けている, -1: 離した瞬間, 0: 何もしてない
    if (nowKey[keyCode] != 0 && prevKey[keyCode] == 0) return 1;  // 押した瞬間
    if (nowKey[keyCode] != 0 && prevKey[keyCode] != 0) return 2;  // 押し続けている
    if (nowKey[keyCode] == 0 && prevKey[keyCode] != 0) return -1; // 離した瞬間
    return 0; // 何もしていない
}

#include "keyboard_input.h"

void KeyboardInput::update() {
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll(tmpKey); // 全てのキーの入力状態を得る
	for (int i = 0; i < 256; i++) {
		if (tmpKey[i] != 0) { // i番のキーコードに対応するキーが押されていたら
			keyboardFrameState[i]++;     // 加算
		}
		else {              // 押されていなければ
			keyboardFrameState[i] = 0;   // 0にする
		}
	}
}

bool KeyboardInput::getMenuUp() {
	if (
		keyboardFrameState[KEY_INPUT_UP] == 1
		|| keyboardFrameState[KEY_INPUT_UP] == menuRendaFirstFrame + 1
		|| (keyboardFrameState[KEY_INPUT_UP] > (menuRendaFirstFrame + menuRendaFrame) && ((keyboardFrameState[KEY_INPUT_UP] % menuRendaFrame) == 1))
		)return true;
	else
		return false;
}
bool KeyboardInput::getMenuDown() {
	if (
		keyboardFrameState[KEY_INPUT_DOWN] == 1
		|| keyboardFrameState[KEY_INPUT_DOWN] == menuRendaFirstFrame + 1
		|| (keyboardFrameState[KEY_INPUT_DOWN] > (menuRendaFirstFrame + menuRendaFrame) && ((keyboardFrameState[KEY_INPUT_DOWN] % menuRendaFrame) == 1))
		)return true;
	else
		return false;
}
bool KeyboardInput::getMenuRight() {
	if (
		keyboardFrameState[KEY_INPUT_RIGHT] == 1
		|| keyboardFrameState[KEY_INPUT_RIGHT] == menuRendaFirstFrame + 1
		|| (keyboardFrameState[KEY_INPUT_RIGHT] > (menuRendaFirstFrame + menuRendaFrame) && ((keyboardFrameState[KEY_INPUT_RIGHT] % menuRendaFrame) == 1))
		)return true;
	else
		return false;
}
bool KeyboardInput::getMenuLeft() {
	if (
		keyboardFrameState[KEY_INPUT_LEFT] == 1
		|| keyboardFrameState[KEY_INPUT_LEFT] == menuRendaFirstFrame + 1
		|| (keyboardFrameState[KEY_INPUT_LEFT] > (menuRendaFirstFrame + menuRendaFrame) && ((keyboardFrameState[KEY_INPUT_LEFT] % menuRendaFrame) == 1))
		)return true;
	else
		return false;
}

bool KeyboardInput::getMenuOk() {
	if (
		keyboardFrameState[KEY_INPUT_RETURN] == 1
		)return true;
	else
		return false;
}

bool KeyboardInput::getMenuCancel() {
	if (
		keyboardFrameState[KEY_INPUT_ESCAPE] == 1
		)return true;
	else
		return false;
}

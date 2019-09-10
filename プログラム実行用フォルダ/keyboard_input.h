#pragma once
#include "DxLib.h"

class KeyboardInput {
public:
	KeyboardInput(const int firstFrame, const int frame) :menuRendaFirstFrame(firstFrame), menuRendaFrame(frame) {};
	void update();
	bool getMenuUp();
	bool getMenuDown();
	bool getMenuRight();
	bool getMenuLeft();
private:
	int keyboardFrameState[256];

	const int menuRendaFirstFrame;
	const int menuRendaFrame;

	bool menuUp = false;
	bool menuDown = false;
	bool menuRight = false;
	bool menuLeft = false;
};
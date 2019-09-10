#pragma once
#include "keyboard_input.h"


class GameInput {
public:
	GameInput(const int firstFrame, const int frame) {
		ki = new KeyboardInput(firstFrame,frame);
	}
	~GameInput() {
		delete ki;
	}

	void update() {
		ki->update();
	}
	bool getMenuUp() {
		return ki->getMenuUp();
	}
	bool getMenuDown() {
		return ki->getMenuDown();
	}
	bool getMenuRight() {
		return ki->getMenuRight();
	}
	bool getMenuLeft() {
		return ki->getMenuLeft();
	}

private:
	KeyboardInput* ki;
};
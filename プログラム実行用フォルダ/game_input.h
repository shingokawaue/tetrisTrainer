#pragma once
#include "keyboard_input.h"
#include "mouse_input.h"

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
		mi.update();
	}
	bool getMenuUp() const {
		return ki->getMenuUp();
	}
	bool getMenuDown() const {
		return ki->getMenuDown();
	}
	bool getMenuRight() const {
		return ki->getMenuRight();
	}
	bool getMenuLeft() const {
		return ki->getMenuLeft();
	}
	bool getMenuOk() {
		if (ki->getMenuOk() || mi.getMenuOk()) return true;
		else return false;
	}
	bool getMenuCancel() {
		if (ki->getMenuCancel() || mi.getMenuCancel()) return true;
		else return false;
	}
	int getMX() { return mi.getMX(); }
	int getMY() { return mi.getMY(); }
	bool getIsMActive() {
		return mi.getIsActive();
	}
	void setMouseActiveFalse() {
		mi.setMouseActiveFalse();
	}
private:
	KeyboardInput* ki;
	MouseInput mi;
};
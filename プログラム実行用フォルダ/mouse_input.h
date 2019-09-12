#pragma once
#include "DxLib.h"

class MouseInput {
public:
	void update();
	bool getMenuOk() {
		if (LeftButtonState == 1) return true;
		else return false;
	}
	bool getMenuCancel() {
		if (RightButtonState == 1) return true;
		else return false;
	}
	//Accessor
	int getMX() const {
		return mx;
	}
	int getMY() const {
		return my;
	}
	bool getIsActive() const{
		return isActive;
	}
	void setMouseActiveFalse() {
		isActive = false;
		SetMouseDispFlag(FALSE);//�}�E�X�J�[�\����\��
	}
private:
	bool isActive = true;//�}�E�X�J�[�\�������������ǂ���
	int cursorStopFrame = 0;

	int mx = 0;
	int my = 0;
	int preX = 0;//�}�E�X�J�[�\���������Ă��邩����p
	int preY = 0;//�}�E�X�J�[�\���������Ă��邩����p

	int LeftButtonState = 0;
	int RightButtonState = 0;
	int MiddleButtonState = 0;
};
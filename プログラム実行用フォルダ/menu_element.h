#pragma once

#include "DxLib.h"
class MenuElement {
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	MenuElement(const TCHAR* _displayString, int _x, int _y, int _color, int _fontHandle)
		: displayString(_displayString), x(_x), y(_y), color(_color)
		, fontHandle(_fontHandle) {}
	~MenuElement() {}
	//public�֐�
	virtual void draw(int row,int column)const {
		DrawStringToHandle(x, y, displayString, color, fontHandle);
	}
	virtual int getRow()const {
		return -1;
	}
	virtual int getColumn()const {
		return -1;
	}
	virtual int getWidth()const {
		return -1;
	}
	virtual int getHeight()const {
		return -1;
	}
	int getX() const { return x; }
	int getY() const { return y; }
protected:
	const TCHAR* displayString;//�\�����镶����
	const int color;//������̕`��F
	const int x;//������`��̋N�_x���W
	const int y;//������`��̋N�_y���W
	const int fontHandle;//������`��p�t�H���g�n���h��

};

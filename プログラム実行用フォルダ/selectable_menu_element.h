#pragma once
#include "menu_element.h"

class SelectableMenuElement : public MenuElement {
public:
	//�R���X�g���N�^�A�f�X�g���N�^
	SelectableMenuElement(const TCHAR* _displayString, int _x
		, int _y, int _color, int _fontHandle,int _row,int _column) : MenuElement(_displayString,_x,_y,_color,_fontHandle ),row(_row),column(_column) {}
	~SelectableMenuElement() {}
	//public�֐�
	virtual void drawWithSelectedJudgment(int _row, int _column)const;

protected:
	const int row;
	const int column;
};
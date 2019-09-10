#pragma once
#include "menu_element.h"

class SelectableMenuElement : public MenuElement {
public:
	//コンストラクタ、デストラクタ
	SelectableMenuElement(const TCHAR* _displayString, int _x
		, int _y, int _width,int _height,int _color, int _fontHandle,int _row,int _column) : MenuElement(_displayString,_x,_y,_color,_fontHandle ),mouseWidth(_width),mouseHeight(_height),row(_row),column(_column) {}
	~SelectableMenuElement() {}
	//public関数
	virtual void drawWithSelectedJudgment(int _row, int _column)const;

    int getRow()const{
        return row;
    }
    int getColumn()const{
        return column;
    }
protected:
	const int row;
	const int column;
	const int mouseWidth;
	const int mouseHeight;
};

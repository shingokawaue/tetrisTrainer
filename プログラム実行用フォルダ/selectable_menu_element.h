#pragma once
#include "menu_element.h"

class SelectableMenuElement : public MenuElement {
public:
	//コンストラクタ、デストラクタ
	SelectableMenuElement(const TCHAR* _displayString, int _x
		, int _y, int _width,int _height,int _color, int _fontHandle,int _row,int _column) : MenuElement(_displayString,_x,_y,_color,_fontHandle ),mouseWidth(_width),mouseHeight(_height),row(_row),column(_column) {}
	~SelectableMenuElement() {}
	//public関数
	virtual void draw(int _row, int _column)const;

    virtual int getRow()const{
        return row;
    }
    virtual int getColumn()const{
        return column;
    }
	virtual int getWidth()const {
		return mouseWidth;
	}
	virtual int getHeight()const {
		return mouseHeight;
	}
protected:
	const int row;
	const int column;
	const int mouseWidth;
	const int mouseHeight;
};

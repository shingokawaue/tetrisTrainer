#include "selectable_menu_element.h"

void SelectableMenuElement::draw(int _row, int _column)const {
	if (row == _row && _column == column)
		DrawStringToHandle(x-20, y, displayString, color, fontHandle);//選択されている時
	else
		DrawStringToHandle(x, y, displayString, color, fontHandle);//選択されていない時

}
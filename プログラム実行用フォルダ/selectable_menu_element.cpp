#include "selectable_menu_element.h"

void SelectableMenuElement::drawWithSelectedJudgment(int _row, int _column)const {
	if (row == _row && _column == column)
		DrawStringToHandle(x, y - 20, displayString, color, fontHandle);//選択されている時
	else
		DrawStringToHandle(x, y, displayString, color, fontHandle);//選択されていない時

}
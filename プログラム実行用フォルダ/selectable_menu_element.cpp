#include "selectable_menu_element.h"

void SelectableMenuElement::drawWithSelectedJudgment(int _row, int _column)const {
	if (row == _row && _column == column)
		DrawStringToHandle(x-20, y, displayString, color, fontHandle);//�I������Ă��鎞
	else
		DrawStringToHandle(x, y, displayString, color, fontHandle);//�I������Ă��Ȃ���

}
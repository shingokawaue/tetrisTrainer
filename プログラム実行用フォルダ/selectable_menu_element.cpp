#include "selectable_menu_element.h"

void SelectableMenuElement::drawWithSelectedJudgment(int _row, int _column)const {
	if (row == _row && _column == column)
		DrawStringToHandle(x-20, y, displayString, color, fontHandle);//‘I‘ð‚³‚ê‚Ä‚¢‚éŽž
	else
		DrawStringToHandle(x, y, displayString, color, fontHandle);//‘I‘ð‚³‚ê‚Ä‚¢‚È‚¢Žž

}
#include "display_menu.h"
//draw
void DisplayMenu::drawMenu() {
	for (size_t i = 0; i < menu.size(); i++) {
		menu[i]->draw(cursorRow, cursorColumn);
	}
}
//add menu
void DisplayMenu::addMenu(MenuElement* element) {
	menu.push_back(element);
		rowNum = element->getRow()+1;
		columnNum = element->getColumn()+1;
}

int DisplayMenu::getSelectedElement() const {
	for (size_t i = 0; i < menu.size(); i++) {
		if (menu[i]->getRow() == cursorRow && menu[i]->getColumn() == cursorColumn)
			return i;
	}
	return -1;
}
//cursor
bool DisplayMenu::mouseCursorCheck(int mx, int my) {
	for (size_t i = 0; i < menu.size(); i++) {
		if (menu[i]->getWidth() == -1) continue;//マウスカーソル範囲がない項目は飛ばす
		if (
			menu[i]->getX() <= mx
			&& (menu[i]->getX() + menu[i]->getWidth()) >= mx
			&& menu[i]->getY() <= my
			&& (menu[i]->getY() + menu[i]->getHeight()) >= my
			)
		{//マウスカーソルが重なっている
			if (cursorRow != menu[i]->getRow()
				|| cursorColumn != menu[i]->getColumn())
			{//新しい項目を選択
				cursorRow = menu[i]->getRow();
				cursorColumn = menu[i]->getColumn();
				return true;
			}
			else {//すでに選択されている項目
				return false;
			}
			break;
		}
			
	}//for
	return false;
}
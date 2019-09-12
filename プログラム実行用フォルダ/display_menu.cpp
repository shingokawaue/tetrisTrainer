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
		if (menu[i]->getWidth() == -1) continue;//�}�E�X�J�[�\���͈͂��Ȃ����ڂ͔�΂�
		if (
			menu[i]->getX() <= mx
			&& (menu[i]->getX() + menu[i]->getWidth()) >= mx
			&& menu[i]->getY() <= my
			&& (menu[i]->getY() + menu[i]->getHeight()) >= my
			)
		{//�}�E�X�J�[�\�����d�Ȃ��Ă���
			if (cursorRow != menu[i]->getRow()
				|| cursorColumn != menu[i]->getColumn())
			{//�V�������ڂ�I��
				cursorRow = menu[i]->getRow();
				cursorColumn = menu[i]->getColumn();
				return true;
			}
			else {//���łɑI������Ă��鍀��
				return false;
			}
			break;
		}
			
	}//for
	return false;
}
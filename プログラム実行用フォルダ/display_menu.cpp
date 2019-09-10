#include "display_menu.h"
//draw
void DisplayMenu::drawMenu() {
	for (size_t i = 0; i < menu.size(); i++) {
		menu[i]->drawWithSelectedJudgment(cursorRow, cursorColumn);
	}
}
//add menu
void DisplayMenu::addMenu(SelectableMenuElement* element) {
	menu.push_back(element);
		rowNum = element->getRow()+1;
		columnNum = element->getColumn()+1;
}
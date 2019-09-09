#pragma once
#include <vector>
using namespace std;
#include "selectable_menu_element.h"

class DisplayMenu {
public:
	//�A�N�Z�T�I�Ȃ�
	void setCursor(int row, int column) { cursorRow = row; cursorColumn = column; }
	void setRow(int num) { cursorRow = num; }
	void setColumn(int num) { cursorColumn = num; }
	void upCursor();
	void downCursor();
	void leftCursor();
	void rightCursor();
	void drawMenu();
	//���j���[�ǉ�
	void addMenu(SelectableMenuElement element) {
		menu.push_back(element);
		cursorRow++;
	}
private:
	vector<SelectableMenuElement> menu;
	int cursorRow = 0;
	int cursorColumn = 0;
	int rowNum;
	int columnNum;
};
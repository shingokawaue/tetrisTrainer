#pragma once
#include <vector>
using namespace std;
#include "selectable_menu_element.h"

class DisplayMenu {
public:
	//アクセサ的なの
	void setCursor(int row, int column) { cursorRow = row; cursorColumn = column; }
	void setRow(int num) { cursorRow = num; }
	void setColumn(int num) { cursorColumn = num; }
    void upCursor(){ cursorRow = (cursorRow - 1) % rowNum;}
    void downCursor(){cursorRow = (cursorRow + 1) % rowNum;}
    void leftCursor(){cursorColumn = (cursorColumn - 1) % columnNum;}
	void rightCursor(){cursorColumn = (cursorColumn + 1) % columnNum;}
    //draw
	void drawMenu();
	//メニュー追加
	void addMenu(SelectableMenuElement element) {
		menu.push_back(element);
        if(element.getRow() > rowNum) rowNum = element.getRow();
        if(element.getColumn() > columnNum) columnNum = element.getColumn();
	}
private:
	vector<SelectableMenuElement> menu;
	int cursorRow = 0;
	int cursorColumn = 0;
	int rowNum;
	int columnNum;
};

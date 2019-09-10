#pragma once
#include <vector>
using namespace std;
#include "selectable_menu_element.h"

class DisplayMenu {
public:
	//constractor
	DisplayMenu(int _scene) :scene(_scene) {};
	//Methods like accessor
	void setCursor(int row, int column) { cursorRow = row; cursorColumn = column; }
	void setRow(int num) { cursorRow = num; }
	void setColumn(int num) { cursorColumn = num; }
    void upCursor(){ cursorRow = (cursorRow + (rowNum-1) ) % rowNum;}
    void downCursor(){cursorRow = (cursorRow + 1) % rowNum;}
    void leftCursor(){cursorColumn = (cursorColumn + (rowNum - 1)) % columnNum;}
	void rightCursor(){cursorColumn = (cursorColumn + 1) % columnNum;}
	int getScene() { return scene; }
    //draw
	void drawMenu();
	//add menu
	void addMenu(SelectableMenuElement* element);
private:
	const int scene;
	vector<SelectableMenuElement*> menu;
	int cursorRow = 0;
	int cursorColumn = 0;
	int rowNum;
	int columnNum;
};

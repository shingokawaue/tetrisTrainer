#pragma once
#include <vector>
using namespace std;
#include "selectable_menu_element.h"

class DisplayMenu {
public:
	//constractor
	DisplayMenu(int _scene) :scene(_scene) {};
	//Methods like accessor
	int getScene() const { return scene; }
	int getSelectedElement() const;
	//draw

	//ÉJÅ[É\Éãà⁄ìÆèàóù
	void setCursor(int row, int column) { cursorRow = row; cursorColumn = column; }
	void setRow(int num) { cursorRow = num; }
	void setColumn(int num) { cursorColumn = num; }
    void upCursor(){ cursorRow = (cursorRow + (rowNum-1) ) % rowNum;}
    void downCursor(){cursorRow = (cursorRow + 1) % rowNum;}
    void leftCursor(){cursorColumn = (cursorColumn + (rowNum - 1)) % columnNum;}
	void rightCursor(){cursorColumn = (cursorColumn + 1) % columnNum;}
	bool mouseCursorCheck(int mx, int my);

	//draw
	void drawMenu();
	//add menu
	void addMenu(MenuElement* element);
private:
	const int scene;
	vector<MenuElement*> menu;
	int cursorRow = 0;
	int cursorColumn = 0;
	int rowNum = 0;
	int columnNum = 0;
};

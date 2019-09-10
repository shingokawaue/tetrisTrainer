#pragma once
#include <vector>
#include "display_menu.h"
using namespace std;

extern int SHandle01;

enum EScene {
	MAIN_MENU,
	NUM_OF_SCENE
};
enum EMode {
	MODE_MENU,
	MODE_VALUE_CHANGE,
	MODE_NUM
};
class Scene {
public:
	//add DisplayMenu
	void addDisplayMenu(DisplayMenu* dmp) {
		dmenu.push_back(dmp);
	}
	//draw
	void drawScene() {
		dmenu[dmenuIndex]->drawMenu();
	}
	//change scene
	void changeScene(int _scene);
	//dmenu Accessor
	void setRow(int num) { dmenu[dmenuIndex]->setRow(num); }
	void setColumn(int num) { dmenu[dmenuIndex]->setColumn(num); }
	void upCursor() { dmenu[dmenuIndex]->upCursor();
	PlaySoundMem(SHandle01, DX_PLAYTYPE_BACK);
	}
	void downCursor() { dmenu[dmenuIndex]->downCursor();
	PlaySoundMem(SHandle01, DX_PLAYTYPE_BACK);
	}
	void leftCursor() { dmenu[dmenuIndex]->leftCursor();
	PlaySoundMem(SHandle01, DX_PLAYTYPE_BACK);
	}
	void rightCursor() { dmenu[dmenuIndex]->rightCursor();
	PlaySoundMem(SHandle01, DX_PLAYTYPE_BACK);
	}
	//Accessor
	int getCurrentMode()const { return currentMode; }
    int getCurrentScene()const { return currentScene; }
private:
	int currentScene = MAIN_MENU;
	vector<DisplayMenu*> dmenu;
	int dmenuIndex = 0;//This will change at the same time you change the scene
    //0:MAIN_MENU 1:
    
	int currentMode = MODE_MENU;
};

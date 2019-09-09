#pragma once

#include "DxLib.h"
class MenuElement {
public:
	//コンストラクタ、デストラクタ
	MenuElement(const TCHAR* _displayString, int _x, int _y, int _color, int _fontHandle)
		: displayString(_displayString), x(_x), y(_y), color(_color)
		, fontHandle(_fontHandle) {}
	~MenuElement() {}
	//public関数
	void draw()const {
		DrawStringToHandle(x, y, displayString, color, fontHandle);
	}

protected:
	const TCHAR* displayString;//表示する文字列
	const int color;//文字列の描画色
	const int x;//文字列描画の起点x座標
	const int y;//文字列描画の起点y座標
	const int fontHandle;//文字列描画用フォントハンドル

};

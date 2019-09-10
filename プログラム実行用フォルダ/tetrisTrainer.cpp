// ここにサンプルプログラムをペーストしてください
// 初期状態では LoadGraphScreen のサンプルプログラムが入力されています。
#include "DxLib.h"
#include "scene.h"
#include "display_menu.h"
#include "selectable_menu_element.h"
#include "game_input.h"
#include <array>
using namespace std;
//グローバル変数
int SHandle01;

//定数
const int MENU_RENDA_FIRST_FRAME = 15;
const int MENU_RENDA_FRAME = 8;


enum EMainMenuElements {
	MME_GAMEPLAY,
	MME_TIKEIEDITOR,
	MME_CONFIG,
	MME_GAMEEND,
	MME_NUM
};




int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				 LPSTR lpCmdLine, int nCmdShow )
{
	if (ChangeWindowMode(TRUE) != 0) return -1;  //ウィンドウモード変更
	if( DxLib_Init() == -1 )	return -1;	// ＤＸライブラリ初期化処理// エラーが起きたら直ちに終了
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//描画先を裏画面にする

	//いろいろ宣言&初期化
	//
	//
	//
	//
	//
	GameInput gi(MENU_RENDA_FIRST_FRAME,MENU_RENDA_FRAME);

	int Font00, Font01;
	Font00 = CreateFontToHandle("メイリオ", 30, 6, DX_FONTTYPE_ANTIALIASING_EDGE);//"メイリオ"  の50pt,太さ3のフォントを作成
	Font01 = CreateFontToHandle("ＭＳ ゴシック", 50, 9, DX_FONTTYPE_NORMAL);           //"MSゴシック"の50pt,太さ9のフォントを作成

	Scene scene;

	DisplayMenu* mainMenuDM = new DisplayMenu(MAIN_MENU);
	array <SelectableMenuElement*,MME_NUM> mmElements;
	mmElements[MME_GAMEPLAY] = new SelectableMenuElement("ゲームプレイ", 70,100,30,180, GetColor(255, 255, 255), Font00, 0, 0);
	mmElements[MME_TIKEIEDITOR] = new SelectableMenuElement("地形エディタ", 70, 150, 30, 195, GetColor(255, 255, 255), Font00, 1, 0);
	mmElements[MME_CONFIG] = new SelectableMenuElement("コンフィグ", 70, 200, 30, 165, GetColor(255, 255, 255), Font00, 2, 0);
	mmElements[MME_GAMEEND] = new SelectableMenuElement("ゲームエンド", 70, 250, 30, 180, GetColor(255, 255, 255), Font00, 3, 0);

	for (size_t i = 0; i < mmElements.size(); i++)
		mainMenuDM->addMenu(mmElements[i]);

	scene.addDisplayMenu(mainMenuDM);
	//いろいろ宣言&初期化処理
	//
	//
	//
	//
	//終わり

	//ファイル読み込み

	SHandle01 = LoadSoundMem("サウンド/Congb_003.ogg");


	int x = 50;
	// ＢＭＰ画像の表示
	int Handle;
	Handle = LoadGraph("test1.bmp");
	
	while ( ProcessMessage()== 0 ) {
		if (ClearDrawScreen() != 0) break;//裏画面クリア

		gi.update();

		switch (scene.getCurrentMode()) {
		case MODE_MENU:
			if (gi.getMenuUp())
				scene.upCursor();
			else if (gi.getMenuDown())
				scene.downCursor();
			break;
		}




		DrawGraph(x, 100, Handle, TRUE);
		x += 2;

		scene.drawScene();

		if (ScreenFlip() != 0) {//裏画面を表画面に反映
			break;
		}
	}

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;					// ソフトの終了
}

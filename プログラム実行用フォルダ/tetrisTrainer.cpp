// ここにサンプルプログラムをペーストしてください
// 初期状態では LoadGraphScreen のサンプルプログラムが入力されています。
#include "DxLib.h"
#include "scene.h"
#include "display_menu.h"
#include "selectable_menu_element.h"
#include "game_input.h"
#include <array>

#include <iostream>
#include <boost/version.hpp>

using namespace std;

struct SSettingData {
	int keyboardUp;
	int keyboardDown;
	int keyboardLeft;
	int keyboardRight;
	int keyboardRRote;
	int keyboardLRote;

	int joypadUp;
	int joypadDown;
	int joypadLeft;
	int joypadRight;
	int joypadRRote;
	int joypadLRote;
}settingData;

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
enum EConfigElements {
	CE_KEYCONFIG,
	CE_SOUNDCONFIG,
	CE_DRAWCONFIG,
	CE_BACK,
	CE_NUM
};
enum EKeyConfigElements {
	KCE_KEYBOARD,
	KCE_KEYBOARD_LEFT,
	KCE_KEYBOARD_RIGHT,
	KCE_KEYBOARD_HARDDROP,
	KCE_KEYBOARD_SOFTDROP,
	KCE_KEYBOARD_L_ROTE,
	KCE_KEYBOARD_R_ROTE,
	KCE_BACK,
	KCE_NUM
};


//■　　　　　■
//■■　　　■■　　　　　　　　
//■　■　■　■　　　　　　　　　■　
//■　　■　　■　　　■■　　　　　　　■　■■　　
//■　　　　　■　　■　　■　　　■　　■■　　■
//■　　　　　■　　■　　■　　　■　　■　　　■
//■　　　　　■　　　■■　■　　■　　■　　　■

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				 LPSTR lpCmdLine, int nCmdShow )
{
	if (ChangeWindowMode(TRUE) != 0) return -1;  //ウィンドウモード変更
	if( DxLib_Init() == -1 )	return -1;	// ＤＸライブラリ初期化処理// エラーが起きたら直ちに終了
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//描画先を裏画面にする

	//いろいろ宣言&初期化
	//
	bool endFlag = false;//ゲーム終了フラグ trueならwhileループを抜けるようにする
	GameInput gi(MENU_RENDA_FIRST_FRAME,MENU_RENDA_FRAME);

	int Font00, Font01,
		Font02;
	Font00 = CreateFontToHandle("メイリオ", 30, 6, DX_FONTTYPE_ANTIALIASING_EDGE);//"メイリオ"  の50pt,太さ3のフォントを作成
	Font01 = CreateFontToHandle("ＭＳ ゴシック", 20, 6, DX_FONTTYPE_NORMAL);           //"MSゴシック"の50pt,太さ9のフォントを作成
	Font02 = CreateFontToHandle("ＭＳ ゴシック", 10, 6, DX_FONTTYPE_NORMAL);           //"MSゴシック"の50pt,太さ9のフォントを作成
	Scene scene;

	//メインメニュー　項目登録
	DisplayMenu* mainMenuDM = new DisplayMenu(SCENE_MAIN_MENU);
	array <MenuElement*,MME_NUM> mmElements;
	mmElements[MME_GAMEPLAY] = new SelectableMenuElement("ゲームプレイ", 70,100,180,30, GetColor(255, 255, 255), Font00, 0, 0);
	mmElements[MME_TIKEIEDITOR] = new SelectableMenuElement("地形エディタ", 70, 150, 195, 30, GetColor(255, 255, 255), Font00, 1, 0);
	mmElements[MME_CONFIG] = new SelectableMenuElement("コンフィグ", 70, 200, 165,30, GetColor(255, 255, 255), Font00, 2, 0);
	mmElements[MME_GAMEEND] = new SelectableMenuElement("ゲームエンド", 70, 250, 180,30, GetColor(255, 255, 255), Font00, 3, 0);
	for (size_t i = 0; i < mmElements.size(); i++)
		mainMenuDM->addMenu(mmElements[i]);
	scene.addDisplayMenu(mainMenuDM);
	//コンフィグ　項目登録	
	DisplayMenu* configDM = new DisplayMenu(SCENE_CONFIG);
	array <MenuElement*, CE_NUM> configElements;
	configElements[CE_KEYCONFIG] = new SelectableMenuElement("キーコンフィグ", 70, 100, 195, 30, GetColor(255, 255, 255), Font00, 0, 0);
	configElements[CE_SOUNDCONFIG] = new SelectableMenuElement("サウンドコンフィグ", 70, 150, 255, 30, GetColor(255, 255, 255), Font00, 1, 0);
	configElements[CE_DRAWCONFIG] = new SelectableMenuElement("描画コンフィグ", 70, 200, 195, 30, GetColor(255, 255, 255), Font00, 2, 0);
	configElements[CE_BACK] = new SelectableMenuElement("もどる", 70, 250, 90, 30, GetColor(255, 255, 255), Font00, 3, 0);
	for (size_t i = 0; i < configElements.size(); i++)
		configDM->addMenu(configElements[i]);
	scene.addDisplayMenu(configDM);


	//キーコンフィグ　項目登録	
	DisplayMenu* keyconfigDM = new DisplayMenu(SCENE_KEY_CONFIG);
	array <MenuElement*, KCE_NUM> keyconfigElements;
	keyconfigElements[KCE_KEYBOARD] = new MenuElement("キーボード", 100, 20, GetColor(255, 255, 255), Font01);
	keyconfigElements[KCE_KEYBOARD_LEFT] = new SelectableMenuElement("左移動", 70, 100, 60, 20, GetColor(255, 255, 255), Font01, 0, 0);
	keyconfigElements[KCE_KEYBOARD_RIGHT] = new SelectableMenuElement("右移動", 70, 140, 60, 20, GetColor(255, 255, 255), Font01, 1, 0);
	keyconfigElements[KCE_KEYBOARD_HARDDROP] = new SelectableMenuElement("ハードドロップ", 70, 180, 130, 20, GetColor(255, 255, 255), Font01, 2, 0);
	keyconfigElements[KCE_KEYBOARD_SOFTDROP] = new SelectableMenuElement("ソフトドロップ", 70, 220, 130,20, GetColor(255, 255, 255), Font01, 3, 0);
	keyconfigElements[KCE_KEYBOARD_L_ROTE] = new SelectableMenuElement("左回転", 70, 260, 60, 20, GetColor(255, 255, 255), Font01, 4, 0);
	keyconfigElements[KCE_KEYBOARD_R_ROTE] = new SelectableMenuElement("右回転", 70, 300, 60, 20, GetColor(255, 255, 255), Font01, 5, 0);

	keyconfigElements[KCE_BACK] = new SelectableMenuElement("もどる", 70, 400, 90,30, GetColor(255, 255, 255), Font00, 6, 0);

	for (size_t i = 0; i < keyconfigElements.size(); i++)
		keyconfigDM->addMenu(keyconfigElements[i]);
	scene.addDisplayMenu(keyconfigDM);
	//いろいろ宣言&初期化処理
	//
	//終わり

	//ファイル読み込み

	SHandle01 = LoadSoundMem("サウンド/TEMPLEBLOCK.ogg");
	ChangeVolumeSoundMem(80, SHandle01);//音量0~255

	int x = 50;
	// ＢＭＰ画像の表示
	int Handle;
	Handle = LoadGraph("test1.bmp");

	char   buf[256];
	DWORD  ret;

	ret = GetPrivateProfileString("KEYCONFIG", "HardDrop_Keyboard", "localhost", buf, sizeof(buf), "設定ファイル/設定データ.ini");
	//WritePrivateProfileString
	//■　　　　　　　■　■　　　　　■　■　　■■
	//■　　　■　　　■　■　　　　　　　■　■　　■
	//　■　■　■　■　　■　■■　　■　■　■■■■
	//　■　■　■　■　　■　　　■　■　■　■　　
	//　　■　　　■　　　■　　　■　■　■　　■■
	while ( ProcessMessage()== 0 ) {
		if (ClearDrawScreen() != 0) break;//裏画面クリア

		gi.update();

		//MENUモード　シーン共通の処理
		if (scene.getCurrentMode() == MODE_MENU) {
			if (gi.getIsMActive()) {
				scene.mouseCursorCheck(gi.getMX(), gi.getMY());
			}
			if (gi.getMenuUp()) {
				scene.upCursor();
				gi.setMouseActiveFalse();
			}
			else if (gi.getMenuDown()) {
				scene.downCursor();
				gi.setMouseActiveFalse();
			}
		}


        switch (scene.getCurrentScene()){
			//
			//　MAIN_MENU
			//
            case SCENE_MAIN_MENU:{
                switch (scene.getCurrentMode()) {
				case MODE_MENU: {
					
					if (gi.getMenuOk()) {//OKボタンが押されていたら
						switch (scene.getSelectedElement()) {
						case MME_GAMEPLAY:
							break;
						case	MME_TIKEIEDITOR:
							break;
						case	MME_CONFIG:
							scene.changeScene(SCENE_CONFIG);
							break;
						case	MME_GAMEEND:
							endFlag = true;
							break;
						}
					}
				}//case MODE_MENU
                        break;
                }
            }//case MAIN_MENU
                break;
			//
			//　CONFIG
			//
			case SCENE_CONFIG: {
				switch (scene.getCurrentMode()) {
				case MODE_MENU: {

					if (gi.getMenuOk()) {//OKボタンが押されていたら
						switch (scene.getSelectedElement()) {
						case CE_KEYCONFIG:
							scene.changeScene(SCENE_KEY_CONFIG);
							break;
						case	CE_SOUNDCONFIG:
							break;
						case	CE_DRAWCONFIG:
							break;
						case CE_BACK:
							scene.changeScene(SCENE_MAIN_MENU);
							break;
						}
					}
					if (gi.getMenuCancel()) {
						scene.changeScene(SCENE_MAIN_MENU);
					}
				}//case MODE_MENU
								break;
				}
			}
								  break;
			//
			//　KEY_CONFIG
			//
			case SCENE_KEY_CONFIG: {
				switch (scene.getCurrentMode()) {
				case MODE_MENU: {

					if (gi.getMenuOk()) {//OKボタンが押されていたら
						switch (scene.getSelectedElement()) {
						case 	KCE_KEYBOARD_LEFT:
							scene.setCurrentMode(MODE_KEY_CHANGE);
							break;
						case	KCE_KEYBOARD_RIGHT:
							scene.setCurrentMode(MODE_KEY_CHANGE);
							break;
						case	KCE_KEYBOARD_HARDDROP:
							scene.setCurrentMode(MODE_KEY_CHANGE);
							break;
						case	KCE_KEYBOARD_SOFTDROP:
							scene.setCurrentMode(MODE_KEY_CHANGE);
							break;
						case	KCE_KEYBOARD_L_ROTE:
							scene.setCurrentMode(MODE_KEY_CHANGE);
							break;
						case	KCE_KEYBOARD_R_ROTE:
							scene.setCurrentMode(MODE_KEY_CHANGE);
							break;
						case KCE_BACK:
							scene.changeScene(SCENE_CONFIG);
							break;
						}
					}
					if (gi.getMenuCancel()) {
						scene.changeScene(SCENE_CONFIG);
					}
				}//case MODE_MENU
								break;
				}
			}//case 
							   break;
        }
		




		DrawGraph(x, 100, Handle, TRUE);
		x += 2;

		if(scene.getCurrentMode() == MODE_MENU)
		scene.drawMenuScene();

		if (endFlag) break;

		
			DrawFormatStringToHandle(250, 5, GetColor(255, 255, 255),
				Font02, "x:%d  y:%d", gi.getMX(), gi.getMY());//選択されていない時
			DrawFormatStringToHandle(350, 5, GetColor(255, 255, 255),
				Font02, "%d", BOOST_VERSION);
			//DrawStringToHandle(350, 15, BOOST_VERSION,GetColor(255, 255, 255),Font02 );

		if (ScreenFlip() != 0) {//裏画面を表画面に反映
			break;
		}
	}//while

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;					// ソフトの終了
}

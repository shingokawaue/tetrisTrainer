// ここにサンプルプログラムをペーストしてください
// 初期状態では LoadGraphScreen のサンプルプログラムが入力されています。
#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				 LPSTR lpCmdLine, int nCmdShow )
{
	if (ChangeWindowMode(TRUE) != 0) return -1;  //ウィンドウモード変更
	if( DxLib_Init() == -1 )	return -1;	// ＤＸライブラリ初期化処理// エラーが起きたら直ちに終了
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//描画先を裏画面にする
	int x = 50;
	// ＢＭＰ画像の表示
	int Handle;
	Handle = LoadGraph("test1.bmp");
	
	while ( ProcessMessage()== 0 ) {
		if (ClearDrawScreen() != 0) break;//裏画面クリア

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
		
		DrawGraph(x, 100, Handle, TRUE);
		x += 2;

		if (ScreenFlip() != 0) {//裏画面を表画面に反映
			break;
		}
	}

	DxLib_End() ;				// ＤＸライブラリ使用の終了処理

	return 0 ;					// ソフトの終了
}

// �����ɃT���v���v���O�������y�[�X�g���Ă�������
// ������Ԃł� LoadGraphScreen �̃T���v���v���O���������͂���Ă��܂��B
#include "DxLib.h"
#include "scene.h"
#include "display_menu.h"
#include "selectable_menu_element.h"
#include "game_input.h"
#include <array>
using namespace std;
//�O���[�o���ϐ�
int SHandle01;

//�萔
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
	if (ChangeWindowMode(TRUE) != 0) return -1;  //�E�B���h�E���[�h�ύX
	if( DxLib_Init() == -1 )	return -1;	// �c�w���C�u��������������// �G���[���N�����璼���ɏI��
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//�`���𗠉�ʂɂ���

	//���낢��錾&������
	//
	//
	//
	//
	//
	GameInput gi(MENU_RENDA_FIRST_FRAME,MENU_RENDA_FRAME);

	int Font00, Font01;
	Font00 = CreateFontToHandle("���C���I", 30, 6, DX_FONTTYPE_ANTIALIASING_EDGE);//"���C���I"  ��50pt,����3�̃t�H���g���쐬
	Font01 = CreateFontToHandle("�l�r �S�V�b�N", 50, 9, DX_FONTTYPE_NORMAL);           //"MS�S�V�b�N"��50pt,����9�̃t�H���g���쐬

	Scene scene;

	DisplayMenu* mainMenuDM = new DisplayMenu(MAIN_MENU);
	array <SelectableMenuElement*,MME_NUM> mmElements;
	mmElements[MME_GAMEPLAY] = new SelectableMenuElement("�Q�[���v���C", 70,100,30,180, GetColor(255, 255, 255), Font00, 0, 0);
	mmElements[MME_TIKEIEDITOR] = new SelectableMenuElement("�n�`�G�f�B�^", 70, 150, 30, 195, GetColor(255, 255, 255), Font00, 1, 0);
	mmElements[MME_CONFIG] = new SelectableMenuElement("�R���t�B�O", 70, 200, 30, 165, GetColor(255, 255, 255), Font00, 2, 0);
	mmElements[MME_GAMEEND] = new SelectableMenuElement("�Q�[���G���h", 70, 250, 30, 180, GetColor(255, 255, 255), Font00, 3, 0);

	for (size_t i = 0; i < mmElements.size(); i++)
		mainMenuDM->addMenu(mmElements[i]);

	scene.addDisplayMenu(mainMenuDM);
	//���낢��錾&����������
	//
	//
	//
	//
	//�I���

	//�t�@�C���ǂݍ���

	SHandle01 = LoadSoundMem("�T�E���h/Congb_003.ogg");


	int x = 50;
	// �a�l�o�摜�̕\��
	int Handle;
	Handle = LoadGraph("test1.bmp");
	
	while ( ProcessMessage()== 0 ) {
		if (ClearDrawScreen() != 0) break;//����ʃN���A

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

		if (ScreenFlip() != 0) {//����ʂ�\��ʂɔ��f
			break;
		}
	}

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;					// �\�t�g�̏I��
}

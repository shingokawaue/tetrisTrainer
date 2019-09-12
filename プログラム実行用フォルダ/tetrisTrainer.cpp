// �����ɃT���v���v���O�������y�[�X�g���Ă�������
// ������Ԃł� LoadGraphScreen �̃T���v���v���O���������͂���Ă��܂��B
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


//���@�@�@�@�@��
//�����@�@�@�����@�@�@�@�@�@�@�@
//���@���@���@���@�@�@�@�@�@�@�@�@���@
//���@�@���@�@���@�@�@�����@�@�@�@�@�@�@���@�����@�@
//���@�@�@�@�@���@�@���@�@���@�@�@���@�@�����@�@��
//���@�@�@�@�@���@�@���@�@���@�@�@���@�@���@�@�@��
//���@�@�@�@�@���@�@�@�����@���@�@���@�@���@�@�@��

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				 LPSTR lpCmdLine, int nCmdShow )
{
	if (ChangeWindowMode(TRUE) != 0) return -1;  //�E�B���h�E���[�h�ύX
	if( DxLib_Init() == -1 )	return -1;	// �c�w���C�u��������������// �G���[���N�����璼���ɏI��
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//�`���𗠉�ʂɂ���

	//���낢��錾&������
	//
	bool endFlag = false;//�Q�[���I���t���O true�Ȃ�while���[�v�𔲂���悤�ɂ���
	GameInput gi(MENU_RENDA_FIRST_FRAME,MENU_RENDA_FRAME);

	int Font00, Font01,
		Font02;
	Font00 = CreateFontToHandle("���C���I", 30, 6, DX_FONTTYPE_ANTIALIASING_EDGE);//"���C���I"  ��50pt,����3�̃t�H���g���쐬
	Font01 = CreateFontToHandle("�l�r �S�V�b�N", 20, 6, DX_FONTTYPE_NORMAL);           //"MS�S�V�b�N"��50pt,����9�̃t�H���g���쐬
	Font02 = CreateFontToHandle("�l�r �S�V�b�N", 10, 6, DX_FONTTYPE_NORMAL);           //"MS�S�V�b�N"��50pt,����9�̃t�H���g���쐬
	Scene scene;

	//���C�����j���[�@���ړo�^
	DisplayMenu* mainMenuDM = new DisplayMenu(SCENE_MAIN_MENU);
	array <MenuElement*,MME_NUM> mmElements;
	mmElements[MME_GAMEPLAY] = new SelectableMenuElement("�Q�[���v���C", 70,100,180,30, GetColor(255, 255, 255), Font00, 0, 0);
	mmElements[MME_TIKEIEDITOR] = new SelectableMenuElement("�n�`�G�f�B�^", 70, 150, 195, 30, GetColor(255, 255, 255), Font00, 1, 0);
	mmElements[MME_CONFIG] = new SelectableMenuElement("�R���t�B�O", 70, 200, 165,30, GetColor(255, 255, 255), Font00, 2, 0);
	mmElements[MME_GAMEEND] = new SelectableMenuElement("�Q�[���G���h", 70, 250, 180,30, GetColor(255, 255, 255), Font00, 3, 0);
	for (size_t i = 0; i < mmElements.size(); i++)
		mainMenuDM->addMenu(mmElements[i]);
	scene.addDisplayMenu(mainMenuDM);
	//�R���t�B�O�@���ړo�^	
	DisplayMenu* configDM = new DisplayMenu(SCENE_CONFIG);
	array <MenuElement*, CE_NUM> configElements;
	configElements[CE_KEYCONFIG] = new SelectableMenuElement("�L�[�R���t�B�O", 70, 100, 195, 30, GetColor(255, 255, 255), Font00, 0, 0);
	configElements[CE_SOUNDCONFIG] = new SelectableMenuElement("�T�E���h�R���t�B�O", 70, 150, 255, 30, GetColor(255, 255, 255), Font00, 1, 0);
	configElements[CE_DRAWCONFIG] = new SelectableMenuElement("�`��R���t�B�O", 70, 200, 195, 30, GetColor(255, 255, 255), Font00, 2, 0);
	configElements[CE_BACK] = new SelectableMenuElement("���ǂ�", 70, 250, 90, 30, GetColor(255, 255, 255), Font00, 3, 0);
	for (size_t i = 0; i < configElements.size(); i++)
		configDM->addMenu(configElements[i]);
	scene.addDisplayMenu(configDM);


	//�L�[�R���t�B�O�@���ړo�^	
	DisplayMenu* keyconfigDM = new DisplayMenu(SCENE_KEY_CONFIG);
	array <MenuElement*, KCE_NUM> keyconfigElements;
	keyconfigElements[KCE_KEYBOARD] = new MenuElement("�L�[�{�[�h", 100, 20, GetColor(255, 255, 255), Font01);
	keyconfigElements[KCE_KEYBOARD_LEFT] = new SelectableMenuElement("���ړ�", 70, 100, 60, 20, GetColor(255, 255, 255), Font01, 0, 0);
	keyconfigElements[KCE_KEYBOARD_RIGHT] = new SelectableMenuElement("�E�ړ�", 70, 140, 60, 20, GetColor(255, 255, 255), Font01, 1, 0);
	keyconfigElements[KCE_KEYBOARD_HARDDROP] = new SelectableMenuElement("�n�[�h�h���b�v", 70, 180, 130, 20, GetColor(255, 255, 255), Font01, 2, 0);
	keyconfigElements[KCE_KEYBOARD_SOFTDROP] = new SelectableMenuElement("�\�t�g�h���b�v", 70, 220, 130,20, GetColor(255, 255, 255), Font01, 3, 0);
	keyconfigElements[KCE_KEYBOARD_L_ROTE] = new SelectableMenuElement("����]", 70, 260, 60, 20, GetColor(255, 255, 255), Font01, 4, 0);
	keyconfigElements[KCE_KEYBOARD_R_ROTE] = new SelectableMenuElement("�E��]", 70, 300, 60, 20, GetColor(255, 255, 255), Font01, 5, 0);

	keyconfigElements[KCE_BACK] = new SelectableMenuElement("���ǂ�", 70, 400, 90,30, GetColor(255, 255, 255), Font00, 6, 0);

	for (size_t i = 0; i < keyconfigElements.size(); i++)
		keyconfigDM->addMenu(keyconfigElements[i]);
	scene.addDisplayMenu(keyconfigDM);
	//���낢��錾&����������
	//
	//�I���

	//�t�@�C���ǂݍ���

	SHandle01 = LoadSoundMem("�T�E���h/TEMPLEBLOCK.ogg");
	ChangeVolumeSoundMem(80, SHandle01);//����0~255

	int x = 50;
	// �a�l�o�摜�̕\��
	int Handle;
	Handle = LoadGraph("test1.bmp");

	char   buf[256];
	DWORD  ret;

	ret = GetPrivateProfileString("KEYCONFIG", "HardDrop_Keyboard", "localhost", buf, sizeof(buf), "�ݒ�t�@�C��/�ݒ�f�[�^.ini");
	//WritePrivateProfileString
	//���@�@�@�@�@�@�@���@���@�@�@�@�@���@���@�@����
	//���@�@�@���@�@�@���@���@�@�@�@�@�@�@���@���@�@��
	//�@���@���@���@���@�@���@�����@�@���@���@��������
	//�@���@���@���@���@�@���@�@�@���@���@���@���@�@
	//�@�@���@�@�@���@�@�@���@�@�@���@���@���@�@����
	while ( ProcessMessage()== 0 ) {
		if (ClearDrawScreen() != 0) break;//����ʃN���A

		gi.update();

		//MENU���[�h�@�V�[�����ʂ̏���
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
			//�@MAIN_MENU
			//
            case SCENE_MAIN_MENU:{
                switch (scene.getCurrentMode()) {
				case MODE_MENU: {
					
					if (gi.getMenuOk()) {//OK�{�^����������Ă�����
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
			//�@CONFIG
			//
			case SCENE_CONFIG: {
				switch (scene.getCurrentMode()) {
				case MODE_MENU: {

					if (gi.getMenuOk()) {//OK�{�^����������Ă�����
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
			//�@KEY_CONFIG
			//
			case SCENE_KEY_CONFIG: {
				switch (scene.getCurrentMode()) {
				case MODE_MENU: {

					if (gi.getMenuOk()) {//OK�{�^����������Ă�����
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
				Font02, "x:%d  y:%d", gi.getMX(), gi.getMY());//�I������Ă��Ȃ���
			DrawFormatStringToHandle(350, 5, GetColor(255, 255, 255),
				Font02, "%d", BOOST_VERSION);
			//DrawStringToHandle(350, 15, BOOST_VERSION,GetColor(255, 255, 255),Font02 );

		if (ScreenFlip() != 0) {//����ʂ�\��ʂɔ��f
			break;
		}
	}//while

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;					// �\�t�g�̏I��
}

// �����ɃT���v���v���O�������y�[�X�g���Ă�������
// ������Ԃł� LoadGraphScreen �̃T���v���v���O���������͂���Ă��܂��B
#include "DxLib.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
				 LPSTR lpCmdLine, int nCmdShow )
{
	if (ChangeWindowMode(TRUE) != 0) return -1;  //�E�B���h�E���[�h�ύX
	if( DxLib_Init() == -1 )	return -1;	// �c�w���C�u��������������// �G���[���N�����璼���ɏI��
	if (SetDrawScreen(DX_SCREEN_BACK) != 0) return -1;//�`���𗠉�ʂɂ���
	int x = 50;
	// �a�l�o�摜�̕\��
	int Handle;
	Handle = LoadGraph("test1.bmp");
	
	while ( ProcessMessage()== 0 ) {
		if (ClearDrawScreen() != 0) break;//����ʃN���A

		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
		
		DrawGraph(x, 100, Handle, TRUE);
		x += 2;

		if (ScreenFlip() != 0) {//����ʂ�\��ʂɔ��f
			break;
		}
	}

	DxLib_End() ;				// �c�w���C�u�����g�p�̏I������

	return 0 ;					// �\�t�g�̏I��
}

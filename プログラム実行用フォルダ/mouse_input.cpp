#include "mouse_input.h"

void MouseInput::update() {
	GetMousePoint(&mx, &my);
	
	
		//�}�E�X�J�[�\���������Ă��邩����
	if (mx == preX || my == preY) {
		cursorStopFrame++;
	}
	else {
		cursorStopFrame = 0;
		if (isActive == false) {
			SetMouseDispFlag(TRUE);//�}�E�X�J�[�\���\��
			isActive = true;
		}
	}


	if (cursorStopFrame > 180) {//�}�E�X��������܂�
		isActive = false;
		SetMouseDispFlag(FALSE);//�}�E�X�J�[�\����\��
	}

		preX = mx;
		preY = my;
	




	if ((GetMouseInput() & MOUSE_INPUT_LEFT) != 0)
		LeftButtonState++;
	else
		LeftButtonState = 0;
	if ((GetMouseInput() & MOUSE_INPUT_RIGHT) != 0)
		RightButtonState++;
	else
		RightButtonState = 0;
	if ((GetMouseInput() & MOUSE_INPUT_MIDDLE) != 0)
		MiddleButtonState++;
	else
		MiddleButtonState = 0;
}
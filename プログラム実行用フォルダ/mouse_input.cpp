#include "mouse_input.h"

void MouseInput::update() {
	GetMousePoint(&mx, &my);
	
	
		//マウスカーソルが動いているか判定
	if (mx == preX || my == preY) {
		cursorStopFrame++;
	}
	else {
		cursorStopFrame = 0;
		if (isActive == false) {
			SetMouseDispFlag(TRUE);//マウスカーソル表示
			isActive = true;
		}
	}


	if (cursorStopFrame > 180) {//マウスが消えるまで
		isActive = false;
		SetMouseDispFlag(FALSE);//マウスカーソル非表示
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
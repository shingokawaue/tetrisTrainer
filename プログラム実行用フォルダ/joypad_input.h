#pragma once
#include "DxLib.h"



class JoypadInput {
    enum EPadInput{
        PI_DOWN,
        PI_,
        PI_,
        PI_,
        PI_,
        PI_,
        PI_,
        PI_,
        PI_,
        PI_,
        PI_,
        PI_,
        PI_,
        PI_
    }
public:
    JoypadInput(const int firstFrame, const int frame) :menuRendaFirstFrame(firstFrame), menuRendaFrame(frame) {};
    void update();
    bool getMenuUp();
    bool getMenuDown();
    bool getMenuRight();
    bool getMenuLeft();
private:
    
    
    rightRotation
    const int menuRendaFirstFrame;
    const int menuRendaFrame;
    
};

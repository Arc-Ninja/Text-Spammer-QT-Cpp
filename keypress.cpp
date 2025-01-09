#include "keypress.h"

keypress::keypress(QObject *parent)
    : QObject{parent}
{
}


//FOR WINDOWS ----------------------------------------------------
#ifdef __WIN32
void keypress::simulateKeyPressWin(char key) {

    SHORT vkey = VkKeyScanA(key);
    INPUT input[2];
    input[0].type = INPUT_KEYBOARD;
    input[1].type = INPUT_KEYBOARD;
    BYTE shiftpressed = HIBYTE(vkey);

    //SHIFT down--------------------------
    if(shiftpressed & 1){
        input[1].ki.wVk = VK_SHIFT;
        input[1].ki.dwFlags = 0;
        SendInput(1, &input[1], sizeof(INPUT));
        // QThread::msleep(5);

    }
    //--------------------------------------

    //Just key press and up ----------------------
    if(key == ' '){
        input[0].ki.wVk = 0x20;
    }
    else
        input[0].ki.wVk = LOWORD(vkey);

    try{
        input[0].ki.dwFlags = 0;
    SendInput(1, &input[0], sizeof(INPUT));

     input[0].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(1, &input[0], sizeof(INPUT));

    }
    catch(const std::exception& ex){
        std::cout<<"Exception: "<<ex.what()<<std::endl;
    }
    //----------------------------------------------------

    //SHIFT UP--------------------------
    if(shiftpressed & 1){
        input[1].ki.dwFlags = KEYEVENTF_KEYUP;
        SendInput(1, &input[1], sizeof(INPUT));
        // QThread::msleep(10);
    }

    //--------------------------------------
}
#endif
//-------------------------------------------------------------------------




//FOR IOS-------------------------------------------------------------------------
#ifdef __APPLE__
void simulateKeyPressMac(CGKeyCode key) {
    CGEventRef keyDown = CGEventCreateKeyboardEvent(NULL, key, true);
    CGEventRef keyUp = CGEventCreateKeyboardEvent(NULL, key, false);

    CGEventPost(kCGHIDEventTap, keyDown);
    CGEventPost(kCGHIDEventTap, keyUp);

    CFRelease(keyDown);
    CFRelease(keyUp);
}
#endif
//---------------------------------------------------------------------------------------


//FOR LINUX--------------------------------------------------------------------------------

#ifdef __linux__
void simulateKeyPressLinux(Display* display, KeySym keysym) {
    KeyCode keycode = XKeysymToKeycode(display, keysym);

    XTestFakeKeyEvent(display, keycode, True, 0);
    XTestFakeKeyEvent(display, keycode, False, 0);

    XFlush(display);
}
#endif
//-------------------------------------------------------------------------------------------

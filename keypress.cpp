#include "keypress.h"

keypress::keypress(QObject *parent)
    : QObject{parent}
{


}
#ifdef __WIN32
void keypress::simulateKeyPressWin(char key) {
    SHORT vkey = VkKeyScan(key);
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    if(key == ' '){
        input.ki.wVk = 0x20;
    }
    else
        input.ki.wVk = LOWORD(vkey);

    try{
    SendInput(1, &input, sizeof(INPUT));

     input.ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(1, &input, sizeof(INPUT));
    }
    catch(const std::exception& ex){
        std::cout<<"Exception: "<<ex.what()<<std::endl;
    }
}
#endif

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


#ifdef __linux__
void simulateKeyPressLinux(Display* display, KeySym keysym) {
    KeyCode keycode = XKeysymToKeycode(display, keysym);

    XTestFakeKeyEvent(display, keycode, True, 0);
    XTestFakeKeyEvent(display, keycode, False, 0);

    XFlush(display);
}
#endif

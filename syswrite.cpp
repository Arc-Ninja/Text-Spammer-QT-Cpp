#include "syswrite.h"
// #include <QThread>
syswrite::syswrite() {}
void syswrite::writeOut(string str){
    for(char c:str){
    QThread::msleep(5);
#ifdef __WIN32
    kprs.simulateKeyPressWin(c);
#endif
    }
}

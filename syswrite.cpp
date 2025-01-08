#include "syswrite.h"
// #include <QThread>
syswrite::syswrite() {}
void syswrite::writeOut(string str){
    for(char c:str){
    // QThread::sleep(2);
#ifdef __WIN32
    kprs.simulateKeyPressWin(c);
#endif
    }
}

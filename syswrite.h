#ifndef SYSWRITE_H
#define SYSWRITE_H
#include <bits/stdc++.h>
#include <QThread>
#include "keypress.h"
using namespace std;
class syswrite
{
public:
    syswrite();

    void writeOut(string str);
private:
    keypress kprs;
};

#endif // SYSWRITE_H

#ifndef KEYPRESS_H
#define KEYPRESS_H
#include <QThread>
#ifdef __WIN32
#include <windows.h>
#include <bits/stdc++.h>
#endif

#ifdef __APPLE__
#include <ApplicationServices/ApplicationServices.h>
#endif

#ifdef __linux__
#include <X11/Xlib.h>
#include <X11/keysym.h>
#include <X11/extensions/XTest.h>
#endif

#include <QObject>

class keypress : public QObject
{
    Q_OBJECT
public:
    explicit keypress(QObject *parent = nullptr);

signals:

public slots:
#ifdef __WIN32
    void simulateKeyPressWin(char key);
#endif

#ifdef __APPLE__
    void simulateKeyPressMac(CGKeyCode key);
#endif

#ifdef __linux__
    void simulateKeyPressLinux(Display* display, KeySym keysym);
#endif

};

#endif // KEYPRESS_H

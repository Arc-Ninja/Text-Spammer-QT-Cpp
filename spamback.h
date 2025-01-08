#ifndef SPAMBACK_H
#define SPAMBACK_H
#include <bits/stdc++.h>
#include <QObject>

using namespace std;
class spamback : public QObject
{
    Q_OBJECT
private:
    string str;
    int num;
    atomic<bool> run;
    int maxnum = 0;

public:
    spamback();
    friend class MainWindow;
public slots:
    void spam(string, int);
    void spam(string);
    void stop();

signals:
    void finished();
    void started();
    void progress(int i);
};

#endif // SPAMBACK_H

#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "spamback.h"
class worker : public QObject
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = nullptr):QObject(parent){

    };

public slots:
    void stopwork(){
        spams1.stop();
    }
    void work(string str, int num, bool infi){

        if(infi)spams1.spam(str,num); //infinite mode on hold
        else spams1.spam(str,num);
        emit finished();
    }

private:
    spamback spams1;
signals:
    void finished();
};

#endif // WORKER_H

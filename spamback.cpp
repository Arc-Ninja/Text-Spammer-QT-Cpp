#include "spamback.h"
#include <bits/stdc++.h>
#include <QThread>

using namespace std;

spamback::spamback(){
}

void spamback::spam(string str, int num){
    run = true;
    while(num-->0 && run){
        cout<<str<<" "<<num<<endl;
        QThread::msleep(5);

    }
    emit finished();


}
void spamback::spam(string str){
    run = true;
    while(run){
        cout<<str<<" infinite mode "<<run<<endl;
        QThread::msleep(5);
    }
    emit finished();
}
void spamback::stop(){
    cout<<"STOPPED"<<endl;
    run = false;
}

#include "spamback.h"
#include <bits/stdc++.h>
#include <QThread>

using namespace std;

spamback::spamback(){
}

void spamback::spam(string str, int num){
    emit started();
    run = true;
    maxnum = max(maxnum,num);

    while(num-->0 && run){
        cout<<str<<" "<<num<<endl;
        emit progress((int)(((double)(maxnum-num)/(double)maxnum)*100));
        QThread::msleep(1);



    }

    emit finished();
    // emit progress(0);


}
void spamback::spam(string str){
    emit started();
    run = true;
    emit progress(100);
    while(run){
        cout<<str<<" infinite mode "<<run<<endl;
        QThread::msleep(1);
    }

    emit finished();
    emit progress(0);
}
void spamback::stop(){
    cout<<"STOPPED"<<endl;
    run = false;
}



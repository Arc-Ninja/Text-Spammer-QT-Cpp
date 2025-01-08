#include "spamback.h"
#include <bits/stdc++.h>
#include <QThread>

using namespace std;

spamback::spamback(){
}
//Finite spam function-------------------------
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

}

//Infinite spam function ---------------------------------
void spamback::spam(string str){
    emit started();
    run = true;
    emit progress(0);
    while(run){
        cout<<str<<" infinite mode "<<run<<endl;
        QThread::msleep(1);
    }
    emit finished();
    emit progress(100);
}

//spam stop fucntion ----------------------------------
void spamback::stop(){
    // cout<<"STOPPED"<<endl;
    run = false;
}



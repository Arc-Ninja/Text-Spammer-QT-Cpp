#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QObject>
#include <QThread>
#include <QCloseEvent>
#include "spamback.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(0);
    spambutton();
    stopbutton();
}


MainWindow::~MainWindow()
{
    if(thread1->isRunning()){
        thread1->quit();
        thread1->exit();
    }
    delete ui;
}

//progress bar fucntion--------------------------
void MainWindow::progress(){
    QObject::connect(spams, &spamback::progress, this, [this](int i){

        ui->progressBar->setValue(i);
    });

}
//----------------------------------------------------

//spambutton function -------------------------------------------------------
void MainWindow::spambutton(){
    thread1 = new QThread();
    QObject::connect(ui->spambutt, &QPushButton::clicked, this, [this](){

        string text = ui->textbox1->toPlainText().toStdString();
        int num = ui->spamnum->value();
        spams = new spamback();
        spams->moveToThread(thread1);
        thread1->start();

        //invoking spam --------------------
        if(ui->infinitespam->isChecked()){
            QMetaObject::invokeMethod(spams, "spam", Qt::QueuedConnection,
                                      Q_ARG(string, text));
        }
        else{
            QMetaObject::invokeMethod(spams, "spam", Qt::QueuedConnection,
                                      Q_ARG(string, text),
                                      Q_ARG(int, num));
        }
        //------------------------------------

        //calls the progress bar function
        progress();


        //disable spam button
        QObject::connect(spams,&spamback::started, this, [this](){
            ui->spambutt->setEnabled(false);
            cout<<"started";
        } );
        QObject::connect(spams, &spamback::finished, this, [this](){
            ui->spambutt->setEnabled(true);
            cout<<"stopped";
        });
        //------------------------


        //clearing up ----------------
        QObject::connect(spams, &spamback::finished, thread1, &QThread::quit);
        //-----------------------
    });


}
//--------------------------------------------------------------

//stop button function -------------------------------------------------------
void MainWindow::stopbutton(){
    QObject::connect(ui->stopbutt, &QPushButton::clicked, this, [this](){
        cout<<"pressed stop"<<endl;
        // spams->run = false;
        spams->stop();

        thread1->quit();

    });
}
//-----------------------------------------------------------------

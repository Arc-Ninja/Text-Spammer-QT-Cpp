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



//Thread 1 spambutton and spamstop
    thread1 = new QThread();
    QObject::connect(ui->spambutt, &QPushButton::clicked, this, [this](){
         string text = ui->textbox1->toPlainText().toStdString();
         int num = ui->spamnum->value();
        spams = new spamback();
        spams->moveToThread(thread1);
        thread1->start();
        if(ui->infinitespam->isChecked()){
        QMetaObject::invokeMethod(spams, "spam", Qt::QueuedConnection,
                                  Q_ARG(string, text));
        }
        else{
            QMetaObject::invokeMethod(spams, "spam", Qt::QueuedConnection,
                                      Q_ARG(string, text),
                                      Q_ARG(int, num));
        }

        QObject::connect(spams, &spamback::finished, thread1, &QThread::quit);
    });


    //spamstop
    QObject::connect(ui->stopbutt, &QPushButton::clicked, this, [this](){
        cout<<"pressed stop"<<endl;
        // spams->run = false;
        spams->stop();

        thread1->quit();

    });




}


MainWindow::~MainWindow()
{
    if(thread1->isRunning()){
        thread1->quit();
        thread1->exit();
    }
    delete ui;
}



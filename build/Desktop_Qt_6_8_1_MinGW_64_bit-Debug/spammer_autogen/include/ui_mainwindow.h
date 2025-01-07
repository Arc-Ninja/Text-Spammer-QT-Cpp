/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *spambutt;
    QPushButton *stopbutt;
    QTextEdit *textbox1;
    QProgressBar *progressBar;
    QSpinBox *spamnum;
    QCheckBox *infinitespam;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(681, 381);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(681, 381));
        MainWindow->setMaximumSize(QSize(681, 381));
        MainWindow->setBaseSize(QSize(0, 0));
        MainWindow->setMouseTracking(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        spambutt = new QPushButton(centralwidget);
        spambutt->setObjectName("spambutt");
        spambutt->setGeometry(QRect(220, 310, 121, 41));
        stopbutt = new QPushButton(centralwidget);
        stopbutt->setObjectName("stopbutt");
        stopbutt->setGeometry(QRect(390, 310, 121, 41));
        textbox1 = new QTextEdit(centralwidget);
        textbox1->setObjectName("textbox1");
        textbox1->setGeometry(QRect(20, 20, 641, 271));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName("progressBar");
        progressBar->setGeometry(QRect(540, 320, 118, 23));
        sizePolicy.setHeightForWidth(progressBar->sizePolicy().hasHeightForWidth());
        progressBar->setSizePolicy(sizePolicy);
        progressBar->setValue(24);
        spamnum = new QSpinBox(centralwidget);
        spamnum->setObjectName("spamnum");
        spamnum->setGeometry(QRect(48, 325, 105, 29));
        sizePolicy.setHeightForWidth(spamnum->sizePolicy().hasHeightForWidth());
        spamnum->setSizePolicy(sizePolicy);
        spamnum->setMinimumSize(QSize(105, 29));
        spamnum->setMaximumSize(QSize(105, 29));
        spamnum->setMaximum(99999);
        infinitespam = new QCheckBox(centralwidget);
        infinitespam->setObjectName("infinitespam");
        infinitespam->setGeometry(QRect(50, 300, 111, 26));
        sizePolicy.setHeightForWidth(infinitespam->sizePolicy().hasHeightForWidth());
        infinitespam->setSizePolicy(sizePolicy);
        infinitespam->setMinimumSize(QSize(111, 26));
        infinitespam->setMaximumSize(QSize(111, 26));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        spambutt->setText(QCoreApplication::translate("MainWindow", "SPAM", nullptr));
        stopbutt->setText(QCoreApplication::translate("MainWindow", "STOP", nullptr));
        textbox1->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Type Here ...</p></body></html>", nullptr));
        infinitespam->setText(QCoreApplication::translate("MainWindow", "Infinite Spam", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

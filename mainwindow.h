#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>
#include <QThread>
#include <QTimer>
#include "spamback.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:

    QThread* thread1;
    spamback* spams;
    Ui::MainWindow *ui;


private slots:
    void progress();
    void spambutton();
    void stopbutton();
    void spamnumcheck();

};
#endif // MAINWINDOW_H

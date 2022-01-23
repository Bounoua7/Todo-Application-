#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"addtask.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void chargerTasks(QString myFile);//method to save the content of each listwidget

private slots:

    void on_actionNew_Task_triggered();

    void on_actionExit_triggered();

    void on_actionPending_Task_triggered();

    void on_actionFinished_Task_triggered();

    void on_actionAbout_Todo_Application_triggered();
    void on_actionHide_finished_Tasks_triggered();
private:

    Ui::MainWindow *ui;
    void addelt();
};
#endif // MAINWINDOW_H

#ifndef ADDTASK_H
#define ADDTASK_H

#include <QDialog>

namespace Ui {
class addtask;
}

class addtask : public QDialog
{
    Q_OBJECT

public:
    explicit addtask(QWidget *parent = nullptr);
    ~addtask();
    QString getDescription();
    QString getTag();
    QString getFinished();
    QDate getDueDate();
    void showEvent(QShowEvent * event);




private slots:

    void on_pushButton_clicked();

private:
    Ui::addtask *ui;
};

#endif // ADDTASK_H



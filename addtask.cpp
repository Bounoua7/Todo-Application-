#include "addtask.h"
#include "ui_addtask.h"

addtask::addtask(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addtask)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#A9A9A9");
    this->setWindowTitle("Addtask");

}



void addtask::showEvent(QShowEvent * event)
{
    QDate date = QDate::currentDate();
    ui->dateEdit->setDate(date); // sets the current date to date edit.

    QDialog::showEvent(event);
}

QString addtask::getDescription(){
    return ui->lineEdit->text();

}
QString addtask::getFinished(){
    if (ui->checkBox->isChecked())
       return "finished";
    else
        return "pending";
}
QString addtask::getTag(){

    return ui->comboBox->currentText();


}
QDate addtask::getDueDate(){

    return ui->dateEdit->date();

}

addtask::~addtask()
{
    delete ui;
}

void addtask::on_pushButton_clicked()
{
    accept();
}


#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"addtask.h"
#include"QInputDialog"
#include"QDebug"
#include"QDate"
#include"QTime"
#include <QFile>
#include<QString>
#include<QListWidgetItem >
#include<QTextStream>
#include<QMessageBox>
#include<QIcon>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color:#FFEBCD");
    this->setWindowTitle("TodoApp");
   chargerTasks("C:\\Users\\oum\\Downloads\\cities_coordinates\\TodoApp\\file.txt");
   connect(ui->actionNew_Task, &QAction::triggered, this, &MainWindow::addelt);

}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_actionNew_Task_triggered()
{


}

void MainWindow::addelt(){

    addtask D ;
    D.setModal(false);
    D.exec();


    QString newTask ;
    // Get the line edit text
    QString description = D.getDescription();
    if (description!=NULL){
        //Get Finished bool
        QString finished = D.getFinished();
    // Get current date
         QDate curDate = D.getDueDate();
        // QString date = D.getDueDate().toString();
        newTask = description +"\t Due:"+ curDate.toString() ;
        QString Tag= D.getTag();
        if(Tag == "Work")
            Tag="0";
        else if (Tag == "Life")
            Tag="1";
        else
            Tag="2";
         if (finished=="finished" || curDate < QDate::currentDate())
         {
             newTask = "Finished\t"+newTask+"\tTag :"+Tag+"\n";
               ui->listWidget_2->addItem(new QListWidgetItem(QIcon(":/taskdone.png"),newTask));
}
         else if (curDate == QDate::currentDate()){
              newTask = "For Today\t"+newTask+"\tTag :"+Tag+"\n";
                ui->listWidget->addItem(new QListWidgetItem(QIcon(":/today.png"),newTask));
         }
         else{
                 newTask = "Pending\t"+newTask+"\tTag :"+Tag+"\n";
                ui->listWidget_3->addItem(new QListWidgetItem(QIcon(":/pending.png"),newTask));

         }
    }
    QString fichier = "C:\\Users\\oum\\Downloads\\cities_coordinates\\TodoApp\\file.txt";

    QFile file(fichier); // Appel du constructeur de la classe QFile

    if (file.open(QIODevice::Append | QIODevice::Text)) {
    // Si l'ouverture du fichier en écriture à réussie

    // écrire dans le fichier en utilisant un flux :
    QTextStream out(&file);
    out << newTask;

    // Fermer le fichier
    file.close();
    }

}


void MainWindow::chargerTasks(QString myFile){

    QFile fichier(myFile);

    if(fichier.open(QIODevice::ReadOnly | QIODevice::Text)) // ReadOnly on lecture // ::Text si le fichier est deja ouvert
    {
        QTextStream flux(&fichier);
        while(!flux.atEnd())
        {
            QString temp = flux.readLine();
            if(  temp.startsWith("Finished"))
            ui->listWidget_3->addItem(temp);
            else if( temp.startsWith("Pending"))
                    ui->listWidget_2->addItem(temp);
            else
                ui->listWidget->addItem(temp);
        }
        fichier.close();
    }



    }






void MainWindow::on_actionPending_Task_triggered()
{

    if(ui->listWidget_3->isVisible()){
        ui->listWidget_3->hide();}
        else{
          ui->listWidget_3->show();
        }

}


void MainWindow::on_actionFinished_Task_triggered()
{
    if(ui->listWidget_2->isVisible()){
        ui->listWidget_2->hide();
       } else{
          ui->listWidget_2->show();
        }
}

void MainWindow::on_actionExit_triggered()
{
    qApp->exit();
}

void MainWindow::on_actionAbout_Todo_Application_triggered()
{
     QMessageBox::information(this,"About","To Do Application");
}


void MainWindow::on_actionHide_finished_Tasks_triggered()
{
    ui->listWidget_2->setVisible(false);

}


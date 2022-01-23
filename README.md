                                                                                       | 22/01/2022 |

<h1 style="color:#0B615E;  text-align:center; vertical-align: middle; padding:40px 0; margin-top:30px " > To Do Application </h1>
             </br>
<h2 style="color:#0B615E;">
Create ToDo Application using containers.
<li> <a href="#Todo-id">Todo App</a></li>   
  

</h2>
<h4 style="color:#088A85;">
  


<ul>
<h3 style="color:#58ACFA";>
 <h4> <a href="#Preface-id">Preface</a></h4>
 <h4> <a href="#Task-id">Defining a Task</a></h4>
 <h4> <a href="#Cases-id">Using Cases</a> </h4> 
 <h4> <a href="#Item-id">Using Item Based </a></h4>
  <h4> <a href="#result-id"> The outcome </a></h4>


</h3>
</ul>
      
------------
   <h3 style="color:#088A85" id="Preface-id" >Preface </h3>
<strong>To Do Application</strong> is a Desktop application for task management. It allows users to manage their tasks from a computer.  </br>
Task management involves planning, testing and  tracking. As it can help the  individual to achieve goals, in order that it requires managing all aspects of a task, including its status, priority, time.

The status of tasks can be described by the following states: 
Ready(today) , finished (already done), pending(future). </br>
<strong>The goal</strong> of the project is to create the application to manage  tasks And It should have all the features of main application such as menues, actions and toolbar. The application must store an archive of all the pending and finished tasks.


------------


   <h3 style="color:#088A85" id="Task-id" >Defining a Task</h3>
   <p>
A Task is defined by the following attributes:

<li>A <strong>description</strong>: stating the text and goal for the task like (Buying the milk).</li>

<li>A <strong>finished </strong> boolean indicating if the task is Finished or due.</li>
<li>A <strong>Tag</strong> category to show the class of the task which is reduced to the following values:</li>
<ul>
<li>Work</li>
<li>Life</li>
<li>Other</li>
</ul>

<li>Finally, a task should have a <strong> DueDate </strong> which stores the Date planned for the date.</li>
When the user create a new task, the application must pop up a dialog for the user to get those values.
   </p>

  <h3 style="color:#088A85" id="Cases-id" >Using Cases</h3>
   <p>
   <ul>
  Here is a list of cases that the user could perform with our app:
<li>The user should be able to<strong> close </strong>the application of course.</li>
<li>The Todo application cannot be useful, unless it offers the possibility of <strong>creating new tasks</strong>.</li>
<li>The View of the main widget should be <strong> split </strong>in three areas:</li> 
<ul>
<li>The first (en persistent) area shows the list of <strong>today</strong> tasks.</li>
<li>The second one is reserved for <strong>pending </strong>task (tasks for the future).</li>
<li>Finally, the third one shows the set of  <strong> finished </strong> tasks.</li>
</ul>


<li>Each category must be shown with a <strong>custom</strong> icon.</li>
<li>The user could either <strong>hide/show </strong> the pending and finished views.</li>
<li>Finally, the tasks entered to your application must remains in the app in future use.</li>
</ul>
   </p>

   <h3 style="color:#088A85" id="Item-id" >Using Item Based  </h3>
   <p>
    We will use <strong>Item Based</strong> containers for the three widgets.
   </p>



</p>


------------
   <h3 style="color:#088A85" id="Todo-id" >Todo App</h3>


<h5 style="color:#FF8000"> The main class code</h5>

```c++

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}


```
<h5 style="color:#FF8000">mainwindow.h file:</h5>


```c++
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


```
<h5 style="color:#FF8000">mainwindow.cpp file:</h5>

```c++
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



 ```
<h5 style="color:#FF8000"> result:</h5>



![result](https://user-images.githubusercontent.com/86807424/150687470-e7041c45-9b8d-42ac-abbb-4b669ee2457c.png)







   <h3 style="color:#088A85;" id="spreadsheet-id" > add task dialog </h3>

<p> we press add task and the Qdialog show up</p>


![dialog](https://user-images.githubusercontent.com/86807424/150687687-5cc31f89-c9a3-4899-b22c-6b51376fc3c2.png)



<h5 style="color:#FF8000"> addtask.h file:</h5>

```c++

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




```

<h5 style="color:#FF8000">addtask.cpp file:</h5> 


```c++

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



```


------------


   <h3 style="color:#088A85" id="result-id" >The outcome</h3>






https://user-images.githubusercontent.com/86807424/150687498-11507aeb-6de7-421f-869e-417436bda176.mp4





<p> file.txt is where the tasks are saved.</p>


![saved tasks](https://user-images.githubusercontent.com/86807424/150687881-b45639bd-7b89-40e3-85df-b3f140a16e98.png)




















------------

<h4 style="background-color:#F6CEF5" > By: OUMKOULTHOUME BOUNOUA </h4>
  
  </div>

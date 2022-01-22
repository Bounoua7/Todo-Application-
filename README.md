                                                                                       | 18/01/2022 |

<h1 style="color:#0B615E;  text-align:center; vertical-align: middle; padding:40px 0; margin-top:30px " > To Do Application </h1>
             </br>
<h2 style="color:#0B615E;">
Create ToDo Application using containers.
<li>TodoApp.</li>
<li>database.</li>

</h2>
<h4 style="color:#088A85;">
  


<ul>
<h3 style="color:#58ACFA";>
 <h4> <a href="#Preface-id">Preface</a></h4>
 <h4> <a href="#Task-id">Defining a Task</a></h4>
 <h4> <a href="#Item-id">Using Item Based Model</a></h4>
 <h4> <a href="#MVC-id">Using MVC Model</a></h4>
 <h4> <a href="#Cases-id">Using Cases</a> </h4> 

</h3>
</ul>
      
------------
   <h3 style="color:#088A85" id="Preface-id" >Preface </h3>
<strong>To Do Application</strong> is a Desktop application for task management. It allows users to manage their tasks from a computer.  </br>
Task management involves planning, testing and  tracking. As it can help the  individual to achieve goals, in order that it requires managing all aspects of a task, including its status, priority, time.

The status of tasks can be described by the following states: 
Ready(today) , finished (already done), pending(future). </br>
<strong>The goal</strong> of the project is to create the application to manage  tasks And It should have all the features of main application such as menues, actions and toolbar. The application must store an archive of all the pending and finished tasks.

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



   <h3 style="color:#088A85" id="Item-id" >Using Item Based Model </h3>
   <p>
    We will use <strong>Item Based</strong> containers for the three widgets.
   </p>

 <h3 style="color:#088A85" id="MVC-id" >Using MVC Model</h3>
<p>
   Using complicated model either </br>
 <a href="https://doc.qt.io/qtforpython-5/PySide2/QtWidgets/QTableView.html">QTableView</a>  </br>
 <a href="https://doc.qt.io/qt-5/qabstracttablemodel.html">QAbstractTableModel </a>  
 </br>
 <a href="https://doc.qt.io/qt-5/qsqltablemodel.html">QSqlTableModel </a>  
 </br>

</p>


------------


<h5 style="color:#FF8000"> The main class code</h5>

```c++



```
<h5 style="color:#FF8000">mainwindow.h file:</h5>


```c++



```
<h5 style="color:#FF8000">mainwindow.cpp file:</h5>

```c++


 ```
<h5 style="color:#FF8000"> result:</h5>










   <h3 style="color:#088A85;" id="spreadsheet-id" > SpreadSheet </h3>



<h5 style="color:#FF8000"> main file:</h5>

```c++

```

<h5 style="color:#FF8000"> spreadsheet.h file:</h5>

```c++



```

<h5 style="color:#FF8000">spreadsheet.cpp file:</h5> 


```c++



```


   <h3 style="color:#088A85;" id="Calcul-id" >go dialog</h3>


<h5 style="color:#FF8000"> godialog.cpp :</h5>

```c++


```




 <h5 style="color:#FF8000"> finddialog.h</h5>

```c++



```




 <h5 style="color:#FF8000"> finddialog.cpp</h5>

```c++




```

<h5 style="color:#FF8000">result :</h5>



------------

<h4 style="background-color:#F6CEF5" > By: OUMKOULTHOUME BOUNOUA </h4>
  
  </div>

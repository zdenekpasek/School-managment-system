#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <addstudent.h>
#include <removestudent.h>
#include <showstudents.h>
#include <searchstudent.h>
#include <addteacher.h>
#include <showteachers.h>
#include <database.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Database db;

private slots:
    void on_closeButton_clicked();
    void on_addStudentButton_clicked();
    void moveHome();
    void on_removeStudentButton_clicked();
    void on_listStudentsButton_clicked();
    void on_searchStudentButton_clicked();
    void on_addTeacherButton_clicked();

    void on_listTeachersButton_clicked();

private:
    Ui::MainWindow *ui;
    addStudent studentAdd;
    removeStudent studentRemove;
    showStudents studentShow;
    searchStudent studentSearch;
    addteacher teacherAdd;
    showteachers teacherShow;

};

#endif // MAINWINDOW_H

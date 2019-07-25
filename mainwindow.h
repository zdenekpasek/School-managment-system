#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <addstudent.h>
#include <removestudent.h>
#include <showstudents.h>
#include <searchstudent.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_closeButton_clicked();
    void on_addStudentButton_clicked();
    void moveHome();
    void on_removeStudentButton_clicked();
    void on_showStudentsButton_clicked();
    void on_searchStudentButton_clicked();

private:
    Ui::MainWindow *ui;
    addStudent studentAdd;
    removeStudent studentRemove;
    showStudents studentShow;
    searchStudent studentSearch;


};

#endif // MAINWINDOW_H

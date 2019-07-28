#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <addstudent.h>
#include <database.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->insertWidget(1, &studentAdd);
    ui->stackedWidget->insertWidget(2, &studentRemove);
    ui->stackedWidget->insertWidget(3, &studentShow);
    ui->stackedWidget->insertWidget(4, &studentSearch);
    ui->stackedWidget->insertWidget(5, &teacherAdd);
    ui->stackedWidget->insertWidget(6, &teacherShow);




    connect(&studentAdd, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&studentRemove, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&studentShow, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&studentSearch, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&teacherShow, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&teacherAdd, SIGNAL(HomeClicked()), this, SLOT(moveHome()));



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_closeButton_clicked()
{
    this->close();
}


void MainWindow::on_addStudentButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_removeStudentButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_listStudentsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_searchStudentButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_addTeacherButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_listTeachersButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}








#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <addstudent.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->stackedWidget->insertWidget(1, &studentAdd);
    ui->stackedWidget->insertWidget(2, &studentRemove);
    ui->stackedWidget->insertWidget(3, &studentShow);
    ui->stackedWidget->insertWidget(4, &studentSearch);

    connect(&studentAdd, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&studentRemove, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&studentShow, SIGNAL(HomeClicked()), this, SLOT(moveHome()));
    connect(&studentSearch, SIGNAL(HomeClicked()), this, SLOT(moveHome()));



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

void MainWindow::on_showStudentsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_searchStudentButton_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
}

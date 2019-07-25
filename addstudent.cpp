#include "addstudent.h"
#include "ui_addstudent.h"

addStudent::addStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addStudent)
{
    ui->setupUi(this);



}

addStudent::~addStudent()
{
    delete ui;
}



void addStudent::on_homeButton_clicked()
{
    emit HomeClicked();
}


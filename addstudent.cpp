#include "addstudent.h"
#include "ui_addstudent.h"
#include <database.h>

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

void addStudent::clearLineEdits()
{
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();
    }
}



void addStudent::on_addStudentButton_clicked()
{
   QString name = ui->lineEdit_name->text();
   QString surname = ui->lineEdit_surname->text();
   QString pid = ui->lineEdit_pid->text();
   QString residence = ui->lineEdit_residence->text();
   QString registration = ui->lineEdit_registration->text();
   int subjects = ui->lineEdit_subjects->text().toInt();

   Database conn;
   conn.addStudentToDB(name, surname, pid, residence, registration, subjects);

   clearLineEdits();
}


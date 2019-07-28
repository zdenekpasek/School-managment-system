#include "addteacher.h"
#include "ui_addteacher.h"
#include <database.h>

addteacher::addteacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addteacher)
{
    ui->setupUi(this);
}

addteacher::~addteacher()
{
    delete ui;
}

void addteacher::on_homeButton_clicked()
{
    emit HomeClicked();
}

void addteacher::clearLineEdits()
{
    foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
       le->clear();
    }
}

void addteacher::on_addTeacherButton_clicked()
{
    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_surname->text();
    QString pid = ui->lineEdit_pid->text();
    QString residence = ui->lineEdit_residence->text();
    QString qualification = ui->lineEdit_qual->text();
    QString experience = ui->lineEdit_exp->text();
    QString subject = ui->lineEdit_subject->text();

    Database conn;

    try {
        conn.addTeachertToDB(name, surname, pid, residence, qualification, experience, subject);
    } catch (const char *er) {

    }


    clearLineEdits();
}

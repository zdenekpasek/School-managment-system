#include "addteacher.h"
#include "ui_addteacher.h"
#include <database.h>

addteacher::addteacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addteacher)
{
    ui->setupUi(this);

    QRegExp rx("^[A-Za-z]{3,16}\\s[A-Za-z]{3,16}$");
    QRegExp rx2("^\\d{6}\\\\\\d{4}$");
    QRegExp rx3("^\\d{2}\\-\\d{2}\\-\\d{4}$");
    QValidator *characterVal = new QRegExpValidator(rx, this);
    QValidator *pidVal = new QRegExpValidator(rx2, this);
    ui->lineEdit_name->setValidator(characterVal);
    ui->lineEdit_surname->setValidator(characterVal);
    ui->lineEdit_residence->setValidator(characterVal);
    ui->lineEdit_pid->setValidator(pidVal);
    ui->lineEdit_qual->setValidator(characterVal);
    ui->lineEdit_exp->setValidator(characterVal);
    ui->lineEdit_subject->setValidator(characterVal);

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

bool addteacher::checkLineEditString(QString le, QString le2, QString le3, QString le4, QString le5, QString le6, QString le7)
{
    if(le.isEmpty() || le2.isEmpty() || le3.isEmpty() || le4.isEmpty() || le5.isEmpty() || le6.isEmpty() || le7.isEmpty()){ return false;
    } return true;
}

void addteacher::on_addTeacherButton_clicked()
{
    QMessageBox msgBox;
    Database conn;

    QString name = ui->lineEdit_name->text();
    QString surname = ui->lineEdit_surname->text();
    QString pid = ui->lineEdit_pid->text();
    QString residence = ui->lineEdit_residence->text();
    QString qualification = ui->lineEdit_qual->text();
    QString experience = ui->lineEdit_exp->text();
    QString subject = ui->lineEdit_subject->text();


    if(checkLineEditString(name, surname, pid, residence, qualification, experience, subject)){
        try {
            conn.addTeachertToDB(name, surname, pid, residence, qualification, experience, subject);
            msgBox.setText("Sucessfully added teacher to databse.");
            msgBox.exec();
        } catch (const char *er) {
            qDebug() << er;
            msgBox.setText(er);
            msgBox.exec();
        }
        ui->label->clear();
    } else{
        ui->label->setText("Please enter valid input!");
    }
    clearLineEdits();
}

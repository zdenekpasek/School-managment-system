#include "addstudent.h"
#include "ui_addstudent.h"
#include <database.h>
#include <QRegExpValidator>


addStudent::addStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addStudent)
{
    ui->setupUi(this);

   // validators and regex's
    ui->lineEdit_subjects->setValidator(new QIntValidator(1, 20, this));
    QRegExp rx("^[a-z]{3,32}$");
    QRegExp rx2("^\\d{6}\\\\\\d{4}$");
    QValidator *characterVal = new QRegExpValidator(rx, this);
    QValidator *pidVal = new QRegExpValidator(rx2, this);
    ui->lineEdit_name->setValidator(characterVal);
    ui->lineEdit_surname->setValidator(characterVal);
    ui->lineEdit_residence->setValidator(characterVal);
    ui->lineEdit_pid->setValidator(pidVal);


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

bool addStudent::checkLineEditString(QString le, QString le2, QString le3, QString le4, QString le5)
{
    if(le.isEmpty() || le2.isEmpty() || le3.isEmpty() || le4.isEmpty() || le5.isEmpty()){ return false;
    } return true;
}

bool addStudent::checkLineEditInt(int subj)
{
    if((subj > 0) && (subj <= 20)){
         return true;

    } return false;
}



void addStudent::on_addStudentButton_clicked()
{
   QMessageBox msgBox;
   Database conn;

   QString name = ui->lineEdit_name->text();
   QString surname = ui->lineEdit_surname->text();
   QString pid = ui->lineEdit_pid->text();
   QString residence = ui->lineEdit_residence->text();
   QString registration = ui->lineEdit_registration->text();
   int subjects = ui->lineEdit_subjects->text().toInt();


   if(checkLineEditString(name, surname, pid, residence, registration) && checkLineEditInt(subjects)){
       try {
           conn.addStudentToDB(name, surname, pid, residence, registration, subjects);
           msgBox.setText("Sucessfully added student to databse.");
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


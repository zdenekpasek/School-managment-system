#include "removestudent.h"
#include "ui_removestudent.h"


removeStudent::removeStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::removeStudent)
{
    ui->setupUi(this);
    ui->lineEdit_surname->clear();
}

removeStudent::~removeStudent()
{
    delete ui;
}

void removeStudent::on_homeButton_clicked()
{
    emit HomeClicked();
}

void removeStudent::on_removeStudentButton_clicked()
{
    QMessageBox msgBox;
    Database conn;

    QString surname = ui->lineEdit_surname->text();

    try {
        conn.removeStudentFromDB(surname);
        msgBox.setText("Sucessfully removed student from databse.");
        msgBox.exec();

    } catch (const char *er) {
        qDebug() << er;
        msgBox.setText(er);
        msgBox.exec();
    }
    ui->lineEdit_surname->clear();
}

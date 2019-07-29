#include "searchstudent.h"
#include "ui_searchstudent.h"
#include <QDebug>

searchStudent::searchStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchStudent)
{
    ui->setupUi(this);
}

searchStudent::~searchStudent()
{
    delete ui;
}

void searchStudent::on_homeButton_clicked()
{
    emit HomeClicked();
}

void searchStudent::on_searchButton_clicked()
{
    Database conn;
    QSqlQueryModel * model = new QSqlQueryModel();
    QMessageBox msgBox;

      QString input = ui->lineEdit_surname->text();
      if(ui->comboBox->currentText()=="Surname"){
          try {
              conn.connectToDB();

              QSqlQuery* q = new QSqlQuery(conn.mydb);
              bool prepRet = q->prepare("SELECT * FROM students WHERE surname ='"+input+"'");
              if (!prepRet) {
                qDebug() << q->lastError().text();
                return;
              }
              q->exec();
              if (!q->exec()) {
                qDebug() << q->lastError().text();
                return;
              }
              model->setQuery(*q);
              ui->tableView->setModel(model);

              conn.connClose();
              qDebug() << "rowCount: " << (model->rowCount());


          } catch (const char * er) {
              qDebug() << er;
              msgBox.setText(er);
              msgBox.exec();
          }
          ui->lineEdit_surname->clear();

}
      if(ui->comboBox->currentText()=="Personal ID"){
          try {
              conn.connectToDB();

              QSqlQuery* q = new QSqlQuery(conn.mydb);
              bool prepRet = q->prepare("SELECT * FROM students WHERE pid ='"+input+"'");
              if (!prepRet) {
                qDebug() << q->lastError().text();
                return;
              }
              q->exec();
              if (!q->exec()) {
                qDebug() << q->lastError().text();
                return;
              }
              model->setQuery(*q);
              ui->tableView->setModel(model);

              conn.connClose();
              qDebug() << "rowCount: " << (model->rowCount());


          } catch (const char * er) {
              qDebug() << er;
              msgBox.setText(er);
              msgBox.exec();
          }
          ui->lineEdit_surname->clear();

}
      if(ui->comboBox->currentText()=="Residence"){
          try {
              conn.connectToDB();

              QSqlQuery* q = new QSqlQuery(conn.mydb);
              bool prepRet = q->prepare("SELECT * FROM students WHERE residence ='"+input+"'");
              if (!prepRet) {
                qDebug() << q->lastError().text();
                return;
              }
              q->exec();
              if (!q->exec()) {
                qDebug() << q->lastError().text();
                return;
              }
              model->setQuery(*q);
              ui->tableView->setModel(model);

              conn.connClose();
              qDebug() << "rowCount: " << (model->rowCount());


          } catch (const char * er) {
              qDebug() << er;
              msgBox.setText(er);
              msgBox.exec();
          }
          ui->lineEdit_surname->clear();

}


}

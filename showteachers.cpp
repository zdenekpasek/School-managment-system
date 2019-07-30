#include "showteachers.h"
#include "ui_showteachers.h"
#include <database.h>

showteachers::showteachers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showteachers)
{
    ui->setupUi(this);
}

showteachers::~showteachers()
{
    delete ui;
}

void showteachers::on_homeButton_clicked()
{
    emit HomeClicked();
}

void showteachers::on_listTeachersButton_clicked()
{
    Database conn;
    QSqlQueryModel * model = new QSqlQueryModel();
    QMessageBox msgBox;

    try {
        conn.connectToDB();

        QSqlQuery* q = new QSqlQuery(conn.mydb);
        bool prepRet = q->prepare("SELECT * FROM teachers");
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
}

void showteachers::on_resetDbButton_clicked()
{
    QMessageBox msgBox;
    Database conn;

    try {
        conn.connectToDB();
        conn.resetDB();
        msgBox.setText("Sucessfully reseted database.");
        msgBox.exec();
        ui->labelMessage->setText("Please list database again.");


    } catch (const char * er) {
        qDebug() << er;
        msgBox.setText(er);
        msgBox.exec();
    }

}



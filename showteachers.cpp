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

}

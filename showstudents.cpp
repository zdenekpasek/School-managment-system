#include "showstudents.h"
#include "ui_showstudents.h"
#include "database.h"

showStudents::showStudents(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showStudents)
{
    ui->setupUi(this);
}

showStudents::~showStudents()
{
    delete ui;
}

void showStudents::on_homeButton_clicked()
{
    emit HomeClicked();
}

void showStudents::on_listStudentsButton_clicked()
{
    Database conn;
    QSqlQueryModel * model = new QSqlQueryModel();
    conn.connectToDB();

    QSqlQuery* q = new QSqlQuery(conn.mydb);
    bool prepRet = q->prepare("SELECT * FROM students");
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

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

// select students from database and display values to tableView //
void showStudents::on_listStudentsButton_clicked()
{
    Database conn;
    QSqlQueryModel * model = new QSqlQueryModel();
    QMessageBox msgBox;
    try {
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
        ui->labelMessage->setText("");

    } catch (const char * er) {
        qDebug() << er;
        msgBox.setText(er);
        msgBox.exec();
    }

}

// delete everything from database students //
void showStudents::on_resetDbButton_clicked()
{
    QMessageBox msgBox;
    Database conn;
    QString table = "students";

    try {
        conn.connectToDB();
        conn.resetDB(table);
        msgBox.setText("Sucessfully reseted database.");
        msgBox.exec();
        ui->labelMessage->setText("Please list database again.");

    } catch (const char * er) {
        qDebug() << er;
        msgBox.setText(er);
        msgBox.exec();
    }

}

// update values in database //
void showStudents::on_updateDbButton_clicked()
{
    QMessageBox msgBox;
    Database conn;
    QString user = ui->lineEdit_user->text();
    QString value = ui->lineEdit_value->text();
    QString column;

    // update residence //
    if(ui->comboBox->currentText()=="Residence"){
        column = "residence";
        try {
            conn.connectToDB();
            qDebug() << user << value;
            conn.updateDB(column, value, user);
            msgBox.setText("Sucessfully updated database.");
            msgBox.exec();
            ui->labelMessage->setText("Please list database again.");

        }catch (const char * er) {
            qDebug() << er;
            msgBox.setText(er);
            msgBox.exec();
        }
    }

    // update subjects //
    if(ui->comboBox->currentText()=="Subjects"){
        column = "subjects";
        try {
            conn.connectToDB();
            qDebug() << user << value;
            conn.updateDB(column, value, user);
            msgBox.setText("Sucessfully updated database.");
            msgBox.exec();
            ui->labelMessage->setText("Please list database again.");

        }catch (const char * er) {
            qDebug() << er;
            msgBox.setText(er);
            msgBox.exec();
        }
    }
}

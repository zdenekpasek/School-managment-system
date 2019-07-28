#include "database.h"
#include "showstudents.h"

Database::Database()
{

}



void Database::connClose()
{
    mydb.close();
    qDebug() << "DB disconnected";
    //mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

void Database::connectToDB()
{
    qDebug() << "Connecting to database...";
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("C:/Users/zdenek/Documents/ManagmentSystem/database.db");

    if(mydb.open()){

    qDebug() << "DB connected";

    } else {

    qDebug() << "DB not connected";

    }
}

void Database::addStudentToDB(QString name, QString surname, QString pid, QString residence, QString registration, int subjects)
{
    connectToDB();
    QSqlQuery q;
    q.prepare("INSERT INTO students(name, surname, pid, residence, registration, subjects) VALUES (:name, :surname, :pid, :residence, :registration, :subjects)");
    q.bindValue(":name", name);
    q.bindValue(":surname", surname);
    q.bindValue(":pid", pid);
    q.bindValue(":residence", residence);
    q.bindValue(":registration", registration);
    q.bindValue(":subjects", subjects);

    if(!q.exec()){
        qDebug()<< "Error adding values to table.";
    } else {
        qDebug()<< "Sucessfully added values to table.";

}
    connClose();

}



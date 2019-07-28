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
        qDebug()<< "Error adding values to the table.";
    } else {
        qDebug()<< "Sucessfully added student to the table.";

}
    connClose();

}

void Database::addTeachertToDB(QString name, QString surname, QString pid, QString residence, QString qualification, QString experience, QString subject)
{
    connectToDB();
    QSqlQuery q;
    q.prepare("INSERT INTO teachers(name, surname, pid, residence, qualification, experience, subject) VALUES (:name, :surname, :pid, :residence, :qualification, :experience, :subject)");
    q.bindValue(":name", name);
    q.bindValue(":surname", surname);
    q.bindValue(":pid", pid);
    q.bindValue(":residence", residence);
    q.bindValue(":qualification", qualification);
    q.bindValue(":qualification", experience);
    q.bindValue(":subject", subject);

    if(!q.exec()){
        qDebug()<< "Error adding values to the table.";

    } else {
        qDebug()<< "Sucessfully added teacher to the table.";

}
    connClose();

}

void Database::removeStudentFromDB()
{

}



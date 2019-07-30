#include "database.h"
#include "showstudents.h"


Database::Database()
{

}


// close connection to database //
void Database::connClose()
{
    mydb.close();
    qDebug() << "DB disconnected";
    //mydb.removeDatabase(QSqlDatabase::defaultConnection);
}

// connection to database //
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

// adding student to database //
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

// adding teacher to database //
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
    q.bindValue(":experience", experience);
    q.bindValue(":subject", subject);

    if(!q.exec()){
        qDebug()<< "Error adding values to the table.";
    } else {
        qDebug()<< "Sucessfully added teacher to the table.";
}
    connClose();
}

// removing student from database //
void Database::removeStudentFromDB(QString surname)
{
    connectToDB();
    QSqlQuery q;
    q.prepare("DELETE FROM students WHERE surname = '"+surname+"'");

    if(!q.exec()){
        qDebug()<< "Error while removing values from table.";
    } else {
        qDebug()<< "Sucessfully removed student from table.";
}
    connClose();
}

// deleting everything from database //
void Database::resetDB(QString table)
{
    connectToDB();
    QSqlQuery q;
    q.prepare("DELETE FROM '"+table+"'");

    if(!q.exec()){
        qDebug()<< "Error while reseting database.";
    } else {
        qDebug()<< "Sucessfully reseted database.";
}
    connClose();
}

// update data in database //
void Database::updateDB(QString column, QString newValue, QString user){
    connectToDB();
    QSqlQuery q;
    q.prepare("UPDATE students SET '"+column+"' ='"+newValue+"' WHERE surname ='"+user+"'");

    if(!q.exec()){
        qDebug()<< "Error updating database.";

    } else {
        qDebug()<< "Sucessfully updated database.";
}
    connClose();


}





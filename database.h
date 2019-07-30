#ifndef DATABASE_H
#define DATABASE_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>
#include <string>

using namespace std;

class Database
{
public:
    Database();

    QSqlDatabase mydb;

    void connClose();
    void connectToDB();

    void addStudentToDB(QString name, QString surname, QString pid, QString residence, QString registration, int subjects);
    void addTeachertToDB(QString name, QString surname, QString pid, QString residence, QString qualification, QString experience, QString subject);
    void removeStudentFromDB(QString surname);
    void resetDB();
    void updateDB(QString column, QString newValue, QString user);

};

#endif // DATABASE_H

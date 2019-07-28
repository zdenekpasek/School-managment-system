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

};

#endif // DATABASE_H

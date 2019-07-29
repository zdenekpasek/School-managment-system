#ifndef SEARCHSTUDENT_H
#define SEARCHSTUDENT_H

#include <QWidget>
#include <addstudent.h>
#include <database.h>

namespace Ui {
class searchStudent;
}

class searchStudent : public QWidget
{
    Q_OBJECT

public:
    explicit searchStudent(QWidget *parent = nullptr);
    ~searchStudent();
    addStudent stud;

signals:
    void HomeClicked();
private slots:
    void on_homeButton_clicked();

    void on_searchButton_clicked();

private:
    Ui::searchStudent *ui;
};

#endif // SEARCHSTUDENT_H

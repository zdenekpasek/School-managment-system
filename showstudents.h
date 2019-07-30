#ifndef SHOWSTUDENTS_H
#define SHOWSTUDENTS_H

#include <QWidget>
#include <database.h>

namespace Ui {
class showStudents;
}

class showStudents : public QWidget
{
    Q_OBJECT

public:
    explicit showStudents(QWidget *parent = nullptr);
    ~showStudents();

signals:
    void HomeClicked();
private slots:
    void on_homeButton_clicked();
    void on_listStudentsButton_clicked();
    void on_resetDbButton_clicked();
    void on_updateDbButton_clicked();

private:
    Ui::showStudents *ui;
};

#endif // SHOWSTUDENTS_H

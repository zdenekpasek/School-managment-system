#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QWidget>

namespace Ui {
class addStudent;
}

class addStudent : public QWidget
{
    Q_OBJECT

public:
    explicit addStudent(QWidget *parent = nullptr);
    ~addStudent();



private:
    Ui::addStudent *ui;


signals:
    void HomeClicked();
private slots:
    void on_homeButton_clicked();
    void on_addStudentButton_clicked();
    void clearLineEdits();
};

#endif // ADDSTUDENT_H

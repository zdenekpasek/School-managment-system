#ifndef ADDSTUDENT_H
#define ADDSTUDENT_H

#include <QWidget>
#include <student.h>
#include <QList>


namespace Ui {
class addStudent;
}

class addStudent : public QWidget
{
    Q_OBJECT

public:
    explicit addStudent(QWidget *parent = nullptr);
    ~addStudent();
    vector<Student *> students;
    QList<Student*> list;


private:
    Ui::addStudent *ui;

signals:
    void HomeClicked();
private slots:
    void on_homeButton_clicked();
    void on_addStudentButton_clicked();
    void clearLineEdits();
    bool checkLineEditString(QString le, QString le2, QString le3, QString le4, QString le5);
    bool checkLineEditInt(int subj);

};

#endif // ADDSTUDENT_H

#ifndef REMOVESTUDENT_H
#define REMOVESTUDENT_H

#include <QWidget>
#include <database.h>

namespace Ui {
class removeStudent;
}

class removeStudent : public QWidget
{
    Q_OBJECT

public:
    explicit removeStudent(QWidget *parent = nullptr);
    ~removeStudent();

signals:
    void HomeClicked();
private slots:
    void on_homeButton_clicked();
    void on_removeStudentButton_clicked();

private:
    Ui::removeStudent *ui;
};

#endif // REMOVESTUDENT_H

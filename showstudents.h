#ifndef SHOWSTUDENTS_H
#define SHOWSTUDENTS_H

#include <QWidget>

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

private:
    Ui::showStudents *ui;
};

#endif // SHOWSTUDENTS_H

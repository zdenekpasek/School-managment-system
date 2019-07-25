#ifndef SEARCHSTUDENT_H
#define SEARCHSTUDENT_H

#include <QWidget>

namespace Ui {
class searchStudent;
}

class searchStudent : public QWidget
{
    Q_OBJECT

public:
    explicit searchStudent(QWidget *parent = nullptr);
    ~searchStudent();

signals:
    void HomeClicked();
private slots:
    void on_homeButton_clicked();

private:
    Ui::searchStudent *ui;
};

#endif // SEARCHSTUDENT_H

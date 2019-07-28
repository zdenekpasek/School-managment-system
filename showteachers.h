#ifndef SHOWTEACHERS_H
#define SHOWTEACHERS_H

#include <QWidget>

namespace Ui {
class showteachers;
}

class showteachers : public QWidget
{
    Q_OBJECT

public:
    explicit showteachers(QWidget *parent = nullptr);
    ~showteachers();


signals:
    void HomeClicked();
private slots:
    void on_homeButton_clicked();

    void on_listTeachersButton_clicked();

private:
    Ui::showteachers *ui;
};

#endif // SHOWTEACHERS_H

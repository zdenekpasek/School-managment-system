#ifndef ADDTEACHER_H
#define ADDTEACHER_H

#include <QWidget>

namespace Ui {
class addteacher;
}

class addteacher : public QWidget
{
    Q_OBJECT

public:
    explicit addteacher(QWidget *parent = nullptr);
    ~addteacher();

private:
    Ui::addteacher *ui;

signals:
    void HomeClicked();
private slots:
    void on_homeButton_clicked();
    void on_addTeacherButton_clicked();
    void clearLineEdits();
    bool checkLineEditString(QString le, QString le2, QString le3, QString le4, QString le5, QString le6, QString le7);

};

#endif // ADDTEACHER_H

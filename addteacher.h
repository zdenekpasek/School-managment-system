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
};

#endif // ADDTEACHER_H

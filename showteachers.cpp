#include "showteachers.h"
#include "ui_showteachers.h"

showteachers::showteachers(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showteachers)
{
    ui->setupUi(this);
}

showteachers::~showteachers()
{
    delete ui;
}

void showteachers::on_homeButton_clicked()
{
    emit HomeClicked();
}

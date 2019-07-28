#include "addteacher.h"
#include "ui_addteacher.h"

addteacher::addteacher(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::addteacher)
{
    ui->setupUi(this);
}

addteacher::~addteacher()
{
    delete ui;
}

void addteacher::on_homeButton_clicked()
{
    emit HomeClicked();
}

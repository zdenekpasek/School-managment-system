#include "removestudent.h"
#include "ui_removestudent.h"

removeStudent::removeStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::removeStudent)
{
    ui->setupUi(this);
}

removeStudent::~removeStudent()
{
    delete ui;
}

void removeStudent::on_homeButton_clicked()
{
    emit HomeClicked();
}

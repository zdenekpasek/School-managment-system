#include "showstudents.h"
#include "ui_showstudents.h"

showStudents::showStudents(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::showStudents)
{
    ui->setupUi(this);
}

showStudents::~showStudents()
{
    delete ui;
}

void showStudents::on_homeButton_clicked()
{
    emit HomeClicked();
}

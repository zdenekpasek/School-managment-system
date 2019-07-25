#include "searchstudent.h"
#include "ui_searchstudent.h"

searchStudent::searchStudent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::searchStudent)
{
    ui->setupUi(this);
}

searchStudent::~searchStudent()
{
    delete ui;
}

void searchStudent::on_homeButton_clicked()
{
    emit HomeClicked();
}

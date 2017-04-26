#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;
}




void Widget::on_Button1_clicked()
{
     ui->stackedWidget->setCurrentIndex(1);
}







void Widget::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

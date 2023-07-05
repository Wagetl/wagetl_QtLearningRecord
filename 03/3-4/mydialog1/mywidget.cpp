#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDialog>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    connect(ui->showChildButton,        //connect将信号与槽进行手动关联
            &QPushButton::clicked,      //此为信号
            this,
            &MyWidget::showChildDialog);//此为槽
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::showChildDialog()        //槽是一个函数，接收到信号时就执行这个函数
{
    QDialog * dialog = new QDialog(this);
    dialog->show();
}

//void MyWidget::on_showChildButton_clicked()        //槽是一个函数，接收到信号时就执行这个函数
//{
//    QDialog * dialog = new QDialog(this);
//    dialog->show();
//}

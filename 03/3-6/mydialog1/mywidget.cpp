#include "mywidget.h"
#include "mydialog.h"
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

void MyWidget::on_pushButton_clicked()
{
    close();    //先关闭主界面，其实它是隐藏起来了，并没有退出，在新建MyDialog对象
    MyDialog dlg;
    if(dlg.exec() == QDialog::Accepted)show();//如果按下了进入主界面按钮，则进入主界面，否则程序退出
}


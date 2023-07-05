#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDialog>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

    //QDialog dialog(this);                 //这里的dialog对象只在这个构造函数中有用，等构造函数执行完了dialog也就消失了
    //dialog.show();

    //QDialog * dialog = new QDialog(this); //用this，dialog出现在widget的中间，不用的话出现在屏幕的中间
    //dialog->show();                       //用了指针，创建了指向QDialog类对象的指针变量

    //QDialog dialog(this);                 //通过此种方法创建的dialog不会和widget同时出现，只有关闭
    //dialog.exec();                        //dialog之后widget才会出现，这就是"模态"

    QDialog * dialog = new QDialog(this);   //此种方法创建的模态对话是和它的父窗口同时show的，
    dialog->setModal(true);                 //上面的方法创建的模态对话只有在关闭了之后才会显示父窗口
    dialog->show();
}

MyWidget::~MyWidget()
{
    delete ui;
}


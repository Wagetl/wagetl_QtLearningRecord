#include "mywidget.h"
#include "ui_mywidget.h"
#include <QHBoxLayout>
#include <QGridLayout>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);

//    QHBoxLayout * layout = new QHBoxLayout; //新建水平布局管理器
//    layout->addWidget(ui->fontComboBox);    //向布局管理器中添加部件
//    layout->addWidget(ui->textEdit);
//    layout->setSpacing(50);                 //设置部件的间隔
//    layout->setContentsMargins(30,30,50,50); //设置布局管理器到边界的间隔
//                                            //4个参数顺序是左、上、右、下
//    setLayout(layout);                      //将这个布局设置为MyWidget类的布局

//    QGridLayout * layout = new QGridLayout;         //新建栅格布局管理器
//    layout->addWidget(ui->fontComboBox,0,0,1,2);    //从第0行0列开始，占据1行2列
//    layout->addWidget(ui->pushButton,0,2,1,1);      //从第2行2列开始，占据1行1列
//    layout->addWidget(ui->textEdit,1,0,1,3);        //从第1行0列开始，占据1行3列
//    layout->addWidget(ui->label,3,2,1,1);
//    setLayout(layout);

    ui->textEdit->hide();                       //此代码为了让行编辑器一开始是隐藏的


}

MyWidget::~MyWidget()
{
    delete ui;
}


void MyWidget::on_pushButton_toggled(bool checked)  //显隐窗口按钮
{
    ui->textEdit->setVisible(checked);
    if(checked) ui->pushButton->setText(tr("隐藏可扩展窗口喵"));
    else ui->pushButton->setText(tr("显示可扩展窗口喵"));
}


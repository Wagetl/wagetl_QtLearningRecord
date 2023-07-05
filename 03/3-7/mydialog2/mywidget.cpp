#include "mywidget.h"
#include "ui_mywidget.h"
#include<QDebug>
#include<QColorDialog>
#include<QFileDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QMessageBox>
#include<QProgressDialog>
#include<QErrorMessage>
#include<QWizard>

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MyWidget)
{
    ui->setupUi(this);
    errordlg = new QErrorMessage(this);
}

MyWidget::~MyWidget()
{
    delete ui;

}


//void MyWidget::on_pushButton_clicked()        //静态函数创建颜色对话框
//{
//    QColor color = QColorDialog::getColor(Qt::red,this,tr("颜色对话框"),QColorDialog::ShowAlphaChannel);
//    qDebug() << "color: " << color;
//}

void MyWidget::on_pushButton_clicked()           //创建对象来灵活的创建颜色对话框
{
    QColorDialog dialog(Qt::red,this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();
    qDebug() << "color:" << color;
}

void MyWidget::on_pushButton_5_clicked()         //文件对话框
{
    QStringList fileNames = QFileDialog::getOpenFileNames(this,tr("是文件对话框喵"),
    "e:",tr("图片文件喵(*jpg *png *txt);;视频文件喵(*mp3)"));
    qDebug() << "fileNames:" << fileNames;
}

void MyWidget::on_pushButton_2_clicked()        //字体对话框
{
    bool ok;    //ok用于标记是否按下了ok键
    QFont font = QFontDialog::getFont(&ok,this);
    if(ok) ui->pushButton_2->setFont(font);     //如果按下 ok 键，那么让字体对话框按钮使用新字体
    else qDebug() << tr("没有选择字体喵！！");     //按下cancel键，输出信息
}


void MyWidget::on_pushButton_6_clicked()        //输入对话框
{
    bool ok;
    QString string = QInputDialog::getText(this,tr("是输入字符串对话框喵~"),tr("快输入用户名！！"),
                    QLineEdit::Normal,tr("admin"),&ok);
    if(ok)qDebug() << "string:" << string;
    //上述函数获取字符串

    int value1 = QInputDialog::getInt(this,tr("是输入整数对话框喵~"),
                tr("请输入-1000~1000之间的数值"),100,-1000,1000,10,&ok);
    if(ok) qDebug() << "value1:" <<value1;
    //上述函数获取整数

    double value2 = QInputDialog::getDouble(this,tr("是输入浮点对话框喵~"),
                    tr("请输入-1000~1000之间的数值喵~"),0.00,-1000,1000,2,&ok);
    if(ok)qDebug() << "value2:" << value2;
    //上述函数获取浮点数

    QStringList items;
    items << tr("条目1喵~") << tr("条目二喵~");
    QString item = QInputDialog::getItem(this,tr("输入条目对话框喵~"),
                tr("请选择或输入一个条目"),items,0,true,&ok);
    if(ok)qDebug() << "item:" << item;
}

void MyWidget::on_pushButton_3_clicked()    //消息对话框
{
    int ret1 = QMessageBox::question(this,tr("这是问题对话框喵~"),
              tr("你了解我吗"),QMessageBox::Yes,QMessageBox::No);
    if(ret1 == QMessageBox::Yes)qDebug() << tr("谢谢你！");
    else qDebug() << tr("这都不知道，好生气！");

    int ret2 = QMessageBox::information(this,tr("这是提示对话框喵~"),
             tr("这是他妈的！Qt书籍！！"),QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok)qDebug() << tr("提示！");

    int ret3 = QMessageBox::warning(this,tr("这是警告对话框一枚~"),
            tr("别他妈的提前结束了！"),QMessageBox::Abort);
    if(ret3 == QMessageBox::Abort)qDebug() << tr("严重警告");

    int ret4 = QMessageBox::critical(this,tr("严重错误！"),
            tr("发现了一个严重错误，请务必准备好电脑爆炸的准备！"),QMessageBox::YesAll);
    if(ret4 == QMessageBox::YesAll)qDebug() << tr("error");

    QMessageBox::about(this,tr("关于对话框"),tr("wagetl致力于为您服务！！"));
}


void MyWidget::on_pushButton_7_clicked()    //进度对话框
{
    QProgressDialog dialog(tr("这里是文件复制进度"),tr("取消，不干了！"),0,500000,this);
    dialog.setWindowTitle(tr("进度对话框喵~"));
    dialog.setWindowModality(Qt::WindowModal);
    dialog.show();
    for(int i = 1; i < 500000; i ++){
        dialog.setValue(i);
        QCoreApplication::processEvents();
        if(dialog.wasCanceled()){
            qDebug() << tr("取消吧取消吧！");
            break;}
    }
    dialog.setValue(500000);
    qDebug() << tr("复制！结束！！");
}


void MyWidget::on_pushButton_4_clicked()    //错误信息对话框
{
    errordlg->setWindowTitle(tr("错误信息对话框"));
    errordlg->showMessage(tr("这里是出错信息！！！"));
}

QWizardPage * MyWidget::createPage1()
{
    QWizardPage * page = new QWizardPage;
    page->setTitle(tr("介绍"));
    return page;
}

QWizardPage * MyWidget::createPage2()
{
    QWizardPage * page = new QWizardPage;
    page->setTitle(tr("用户选择信息"));
    return page;
}

QWizardPage * MyWidget::createPage3()
{
    QWizardPage * page = new QWizardPage;
    page->setTitle(tr("结束"));
    return page;
}

void MyWidget::on_pushButton_8_clicked()    //向导对话框
{
    QWizard wizard(this);
    wizard.setWindowTitle(tr("向导对话框"));
    wizard.addPage(createPage1());          //添加向导界面
    wizard.addPage(createPage2());
    wizard.addPage(createPage3());

}


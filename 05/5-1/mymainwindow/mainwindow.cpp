#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QActionGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenu * editMenu = ui->menuBar->addMenu(tr("编辑(&E)"));      //添加编辑菜单
    QAction * action_Open = editMenu->addAction(                 //添加打开菜单
        QIcon(":/image/images/openfile.png"),tr("打开文件(&O)"));
    action_Open->setShortcut(QKeySequence("ctrl+O"));            //设置快捷键
    ui->mainToolBar->addAction(action_Open);                     //在工具栏中添加动作

    QActionGroup * group = new QActionGroup(this);          //添加动作组
                                                            //疑问：为啥这里的动作组添加到了编辑菜单？
    QAction * action_L = group->addAction(tr("左对齐(&L)")); //添加动作
    action_L->setCheckable(true);                           //设置是否可选
    QAction * action_R = group->addAction(tr("右对齐(&R)"));
    action_R->setCheckable(true);
    QAction * action_C = group->addAction(tr("居中(&C)"));
    action_C->setCheckable(true);

    action_L->setChecked(true);                             //指定默认选中状态为 action_L

    editMenu->addSeparator();                               //添加分割线
    editMenu->addAction(action_L);                          //将动作添加到菜单中
    editMenu->addAction(action_R);
    editMenu->addAction(action_C);
    editMenu->addSeparator();

}

MainWindow::~MainWindow()
{
    delete ui;
}


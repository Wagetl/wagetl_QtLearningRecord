#include "mywidget.h"
#include<QApplication>
#include "mydialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MyDialog dialog;                            //新建MyDialog类对象
    if(dialog.exec() == QDialog::Accepted){     //判断dialog执行结果
        MyWidget w;
        w.show();               //如果按下了"显示主界面窗口"按钮，则显示主界面
        return a.exec();        //程序正常执行
    }
    else return 0;              //否则，退出程序
}

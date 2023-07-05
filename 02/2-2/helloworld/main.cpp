#include<QApplication>
#include<QDialog>
#include<QLabel>
int main(int argc,char * argv[])
{
    QApplication a(argc,argv);
    QDialog w;
    w.resize(400,300);//设置窗口大下，单位为像素
    QLabel label(&w);
    label.move(120,120);//设置label位置，左上角(0,0)
    label.setText(QObject::tr("Hello World!你好，Qt！"));//QObject::tr可以实现多语言支持，建议所有
    //字符串都用tr()函数括起来，用于国际化
    w.show();
    return a.exec();
}

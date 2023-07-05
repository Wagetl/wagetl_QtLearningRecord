#include<QApplication>
#include<QWidget>
#include<QDebug>//qDebug函数将调试信息直接输出到控制台，是最常用的调试函数

int main(int argc,char * argv[])
{
    QApplication a(argc,argv);

    QWidget widget;
    widget.resize(400,300);     //设置窗口大小
    widget.move(200,100);       //设置窗口位置
    widget.show();
    int x = widget.x();
    qDebug("x: % d",x);         //输出x的值
    int y = widget.y();
    qDebug("y: % d",y);
    QRect geometry = widget.geometry();//返回无边框窗口框架矩形的值，即(x,y,width,height)
    QRect frame = widget.frameGeometry();//返回有边框窗口框架矩形的值。

    qDebug() << "geometry: " << geometry << "frame: " << frame; //使用此方法需要添加头文件QDebug
    //此方法使用输出流的方式一次输出多个值 "geometry:  QRect(201,130 400x300) frame:  QRect(200,100 402x331)"

    qDebug() << "pos: " << widget.pos() << Qt::endl << "rect: " << widget.rect()
             << Qt::endl << "size: " << widget.size() << Qt::endl << "width: "
             << widget.width() << Qt::endl << "height: " << widget.height();
//    Q_UNUSED(x);
//    Q_UNUSED(y);
//    Q_UNUSED(geometry);
//    Q_UNUSED(frame);

    return a.exec();
}

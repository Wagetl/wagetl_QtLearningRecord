#include<QtWidgets>
int main(int argc,char * argv[])
{
    QApplication a(argc,argv);
    QWidget * widget = new QWidget(nullptr,Qt::Dialog | Qt::FramelessWindowHint);
    widget->setWindowTitle(QObject::tr("我是widget"));

    QLabel * label1 = new QLabel(nullptr,Qt::SplashScreen | Qt::WindowStaysOnTopHint);
    label1->setWindowTitle(QObject::tr("我是label"));
    label1->setText(QObject::tr("label：我是个窗口"));
    label1->resize(180,20);

    QLabel * label2 = new QLabel(widget);
    label2->setText(QObject::tr("label2：我不是独立窗口，只是widget的子部件"));
    label2->resize(260,20);

    label1->show();
    widget->show();
    int ret = a.exec();
    delete label1;
    delete widget;
    return ret;

}

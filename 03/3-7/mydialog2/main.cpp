#include "mywidget.h"

#include <QApplication>
#include<QDebug>
#include<QColorDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyWidget w;
    w.show();
    return a.exec();
}

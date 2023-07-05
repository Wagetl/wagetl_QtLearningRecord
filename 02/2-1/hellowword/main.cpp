#include "hellowdialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    HellowDialog w;
    w.show();
    return a.exec();
}

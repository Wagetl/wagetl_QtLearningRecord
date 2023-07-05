#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MyWidget; }
QT_END_NAMESPACE

class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget(QWidget *parent = nullptr);
    ~MyWidget();

private:
    Ui::MyWidget *ui;
public slots:
    void showChildDialog();//此处为添加槽的说明
//public slots:
//    void on_showChildButton_clicked();此处添加槽的声明并自动关联
private slots:
    void on_pushButton_clicked();
};
#endif // MYWIDGET_H

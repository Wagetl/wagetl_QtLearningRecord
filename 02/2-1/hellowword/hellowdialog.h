#ifndef HELLOWDIALOG_H
#define HELLOWDIALOG_H

#include <QDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class HellowDialog; }
QT_END_NAMESPACE

class HellowDialog : public QDialog
{
    Q_OBJECT

public:
    HellowDialog(QWidget *parent = nullptr);
    ~HellowDialog();

private:
    Ui::HellowDialog *ui;
};
#endif // HELLOWDIALOG_H

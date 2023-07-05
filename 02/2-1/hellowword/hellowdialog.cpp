#include "hellowdialog.h"
#include "ui_hellowdialog.h"

HellowDialog::HellowDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::HellowDialog)
{
    ui->setupUi(this);
}

HellowDialog::~HellowDialog()
{
    delete ui;
}


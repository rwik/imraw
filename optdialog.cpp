#include "optdialog.h"
#include "ui_optdialog.h"

optDialog::optDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::optDialog)
{
    ui->setupUi(this);
}

optDialog::optDialog(int quality,QString name,QString lbl)
{
    this->quality = quality;
    this->name = name;
    this->lbl = lbl;


}

optDialog::~optDialog()
{
    delete ui;
}

void optDialog::on_buttonBox_accepted()
{
    int quality = ui->horizontalSlider->value();
    QString name = ui->lineEdit_2->text();
    QString lbl = ui->lineEdit_2->text();

}

void optDialog::on_buttonBox_rejected()
{
    close();
}

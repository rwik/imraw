#ifndef OPTDIALOG_H
#define OPTDIALOG_H

#include <QDialog>

namespace Ui {
class optDialog;
}

class optDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit optDialog(QWidget *parent = 0);
    optDialog(int, QString, QString);
    int quality;
    QString name;
    QString lbl;
    ~optDialog();
    
private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::optDialog *ui;
};

#endif // OPTDIALOG_H

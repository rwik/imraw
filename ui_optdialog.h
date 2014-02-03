/********************************************************************************
** Form generated from reading UI file 'optdialog.ui'
**
** Created: Sun Feb 2 03:35:31 2014
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OPTDIALOG_H
#define UI_OPTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSlider>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_optDialog
{
public:
    QDialogButtonBox *buttonBox;
    QGroupBox *groupBox;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEdit;
    QSlider *horizontalSlider;
    QLineEdit *lineEdit_2;

    void setupUi(QDialog *optDialog)
    {
        if (optDialog->objectName().isEmpty())
            optDialog->setObjectName(QString::fromUtf8("optDialog"));
        optDialog->resize(308, 174);
        buttonBox = new QDialogButtonBox(optDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(0, 130, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        groupBox = new QGroupBox(optDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(19, 20, 281, 111));
        widget = new QWidget(groupBox);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 268, 99));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout->addWidget(label_3);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        lineEdit = new QLineEdit(widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout_2->addWidget(lineEdit);

        horizontalSlider = new QSlider(widget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_2->addWidget(horizontalSlider);

        lineEdit_2 = new QLineEdit(widget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        verticalLayout_2->addWidget(lineEdit_2);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(optDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), optDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), optDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(optDialog);
    } // setupUi

    void retranslateUi(QDialog *optDialog)
    {
        optDialog->setWindowTitle(QApplication::translate("optDialog", "Options", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("optDialog", "WaterMark Text", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("optDialog", "Quality", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("optDialog", "File name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class optDialog: public Ui_optDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OPTDIALOG_H

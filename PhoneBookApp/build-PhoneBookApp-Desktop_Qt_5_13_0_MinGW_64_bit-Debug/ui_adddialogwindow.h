/********************************************************************************
** Form generated from reading UI file 'adddialogwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDDIALOGWINDOW_H
#define UI_ADDDIALOGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddDialogWindow
{
public:
    QPushButton *adw_saveButton;
    QPushButton *adw_clsoeButton;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *adw_nameLabel;
    QLabel *adw_numberLabel;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *adw_nameLine;
    QLineEdit *adw_numberLine;

    void setupUi(QDialog *AddDialogWindow)
    {
        if (AddDialogWindow->objectName().isEmpty())
            AddDialogWindow->setObjectName(QString::fromUtf8("AddDialogWindow"));
        AddDialogWindow->resize(277, 155);
        adw_saveButton = new QPushButton(AddDialogWindow);
        adw_saveButton->setObjectName(QString::fromUtf8("adw_saveButton"));
        adw_saveButton->setGeometry(QRect(190, 120, 80, 21));
        adw_clsoeButton = new QPushButton(AddDialogWindow);
        adw_clsoeButton->setObjectName(QString::fromUtf8("adw_clsoeButton"));
        adw_clsoeButton->setGeometry(QRect(100, 120, 80, 21));
        widget = new QWidget(AddDialogWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 10, 241, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        adw_nameLabel = new QLabel(widget);
        adw_nameLabel->setObjectName(QString::fromUtf8("adw_nameLabel"));

        verticalLayout->addWidget(adw_nameLabel);

        adw_numberLabel = new QLabel(widget);
        adw_numberLabel->setObjectName(QString::fromUtf8("adw_numberLabel"));

        verticalLayout->addWidget(adw_numberLabel);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        adw_nameLine = new QLineEdit(widget);
        adw_nameLine->setObjectName(QString::fromUtf8("adw_nameLine"));

        verticalLayout_2->addWidget(adw_nameLine);

        adw_numberLine = new QLineEdit(widget);
        adw_numberLine->setObjectName(QString::fromUtf8("adw_numberLine"));

        verticalLayout_2->addWidget(adw_numberLine);


        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(AddDialogWindow);

        QMetaObject::connectSlotsByName(AddDialogWindow);
    } // setupUi

    void retranslateUi(QDialog *AddDialogWindow)
    {
        AddDialogWindow->setWindowTitle(QCoreApplication::translate("AddDialogWindow", "Dialog", nullptr));
        adw_saveButton->setText(QCoreApplication::translate("AddDialogWindow", "Save ", nullptr));
        adw_clsoeButton->setText(QCoreApplication::translate("AddDialogWindow", "Close", nullptr));
        adw_nameLabel->setText(QCoreApplication::translate("AddDialogWindow", "Name", nullptr));
        adw_numberLabel->setText(QCoreApplication::translate("AddDialogWindow", "Number", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddDialogWindow: public Ui_AddDialogWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDDIALOGWINDOW_H

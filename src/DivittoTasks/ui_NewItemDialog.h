/********************************************************************************
** Form generated from reading UI file 'NewItemDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWITEMDIALOG_H
#define UI_NEWITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_NewItemDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QLineEdit *itemNameEdit;
    QLabel *label_2;
    QPlainTextEdit *itemNotesEdit;
    QLabel *label;
    QCheckBox *hasDueDateCheckBox;
    QDateTimeEdit *itemDueDateEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *cancelButton;
    QPushButton *acceptButton;

    void setupUi(QDialog *NewItemDialog)
    {
        if (NewItemDialog->objectName().isEmpty())
            NewItemDialog->setObjectName(QStringLiteral("NewItemDialog"));
        NewItemDialog->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(NewItemDialog);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_3 = new QLabel(NewItemDialog);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        itemNameEdit = new QLineEdit(NewItemDialog);
        itemNameEdit->setObjectName(QStringLiteral("itemNameEdit"));

        verticalLayout->addWidget(itemNameEdit);

        label_2 = new QLabel(NewItemDialog);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        itemNotesEdit = new QPlainTextEdit(NewItemDialog);
        itemNotesEdit->setObjectName(QStringLiteral("itemNotesEdit"));

        verticalLayout->addWidget(itemNotesEdit);

        label = new QLabel(NewItemDialog);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        hasDueDateCheckBox = new QCheckBox(NewItemDialog);
        hasDueDateCheckBox->setObjectName(QStringLiteral("hasDueDateCheckBox"));

        verticalLayout->addWidget(hasDueDateCheckBox);

        itemDueDateEdit = new QDateTimeEdit(NewItemDialog);
        itemDueDateEdit->setObjectName(QStringLiteral("itemDueDateEdit"));

        verticalLayout->addWidget(itemDueDateEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        cancelButton = new QPushButton(NewItemDialog);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        acceptButton = new QPushButton(NewItemDialog);
        acceptButton->setObjectName(QStringLiteral("acceptButton"));

        horizontalLayout->addWidget(acceptButton);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(NewItemDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), NewItemDialog, SLOT(close()));

        QMetaObject::connectSlotsByName(NewItemDialog);
    } // setupUi

    void retranslateUi(QDialog *NewItemDialog)
    {
        NewItemDialog->setWindowTitle(QApplication::translate("NewItemDialog", "Dialog", nullptr));
        label_3->setText(QApplication::translate("NewItemDialog", "Item Name:", nullptr));
        label_2->setText(QApplication::translate("NewItemDialog", "Notes:", nullptr));
        label->setText(QApplication::translate("NewItemDialog", "Due Date:", nullptr));
        hasDueDateCheckBox->setText(QApplication::translate("NewItemDialog", "Has due date", nullptr));
        cancelButton->setText(QApplication::translate("NewItemDialog", "Cancel", nullptr));
        acceptButton->setText(QApplication::translate("NewItemDialog", "Accept", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewItemDialog: public Ui_NewItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWITEMDIALOG_H

/********************************************************************************
** Form generated from reading UI file 'SaveAsDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SAVEASDIALOG_H
#define UI_SAVEASDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SaveAsDialog
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *fileNameEdit;
    QPushButton *browseButton;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *SaveAsDialog)
    {
        if (SaveAsDialog->objectName().isEmpty())
            SaveAsDialog->setObjectName(QStringLiteral("SaveAsDialog"));
        SaveAsDialog->resize(369, 98);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SaveAsDialog->sizePolicy().hasHeightForWidth());
        SaveAsDialog->setSizePolicy(sizePolicy);
        verticalLayoutWidget = new QWidget(SaveAsDialog);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 351, 81));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QStringLiteral("DejaVu Sans"));
        font.setPointSize(10);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        fileNameEdit = new QLineEdit(verticalLayoutWidget);
        fileNameEdit->setObjectName(QStringLiteral("fileNameEdit"));

        horizontalLayout_2->addWidget(fileNameEdit);

        browseButton = new QPushButton(verticalLayoutWidget);
        browseButton->setObjectName(QStringLiteral("browseButton"));

        horizontalLayout_2->addWidget(browseButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);

        saveButton = new QPushButton(verticalLayoutWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        horizontalLayout->addWidget(saveButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(SaveAsDialog);

        QMetaObject::connectSlotsByName(SaveAsDialog);
    } // setupUi

    void retranslateUi(QDialog *SaveAsDialog)
    {
        SaveAsDialog->setWindowTitle(QApplication::translate("SaveAsDialog", "Save As", nullptr));
        label->setText(QApplication::translate("SaveAsDialog", "File Name:", nullptr));
        browseButton->setText(QApplication::translate("SaveAsDialog", "Browse", nullptr));
        cancelButton->setText(QApplication::translate("SaveAsDialog", "Cancel", nullptr));
        saveButton->setText(QApplication::translate("SaveAsDialog", "Save", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SaveAsDialog: public Ui_SaveAsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SAVEASDIALOG_H

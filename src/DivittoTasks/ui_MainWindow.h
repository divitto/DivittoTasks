/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_List;
    QAction *actionExit;
    QAction *actionOpen_List;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionAdd;
    QAction *actionRemove;
    QAction *actionEdit;
    QAction *actionMove_Up;
    QAction *actionMove_Down;
    QAction *actionClose_List;
    QAction *actionBy_Due_Date;
    QAction *actionAlpha_Numeric;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QListWidget *listDisplay;
    QPlainTextEdit *descriptionDisplay;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuEdit;
    QMenu *menuSort;
    QMenu *menuClipboard;
    QMenu *menuAbout;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(528, 426);
        actionNew_List = new QAction(MainWindow);
        actionNew_List->setObjectName(QStringLiteral("actionNew_List"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionOpen_List = new QAction(MainWindow);
        actionOpen_List->setObjectName(QStringLiteral("actionOpen_List"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionRemove = new QAction(MainWindow);
        actionRemove->setObjectName(QStringLiteral("actionRemove"));
        actionEdit = new QAction(MainWindow);
        actionEdit->setObjectName(QStringLiteral("actionEdit"));
        actionMove_Up = new QAction(MainWindow);
        actionMove_Up->setObjectName(QStringLiteral("actionMove_Up"));
        actionMove_Down = new QAction(MainWindow);
        actionMove_Down->setObjectName(QStringLiteral("actionMove_Down"));
        actionClose_List = new QAction(MainWindow);
        actionClose_List->setObjectName(QStringLiteral("actionClose_List"));
        actionBy_Due_Date = new QAction(MainWindow);
        actionBy_Due_Date->setObjectName(QStringLiteral("actionBy_Due_Date"));
        actionAlpha_Numeric = new QAction(MainWindow);
        actionAlpha_Numeric->setObjectName(QStringLiteral("actionAlpha_Numeric"));
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionCut = new QAction(MainWindow);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        listDisplay = new QListWidget(centralWidget);
        listDisplay->setObjectName(QStringLiteral("listDisplay"));
        listDisplay->setLayoutMode(QListView::SinglePass);

        verticalLayout->addWidget(listDisplay);

        descriptionDisplay = new QPlainTextEdit(centralWidget);
        descriptionDisplay->setObjectName(QStringLiteral("descriptionDisplay"));

        verticalLayout->addWidget(descriptionDisplay);

        verticalLayout->setStretch(0, 3);
        verticalLayout->setStretch(1, 1);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 528, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuSort = new QMenu(menuEdit);
        menuSort->setObjectName(QStringLiteral("menuSort"));
        menuClipboard = new QMenu(menuEdit);
        menuClipboard->setObjectName(QStringLiteral("menuClipboard"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        MainWindow->insertToolBarBreak(mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew_List);
        menuFile->addAction(actionOpen_List);
        menuFile->addAction(actionClose_List);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuEdit->addAction(actionMove_Up);
        menuEdit->addAction(actionMove_Down);
        menuEdit->addSeparator();
        menuEdit->addAction(menuSort->menuAction());
        menuEdit->addSeparator();
        menuEdit->addAction(actionAdd);
        menuEdit->addAction(actionRemove);
        menuEdit->addAction(actionEdit);
        menuEdit->addSeparator();
        menuEdit->addAction(menuClipboard->menuAction());
        menuSort->addSeparator();
        menuSort->addAction(actionBy_Due_Date);
        menuSort->addAction(actionAlpha_Numeric);
        menuClipboard->addAction(actionCut);
        menuClipboard->addAction(actionCopy);
        menuClipboard->addAction(actionPaste);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionAdd);
        mainToolBar->addAction(actionRemove);
        mainToolBar->addAction(actionEdit);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionMove_Up);
        mainToolBar->addAction(actionMove_Down);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        actionNew_List->setText(QApplication::translate("MainWindow", "New List", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionOpen_List->setText(QApplication::translate("MainWindow", "Open List", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "Save", nullptr));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save as..", nullptr));
        actionAdd->setText(QApplication::translate("MainWindow", "Add Item", nullptr));
        actionRemove->setText(QApplication::translate("MainWindow", "Remove Item", nullptr));
        actionEdit->setText(QApplication::translate("MainWindow", "Edit Item", nullptr));
        actionMove_Up->setText(QApplication::translate("MainWindow", "Move Up", nullptr));
        actionMove_Down->setText(QApplication::translate("MainWindow", "Move Down", nullptr));
        actionClose_List->setText(QApplication::translate("MainWindow", "Close List", nullptr));
        actionBy_Due_Date->setText(QApplication::translate("MainWindow", "Due Date", nullptr));
        actionAlpha_Numeric->setText(QApplication::translate("MainWindow", "Alpha-Numeric", nullptr));
        actionCopy->setText(QApplication::translate("MainWindow", "Copy", nullptr));
        actionPaste->setText(QApplication::translate("MainWindow", "Paste", nullptr));
        actionCut->setText(QApplication::translate("MainWindow", "Cut", nullptr));
        menuFile->setTitle(QApplication::translate("MainWindow", "Fi&le", nullptr));
        menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", nullptr));
        menuSort->setTitle(QApplication::translate("MainWindow", "Sort", nullptr));
        menuClipboard->setTitle(QApplication::translate("MainWindow", "Clipboard", nullptr));
        menuAbout->setTitle(QApplication::translate("MainWindow", "Abo&ut", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "NewItemDialog.h"
#include "SaveAsDialog.h"
#include "Item.h"

#include <map>

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow( QWidget *parent = 0 );
    ~MainWindow( void) ;

private slots:
    void on_actionAdd_triggered( void );
    void on_actionRemove_triggered( void );
    void on_newItemDialogAccept( Item* item );
    void on_editItemDialogAccept( Item* item );
    void updateDescriptionDisplay( Item *item );
    void on_listDisplay_itemSelectionChanged();
    void on_actionMove_Up_triggered();
    void on_actionMove_Down_triggered();
    void on_actionOpen_List_triggered();
    void on_actionSave_as_triggered();
    void on_actionSave_triggered();
    void setCurrentFile( QString fileName );
    void on_actionClose_List_triggered();

    void on_actionEdit_triggered();

private:
    Ui::MainWindow *ui;

    //## Attributes
    std::map<QString, Item*> items;
    bool mHasChanged; // indicates whether or not the user has made changes to the current list
    QString mCurrentFile;
    //## Gui Dialogs
    NewItemDialog* mNewItemDialog;
    SaveAsDialog* mSaveAsDialog;
};

#endif // MAINWINDOW_H

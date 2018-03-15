#ifndef NEWITEMDIALOG_H
#define NEWITEMDIALOG_H

#include "Item.h"

#include <QDialog>

namespace Ui {
class NewItemDialog;
}

class NewItemDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewItemDialog(QWidget *parent = 0);
    ~NewItemDialog();
    void setItem( Item* newItem );

signals:
    void createItem( Item* item );
    void editItem( Item* item );
private slots:
    void on_acceptButton_clicked();

    void on_hasDueDateCheckBox_toggled(bool checked);

private:
    Ui::NewItemDialog *ui;

    bool isEditingItem;
    Item* newItem;
};

#endif // NEWITEMDIALOG_H

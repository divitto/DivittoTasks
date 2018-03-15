#include "NewItemDialog.h"
#include "ui_NewItemDialog.h"

#include <QMessageBox>

NewItemDialog::NewItemDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewItemDialog),
    isEditingItem( false ),
    newItem( nullptr )
{
    ui->setupUi(this);
    ui->hasDueDateCheckBox->setChecked( true );
    ui->itemDueDateEdit->setEnabled( ui->hasDueDateCheckBox->isChecked( ) );
}

NewItemDialog::~NewItemDialog()
{
    delete ui;
    delete newItem;
}

void NewItemDialog::on_acceptButton_clicked()
{
    if( ui->itemNameEdit->text() != "" )
    {
        if( ui->itemNotesEdit->toPlainText() != "" ||
                QMessageBox::question( nullptr, "Are you sure?", "You didn't add any notes for this item. Do you still wish to accept?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes )
        {
            this->newItem = new Item( ui->itemNameEdit->text( ), ui->itemNotesEdit->toPlainText( ), ui->hasDueDateCheckBox->isChecked( ), ui->itemDueDateEdit );
            if( isEditingItem )
                emit( editItem( newItem ) );
            else
                emit createItem( newItem );
            newItem = new Item( );

            ui->itemNameEdit->setText( "" );
            ui->itemNotesEdit->setPlainText( "" );
            ui->hasDueDateCheckBox->setChecked( true );
            ui->itemDueDateEdit->clear( );
            this->close( );
        }
    }
    else
    {
        QMessageBox( QString("Oops!"), QString("There must be a name to save the item."), QMessageBox::NoIcon, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton ).exec();
    }
}

void NewItemDialog::on_hasDueDateCheckBox_toggled(bool checked)
{
    if( checked )
        ui->itemDueDateEdit->setEnabled( true );
    else
        ui->itemDueDateEdit->setEnabled( false );
}

void NewItemDialog::setItem( Item* newItem )
{
    if( newItem )
    {
        this->newItem = newItem;
        ui->itemNameEdit->setText( this->newItem->name );
        ui->itemNotesEdit->setPlainText( this->newItem->description );
        ui->hasDueDateCheckBox->setChecked( this->newItem->hasDueDate );
        ui->itemDueDateEdit = this->newItem->dueDate;
        this->isEditingItem = true;
    }
}

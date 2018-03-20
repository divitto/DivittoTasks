#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QListWidgetItem>
#include <QFile>
#include <QFileDialog>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    items( std::map<QString, Item*>( ) ),
    mHasChanged( false ),
    mCurrentFile( "" ),
    mNewItemDialog( new NewItemDialog( ) ),
    mSaveAsDialog( new SaveAsDialog( ) )
{
    ui->setupUi(this);
    QMainWindow::setWindowTitle( "Divitto's Task Manager" );


    connect( this->mNewItemDialog, SIGNAL( createItem( Item* ) ), this, SLOT( on_newItemDialogAccept( Item* ) ) );
    connect( this->mNewItemDialog, SIGNAL( editItem( Item* ) ), this, SLOT( on_editItemDialogAccept( Item* ) ) );
    connect( this->mSaveAsDialog, SIGNAL( saveSignal( ) ), this, SLOT( on_actionSave_triggered( ) ) );
    connect( this->mSaveAsDialog, SIGNAL( saveFileNameSignal( QString ) ), this, SLOT( setCurrentFile( QString ) ) );

    connect( ui->actionSelect_Deselect_All, SIGNAL( toggled(bool) ), this, SLOT( on_actionSelect_Deselct_All_toggled( bool ) ) );
    ui->actionSelect_Deselect_All->setCheckable( true );
    ui->actionSelect_Deselect_All->setChecked( false );

}

MainWindow::~MainWindow( void )
{
    delete this->mNewItemDialog;
    delete ui;
}

void MainWindow::on_actionAdd_triggered( void )
{
    this->mNewItemDialog->exec();
}

void MainWindow::on_actionRemove_triggered( void )
{
    auto ptr = ui->listDisplay->takeItem( ui->listDisplay->currentRow( ) );
    delete ptr;
    this->mHasChanged = true;
}

void MainWindow::on_newItemDialogAccept( Item* item )
{
    QListWidgetItem* listItem;
    listItem = new QListWidgetItem( item->name );
    ui->listDisplay->addItem( listItem );
    ui->listDisplay->setCurrentItem( listItem );
    ui->listDisplay->currentItem()->setCheckState( Qt::Unchecked );

    this->mHasChanged = true;
    updateDescriptionDisplay( item );

    items.insert( std::pair<QString, Item*>( item->name, item ) );
}

void MainWindow::on_editItemDialogAccept( Item* item )
{
    if( this->items.find( item->name ) == this->items.end( ) ) // the name was changed and so the underlying items data structure will need to be modified...
    {
        this->items.erase( ui->listDisplay->currentItem()->text( ) );
        this->items.insert( std::pair<QString, Item*>( item->name, item ) );
    }
    else
        this->items.at( item->name ) = item;

    // adjust gui
    ui->listDisplay->currentItem()->setText( item->name );
    updateDescriptionDisplay( item );

    this->mHasChanged = true;
}

void MainWindow::updateDescriptionDisplay( Item* item )
{
    ui->descriptionDisplay->clear( );
    if( item->hasDueDate )
        ui->descriptionDisplay->document( )->setPlainText( "Due:\n" + item->dueDate->text( ) + "\n" + item->description );
    else
        ui->descriptionDisplay->document( )->setPlainText( item->description );
}

void MainWindow::on_listDisplay_itemSelectionChanged()
{
    if( ui->listDisplay->currentItem( ) )
    {
        QString name = ui->listDisplay->currentItem()->text();
        if( this->items.find( name ) != this->items.end( ) )
            updateDescriptionDisplay( this->items.at( name ) );
    }
    else
        ui->descriptionDisplay->clear();
}

void MainWindow::on_actionMove_Up_triggered()
{
    int currentRow = ui->listDisplay->currentRow( );

    if( currentRow > 0 )
    {
        ui->listDisplay->insertItem( currentRow - 1, ui->listDisplay->takeItem( currentRow ) );
        ui->listDisplay->setCurrentRow( currentRow - 1 );
        this->mHasChanged = true;
    }
}

void MainWindow::on_actionMove_Down_triggered()
{
    int currentRow = ui->listDisplay->currentRow( );

    if( currentRow < ui->listDisplay->model()->rowCount( ) - 1 )
    {
        ui->listDisplay->insertItem( currentRow + 1, ui->listDisplay->takeItem( currentRow ) );
        ui->listDisplay->setCurrentRow( currentRow + 1 );
        this->mHasChanged = true;
    }
}

void MainWindow::on_actionOpen_List_triggered()
{
    if( !this->mHasChanged || QMessageBox::question(nullptr, "Are you SURE?",
                                            "You have unsaved data!\nAre you SURE you want to close the current list?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        QFile* newFile = new QFile( QFileDialog::getOpenFileName( nullptr, "Open File" ), nullptr );
        if( newFile->exists( ) && newFile->open( QFile::ReadOnly ) )
        {
            ui->listDisplay->clear( );
            ui->descriptionDisplay->clear( );

            this->mCurrentFile = newFile->fileName();
            qDebug() << this->mCurrentFile << " has been set as the currentFile";
            QXmlStreamReader reader( newFile->readAll( ) );
            while( !reader.atEnd( ) && !reader.hasError( ) )
            {
                if(reader.readNext() == QXmlStreamReader::StartElement )
                {
                    QString element = reader.name( ).toString( );
                    if( element == "name" )
                    {
                        QString name = reader.readElementText( );
                        on_newItemDialogAccept( new Item( name, "", false, nullptr ) ); // add empty item to be filled in later.
                        ui->listDisplay->currentItem()->setText( name );
                    }
                    else if( element == "hasDueDate" )
                    {
                        QString flag = reader.readElementText( );
                        if( flag == '1' )
                            this->items.at( ui->listDisplay->currentItem()->text() )->hasDueDate = true;
                        else if( flag == '0' )
                            this->items.at( ui->listDisplay->currentItem()->text() )->hasDueDate = false;
                        else
                            qDebug() << "invalid data found in file!!";
                    }
                    else if( element == "dueDate" )
                    {
                        auto item = this->items.at( ui->listDisplay->currentItem()->text() );
                        if( item->hasDueDate )
                        {
                            item->dueDate = new QDateTimeEdit();
                            ui->descriptionDisplay->setPlainText( "Due Date: " + reader.readElementText( ) + "\n" );
                        }
                    }
                    else if( element == "description" )
                    {
                        this->items.at( ui->listDisplay->currentItem()->text() )->description = reader.readElementText( );
                        ui->descriptionDisplay->appendPlainText( reader.readElementText( ) );
                    }
                    else if( element == "isCompleted" )
                    {
                        QString flag = reader.readElementText( );
                        if( flag == '1' )
                        {
                            this->items.at( ui->listDisplay->currentItem()->text() )->isCompleted = true;
                            ui->listDisplay->currentItem()->setCheckState( Qt::Checked );
                        }
                        else if( flag == '0' )
                        {
                            this->items.at( ui->listDisplay->currentItem()->text() )->isCompleted = false;
                            ui->listDisplay->currentItem()->setCheckState( Qt::Unchecked );
                        }
                        else
                            qDebug() << "invalid data found in file!!";
                    }
                }
            }
            if( ui->listDisplay->model()->rowCount() > 0 ) ui->listDisplay->setCurrentRow( 0 );

            this->mHasChanged = false; // cause theres a new list open
            newFile->close( );
        }
        delete newFile;
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    this->mSaveAsDialog->exec( );
}

void MainWindow::on_actionSave_triggered()
{
    if( ui->listDisplay->model()->rowCount() > 0 || this->mHasChanged )
    {
        if( this->mCurrentFile == "" )
            on_actionSave_as_triggered();
        else
        {
            QFile* file = new QFile( this->mCurrentFile );
            if( file->open( QFile::WriteOnly ) )
            {
                int prevIndex = ui->listDisplay->currentRow( ); // used to return interface to the index it was at before the save occured
                QString saveData = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n<taskList>\n\t<fileName>" + this->mCurrentFile + "</fileName>\n\t<list>";

                for( int i = 0; i < ui->listDisplay->model()->rowCount(); ++i )
                {
                    // use this->items to get data
                    ui->listDisplay->setCurrentRow( i );
                    QString name = ui->listDisplay->currentItem()->text( );
                    if( this->items.find( name ) != this->items.end( ) )
                    {
                        auto item = this->items.at( name );
                        saveData += "\n\t\t<item>\n\t\t\t<name>" + name + "</name>\n\t\t\t<hasDueDate>" + QString::number( item->hasDueDate ) + "</hasDueDate>\n";
                        if( item->hasDueDate )
                            saveData += ( "\t\t\t<dueDate>" + item->dueDate->text( ) + "</dueDate>\n\t\t\t<description>" + item->description + "</description>" );
                        else
                            saveData += ( "\t\t\t<dueDate></dueDate>\n\t\t\t<description>" + item->description + "</description>");

                        if( ui->listDisplay->currentItem()->checkState() == Qt::Checked )
                            saveData += ( "\n\t\t\t<isCompleted>1</isCompleted>\n\t\t</item>" );
                        else
                            saveData += ( "\n\t\t\t<isCompleted>0</isCompleted>\n\t\t</item>" );
                    }
                }
                saveData += "\n\t</list>\n</taskList>";
                file->write( saveData.toStdString().c_str( ) );
                ui->listDisplay->setCurrentRow( prevIndex );
                this->mHasChanged = false;
                QMessageBox( QString("Hurray!"), QString("Save has completed!"), QMessageBox::NoIcon, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton ).exec();
            }
            file->close();
        }
    }
    else
        QMessageBox( QString("Oops!"), QString("There is nothing to be saved!"), QMessageBox::NoIcon, QMessageBox::Ok, QMessageBox::NoButton, QMessageBox::NoButton ).exec();
}

void MainWindow::setCurrentFile( QString fileName )
{
    this->mCurrentFile = fileName;
}

void MainWindow::on_actionClose_List_triggered( )
{
    if( !this->mHasChanged || QMessageBox::question(nullptr, "Are you SURE?",
                                            "You have unsaved data!\nAre you SURE you want to close the current list?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        ui->listDisplay->clear( );
        ui->descriptionDisplay->clear( );
        this->items.clear( );
        this->mHasChanged = false;
        this->mCurrentFile = "";
    }
}

void MainWindow::on_actionEdit_triggered()
{
    this->mNewItemDialog->setItem( this->items.at( ui->listDisplay->currentItem()->text( ) ) );
    this->mNewItemDialog->exec( );
}

void MainWindow::on_actionRemove_all_checked_items_triggered()
{
    int i = 0;
    while( i < ui->listDisplay->model()->rowCount( ) )
    {
        ui->listDisplay->setCurrentRow( i );
        if( ui->listDisplay->currentItem()->checkState() == Qt::Checked )
        {
            auto ptr = ui->listDisplay->takeItem( ui->listDisplay->currentRow( ) );
            delete ptr;
        }
        else
            i++;
    }
    this->mHasChanged = true;
}

void MainWindow::on_actionSelect_Deselct_All_toggled( bool flag )
{
    int currentRow = ui->listDisplay->currentRow( );
    for( int i = 0; i < ui->listDisplay->model()->rowCount( ); ++i )
    {
        ui->listDisplay->setCurrentRow( i );
        if( flag )
            ui->listDisplay->currentItem( )->setCheckState( Qt::Checked );
        else
            ui->listDisplay->currentItem( )->setCheckState( Qt::Unchecked );
    }
    ui->listDisplay->setCurrentRow( currentRow );
    this->mHasChanged = true;
}

void MainWindow::closeEvent( QCloseEvent* event )
{
    if( !this->mHasChanged || QMessageBox::question(nullptr, "Are you SURE?",
                                            "You have unsaved data!\nAre you SURE you want to close the application?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        event->accept( );
    }
    else
    {
        this->mSaveAsDialog->exec( );
        event->ignore();
    }
}

void MainWindow::on_actionExit_triggered()
{
    if( !this->mHasChanged || QMessageBox::question(nullptr, "Are you SURE?",
                                            "You have unsaved data!\nAre you SURE you want to close the application?", QMessageBox::Yes|QMessageBox::No) == QMessageBox::Yes)
    {
        this->close( );
    }
    else
    {
        this->mSaveAsDialog->exec( );
    }
}

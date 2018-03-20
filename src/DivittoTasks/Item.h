#ifndef ITEM_H
#define ITEM_H

#include <QString>
#include <QDateTimeEdit>

class Item
{
public:
    Item( QString name = "UNKNOWN", QString description = "", bool hasDueDate = true, QDateTimeEdit* dueDate = new QDateTimeEdit( ) );
    ~Item( void );

    //## Attributes
    QString name;
    QString description;
    bool hasDueDate;
    QDateTimeEdit* dueDate;
    bool isCompleted;
};

#endif // ITEM_H

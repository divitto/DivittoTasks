#include "Item.h"

Item::Item( QString name, QString description, bool hasDueDate, QDateTimeEdit* dueDate )
    : name( name ),
      description( description ),
      hasDueDate( hasDueDate ),
      dueDate( dueDate ),
      isCompleted( false )
{
}

Item::~Item( void )
{
    delete dueDate;
}

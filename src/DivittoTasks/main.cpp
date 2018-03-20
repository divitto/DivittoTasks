#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
/*
 * TO-DO
 * - Fix save as to accept a file that does not exist from file selection and create it if it does not exist
 * - open edit item dialog on list item double click
 * - Add priority coloring
 * - Sort alphabeticly, by due date, by completed, by priority.
 * - Clipboard items
 *  - copy
 *  - cut
 *  - paste
 */

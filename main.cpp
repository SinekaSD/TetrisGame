#include "menu.h"

#include <QApplication>
/*!
*	Program start fucntion
*	@name	: main
*	@param	: argc, argv[]
*	@return : int
*/
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Menu w(&a);
    w.setWindowIcon(QIcon(":/img/res/icon.ico"));
    w.show();
    return a.exec();
}

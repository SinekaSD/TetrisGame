#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include "precompiledHeader.h"

namespace Ui {
class MainWindowTetris;
}

/*!
*Header of Game Window
*/
class GameWindow : public QMainWindow
{
/*!
*Declares the class as a QObject which is the base class for all Qt objects and handle events
*/
    Q_OBJECT

public:
    explicit GameWindow(QWidget *parent = nullptr);
    ~GameWindow();

private:
    Ui::MainWindowTetris *ui;




};

#endif // GAMEWINDOW_H

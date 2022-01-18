#include "menu.h"
#include "ui_menu.h"
#include <QApplication>
#include "about.h"
#include "instructions.h"
#include "gameArea.h"
#include "gameWindow.h"

/*!
*	constructor Menu Window
*	@name	: Menu
*	@param	: QWidget
*	@return : void
*/

Menu::Menu(QApplication *app,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->app=app;
    setFixedSize(width(), height());
}

/*!
*	destructor Menu Window
*	@name	: ~Menu
*	@param	: no param.
*	@return : void
*/
Menu::~Menu()
{
    delete ui;
}


/*!
*	Load Game Window when clicked
*	@name	: on_gameBtn_clicked
*	@param	: no param.
*	@return : void
*/

void Menu::on_gameBtn_clicked()
{
    this->hide();
    GameWindow *windowTetris=new GameWindow();
    windowTetris->setWindowTitle("Game");
    windowTetris->setWindowIcon(QIcon(":/img/res/icon.ico"));
    windowTetris->show();
}


/*!
*	Load Instructions Window when clicked
*	@name	: on_instBtn_clicked
*	@param	: no param.
*	@return : void
*/

void Menu::on_instBtn_clicked()
{
    Instructions *inst=new Instructions();
    inst->setWindowTitle("Instructions");
    inst->setFixedSize(300,400);
    inst->setWindowIcon(QIcon(":/img/res/icon.ico"));
    inst->show();
}


/*!
*	Load About Window when clicked
*	@name	: on_abtBtn_clicked
*	@param	: no param.
*	@return : void
*/
void Menu::on_abtBtn_clicked()
{
    About *about=new About();
    about->setWindowTitle("About");
    about->setFixedSize(300,400);
    about->setWindowIcon(QIcon(":/img/res/icon.ico"));
    about->show();
}


/*!
*	Exit Application
*	@name	: on_exitBtn_clicked
*	@param	: no param.
*	@return : void
*/
void Menu::on_exitBtn_clicked()
{
    app->exit();
}


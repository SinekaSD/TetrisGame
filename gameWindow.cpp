#include "precompiledHeader.h"
#include "gameWindow.h"
#include "ui_mainWindowTetris.h"
#include "gameArea.h"

/*!
*	constructor Game Window
*	@name	: GameWindow
*	@param	: QWidget
*	@return : void
*/
GameWindow::GameWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowTetris)
{
    ui->setupUi(this);
    GameArea *area = new GameArea;
	QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(area);
	setCentralWidget(new QWidget);
	centralWidget()->setLayout(layout);
    setFixedSize(500, 650);
    this->setWindowTitle("Tetris Game");
    this->setWindowIcon(QIcon(":/img/res/icon.ico"));
}


/*!
*	destructor Game Window
*	@name	: ~GameWindow
*	@param	: no param.
*	@return : void
*/
GameWindow::~GameWindow()
{
    delete ui;
}

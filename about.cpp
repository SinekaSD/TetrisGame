#include "about.h"
#include "ui_about.h"


/*!
*	Constructor About
*	@name	: About
*	@param	: QWidget
*	@return : void
*/
About::About(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::About)
{
    ui->setupUi(this);
}


/*!
*	destructor About Window
*	@name	: ~About
*	@param	: no param.
*	@return : void
*/
About::~About()
{
    delete ui;
}

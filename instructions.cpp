#include "instructions.h"
#include "ui_instructions.h"

/*!
*	constructor Instructions Window
*	@name	: Instructions
*	@param	: QWidget
*	@return : void
*/

Instructions::Instructions(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Instructions)
{
    ui->setupUi(this);
}

/*!
*	destructor Instructions Window
*	@name	: ~Instructions
*	@param	: no param.
*	@return : void
*/
Instructions::~Instructions()
{
    delete ui;
}

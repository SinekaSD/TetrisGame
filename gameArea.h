#ifndef GAMEAREA_H
#define GAMEAREA_H

#include "precompiledHeader.h"

class QLCDNumber;
class QLabel;
class QPushButton;

class Game;

/*!
*	Header of Game Area Class
*/
class GameArea : public QWidget
{
    Q_OBJECT

public:
    GameArea();

private:
    QLabel *createLabel(const QString &text);

    //Displays game information & contains playing area
    Game *board;
    QLabel *nextPieceLabel;
    QLCDNumber *scoreLcd;
    QLCDNumber *linesLcd;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *pauseButton;
};
#endif // GAMEAREA_H

#include "game.h"
#include "gameArea.h"

/*!
*	Constructor Game Area
*	@name	: GameArea
*	@param	: no param.
*	@return : void
*/
GameArea::GameArea()
{
    board = new Game;
    nextPieceLabel = new QLabel;
    nextPieceLabel->setFrameStyle(QFrame::Box | QFrame::Raised);
    nextPieceLabel->setAlignment(Qt::AlignCenter);
    board->setNextPieceLabel(nextPieceLabel);
    board->setStyleSheet("background-image: url(:/img/res/img/home.png);");

    //Initializing lcd indicators of GameArea
    scoreLcd = new QLCDNumber(2);
    scoreLcd->setSegmentStyle(QLCDNumber::Outline);
    scoreLcd->setStyleSheet("background-color: black");
    linesLcd = new QLCDNumber(2);
    linesLcd->setSegmentStyle(QLCDNumber::Outline);
    linesLcd->setStyleSheet("background-color: black");

    //Initializing Buttons of GameArea
    startButton = new QPushButton(tr("&Start"));
    startButton->setFocusPolicy(Qt::NoFocus);
    quitButton = new QPushButton(tr("&Quit"));
    quitButton->setFocusPolicy(Qt::NoFocus);
    pauseButton = new QPushButton(tr("&Pause/Play"));
    pauseButton->setFocusPolicy(Qt::NoFocus);

/*!
*	Signal and Slots of start Button, Quit Button and Pause Button
*/
    connect(startButton, &QPushButton::clicked, board, &Game::start);
    connect(quitButton , &QPushButton::clicked, qApp, &QApplication::quit);
    connect(pauseButton, &QPushButton::clicked, board, &Game::pause);
#if __cplusplus >= 201402L
    connect(board, &TetrixBoard::scoreChanged,
            scoreLcd, qOverload<int>(&QLCDNumber::display));
    connect(board, &TetrixBoard::linesRemovedChanged,
            linesLcd, qOverload<int>(&QLCDNumber::display));
#else
    connect(board, &Game::scoreChanged,
            scoreLcd, QOverload<int>::of(&QLCDNumber::display));
    connect(board, &Game::linesRemovedChanged,
            linesLcd, QOverload<int>::of(&QLCDNumber::display));
#endif

    //Adding widgets to grid
    QGridLayout *grid = new QGridLayout;
    grid->addWidget(board, 0, 0, 15, 8);
    grid->addWidget(createLabel(tr("NEXT")), 0, 9);
    grid->addWidget(nextPieceLabel, 1, 9);
    grid->addWidget(createLabel(tr("SCORE")), 4, 9);
    grid->addWidget(scoreLcd, 5, 9);
    grid->addWidget(createLabel(tr("LINES REMOVED")), 6, 9);
    grid->addWidget(linesLcd, 7, 9);
    grid->addWidget(createLabel(tr("    ")), 8, 9);
    grid->addWidget(quitButton, 9, 9);
    grid->addWidget(pauseButton, 10, 9);
    grid->addWidget(startButton, 11, 9);
    setLayout(grid);
}

/*!
*	create Label for Next, Score, Lines Removed
*	@name	: createLabel
*	@param	: QString
*	@return : QLabel
*/
QLabel *GameArea::createLabel(const QString &text)
{
    QLabel *label = new QLabel(text);
    label->setAlignment(Qt::AlignHCenter | Qt::AlignBottom);
    return label;
}

#ifndef GAME_H
#define GAME_H

#include "precompiledHeader.h"
#include "tetrixpiece.h"

class QLabel;

/*!
*	Header of Game Class
*/
class Game : public QFrame
{
    Q_OBJECT

public:
    Game(QWidget *parent = 0);

    void setNextPieceLabel(QLabel *label);
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;

public slots:
    void start();
    void pause();
    void setVolume(int volume);

signals:
    void scoreChanged(int score);

    void linesRemovedChanged(int numLines);

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void timerEvent(QTimerEvent *event) override;

private:
    enum { BoardWidth = 10, BoardHeight = 22 };

    TetrixShape &shapeAt(int x, int y) { return board[(y * BoardWidth) + x]; }
    int timeoutTime() { return 1000 / (1 + level); }
    int squareWidth() { return contentsRect().width() / BoardWidth; }
    int squareHeight() { return contentsRect().height() / BoardHeight; }
    void EmptyBoard();
    void dropPiece();
    void singleLineDown();
    void pieceDropped(int dropHeight);
    void removeFullLines();
    void newPiece();
    void showNextPiece();
    bool tryMotion(const TetrixPiece &newPiece, int newX, int newY);
    void drawTetris(QPainter &painter, int x, int y, TetrixShape shape);

    //Handle all the events
    QBasicTimer timer;
    QPointer<QLabel> nextPieceLabel;
    bool isStarted;
    bool isPaused;
    bool isWaitingAfterLine;
    TetrixPiece curPiece;
    TetrixPiece nextPiece;
    int curX;
    int curY;
    int numLinesRemoved;
    int numPiecesDropped;
    int score;
    int level=1;
    int volume;
    TetrixShape board[BoardWidth * BoardHeight];
    QMediaPlayer player;
    QMediaPlayer pieceSound;
};
#endif // GAME_H

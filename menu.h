#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QApplication>


QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE


/*!
*	Header of Menu Class
*/
class Menu : public QMainWindow
{
    Q_OBJECT

public:
    Menu(QApplication *a,QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_gameBtn_clicked();

    void on_instBtn_clicked();

    void on_abtBtn_clicked();

    void on_exitBtn_clicked();

private:
    Ui::Menu *ui;
    QApplication *app;
};
#endif // MENU_H

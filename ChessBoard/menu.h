#ifndef MENU_H
#define MENU_H

#include <QPushButton>
#include <QWidget>
#include "mainwindow.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();
signals:
    void signalFromButtonStart();
    void signalFromButtonExit();

private:
    QWidget *field;
    Ui::Menu *ui;

    QMainWindow *board;

    QPushButton *start;
    QPushButton *exit;
private slots:

    void clickStart();
    void clickExit();

    void startGame();
    void exitGame();


};

#endif // MENU_H

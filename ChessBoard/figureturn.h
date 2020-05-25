#ifndef FIGURETURN_H
#define FIGURETURN_H
#include <mainwindow.h>


class FigureTurn
{
public:
    void TurnFigure(int i, int n);

    FigureTurn(MainWindow *mainT);

    MainWindow *mainT;
};

#endif // FIGURETURN_H

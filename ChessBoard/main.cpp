#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        Menu menu;
        QPalette pal;
        pal.setColor(QPalette::Background, "#efe4b0");
        menu.setPalette(pal);
        menu.show();
        return a.exec();
}

#include "mainwindow.h"
#include "board.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

        Board window;       // СОЗДАНИЕ ДОСКИ
        window.resize(500, 500);  // УСТАНОВКА РАЗМЕРОВ ДОСКИ
        window.setWindowTitle("Chess");  // НАЗВАНИЕ ПРОГРАММЫ
        window.show();

    return a.exec();
}

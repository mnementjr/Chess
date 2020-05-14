#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        QWidget window;
        window.resize(800, 600);
        window.setWindowTitle("Chess");  // НАЗВАНИЕ ПРОГРАММЫ
        window.setMinimumSize(QSize(512, 512));
        QWidget field(&window);
        field.setMaximumSize(QSize(512, 512));
        field.setMinimumSize(QSize(512, 512));
        MainWindow board(&field, &window);       // СОЗДАНИЕ ДОСКИ
        QLabel qlabel(&window);
        qlabel.setGeometry(600, 100, 300, 200);
        qlabel.setText(QDir::currentPath() + "\nСюда нужно поместить папки с фото");

        window.show();

    return a.exec();
}

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

        /*
        QWidget field(&window);
        field.setMaximumSize(QSize(512, 512));
        field.setMinimumSize(QSize(512, 512));
        MainWindow board(&field, &window);       // СОЗДАНИЕ ДОСКИ

        QLabel qlabel(&window);
        qlabel.setGeometry(510, 0, 600, 30);
        qlabel.setText(QDir::currentPath() + "\nСюда нужно поместить папки с фото");
        */


    return a.exec();
}

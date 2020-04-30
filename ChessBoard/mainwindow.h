#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QDir>
#include "cell.h"

// ТУТ НИЧЕГО НЕ ТРОГАЛ

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    Cell *cells[8][8];     // ПУСТОЙ МАССИВ КЛАССА CELLS В КОТОРОМ ЕСТЬ САМА КНОПКА

    void swapImages(Cell *cell1, Cell *cell2);
    void swapFigureColor(Cell *cell);
    QString findPathImage(QString nameImage);
    QString findNameImage(QString path);

    const int SIZE = 8;
    bool isGreenHere;
    Cell tempCell;

    // ЗДЕСЬ ИДЕТ СОЗДАНИЕ ПЕРЕМЕННЫХ, В КОТОРЫХ НАХОДЯТСЯ ПУТИ ДО ИЗОБРАЖЕНИЙ
    // ДЛЯ КАЖДОЙ ФИГУРЫ ДОЛЖНО БЫТЬ ПО 4 ИЗОБРАЖЕНИЯ
    // 1. ДЛЯ БЕЛЫХ ЦВЕТА MAROON
    // 2. ДЛЯ БЕЛЫХ ЦВЕТА PEACH
    // 3. ДЛЯ ЧЕРНЫХ ЦВЕТА MAROON
    // 4. ДЛЯ ЧЕРНЫХ ЦВЕТА PEACH
    // QDir::currentPath() --- УКАЗЫВАТЬ ОБЯЗАТЕЛЬНО, ОЗНАЧАЕТ, ЧТО МЫ НАХОДИМСЯ В ПАПКЕ, ИЗ КОТОРОЙ БЫЛ ЗАПУЩЕН ПРОЕКТ

    QString maroon = QDir::currentPath() + "/images/maroon.jpg";  // КЛЕТКА ЦВЕТОМ MAROON
    QString peach = QDir::currentPath() + "/images/peach.jpg";    // КЛЕТКА ЦВЕТОМ PEACH
    QString green = QDir::currentPath() + "/images/green.jpg";    // КЛЕТКА ЦВЕТОМ GREEN

    // ПЕШКА
    QString white_pawn_maroon = QDir::currentPath() + "/images/white/pawn_maroon.jpg";
    QString white_pawn_peach = QDir::currentPath() + "/images/white/pawn_peach.jpg";
    QString black_pawn_maroon = QDir::currentPath() + "/images/black/pawn_maroon.jpg";
    QString black_pawn_peach = QDir::currentPath() + "/images/black/pawn_peach.jpg";

    // ЛАДЬЯ
    QString white_rook_maroon = QDir::currentPath() + "/images/white/rook_maroon.jpg";
    QString white_rook_peach = QDir::currentPath() + "/images/white/rook_peach.jpg";
    QString black_rook_maroon = QDir::currentPath() + "/images/black/rook_maroon.jpg";
    QString black_rook_peach = QDir::currentPath() + "/images/black/rook_peach.jpg";


    // КОНЬ
    QString white_knight_maroon = QDir::currentPath() + "/images/white/knight_maroon.jpg";
    QString white_knight_peach = QDir::currentPath() + "/images/white/knight_peach.jpg";
    QString black_knight_maroon = QDir::currentPath() + "/images/black/knight_maroon.jpg";
    QString black_knight_peach = QDir::currentPath() + "/images/black/knight_peach.jpg";

    // CЛОН
    QString white_bishop_maroon = QDir::currentPath() + "/images/white/bishop_maroon.jpg";
    QString white_bishop_peach = QDir::currentPath() + "/images/white/bishop_peach.jpg";
    QString black_bishop_maroon = QDir::currentPath() + "/images/black/bishop_maroon.jpg";
    QString black_bishop_peach = QDir::currentPath() + "/images/black/bishop_peach.jpg";

signals:
    void signalFromButton(int ID);

private slots:
    void changeImage(int ID);
    void slotButton1();

    void slotButton2();
    void slotButton3();
    void slotButton4();
    void slotButton5();
    void slotButton6();
    void slotButton7();
    void slotButton8();
    void slotButton9();
    void slotButton10();
    void slotButton11();
    void slotButton12();
    void slotButton13();
    void slotButton14();
    void slotButton15();
    void slotButton16();
    void slotButton17();
    void slotButton18();
    void slotButton19();
    void slotButton20();
    void slotButton21();
    void slotButton22();
    void slotButton23();
    void slotButton24();
    void slotButton25();
    void slotButton26();
    void slotButton27();
    void slotButton28();
    void slotButton29();
    void slotButton30();
    void slotButton31();
    void slotButton32();
    void slotButton33();
    void slotButton34();
    void slotButton35();
    void slotButton36();
    void slotButton37();
    void slotButton38();
    void slotButton39();
    void slotButton40();
    void slotButton41();
    void slotButton42();
    void slotButton43();
    void slotButton44();
    void slotButton45();
    void slotButton46();
    void slotButton47();
    void slotButton48();
    void slotButton49();
    void slotButton50();
    void slotButton51();
    void slotButton52();
    void slotButton53();
    void slotButton54();
    void slotButton55();
    void slotButton56();
    void slotButton57();
    void slotButton58();
    void slotButton59();
    void slotButton60();
    void slotButton61();
    void slotButton62();
    void slotButton63();
    void slotButton64();

};
#endif // MAINWINDOW_H

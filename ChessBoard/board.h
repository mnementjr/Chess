#ifndef BOARD_H
#define BOARD_H
#pragma once

#include <QWidget>
#include <QPushButton>
#include <QDir>
#include "cell.h"

class Board : public QWidget  // КЛАСС, В КОТОРОМ СКОРЕЕ ВСЕГО БУДЕТ ВСЯ ЛОГИКА ИГРЫ
{
public:
    Board(QWidget *parent = 0);  // КОНСТРУКТОР
    Cell *cells[8][8];     // ПУСТОЙ МАССИВ КЛАССА CELLS В КОТОРОМ ЕСТЬ САМА КНОПКА
private:
    const int SIZE = 8;

    // ЗДЕСЬ ИДЕТ СОЗДАНИЕ ПЕРЕМЕННЫХ, В КОТОРЫХ НАХОДЯТСЯ ПУТИ ДО ИЗОБРАЖЕНИЙ
    // ДЛЯ КАЖДОЙ ФИГУРЫ ДОЛЖНО БЫТЬ ПО 4 ИЗОБРАЖЕНИЯ
    // 1. ДЛЯ БЕЛЫХ ЦВЕТА MAROON
    // 2. ДЛЯ БЕЛЫХ ЦВЕТА PEACH
    // 3. ДЛЯ ЧЕРНЫХ ЦВЕТА MAROON
    // 4. ДЛЯ ЧЕРНЫХ ЦВЕТА PEACH
    // QDir::currentPath() --- УКАЗЫВАТЬ ОБЯЗАТЕЛЬНО, ОЗНАЧАЕТ, ЧТО МЫ НАХОДИМСЯ В ПАПКЕ, ИЗ КОТОРОЙ БЫЛ ЗАПУЩЕН ПРОЕКТ

    QString maroon = QDir::currentPath() + "/images/maroon.jpg";  // КЛЕТКА ЦВЕТОМ MAROON
    QString peach = QDir::currentPath() + "/images/peach.jpg";    // КЛЕТКА ЦВЕТОМ PEACH

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
};

#endif // BOARD_H

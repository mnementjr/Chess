#ifndef BOARD_H
#define BOARD_H
#pragma once

#include <QWidget>
#include <QPushButton>
#include "cell.h"

class Board : public QWidget  // КЛАСС, В КОТОРОМ СКОРЕЕ ВСЕГО БУДЕТ ВСЯ ЛОГИКА ИГРЫ
{
public:
    Board(QWidget *parent = 0);  // КОНСТРУКТОР
    Cell *cells[8][8];     // ПУСТОЙ МАССИВ КЛАССА CELLS В КОТОРОМ ЕСТЬ САМА КНОПКА
};

#endif // BOARD_H

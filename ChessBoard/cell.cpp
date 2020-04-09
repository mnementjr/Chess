#include "cell.h"

// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА CELL

Cell::Cell(QWidget *parent,int ID) : QWidget(parent){
    this->ID = ID;
    button = new QPushButton();
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}
int Cell::getID(){
    return ID;
}
QPushButton *Cell::getButton(){          // ТУТ НУЖЕН УКАЗАТЕЛЬ (ТОЖЕ НЕ ЗНАЮ ЗАЧЕМ)
    return button;
}
void Cell::setText(QString text){
    button->setText(text);
}

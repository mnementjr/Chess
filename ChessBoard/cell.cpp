#include "cell.h"

// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА CELL

Cell::Cell(QWidget *parent,int ID) : QWidget(parent){
    this->ID = ID;
    button = new QPushButton();
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    button->setIconSize(QSize(64, 64));
    button->setFlat(true);
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
void Cell::setImage(QString path, QString nameImage){
    this->nameImage = nameImage;
    QIcon icon(path);
    button->setIcon(icon);
    //button->setText(QString::number(ID));
}
bool Cell::isPeach(){
    if(nameImage == "peach") return true;
    return false;
}
bool Cell::isMaroon(){
    if(nameImage == "maroon") return true;
    return false;
}

#include "cell.h"

// РЕАЛИЗАЦИЯ МЕТОДОВ КЛАССА CELL

Cell::Cell(QWidget *parent,int ID) : QWidget(parent){
    this->ID = ID;                                      // КНОПКЕ ПРИСВАЕВАЕТСЯ ID
    button = new QPushButton();
    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);     // РАЗМЕР КНОПКИ
    button->setIconSize(QSize(64, 64));        // РАЗМЕР КНОПКИ
    button->setFlat(true);              // НЕ ЗНАЮ)
}
int Cell::getID(){            // ВОЗВРАЩАЕТ ID КНОПКИ
    return ID;
}
QPushButton *Cell::getButton(){          // ТУТ НУЖЕН УКАЗАТЕЛЬ (ТОЖЕ НЕ ЗНАЮ ЗАЧЕМ)
    return button;
}
void Cell::setText(QString text){          // ДЛЯ ОТЛАДКИ (НЕ НУЖНО)
    button->setText(text);
}
void Cell::setImage(QString path, QString nameImage){         // УСТАНАВЛИВАЕТ ИЗОБРАЖЕНИЕ НА КНОПКУ
    this->nameImage = nameImage;
    QIcon icon(path);
    button->setIcon(icon);
    //button->setText(QString::number(ID));
}
bool Cell::isPeach(){                       // ЕСЛИ КОНПКА ЦВЕТА PEACH, ТО TRUE, ИНАЧЕ FALSE
    if(nameImage == "peach") return true;
    return false;
}
bool Cell::isMaroon(){                     // ЕСЛИ КОНПКА ЦВЕТА MAROON, ТО TRUE, ИНАЧЕ FALSE
    if(nameImage == "maroon") return true;
    return false;
}

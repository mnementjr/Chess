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
QPushButton *Cell::getButton(){          // ТУТ НУЖЕН УКАЗАТЕЛЬ (ТОЖЕ НЕ ЗНАЮ ЗАЧЕМ, ТЕПЕРЬ ЗНАЮ)
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
QString Cell::getNameImage(){
    return nameImage;
}
bool Cell::isPeach(){                       // ЕСЛИ КОНПКА ЦВЕТА PEACH, ТО TRUE, ИНАЧЕ FALSE
    if(nameImage == "peach"){
        return true;
    }
    else if(nameImage == "white_pawn_peach"){
        return  true;
    }
    else if(nameImage == "black_pawn_peach"){
    return  true;
    }
    else if(nameImage == "white_rook_peach"){
        return true;
    }
    else if(nameImage == "black_rook_peach"){
        return true;
    }
    else if(nameImage == "white_knight_peach"){
        return true;
    }
    else if(nameImage == "black_knight_peach"){
        return true;
    }
    else if(nameImage == "white_bishop_peach"){
        return true;
    }
    else if(nameImage == "black_bishop_peach"){
        return true;
    }
    else return false;
}
bool Cell::isMaroon(){                     // ЕСЛИ КОНПКА ЦВЕТА MAROON, ТО TRUE, ИНАЧЕ FALSE
    if(nameImage == "maroon"){
        return true;
    }
    else if(nameImage == "maroon_pawn_peach"){
        return  true;
    }
    else if(nameImage == "maroon_pawn_peach"){
    return  true;
    }
    else if(nameImage == "maroon_rook_peach"){
        return true;
    }
    else if(nameImage == "maroon_rook_peach"){
        return true;
    }
    else if(nameImage == "maroon_knight_peach"){
        return true;
    }
    else if(nameImage == "maroon_knight_peach"){
        return true;
    }
    else if(nameImage == "maroon_bishop_peach"){
        return true;
    }
    else if(nameImage == "maroon_bishop_peach"){
        return true;
    }
    else return false;
}
bool Cell::hasFigure(){                     // ЕСЛИ НА КНОПКЕ ЕСТЬ ФИГУРА, ТО TRUE, ИНАЧЕ FALSE
    if(nameImage == "white_pawn_maroon") return true;
    else if(nameImage == "white_pawn_peach") return true;
    else if(nameImage == "black_pawn_maroon") return true;
    else if(nameImage == "black_pawn_peach") return true;

    else if(nameImage == "white_rook_maroon") return true;
    else if(nameImage == "white_rook_peach") return true;
    else if(nameImage == "black_rook_maroon") return true;
    else if(nameImage == "black_rook_peach") return true;

    else if(nameImage == "white_knight_maroon") return true;
    else if(nameImage == "white_knight_peach") return true;
    else if(nameImage == "black_knight_maroon") return true;
    else if(nameImage == "black_knight_peach") return true;

    else if(nameImage == "white_bishop_maroon") return true;
    else if(nameImage == "white_bishop_peach") return true;
    else if(nameImage == "black_bishop_maroon") return true;
    else if(nameImage == "black_bishop_peach") return true;

    else return false;
}

bool Cell::isFigureBlack(){
    return nameImage.contains("black");
}
bool Cell::isFigureWhite(){
    return nameImage.contains("white");
}

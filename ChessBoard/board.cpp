#include "board.h"
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QCoreApplication>

Board::Board(QWidget *parent) : QWidget(parent) {
    // РЕАЛИЗАЦИЯ КОНСТРУКТАРА

    int ID = 1;      // ЛОКАЛЬНАЯ ПЕРЕМЕННАЯ АЙДИ ДЛЯ ТОГО, ЧТОБЫ У КАЖДОГО ЭКЗЕМПЛЯРА CELL БЫЛ СВОЙ ID (ПОКА НЕ ЗНАЮ КАК ДАЛЬШЕ ЭТО ИСПОЛЬЗОВАТЬ)
    int conf = 1;    // ПАРАМЕТР. НУЖЕН ДЛЯ ТОГО, ЧТОБЫ ЧЕРЕДОВАЛИСЬ ЦВЕТА

    QGridLayout *layout = new QGridLayout(this); // СОЗДАНИЕ ОБЛАСТИ, В КОТОРОЙ БУДУТ КНОПКИ
    layout->setHorizontalSpacing(0);    // УСТАНОВКА ОТСТУПОВ МЕЖДУ КНОПКАМИ
    layout->setVerticalSpacing(0);


    for(int i = 0; i < SIZE; ++i) { // ЦИКЛ, В КОТОРОМ СОЗДАЕТСЯ КЛЕТЧАТАЯ ДОСКА (ПУСТАЯ)
        for (int n = 0; n < 8; n++) {
            QString path;            // СЮДА УСТАНОВИТСЯ ПУТЬ ДО ИЗОБРАЖЕНИЯ
            QString nameImage;       // СЮДА УСТАНОВИТСЯ НАЗВАНИЕ ФИГУРЫ, ЧТОБ ПОТОМ ЕЕ МОЖНО БЫЛО ИНДЕНТИФИЦИРОВАТЬ
            if(conf % 2 == 1){
                if(ID % 2 == 0){
                    path = maroon;
                    nameImage = "maroon";
                }
                else{
                    path = peach;
                    nameImage = "peach";
                }
            } else {
                if(ID % 2 == 0){
                    path = peach;
                    nameImage = "peach";
                }
                else{
                    path = maroon;
                    nameImage = "maroon";
                }
            }
            cells[i][n] = new Cell(new QWidget, ID);   // ЗАПОЛНЕНИЕ МАССИВА ИЗ КЛАССА BOARD ЭКЗЕМПЛЯРАМИ КЛАССА CELL
            cells[i][n]->setImage(path, nameImage);
            layout->addWidget(cells[i][n]->getButton(), i, n); // ВЫВОД КНОПКИ НА ОБЛАСТЬ
            ID++;
        }
        conf++;
    }

    for (int i = 0; i < SIZE; i++) {        // ЦИКЛ, В КОТОРОМ ПОЛЕ ЗАПОЛНЯЕТСЯ ФИГУРАМИ
        for(int n = 0; n < SIZE; n++){
            //-------------------------------------ПЕШКИ-----------------------------------------
            // БЕЛЫЕ
            if(cells[i][n]->getID() >= 49 && cells[i][n]->getID() <= 56){   // ТУТ МЫ ПОЛУЧАЕМ cells[i][n]->getID()
                // ID КНОПКИ И ЕСЛИ ПОЗИЦИЯ РАВНА УКАЗАННОЙ, ТО СТАВИМ ИЗОБРАЖЕНИЕ ПЕШКИ
                if(cells[i][n]->isPeach()){            // МЫ ЖЕ НЕ ЗНАЕМ НА КАКОЙ ЦВЕТ КЛЕТКИ ПОСТАВИМ ПЕШКУ, ПОЭТОМУ ИСПОЛЬЗУЕМ if(cells[i][n]->isPeach()
                    // ДЛЯ ТОГО, ЧТОБЫ ПОСТАВИТЬ ПЕШКУ НУЖНОГО ЦВЕТА!
                    cells[i][n]->setImage(white_pawn_peach, "white_pawn_peach");    // cells[i][n]->setImage(white_pawn_peach, "white_pawn_peach")
                    // УСТАНАВЛИВАЕМ ИЗОБРАЖЕНИЕ КНОПКИ. ПЕРВУЮ ПЕРЕМЕННУЮ НУЖНО СОЗДАТЬ В BOARD.H, А ВТОРОЕ - ЭТО НАЗВАНИЕ ФИГУРЫ(ДОЛЖНО СОВПАДАТЬ С 1 ПЕРЕМЕННОЙ)
                } else {
                    cells[i][n]->setImage(white_pawn_maroon, "white_pawn_maroon");
                }
            }
            // ЧЕРНЫЕ
            if(cells[i][n]->getID() >= 9 && cells[i][n]->getID() <= 16){
                if(cells[i][n]->isPeach()){
                    cells[i][n]->setImage(black_pawn_peach, "black_pawn_peach");
                } else {
                    cells[i][n]->setImage(black_pawn_maroon, "black_pawn_maroon");
                }
            }
            //---------------------------------ЛАДЬИ-----------------------------------
            //БЕЛЫЕ
            if(cells[i][n]->getID() == 57 or cells[i][n]->getID() == 64){
                if(cells[i][n]->isPeach()){
                    cells[i][n]->setImage(white_rook_peach, "white_rook_peach");
                } else {
                    cells[i][n]->setImage(white_rook_maroon, "white_rook_maroon");
                }
            }
            //ЧЕРНЫЕ
            if(cells[i][n]->getID() == 1 or cells[i][n]->getID() == 8){
                if(cells[i][n]->isPeach()){
                    cells[i][n]->setImage(black_rook_peach, "black_rook_peach");
                } else {
                    cells[i][n]->setImage(black_rook_maroon, "black_rook_maroon");
                }
            }


            //--------------------------------КОНИ--------------------------------------
            // БЕЛЫЕ
            if(cells[i][n]->getID() == 58 or cells[i][n]->getID() == 63){
                if(cells[i][n]->isPeach()){
                    cells[i][n]->setImage(white_knight_peach, "white_knight_peach");
                } else {
                    cells[i][n]->setImage(white_knight_maroon, "white_knight_maroon");
                }
            }
            // ЧЕРНЫЕ
            if(cells[i][n]->getID() == 2 or cells[i][n]->getID() == 7){
                if(cells[i][n]->isPeach()){
                    cells[i][n]->setImage(black_knight_peach, "black_knight_peach");
                } else {
                    cells[i][n]->setImage(black_knight_maroon, "black_knight_maroon");
                }
            }
            // ДАЛЬШЕ САМИ

        }
    }

}

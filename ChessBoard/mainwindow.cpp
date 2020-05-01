#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QGridLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    isGreenHere = false;

    // РЕАЛИЗАЦИЯ КОНСТРУКТАРА
    int ID = 1;      // ЛОКАЛЬНАЯ ПЕРЕМЕННАЯ АЙДИ ДЛЯ ТОГО, ЧТОБЫ У КАЖДОГО ЭКЗЕМПЛЯРА CELL БЫЛ СВОЙ ID (ПОКА НЕ ЗНАЮ КАК ДАЛЬШЕ ЭТО ИСПОЛЬЗОВАТЬ)
    int colorConfiguration = 1;    // ПАРАМЕТР. НУЖЕН ДЛЯ ТОГО, ЧТОБЫ ЧЕРЕДОВАЛИСЬ ЦВЕТА

    QGridLayout *layout = new QGridLayout(parent); // СОЗДАНИЕ ОБЛАСТИ, В КОТОРОЙ БУДУТ КНОПКИ
    layout->setHorizontalSpacing(0);    // УСТАНОВКА ОТСТУПОВ МЕЖДУ КНОПКАМИ
    layout->setVerticalSpacing(0);


    for(int i = 0; i < SIZE; ++i) { // ЦИКЛ, В КОТОРОМ СОЗДАЕТСЯ КЛЕТЧАТАЯ ДОСКА (ПУСТАЯ)
        for (int n = 0; n < 8; n++) {
            QString path;            // СЮДА УСТАНОВИТСЯ ПУТЬ ДО ИЗОБРАЖЕНИЯ
            QString nameImage;       // СЮДА УСТАНОВИТСЯ НАЗВАНИЕ ФИГУРЫ, ЧТОБ ПОТОМ ЕЕ МОЖНО БЫЛО ИНДЕНТИФИЦИРОВАТЬ
            if(colorConfiguration % 2 == 1){
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
        colorConfiguration++;
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

            // БЕЛЫЕ СЛОН
            if(cells[i][n]->getID() == 59 or cells[i][n]->getID() == 62){
                if(cells[i][n]->isPeach()){
                    cells[i][n]->setImage(white_bishop_peach, "white_bishop_peach");
                } else {
                    cells[i][n]->setImage(white_bishop_maroon, "white_bishop_maroon");
                }
            }
            // ЧЕРНЫЕ
            if(cells[i][n]->getID() == 3 or cells[i][n]->getID() == 6){
                if(cells[i][n]->isPeach()){
                    cells[i][n]->setImage(black_bishop_peach, "black_bishop_peach");
                } else {
                    cells[i][n]->setImage(black_bishop_maroon, "black_bishop_maroon");
                }
            }


        }
    }
    connect(cells[0][0]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton1()));
    connect(cells[0][1]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton2()));
    connect(cells[0][2]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton3()));
    connect(cells[0][3]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton4()));
    connect(cells[0][4]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton5()));
    connect(cells[0][5]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton6()));
    connect(cells[0][6]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton7()));
    connect(cells[0][7]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton8()));

    connect(cells[1][0]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton9()));
    connect(cells[1][1]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton10()));
    connect(cells[1][2]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton11()));
    connect(cells[1][3]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton12()));
    connect(cells[1][4]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton13()));
    connect(cells[1][5]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton14()));
    connect(cells[1][6]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton15()));
    connect(cells[1][7]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton16()));

    connect(cells[2][0]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton17()));
    connect(cells[2][1]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton18()));
    connect(cells[2][2]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton19()));
    connect(cells[2][3]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton20()));
    connect(cells[2][4]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton21()));
    connect(cells[2][5]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton22()));
    connect(cells[2][6]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton23()));
    connect(cells[2][7]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton24()));

    connect(cells[3][0]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton25()));
    connect(cells[3][1]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton26()));
    connect(cells[3][2]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton27()));
    connect(cells[3][3]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton28()));
    connect(cells[3][4]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton29()));
    connect(cells[3][5]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton30()));
    connect(cells[3][6]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton31()));
    connect(cells[3][7]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton32()));

    connect(cells[4][0]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton33()));
    connect(cells[4][1]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton34()));
    connect(cells[4][2]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton35()));
    connect(cells[4][3]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton36()));
    connect(cells[4][4]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton37()));
    connect(cells[4][5]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton38()));
    connect(cells[4][6]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton39()));
    connect(cells[4][7]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton40()));

    connect(cells[5][0]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton41()));
    connect(cells[5][1]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton42()));
    connect(cells[5][2]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton43()));
    connect(cells[5][3]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton44()));
    connect(cells[5][4]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton45()));
    connect(cells[5][5]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton46()));
    connect(cells[5][6]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton47()));
    connect(cells[5][7]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton48()));

    connect(cells[6][0]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton49()));
    connect(cells[6][1]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton50()));
    connect(cells[6][2]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton51()));
    connect(cells[6][3]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton52()));
    connect(cells[6][4]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton53()));
    connect(cells[6][5]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton54()));
    connect(cells[6][6]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton55()));
    connect(cells[6][7]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton56()));

    connect(cells[7][0]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton57()));
    connect(cells[7][1]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton58()));
    connect(cells[7][2]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton59()));
    connect(cells[7][3]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton60()));
    connect(cells[7][4]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton61()));
    connect(cells[7][5]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton62()));
    connect(cells[7][6]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton63()));
    connect(cells[7][7]->getButton(), SIGNAL(clicked()), this, SLOT(slotButton64()));


    connect(this, &MainWindow::signalFromButton, this, &MainWindow::changeImage);

}

void MainWindow::changeImage(int ID){
    for (int i = 0; i < 8; i++) {
        for (int n = 0; n < 8; n++) {
            if(cells[i][n]->getID() == ID){
                if(cells[i][n]->getNameImage() == "green" ){
                    if(whichFigureClicked == "white_pawn_peach" || whichFigureClicked == "white_pawn_maroon"){
                        if(cells[i+1][n]->getNameImage() == "green"){
                            clearGreenColors();
                            swapImages(cells[i+2][n], cells[i][n], 1);
                        }
                        else {
                            clearGreenColors();
                            swapImages(cells[i+1][n], cells[i][n]);
                        }
                    }
                    isGreenHere = false;
                }
                else if(!isGreenHere){
                    if(cells[i][n]->getNameImage() == "white_pawn_peach"){
                        whichFigureClicked = "white_pawn_peach";
                        if(ID >= 49 && ID <= 56){
                            cells[i-1][n]->setImage(green, "green");
                            cells[i-2][n]->setImage(green, "green");
                            isGreenHere = true;
                        }
                        else {
                            cells[i-1][n]->setImage(green, "green");
                            isGreenHere = true;
                        }
                    }
                    if(cells[i][n]->getNameImage() == "white_pawn_maroon"){
                        whichFigureClicked = "white_pawn_maroon";
                        if(ID >= 49 && ID <= 56){
                            cells[i-1][n]->setImage(green, "green");
                            cells[i-2][n]->setImage(green, "green");
                            isGreenHere = true;
                        }
                        else {
                            cells[i-1][n]->setImage(green, "green");
                            isGreenHere = true;
                        }
                    }
                }
            }
        }
    }
}

void MainWindow::swapImages(Cell *cell1, Cell *cell2, int configuration){
    QString path = findPathImage(cell1->getNameImage());
    if(configuration == 0){
        if(cell1->isPeach()){
            cell1->setImage(peach, "peach");
        } else {
            cell1->setImage(maroon, "maroon");
        }
        cell2->setImage(path, findNameImage(path));
        swapFigureColor(cell2);
    } else if(configuration == 1){
        if(cell1->isPeach()){
            cell1->setImage(peach, "peach");
        } else {
            cell1->setImage(maroon, "maroon");
        }
        cell2->setImage(path, findNameImage(path));
    }

}

void MainWindow:: swapFigureColor(Cell *cell){
    if(cell->getNameImage() == "white_pawn_maroon"){
        cell->setImage(white_pawn_peach, "white_pawn_peach");
    }
    else if(cell->getNameImage() == "white_pawn_peach"){
        cell->setImage(white_pawn_maroon, "white_pawn_maroon");
    }
    else if(cell->getNameImage() == "black_pawn_maroon"){
        cell->setImage(black_pawn_peach, "black_pawn_peach");
    }
    else if(cell->getNameImage() == "black_pawn_peach"){
        cell->setImage(black_pawn_maroon, "black_pawn_maroon");
    }
    else if(cell->getNameImage() == "white_rook_maroon"){
        cell->setImage(white_rook_peach, "white_rook_peach");
    }
    else if(cell->getNameImage() == "white_rook_peach"){
        cell->setImage(white_rook_maroon, "white_rook_maroon");
    }
    else if(cell->getNameImage() == "black_rook_maroon"){
        cell->setImage(black_rook_peach, "black_rook_peach");
    }
    else if(cell->getNameImage() == "black_rook_peach"){
        cell->setImage(black_rook_maroon, "black_rook_maroon");
    }
    else if(cell->getNameImage() == "white_knight_maroon"){
        cell->setImage(white_knight_peach, "white_knight_peach");
    }
    else if(cell->getNameImage() == "white_knight_peach"){
        cell->setImage(white_knight_maroon, "white_knight_maroon");
    }
    else if(cell->getNameImage() == "black_knight_maroon"){
        cell->setImage(white_knight_peach, "black_knight_peach");
    }
    else if(cell->getNameImage() == "black_knight_peach"){
        cell->setImage(black_knight_maroon, "black_knight_maroon");
    }
    else if(cell->getNameImage() == "white_bishop_maroon"){
        cell->setImage(white_bishop_peach, "white_bishop_peach");
    }
    else if(cell->getNameImage() == "white_bishop_peach"){
        cell->setImage(white_bishop_maroon, "white_bishop_maroon");
    }
    else if(cell->getNameImage() == "black_bishop_maroon"){
        cell->setImage(black_bishop_peach, "black_bishop_peach");
    }
    else if(cell->getNameImage() == "black_bishop_peach"){
        cell->setImage(black_bishop_maroon, "black_bishop_maroon");
    }

}

QString MainWindow::findNameImage(QString path){
    if(path == maroon) return maroon;
    else if(path == peach) return peach;
    else if(path == green) return green;

    else if(path == white_pawn_maroon) return "white_pawn_maroon";
    else if(path == white_pawn_peach) return "white_pawn_peach";
    else if(path == black_pawn_maroon) return "black_pawn_maroon";
    else if(path == black_pawn_peach) return "black_pawn_peach";

    else if(path == white_rook_maroon) return "white_rook_maroon";
    else if(path == white_rook_peach) return "white_rook_peach";
    else if(path == black_rook_maroon) return "black_rook_maroon";
    else if(path == black_rook_peach) return "black_rook_peach";

    else if(path == white_knight_maroon) return "white_knight_maroon";
    else if(path == white_knight_peach) return "white_knight_peach";
    else if(path == black_knight_maroon) return "black_knight_maroon";
    else if(path == black_knight_peach) return "black_knight_peach";

    else if(path == white_bishop_maroon) return "white_bishop_maroon";
    else if(path == white_bishop_peach) return "white_bishop_peach";
    else if(path == black_bishop_maroon) return "black_bishop_maroon";
    else if(path == black_bishop_peach) return "black_bishop_peach";
}

QString MainWindow::findPathImage(QString nameImage){
    if(nameImage == "maroon") return maroon;
    else if(nameImage == "peach") return peach;
    else if(nameImage == "green") return green;

    else if(nameImage == "white_pawn_maroon") return white_pawn_maroon;
    else if(nameImage == "white_pawn_peach") return white_pawn_peach;
    else if(nameImage == "black_pawn_maroon") return black_pawn_maroon;
    else if(nameImage == "black_pawn_peach") return black_pawn_peach;

    else if(nameImage == "white_rook_maroon") return white_rook_maroon;
    else if(nameImage == "white_rook_peach") return white_rook_peach;
    else if(nameImage == "black_rook_maroon") return black_rook_maroon;
    else if(nameImage == "black_rook_peach") return black_rook_peach;

    else if(nameImage == "white_knight_maroon") return white_knight_maroon;
    else if(nameImage == "white_knight_peach") return white_knight_peach;
    else if(nameImage == "black_knight_maroon") return black_knight_maroon;
    else if(nameImage == "black_knight_peach") return black_knight_peach;

    else if(nameImage == "white_bishop_maroon") return white_bishop_maroon;
    else if(nameImage == "white_bishop_peach") return white_bishop_peach;
    else if(nameImage == "black_bishop_maroon") return black_bishop_maroon;
    else if(nameImage == "black_bishop_peach") return black_bishop_peach;

}

void MainWindow::clearGreenColors(){
    for (int i = 0; i < 8; i++) {
        for (int n = 0; n < 8; n++) {
            if(cells[i][n]->getNameImage() == "green"){
                if(i > 0 && i < 7){
                    if(cells[i-1][n]->isPeach()) cells[i][n]->setImage(maroon, "maroon");
                    else cells[i][n]->setImage(peach, "peach");
                }
                if(n > 0 && n < 7){
                    if(cells[i][n-1]->isPeach()) cells[i][n]->setImage(maroon, "maroon");
                    else cells[i][n]->setImage(peach, "peach");
                }
                if(i == 0){
                    if(cells[i+1][n]->isPeach()) cells[i][n]->setImage(maroon, "maroon");
                    else cells[i][n]->setImage(peach, "peach");
                }
                if(n == 0){
                    if(cells[i][n+1]->isPeach()) cells[i][n]->setImage(maroon, "maroon");
                    else cells[i][n]->setImage(peach, "peach");
                }
                if(i == 7){
                    if(cells[i-1][n]->isPeach()) cells[i][n]->setImage(maroon, "maroon");
                    else cells[i][n]->setImage(peach, "peach");
                }
                if(n == 7){
                    if(cells[i][n-1]->isPeach()) cells[i][n]->setImage(maroon, "maroon");
                    else cells[i][n]->setImage(peach, "peach");
                }
            }
        }
    }
}

void MainWindow::slotButton1(){
    emit signalFromButton(1);
}
void MainWindow::slotButton2(){
    emit signalFromButton(2);
}
void MainWindow::slotButton3(){
    emit signalFromButton(3);
}
void MainWindow::slotButton4(){
    emit signalFromButton(4);
}
void MainWindow::slotButton5(){
    emit signalFromButton(5);
}
void MainWindow::slotButton6(){
    emit signalFromButton(6);
}
void MainWindow::slotButton7(){
    emit signalFromButton(7);
}
void MainWindow::slotButton8(){
    emit signalFromButton(8);
}
void MainWindow::slotButton9(){
    emit signalFromButton(9);
}
void MainWindow::slotButton10(){
    emit signalFromButton(10);
}
void MainWindow::slotButton11(){
    emit signalFromButton(11);
}
void MainWindow::slotButton12(){
    emit signalFromButton(12);
}
void MainWindow::slotButton13(){
    emit signalFromButton(13);
}
void MainWindow::slotButton14(){
    emit signalFromButton(14);
}
void MainWindow::slotButton15(){
    emit signalFromButton(15);
}
void MainWindow::slotButton16(){
    emit signalFromButton(16);
}
void MainWindow::slotButton17(){
    emit signalFromButton(17);
}
void MainWindow::slotButton18(){
    emit signalFromButton(18);
}
void MainWindow::slotButton19(){
    emit signalFromButton(19);
}
void MainWindow::slotButton20(){
    emit signalFromButton(20);
}
void MainWindow::slotButton21(){
    emit signalFromButton(21);
}
void MainWindow::slotButton22(){
    emit signalFromButton(22);
}
void MainWindow::slotButton23(){
    emit signalFromButton(23);
}
void MainWindow::slotButton24(){
    emit signalFromButton(24);
}
void MainWindow::slotButton25(){
    emit signalFromButton(25);
}
void MainWindow::slotButton26(){
    emit signalFromButton(26);
}
void MainWindow::slotButton27(){
    emit signalFromButton(27);
}
void MainWindow::slotButton28(){
    emit signalFromButton(28);
}
void MainWindow::slotButton29(){
    emit signalFromButton(29);
}
void MainWindow::slotButton30(){
    emit signalFromButton(30);
}
void MainWindow::slotButton31(){
    emit signalFromButton(31);
}
void MainWindow::slotButton32(){
    emit signalFromButton(32);
}
void MainWindow::slotButton33(){
    emit signalFromButton(33);
}
void MainWindow::slotButton34(){
    emit signalFromButton(34);
}
void MainWindow::slotButton35(){
    emit signalFromButton(35);
}
void MainWindow::slotButton36(){
    emit signalFromButton(36);
}
void MainWindow::slotButton37(){
    emit signalFromButton(37);
}
void MainWindow::slotButton38(){
    emit signalFromButton(38);
}
void MainWindow::slotButton39(){
    emit signalFromButton(39);
}
void MainWindow::slotButton40(){
    emit signalFromButton(40);
}
void MainWindow::slotButton41(){
    emit signalFromButton(41);
}
void MainWindow::slotButton42(){
    emit signalFromButton(42);
}
void MainWindow::slotButton43(){
    emit signalFromButton(43);
}
void MainWindow::slotButton44(){
    emit signalFromButton(44);
}
void MainWindow::slotButton45(){
    emit signalFromButton(45);
}
void MainWindow::slotButton46(){
    emit signalFromButton(46);
}
void MainWindow::slotButton47(){
    emit signalFromButton(47);
}
void MainWindow::slotButton48(){
    emit signalFromButton(48);
}
void MainWindow::slotButton49(){
    emit signalFromButton(49);
}
void MainWindow::slotButton50(){
    emit signalFromButton(50);
}
void MainWindow::slotButton51(){
    emit signalFromButton(51);
}
void MainWindow::slotButton52(){
    emit signalFromButton(52);
}
void MainWindow::slotButton53(){
    emit signalFromButton(53);
}
void MainWindow::slotButton54(){
    emit signalFromButton(54);
}
void MainWindow::slotButton55(){
    emit signalFromButton(55);
}
void MainWindow::slotButton56(){
    emit signalFromButton(56);
}
void MainWindow::slotButton57(){
    emit signalFromButton(57);
}
void MainWindow::slotButton58(){
    emit signalFromButton(58);
}
void MainWindow::slotButton59(){
    emit signalFromButton(59);
}
void MainWindow::slotButton60(){
    emit signalFromButton(60);
}
void MainWindow::slotButton61(){
    emit signalFromButton(61);
}
void MainWindow::slotButton62(){
    emit signalFromButton(62);
}
void MainWindow::slotButton63(){
    emit signalFromButton(63);
}
void MainWindow::slotButton64(){
    emit signalFromButton(64);
}

MainWindow::~MainWindow()
{
    delete ui;
}


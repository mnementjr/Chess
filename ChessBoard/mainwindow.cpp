#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGridLayout>
#include <QLabel>

MainWindow::MainWindow(QWidget *menu, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    connect(this, &MainWindow::signalShit, menu , &Menu::show);
    ui->setupUi(this);

    this->resize(800, 600);
    this->setWindowTitle("Chess");  // НАЗВАНИЕ ПРОГРАММЫ
    this->setMinimumSize(QSize(800, 600));
    this->setMaximumSize(QSize(800, 600));

    field = new QWidget(this);
    field->setMaximumSize(QSize(512, 512));
    field->setMinimumSize(QSize(512, 512));

    fieldWhite = new QWidget(this);
    fieldWhite->setMaximumSize(QSize(256, 256));
    fieldWhite->setMinimumSize(QSize(256, 256));
    fieldWhite->setGeometry(515, 0, 256, 256);
    fieldWhite->setStyleSheet("background-color: beige");

    fieldBlack = new QWidget(this);
    fieldBlack->setMaximumSize(QSize(256, 256));
    fieldBlack->setMinimumSize(QSize(256, 256));
    fieldBlack->setGeometry(515, 260, 256, 256);
    fieldBlack->setStyleSheet("background-color: beige");

    isGreenHere = false;
    isDarkGreenHere = false;
    isYellowHere = false;
    singleWhiteCastling = false;
    singleBlackCastling = false;
    blackTurn = false;
    whiteTurn = true;
    whiteRow = 0;
    whiteColumn = 0;
    blackRow = 0;
    blackColumn = 0;

    back = new QPushButton(this);
    setButtonBack();

    // РЕАЛИЗАЦИЯ КОНСТРУКТОРА
    int ID = 1;      // ЛОКАЛЬНАЯ ПЕРЕМЕННАЯ ID ДЛЯ ТОГО, ЧТОБЫ У КАЖДОГО ЭКЗЕМПЛЯРА CELL БЫЛ СВОЙ ID (ПОКА НЕ ЗНАЮ КАК ДАЛЬШЕ ЭТО ИСПОЛЬЗОВАТЬ)
    int colorConfiguration = 1;    // ПАРАМЕТР. НУЖЕН ДЛЯ ТОГО, ЧТОБЫ ЧЕРЕДОВАЛИСЬ ЦВЕТА

    QGridLayout *layout = new QGridLayout(field); // СОЗДАНИЕ ОБЛАСТИ, В КОТОРОЙ БУДУТ КНОПКИ
    layout->setHorizontalSpacing(0);    // УСТАНОВКА ОТСТУПОВ МЕЖДУ КНОПКАМИ
    layout->setVerticalSpacing(0);

    layoutWhite = new QGridLayout(fieldWhite);
    layoutWhite->setHorizontalSpacing(0);
    layoutWhite->setVerticalSpacing(0);

    layoutBlack = new QGridLayout(fieldBlack);
    layoutBlack->setHorizontalSpacing(0);
    layoutBlack->setVerticalSpacing(0);

    information = new QLabel(this);
    information->setFont(QFont("Purisa", 20));
    labelSetWhiteTurn();
    information->setGeometry(100, 520, 320, 55);
    information->setStyleSheet("background-color: orange; border: 3px solid black");
    information->setAlignment(Qt::AlignCenter);


    for(int i = 0; i < 8; ++i) { // ЦИКЛ, В КОТОРОМ СОЗДАЕТСЯ КЛЕТЧАТАЯ ДОСКА (ПУСТАЯ)
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
            cells[i][n] = new Cell(new QWidget, ID);   // ЗАПОЛНЕНИЕ МАССИВА КЛАССА CELL
            cells[i][n]->setImage(path, nameImage);
            layout->addWidget(cells[i][n]->getButton(), i, n); // ВЫВОД КНОПКИ НА ОБЛАСТЬ
            ID++;
        }
        colorConfiguration++;
    }

    for(int i = 0; i < 4; ++i) {
        for (int n = 0; n < 4; n++) {
            QIcon icon(yellow);
            QPushButton *button = new QPushButton;
            button->setIcon(icon);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setIconSize(QSize(64, 64));
            layoutWhite->addWidget(button, i, n); // ВЫВОД КНОПКИ НА ОБЛАСТЬ
            QIcon icon2(yellow);
            QPushButton *button2 = new QPushButton;
            button2->setIcon(icon2);
            button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button2->setIconSize(QSize(64, 64));
            layoutBlack->addWidget(button2, i, n); // ВЫВОД КНОПКИ НА ОБЛАСТЬ
        }
    }

    cells[6][0]->setImage(white_pawn_peach, "white_pawn_peach");
    cells[6][2]->setImage(white_pawn_peach, "white_pawn_peach");
    cells[6][4]->setImage(white_pawn_peach, "white_pawn_peach");
    cells[6][6]->setImage(white_pawn_peach, "white_pawn_peach");
    cells[6][1]->setImage(white_pawn_maroon, "white_pawn_maroon");
    cells[6][3]->setImage(white_pawn_maroon, "white_pawn_maroon");
    cells[6][5]->setImage(white_pawn_maroon, "white_pawn_maroon");
    cells[6][7]->setImage(white_pawn_maroon, "white_pawn_maroon");
    cells[1][1]->setImage(black_pawn_peach, "black_pawn_peach");
    cells[1][3]->setImage(black_pawn_peach, "black_pawn_peach");
    cells[1][5]->setImage(black_pawn_peach, "black_pawn_peach");
    cells[1][7]->setImage(black_pawn_peach, "black_pawn_peach");
    cells[1][0]->setImage(black_pawn_maroon, "black_pawn_maroon");
    cells[1][2]->setImage(black_pawn_maroon, "black_pawn_maroon");
    cells[1][4]->setImage(black_pawn_maroon, "black_pawn_maroon");
    cells[1][6]->setImage(black_pawn_maroon, "black_pawn_maroon");
    cells[7][7]->setImage(white_rook_peach, "white_rook_peach");
    cells[7][0]->setImage(white_rook_maroon, "white_rook_maroon");
    cells[0][0]->setImage(black_rook_peach, "black_rook_peach");
    cells[0][7]->setImage(black_rook_maroon, "black_rook_maroon");
    cells[7][1]->setImage(white_knight_peach, "white_knight_peach");
    cells[7][6]->setImage(white_knight_maroon, "white_knight_maroon");
    cells[0][6]->setImage(black_knight_peach, "black_knight_peach");
    cells[0][1]->setImage(black_knight_maroon, "black_knight_maroon");
    cells[7][5]->setImage(white_bishop_peach, "white_bishop_peach");
    cells[7][2]->setImage(white_bishop_maroon, "white_bishop_maroon");
    cells[0][2]->setImage(black_bishop_peach, "black_bishop_peach");
    cells[0][5]->setImage(black_bishop_maroon, "black_bishop_maroon");
    cells[7][3]->setImage(white_queen_peach, "white_queen_peach");
    cells[0][3]->setImage(black_queen_maroon, "black_queen_maroon");
    cells[7][4]->setImage(white_king_maroon, "white_king_maroon");
    cells[0][4]->setImage(black_king_peach, "black_king_peach");

//--------------------------------------------------------------------------------------------------------------------
    // ПОДКЛЮЧЕНИЕ СИГНАЛОВ (НЕ ТРОГАТЬ)


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


    connect(back, SIGNAL(clicked()), this, SLOT(slotBack()));
    connect(this, &MainWindow::signalFromButtonBack, this, &MainWindow::closeWindow);

}

//--------------------------------------------------------------------------------------------------------------------
// ОСНОВНЫЕ ФУНКЦИИ

void MainWindow::changeImage(int ID){      // ОСНОВНОЙ СЛОТ, ГДЕ ПРОИСХОДИТ САМА ИГРА

        for (int i = 0; i < 8; i++) {
            for (int n = 0; n < 8; n++) {
                if(cells[i][n]->getID() == ID){
                    if(cells[i][n]->getNameImage() == "green" || cells[i][n]->getNameImage() == "dark_green" || cells[i][n]->getNameImage() == "yellow"){            // 1. УСЛОВИЕ (УНИВЕРСАЛЬНОЕ)

                        if(whichFigureClicked == "white_pawn_peach" || whichFigureClicked == "white_pawn_maroon"){
                            whitePawnTurn(i, n);
                        }
                        else if(whichFigureClicked == "black_pawn_peach" || whichFigureClicked == "black_pawn_maroon"){
                            blackPawnTurn(i, n);
                        }
                        else if(whichFigureClicked == "white_queen_peach" || whichFigureClicked == "white_queen_maroon"){
                            anyQueenTurn(i, n);
                        }
                        else if(whichFigureClicked == "black_queen_peach" || whichFigureClicked == "black_queen_maroon"){
                            anyQueenTurn(i, n);
                        }

                        else if(whichFigureClicked == "white_bishop_peach" || whichFigureClicked == "white_bishop_maroon"){
                            anyBishopTurn(i, n);
                        }
                        else if(whichFigureClicked == "black_bishop_peach" || whichFigureClicked == "black_bishop_maroon"){
                            anyBishopTurn(i, n);
                        }
                        else if(whichFigureClicked == "white_king_peach" || whichFigureClicked == "white_king_maroon"){
                            anyKingTurn(i, n);
                        }
                        else if(whichFigureClicked == "black_king_peach" || whichFigureClicked == "black_king_maroon"){
                            anyKingTurn(i, n);
                        }
                        else if(whichFigureClicked == "white_rook_peach" || whichFigureClicked == "white_rook_maroon"){
                            anyRookTurn(i, n);
                        }
                        else if(whichFigureClicked == "black_rook_peach" || whichFigureClicked == "black_rook_maroon"){
                            anyRookTurn(i, n);
                        }
                        else if(whichFigureClicked == "white_knight_peach" || whichFigureClicked == "white_knight_maroon"){
                            anyKnightTurn(i, n);
                        }
                        else if(whichFigureClicked == "black_knight_peach" || whichFigureClicked == "black_knight_maroon"){
                            anyKnightTurn(i, n);
                        }
                    }
                    else if(isGreenHere || isDarkGreenHere || isYellowHere){                // 2. УСЛОВИЕ (УНИВЕРСАЛЬНОЕ)
                        clearGreenColors();
                        FigureMemory.clear();
                    }
                    else if(!isGreenHere || !isDarkGreenHere || !isYellowHere){              // 3. УСЛОВИЕ (УНИВЕРСАЛЬНОЕ)
                        // ЕСЛИ ИМЯ ИЗОБРАЖЕНИЯ КЛЕТКИ == "какой-то фигуре". БУДЕМ ДОПИСЫВАТЬ (2 БЛОКА ДЛЯ КАЖДОЙ ФИГУРЫ РАЗНЫХ СТОРОН)

                        //----------------------------ПЕШКА--------------------------------------------------------
                        if(cells[i][n]->getNameImage() == "white_pawn_peach" && whiteTurn){  // ЕСЛИ БЕЛАЯ ПЕРСИКОВАЯ ПЕШКА
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_pawn_peach", cells[i][n]->getID()));  // ТО СОХРАНЯЕМ ЕЕ В ВЕКТОР
                            whichFigureClicked = "white_pawn_peach";
                            pawnSetGreen(i, n, ID, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "white_pawn_maroon" && whiteTurn){ // ЕСЛИ БЕЛАЯ КРАСНАЯ ПЕШКА
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_pawn_maroon", cells[i][n]->getID()));  // ТО СОХРАНЯЕМ ЕЕ В ВЕКТОР
                            whichFigureClicked = "white_pawn_maroon";
                            pawnSetGreen(i, n, ID, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_pawn_peach" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_pawn_peach", cells[i][n]->getID()));
                            whichFigureClicked = "black_pawn_peach";
                            pawnSetGreen(i, n, ID, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_pawn_maroon" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_pawn_maroon", cells[i][n]->getID()));
                            whichFigureClicked = "black_pawn_maroon";
                            pawnSetGreen(i, n, ID, whichFigureClicked);
                        }

                        //------------------------------КОРОЛЕВА---------------------------------------------------------
                        else if(cells[i][n]->getNameImage() == "white_queen_peach" && whiteTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_queen_peach", cells[i][n]->getID()));
                            whichFigureClicked = "white_queen_peach";
                            queenSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "white_queen_maroon" && whiteTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_queen_maroon", cells[i][n]->getID()));
                            whichFigureClicked = "white_queen_maroon";
                            queenSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_queen_peach" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_queen_peach", cells[i][n]->getID()));
                            whichFigureClicked = "black_queen_peach";
                            queenSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_queen_maroon" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_queen_maroon", cells[i][n]->getID()));
                            whichFigureClicked = "black_queen_maroon";
                            queenSetGreen(i, n, whichFigureClicked);
                        }
                        //------------------------------СЛОН---------------------------------------------------------
                        else if(cells[i][n]->getNameImage() == "white_bishop_peach" && whiteTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_bishop_peach", cells[i][n]->getID()));
                            whichFigureClicked = "white_bishop_peach";
                            bishopSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "white_bishop_maroon" && whiteTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_bishop_maroon", cells[i][n]->getID()));
                            whichFigureClicked = "white_bishop_maroon";
                            bishopSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_bishop_peach" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_bishop_peach", cells[i][n]->getID()));
                            whichFigureClicked = "black_bishop_peach";
                            bishopSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_bishop_maroon" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_bishop_maroon", cells[i][n]->getID()));
                            whichFigureClicked = "black_bishop_maroon";
                            bishopSetGreen(i, n, whichFigureClicked);
                        }
                        //------------------------------КОРОЛЬ---------------------------------------------------------
                        else if(cells[i][n]->getNameImage() == "white_king_peach" && whiteTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_king_peach", cells[i][n]->getID()));
                            whichFigureClicked = "white_king_peach";
                            kingSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "white_king_maroon" && whiteTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_king_maroon", cells[i][n]->getID()));
                            whichFigureClicked = "white_king_maroon";
                            kingSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_king_peach" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_king_peach", cells[i][n]->getID()));
                            whichFigureClicked = "black_king_peach";
                            kingSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_king_maroon" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_king_maroon", cells[i][n]->getID()));
                            whichFigureClicked = "black_king_maroon";
                            kingSetGreen(i, n, whichFigureClicked);
                        }
                        //----------------------------КОНЬ-----------------------------------------------------------------

                        else if(cells[i][n]->getNameImage() == "white_knight_peach" && whiteTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_knight_peach", cells[i][n]->getID()));
                            whichFigureClicked = "white_knight_peach";
                            knightSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "white_knight_maroon" && whiteTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("white_knight_maroon", cells[i][n]->getID()));
                            whichFigureClicked = "white_knight_maroon";
                            knightSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_knight_peach" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_knight_peach", cells[i][n]->getID()));
                            whichFigureClicked = "black_knight_peach";
                            knightSetGreen(i, n, whichFigureClicked);
                        }
                        else if(cells[i][n]->getNameImage() == "black_knight_maroon" && blackTurn){
                            FigureMemory.clear();
                            FigureMemory.push_back(*new Container("black_knight_maroon", cells[i][n]->getID()));
                            whichFigureClicked = "black_knight_maroon";
                            knightSetGreen(i, n, whichFigureClicked);
                        }
                    //--------------------------ROOK-------------------------------------------------------------------

                    else if(cells[i][n]->getNameImage() == "white_rook_peach" && whiteTurn){
                        FigureMemory.push_back(*new Container("white_rook_peach", cells[i][n]->getID()));
                        whichFigureClicked = "white_rook_peach";
                        rookSetGreen(i, n, whichFigureClicked);
                    }
                    else if(cells[i][n]->getNameImage() == "white_rook_maroon" && whiteTurn){
                        FigureMemory.push_back(*new Container("white_rook_maroon", cells[i][n]->getID()));
                        whichFigureClicked = "white_rook_maroon";
                        rookSetGreen(i, n, whichFigureClicked);
                    }
                    else if(cells[i][n]->getNameImage() == "black_rook_peach" && blackTurn){
                        FigureMemory.push_back(*new Container("black_rook_peach", cells[i][n]->getID()));
                        whichFigureClicked = "black_rook_peach";
                        rookSetGreen(i, n, whichFigureClicked);
                    }
                    else if(cells[i][n]->getNameImage() == "black_rook_maroon" && blackTurn){
                        FigureMemory.push_back(*new Container("black_rook_maroon", cells[i][n]->getID()));
                        whichFigureClicked = "black_rook_peach";
                        rookSetGreen(i, n, whichFigureClicked);
                    }
                }
            }
        }
     }
}


// ПЕРЕМЕЩЕНИЕ БЕЛОЙ ПЕШКИ
void MainWindow::whitePawnTurn(int i, int n){
    if(cells[i+1][n]->getNameImage() == "green"){       // ЕСЛИ НИЖЕ ЗЕЛЕНОЙ КНОПКИ ЕСТЬ ЗЕЛЕНАЯ КНОПКА, ТО....
        clearGreenColors();                             // УБИРАЕМ ВСЕ ЗЕЛЕНЫЕ ЦВЕТА
        swapImages(cells[i+2][n], cells[i][n], 1);      // ПЕРЕМЕЩАЕМ ИЗОБРАЖЕНИЕ ПЕШКИ НА 2 КНОПКИ ВВЕРХ
    }
    else if(cells[i][n]->getNameImage() == "dark_green"){
        for (int j = 0; j < DarkGreenMemory.size(); j++) {
            if(DarkGreenMemory[j].getID() == (i + 1) * (n + 1)){
                if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    return;
                }
            }
            QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
            QPushButton *button = new QPushButton;
            button->setIcon(icon);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setIconSize(QSize(64, 64));
            layoutBlack->addWidget(button, blackColumn, blackRow);
            blackRow++;
            if(blackRow % 4 == 0){
            blackRow = 0;
            blackColumn++;
        }
        }
        clearGreenColors();
        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
    }
    else{
        clearGreenColors();                             // ЕСЛИ ЖЕ НЕТ, ТО...
        swapImages(cells[i+1][n], cells[i][n]);         // ПЕРЕМЕЩАЕМ ИЗОБРАЖЕНИЕ ПЕШКИ НА 1 КНОПКУ ВВЕРХ
    }
    if(cells[i][n]->getID() > 0 && cells[i][n]->getID() < 9){
        QMessageBox msg;
        msg.setIcon(QMessageBox::Information);
        msg.setText("Пешка дошла до конца, выберите фигуру!");
        QPushButton *queen = msg.addButton(tr("Корлева"), QMessageBox::ActionRole);
        QPushButton *bishop = msg.addButton(tr("Слон"), QMessageBox::ActionRole);
        QPushButton *knight = msg.addButton(tr("Конь"), QMessageBox::ActionRole);
        QPushButton *rook = msg.addButton(tr("Ладья"), QMessageBox::ActionRole);
        msg.exec();
        if(msg.clickedButton() == queen){
            if(cells[i][n]->isPeach())
                cells[i][n]->setImage(white_queen_peach, "white_queen_peach");
            else cells[i][n]->setImage(white_queen_maroon, "white_queen_maroon");
        }
        else if(msg.clickedButton() == bishop){
            if(cells[i][n]->isPeach())
                cells[i][n]->setImage(white_bishop_peach, "white_bishop_peach");
            else cells[i][n]->setImage(white_bishop_maroon, "white_bishop_maroon");
        }
        else if(msg.clickedButton() == knight){
            if(cells[i][n]->isPeach())
                cells[i][n]->setImage(white_knight_peach, "white_knight_peach");
            else cells[i][n]->setImage(white_knight_maroon, "white_knight_maroon");
        }
        else if(msg.clickedButton() == rook){
            if(cells[i][n]->isPeach())
                cells[i][n]->setImage(white_rook_peach, "white_rook_peach");
            else cells[i][n]->setImage(white_rook_maroon, "white_rook_maroon");
        }
    }
    whiteTurn = false;
    blackTurn = true;
    labelSetBlackTurn();
    FigureMemory.clear();          // В КОНЦЕ ТАКОЙ ФУНКЦИИ ПИШЕМ ЭТО ОБЯЗАТЕЛЬНО
}
// ПЕРЕМЕЩЕНИЕ ЧЁРНОЙ ПЕШКИ
void MainWindow::blackPawnTurn(int i, int n){
    if(cells[i-1][n]->getNameImage() == "green"){       // ЕСЛИ ВЫШЕ ЗЕЛЕНОЙ КНОПКИ ЕСТЬ ЗЕЛЕНАЯ КНОПКА, ТО....
        clearGreenColors();                             // УБИРАЕМ ВСЕ ЗЕЛЕНЫЕ ЦВЕТА
        swapImages(cells[i-2][n], cells[i][n], 1);      // ПЕРЕМЕЩАЕМ ИЗОБРАЖЕНИЕ ПЕШКИ НА 2 КНОПКИ ВВЕРХ
    }
    else if(cells[i][n]->getNameImage() == "dark_green"){
        for (int j = 0; j < DarkGreenMemory.size(); j++) {
            if(DarkGreenMemory[j].getID() == (i + 1) * (n + 1)){
                if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    return;
                }
            }
                QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                QPushButton *button = new QPushButton;
                button->setIcon(icon);
                button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                button->setIconSize(QSize(64, 64));
                layoutWhite->addWidget(button, whiteColumn, whiteRow);
                whiteRow++;
                if(whiteRow % 4 == 0){
                whiteRow = 0;
                whiteColumn++;
            }
                clearGreenColors();
                swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
        }

    }
    else{
        clearGreenColors();                             // ЕСЛИ ЖЕ НЕТ, ТО...
        swapImages(cells[i-1][n], cells[i][n]);         // ПЕРЕМЕЩАЕМ ИЗОБРАЖЕНИЕ ПЕШКИ НА 1 КНОПКУ ВВЕРХ
    }
    if(cells[i][n]->getID() > 56 && cells[i][n]->getID() < 65){ // <------ МЕНЮ С ВЫБОРОМ НОВОЙ ФИГУРЫ
        QMessageBox msg;
        msg.setIcon(QMessageBox::Information);
        msg.setText("Пешка дошла до конца, выберите фигуру!");
        QPushButton *queen = msg.addButton(tr("Корлева"), QMessageBox::ActionRole);
        QPushButton *bishop = msg.addButton(tr("Слон"), QMessageBox::ActionRole);
        QPushButton *knight = msg.addButton(tr("Конь"), QMessageBox::ActionRole);
        QPushButton *rook = msg.addButton(tr("Ладья"), QMessageBox::ActionRole);
        msg.exec();
        if(msg.clickedButton() == queen){
            if(cells[i][n]->isPeach())
                cells[i][n]->setImage(black_queen_peach, "black_queen_peach");
            else cells[i][n]->setImage(black_queen_maroon, "black_queen_maroon");
        }
        else if(msg.clickedButton() == bishop){
            if(cells[i][n]->isPeach())
                cells[i][n]->setImage(black_bishop_peach, "black_bishop_peach");
            else cells[i][n]->setImage(black_bishop_maroon, "black_bishop_maroon");
        }
        else if(msg.clickedButton() == knight){
            if(cells[i][n]->isPeach())
                cells[i][n]->setImage(black_knight_peach, "black_knight_peach");
            else cells[i][n]->setImage(black_knight_maroon, "black_knight_maroon");
        }
        else if(msg.clickedButton() == rook){
            if(cells[i][n]->isPeach())
                cells[i][n]->setImage(black_rook_peach, "black_rook_peach");
            else cells[i][n]->setImage(black_rook_maroon, "black_rook_maroon");
        }
    }
    whiteTurn = true;
    blackTurn = false;
    labelSetWhiteTurn();
    FigureMemory.clear();          // В КОНЦЕ ТАКОЙ ФУНКЦИИ ПИШЕМ ЭТО ОБЯЗАТЕЛЬНО
}
// СОЗДАЕМ ЗЕЛЕНЫЕ ЦВЕТА ДЛЯ ПЕШЕК ДВУХ КОМАНД
void MainWindow::pawnSetGreen(int i, int n, int ID, QString whichFigClicked){
    if(whichFigClicked == "white_pawn_peach" || whichFigClicked == "white_pawn_maroon"){  // ЕСЛИ БЫЛА НАЖАТА БЕЛАЯ ПЕШКА, ТО..
            // ИДУТ ПРОВЕРКИ НА ВЫХОД ЗА ПРЕДЕЛЫ МАССИВА...
            if(i == 0){   // ЕСЛИ ДОШЛА ДОВЕРХУ , ТО МЫ НЕ МОЖЕМ ПОСТАВИТЬ ЗЕЛЕНЫЙ ЦВЕТ, ПОТОМУ ЧТО ИДТИ БОЛЬШЕ НЕКУДА
                isGreenHere = false;  // РАЗ НЕТУ ЗЕЛЕНОГО ЦВЕТА, ТО И isGreenHere СТАВИМ false
                isDarkGreenHere = false;
                FigureMemory.clear();
                return; // <------- ВЫХОД ИЗ ФУНКЦИИ

            }
            if(n > 0 && n < 7){ // ЕСЛИ ПЕШКА ИДЕТ НИ С КРАЮ СЛЕВА НИ С КРАЮ СПРАВА, ТО...
                if(cells[i-1][n-1]->hasFigure() && cells[i-1][n-1]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n-1]->getNameImage(), cells[i-1][n-1]->getID()));
                    cells[i-1][n-1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
                if(cells[i-1][n+1]->hasFigure() && cells[i-1][n+1]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n+1]->getNameImage(), cells[i-1][n+1]->getID()));
                    cells[i-1][n+1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            else if (n == 0){   // ЕСЛИ ПЕШКА ИДЕТ С КРАЮ СЛЕВА, ТО.......
                if(cells[i-1][n+1]->hasFigure() && cells[i-1][n+1]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n+1]->getNameImage(), cells[i-1][n+1]->getID()));
                    cells[i-1][n+1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            else if (n == 7){    // ЕСЛИ ПЕШКА ИДЕТ С КРАЮ СПРАВА, ТО.....
                if(cells[i-1][n-1]->hasFigure() && cells[i-1][n-1]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n-1]->getNameImage(), cells[i-1][n-1]->getID()));
                    cells[i-1][n-1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            // ПОСЛЕ ЭТОГО
            if(cells[i-1][n]->hasFigure()){     // ЕСЛИ ВПЕРЕДИ ЕСТЬ КАКАЯ-ТО ФИГУРА, ТО....
                isGreenHere = false;
                if(!isDarkGreenHere){
                    FigureMemory.clear();
                    return;
                } else {
                    isDarkGreenHere = true;
                    return;  // <------ ВЫХОД ИЗ ФУНКЦИИ
                }
            }
            // ЕСЛИ ДОШЛО ДО СЮДА, ТО ЗНАЧИТ ПЕШКА МОЖЕТ ПОЙТИ НАВЕРХ И СТАВИМ ЗЕЛЕНЫЙ ЦВЕТ СВЕРХУ
            if(ID >= 49 && ID <= 56 && !cells[i-2][n]->hasFigure()){    // ЕСЛИ ЭТО ЕЕ ПЕРВОЕ ДВИЖЕНИЕ, ТО ОНА МОЖЕТ ХОДИТЬ НА 2 КЛЕТКИ ВВЕРХ
                // СОХРАНЯЕМ В GREEN MEMORY ИЗОБРАЖЕНИЯ ТЕХ КНОПОК, КОТОРЫЕ БУДУТ ЗАМЕНЕНЫ НА ЗЕЛЕНЫЙ ЦВЕТ
                GreenMemory.push_back(*new Container(cells[i-2][n]->getNameImage(), cells[i-2][n]->getID()));
                cells[i-2][n]->setImage(green, "green");  // ТЕПЕРЬ У ЭТИХ КНОПОК СТАВИМ ЗЕЛЕНЫЙ ЦВЕТ                  // РАЗ МЫ ПОСТАВИЛИ ЗЕЛЕНЫЙ ЦВЕТ, ТО isGreenHere СТАВИМ true
            }
            GreenMemory.push_back(*new Container(cells[i-1][n]->getNameImage(), cells[i-1][n]->getID()));
            cells[i-1][n]->setImage(green, "green");
            isGreenHere = true;
    }
    else if(whichFigClicked == "black_pawn_peach" || whichFigClicked == "black_pawn_maroon"){
        if(i == 7){
            isGreenHere = false;
            isDarkGreenHere = false;
            FigureMemory.clear();
            return;
        }

        if(n > 0 && n < 7){ // ЕСЛИ ПЕШКА ИДЕТ НИ С КРАЮ СЛЕВА НИ С КРАЮ СПРАВА, ТО...
            if(cells[i+1][n-1]->hasFigure() && cells[i+1][n-1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[i+1][n-1]->getNameImage(), cells[i+1][n-1]->getID()));
                cells[i+1][n-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
            if(cells[i+1][n+1]->hasFigure() && cells[i+1][n+1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[i+1][n+1]->getNameImage(), cells[i+1][n+1]->getID()));
                cells[i+1][n+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
        }
        else if (n == 0){   // ЕСЛИ ПЕШКА ИДЕТ С КРАЮ СЛЕВА, ТО.......
            if(cells[i+1][n+1]->hasFigure() && cells[i+1][n+1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[i+1][n+1]->getNameImage(), cells[i+1][n+1]->getID()));
                cells[i+1][n+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
        }
        else if (n == 7){    // ЕСЛИ ПЕШКА ИДЕТ С КРАЮ СПРАВА, ТО.....
            if(cells[i+1][n-1]->hasFigure() && cells[i+1][n-1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[i+1][n-1]->getNameImage(), cells[i+1][n-1]->getID()));
                cells[i+1][n-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
        }

        if(cells[i+1][n]->hasFigure()){     // ЕСЛИ ВПЕРЕДИ ЕСТЬ КАКАЯ-ТО ФИГУРА, ТО....
            isGreenHere = false;
            if(!isDarkGreenHere){
                FigureMemory.clear();
                return;
            } else {
                isDarkGreenHere = true;
                return;  // <------ ВЫХОД ИЗ ФУНКЦИИ
            }
        }
        // ЕСЛИ ДОШЛО ДО СЮДА, ТО ЗНАЧИТ ПЕШКА МОЖЕТ ПОЙТИ НАВЕРХ И СТАВИМ ЗЕЛЕНЫЙ ЦВЕТ СВЕРХУ
        if(ID >= 9 && ID <= 16 && !cells[i+2][n]->hasFigure()){
            GreenMemory.push_back(*new Container(cells[i+2][n]->getNameImage(), cells[i+2][n]->getID()));
            cells[i+2][n]->setImage(green, "green");
        }
        GreenMemory.push_back(*new Container(cells[i+1][n]->getNameImage(), cells[i+1][n]->getID()));
        cells[i+1][n]->setImage(green, "green");
        isGreenHere = true;
    }
    else return;
}


void MainWindow::anyQueenTurn(int i, int n){
    QString name = FigureMemory[0].getNameImage();
    if(cells[i][n]->getNameImage() == "dark_green"){
        for (int j = 0; j < DarkGreenMemory.length(); j++) {
            if(cells[i][n]->getID() == DarkGreenMemory[j].getID()){
                if(DarkGreenMemory[j].getNameImage().contains("white")){
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutWhite->addWidget(button, whiteColumn, whiteRow);
                    whiteRow++;
                    if(whiteRow % 4 == 0){
                    whiteRow = 0;
                    whiteColumn++;
            }
                } else {
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutBlack->addWidget(button, blackColumn, blackRow);
                    blackRow++;
                    if(blackRow % 4 == 0){
                    blackRow = 0;
                    blackColumn++;
                    }
                }
                if(DarkGreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isPeach()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }
            }
        }
    }
    else if (cells[i][n]->getNameImage() == "green"){
            for (int j = 0; j < GreenMemory.length(); j++) {
                if(cells[i][n]->getID() == GreenMemory[j].getID()){
                    if(GreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                    }
                    else if(GreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                    else if(GreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isPeach()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                    }
                    else if(GreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                }
            }
        }
    if(name.contains("white")){
        whiteTurn = false;
        blackTurn = true;
        labelSetBlackTurn();
    }
    else if(name.contains("black")) {
        whiteTurn = true;
        blackTurn = false;
        labelSetWhiteTurn();
    }
    FigureMemory.clear();
}
void MainWindow::queenSetGreen(int i, int n, QString whichFigClicked){
    int x = i;
    int j = n;
    if(whichFigClicked == "white_queen_peach" || whichFigClicked == "white_queen_maroon"){
        while(x != 0){         // ВЕРХНЯЯ ЛИНИЯ
            if(cells[x-1][n]->isFigureWhite()) {
                isGreenHere = false;
                isDarkGreenHere = false;
                break;
            }
            if(cells[x-1][n]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][n]->getNameImage(), cells[x-1][n]->getID()));
                cells[x-1][n]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][n]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][n]->getNameImage(), cells[x-1][n]->getID()));
                cells[x-1][n]->setImage(green, "green");
                x--;
                isGreenHere = true;
            }
        }
        x = i;
        while(x != 7){       // НИЖНЯЯ ЛИНИЯ
            if(cells[x+1][n]->isFigureWhite()) {
                break;
            }
            if(cells[x+1][n]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][n]->getNameImage(), cells[x+1][n]->getID()));
                cells[x+1][n]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][n]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][n]->getNameImage(), cells[x+1][n]->getID()));
                cells[x+1][n]->setImage(green, "green");
                x++;
                isGreenHere = true;
            }
        }
        x = n;
        while(x != 0){       // ЛЕВАЯ ЛИНИЯ
            if(cells[i][x-1]->isFigureWhite()) {
                break;
            }
            if(cells[i][x-1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i][x-1]->getNameImage(), cells[i][x-1]->getID()));
                cells[i][x-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[i][x-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i][x-1]->getNameImage(), cells[i][x-1]->getID()));
                cells[i][x-1]->setImage(green, "green");
                x--;
                isGreenHere = true;
            }
        }
        x = n;
        while(x != 7){       // ПРАВАЯ ЛИНИЯ
            if(cells[i][x+1]->isFigureWhite()) {
                break;
            }
            if(cells[i][x+1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i][x+1]->getNameImage(), cells[i][x+1]->getID()));
                cells[i][x+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[i][x+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i][x+1]->getNameImage(), cells[i][x+1]->getID()));
                cells[i][x+1]->setImage(green, "green");
                x++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 0 && j != 7){   // ВЕРХНЯЯ ПРАВАЯ ДИАГОНАЛЬ
            if(cells[x-1][j+1]->isFigureWhite()) {
                break;
            }
            if(cells[x-1][j+1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][j+1]->getNameImage(), cells[x-1][j+1]->getID()));
                cells[x-1][j+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][j+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][j+1]->getNameImage(), cells[x-1][j+1]->getID()));
                cells[x-1][j+1]->setImage(green, "green");
                x--;
                j++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 0 && j != 0){   // ВЕРХНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
            if(cells[x-1][j-1]->isFigureWhite()) {
                break;
            }
            if(cells[x-1][j-1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][j-1]->getNameImage(), cells[x-1][j-1]->getID()));
                cells[x-1][j-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][j-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][j-1]->getNameImage(), cells[x-1][j-1]->getID()));
                cells[x-1][j-1]->setImage(green, "green");
                x--;
                j--;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 7 && j != 7){   // НИЖНЯЯ ПРАВАЯ ДИАГОНАЛЬ
            if(cells[x+1][j+1]->isFigureWhite()) {
                break;
            }
            if(cells[x+1][j+1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][j+1]->getNameImage(), cells[x+1][j+1]->getID()));
                cells[x+1][j+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][j+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][j+1]->getNameImage(), cells[x+1][j+1]->getID()));
                cells[x+1][j+1]->setImage(green, "green");
                x++;
                j++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 7 && j != 0){   // НИЖНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
            if(cells[x+1][j-1]->isFigureWhite()) {
                break;
            }
            if(cells[x+1][j-1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][j-1]->getNameImage(), cells[x+1][j-1]->getID()));
                cells[x+1][j-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][j-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][j-1]->getNameImage(), cells[x+1][j-1]->getID()));
                cells[x+1][j-1]->setImage(green, "green");
                x++;
                j--;
                isGreenHere = true;
            }
        }

    }
    else if(whichFigClicked == "black_queen_peach" || whichFigClicked == "black_queen_maroon"){
        while(x != 0){         // ВЕРХНЯЯ ЛИНИЯ
            if(cells[x-1][n]->isFigureBlack()) {
                break;
            }
            if(cells[x-1][n]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][n]->getNameImage(), cells[x-1][n]->getID()));
                cells[x-1][n]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][n]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][n]->getNameImage(), cells[x-1][n]->getID()));
                cells[x-1][n]->setImage(green, "green");
                x--;
                isGreenHere = true;
            }
        }
        x = i;
        while(x != 7){       // НИЖНЯЯ ЛИНИЯ
            if(cells[x+1][n]->isFigureBlack()) {
                break;
            }
            if(cells[x+1][n]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][n]->getNameImage(), cells[x+1][n]->getID()));
                cells[x+1][n]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][n]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][n]->getNameImage(), cells[x+1][n]->getID()));
                cells[x+1][n]->setImage(green, "green");
                x++;
                isGreenHere = true;
            }
        }
        x = n;
        while(x != 0){       // ЛЕВАЯ ЛИНИЯ
            if(cells[i][x-1]->isFigureBlack()) {
                break;
            }
            if(cells[i][x-1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[i][x-1]->getNameImage(), cells[i][x-1]->getID()));
                cells[i][x-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[i][x-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i][x-1]->getNameImage(), cells[i][x-1]->getID()));
                cells[i][x-1]->setImage(green, "green");
                x--;
                isGreenHere = true;
            }
        }
        x = n;
        while(x != 7){       // ПРАВАЯ ЛИНИЯ
            if(cells[i][x+1]->isFigureBlack()) {
                break;
            }
            if(cells[i][x+1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[i][x+1]->getNameImage(), cells[i][x+1]->getID()));
                cells[i][x+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[i][x+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i][x+1]->getNameImage(), cells[i][x+1]->getID()));
                cells[i][x+1]->setImage(green, "green");
                x++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 0 && j != 7){   // ВЕРХНЯЯ ПРАВАЯ ДИАГОНАЛЬ
            if(cells[x-1][j+1]->isFigureBlack()) {
                break;
            }
            if(cells[x-1][j+1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][j+1]->getNameImage(), cells[x-1][j+1]->getID()));
                cells[x-1][j+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][j+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][j+1]->getNameImage(), cells[x-1][j+1]->getID()));
                cells[x-1][j+1]->setImage(green, "green");
                x--;
                j++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 0 && j != 0){   // ВЕРХНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
            if(cells[x-1][j-1]->isFigureBlack()) {
                break;
            }
            if(cells[x-1][j-1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][j-1]->getNameImage(), cells[x-1][j-1]->getID()));
                cells[x-1][j-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][j-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][j-1]->getNameImage(), cells[x-1][j-1]->getID()));
                cells[x-1][j-1]->setImage(green, "green");
                x--;
                j--;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 7 && j != 7){   // НИЖНЯЯ ПРАВАЯ ДИАГОНАЛЬ
            if(cells[x+1][j+1]->isFigureBlack()) {
                break;
            }
            if(cells[x+1][j+1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][j+1]->getNameImage(), cells[x+1][j+1]->getID()));
                cells[x+1][j+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][j+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][j+1]->getNameImage(), cells[x+1][j+1]->getID()));
                cells[x+1][j+1]->setImage(green, "green");
                x++;
                j++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 7 && j != 0){   // НИЖНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
            if(cells[x+1][j-1]->isFigureBlack()) {
                break;
            }
            if(cells[x+1][j-1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][j-1]->getNameImage(), cells[x+1][j-1]->getID()));
                cells[x+1][j-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][j-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][j-1]->getNameImage(), cells[x+1][j-1]->getID()));
                cells[x+1][j-1]->setImage(green, "green");
                x++;
                j--;
                isGreenHere = true;
            }
        }
    }

}
// ПЕРЕМЕЩЕНИЕ СЛОНОВ
void MainWindow::anyBishopTurn(int i, int n){
    QString name = FigureMemory[0].getNameImage();
    if(cells[i][n]->getNameImage() == "dark_green"){
        for (int j = 0; j < DarkGreenMemory.length(); j++) {
            if(cells[i][n]->getID() == DarkGreenMemory[j].getID()){
                if(DarkGreenMemory[j].getNameImage().contains("white")){
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutWhite->addWidget(button, whiteColumn, whiteRow);
                    whiteRow++;
                    if(whiteRow % 4 == 0){
                    whiteRow = 0;
                    whiteColumn++;
            }
                } else {
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutBlack->addWidget(button, blackColumn, blackRow);
                    blackRow++;
                    if(blackRow % 4 == 0){
                    blackRow = 0;
                    blackColumn++;
                    }
                }
                if(DarkGreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }
            }
        }
    }
    else if (cells[i][n]->getNameImage() == "green"){
            for (int j = 0; j < GreenMemory.length(); j++) {
                if(cells[i][n]->getID() == GreenMemory[j].getID()){
                    if(GreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                    else if(GreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                }
            }
        }
    if(name.contains("white")){
        whiteTurn = false;
        blackTurn = true;
        labelSetBlackTurn();
    }
    else if(name.contains("black")) {
        whiteTurn = true;
        blackTurn = false;
        labelSetWhiteTurn();
    }
    FigureMemory.clear();
}
// СОЗДАЕМ ЗЕЛЕНЫЕ ЦВЕТА ДЛЯ СЛОНОВ ДВУХ КОМАНД
void MainWindow::bishopSetGreen(int i, int n, QString whichFigClicked){
    int x = i;
    int j = n;
    if(whichFigClicked == "white_bishop_peach" || whichFigClicked == "white_bishop_maroon"){
        while(x != 0 && j != 7){   // ВЕРХНЯЯ ПРАВАЯ ДИАГОНАЛЬ
            if(cells[x-1][j+1]->isFigureWhite()) {
                break;
            }
            if(cells[x-1][j+1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][j+1]->getNameImage(), cells[x-1][j+1]->getID()));
                cells[x-1][j+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][j+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][j+1]->getNameImage(), cells[x-1][j+1]->getID()));
                cells[x-1][j+1]->setImage(green, "green");
                x--;
                j++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 0 && j != 0){   // ВЕРХНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
            if(cells[x-1][j-1]->isFigureWhite()) {
                break;
            }
            if(cells[x-1][j-1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][j-1]->getNameImage(), cells[x-1][j-1]->getID()));
                cells[x-1][j-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][j-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][j-1]->getNameImage(), cells[x-1][j-1]->getID()));
                cells[x-1][j-1]->setImage(green, "green");
                x--;
                j--;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 7 && j != 7){   // НИЖНЯЯ ПРАВАЯ ДИАГОНАЛЬ
            if(cells[x+1][j+1]->isFigureWhite()) {
                break;
            }
            if(cells[x+1][j+1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][j+1]->getNameImage(), cells[x+1][j+1]->getID()));
                cells[x+1][j+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][j+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][j+1]->getNameImage(), cells[x+1][j+1]->getID()));
                cells[x+1][j+1]->setImage(green, "green");
                x++;
                j++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 7 && j != 0){   // НИЖНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
            if(cells[x+1][j-1]->isFigureWhite()) {
                break;
            }
            if(cells[x+1][j-1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][j-1]->getNameImage(), cells[x+1][j-1]->getID()));
                cells[x+1][j-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][j-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][j-1]->getNameImage(), cells[x+1][j-1]->getID()));
                cells[x+1][j-1]->setImage(green, "green");
                x++;
                j--;
                isGreenHere = true;
            }
        }

    }
    else if(whichFigClicked == "black_bishop_peach" || whichFigClicked == "black_bishop_maroon"){
        x = i;
        j = n;
        while(x != 0 && j != 7){   // ВЕРХНЯЯ ПРАВАЯ ДИАГОНАЛЬ
            if(cells[x-1][j+1]->isFigureBlack()) {
                break;
            }
            if(cells[x-1][j+1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][j+1]->getNameImage(), cells[x-1][j+1]->getID()));
                cells[x-1][j+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][j+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][j+1]->getNameImage(), cells[x-1][j+1]->getID()));
                cells[x-1][j+1]->setImage(green, "green");
                x--;
                j++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 0 && j != 0){   // ВЕРХНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
            if(cells[x-1][j-1]->isFigureBlack()) {
                break;
            }
            if(cells[x-1][j-1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x-1][j-1]->getNameImage(), cells[x-1][j-1]->getID()));
                cells[x-1][j-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x-1][j-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x-1][j-1]->getNameImage(), cells[x-1][j-1]->getID()));
                cells[x-1][j-1]->setImage(green, "green");
                x--;
                j--;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 7 && j != 7){   // НИЖНЯЯ ПРАВАЯ ДИАГОНАЛЬ
            if(cells[x+1][j+1]->isFigureBlack()) {
                break;
            }
            if(cells[x+1][j+1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][j+1]->getNameImage(), cells[x+1][j+1]->getID()));
                cells[x+1][j+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][j+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][j+1]->getNameImage(), cells[x+1][j+1]->getID()));
                cells[x+1][j+1]->setImage(green, "green");
                x++;
                j++;
                isGreenHere = true;
            }
        }
        x = i;
        j = n;
        while(x != 7 && j != 0){   // НИЖНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
            if(cells[x+1][j-1]->isFigureBlack()) {
                break;
            }
            if(cells[x+1][j-1]->isFigureWhite()){
                DarkGreenMemory.push_back(*new Container(cells[x+1][j-1]->getNameImage(), cells[x+1][j-1]->getID()));
                cells[x+1][j-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
                break;
            }
            else if(!cells[x+1][j-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[x+1][j-1]->getNameImage(), cells[x+1][j-1]->getID()));
                cells[x+1][j-1]->setImage(green, "green");
                x++;
                j--;
                isGreenHere = true;
            }
        }
    }

}

void MainWindow::anyKingTurn(int i, int n){
    QString name = FigureMemory[0].getNameImage();
    if(cells[i][n]->getNameImage() == "dark_green"){
        for (int j = 0; j < DarkGreenMemory.length(); j++) {
            if(cells[i][n]->getID() == DarkGreenMemory[j].getID()){
                if(DarkGreenMemory[j].getNameImage().contains("white")){
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutWhite->addWidget(button, whiteColumn, whiteRow);
                    whiteRow++;
                    if(whiteRow % 4 == 0){
                    whiteRow = 0;
                    whiteColumn++;
            }
                } else {
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutBlack->addWidget(button, blackColumn, blackRow);
                    blackRow++;
                    if(blackRow % 4 == 0){
                    blackRow = 0;
                    blackColumn++;
                    }
                }
                if(DarkGreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isPeach()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }
            }
        }
    }
    else if (cells[i][n]->getNameImage() == "green"){
            for (int j = 0; j < GreenMemory.length(); j++) {
                if(cells[i][n]->getID() == GreenMemory[j].getID()){
                    if(GreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                    }
                    else if(GreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                    else if(GreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isPeach()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                    }
                    else if(GreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                }
            }
        }
    else if (cells[i][n]->getNameImage() == "yellow"){
        for (int j = 0; j < YellowMemory.length(); j++) {
            if(FigureMemory[0].getNameImage().contains("white")){
                singleWhiteCastling = true;
            } else if (FigureMemory[0].getNameImage().contains("black")){
                singleBlackCastling = true;
            }
            if(cells[i][n]->getID() == 59){
                clearGreenColors();
                swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                swapImages(cells[7][0], cells[7][3]);
            }
            else if(cells[i][n]->getID() == 63){
                clearGreenColors();
                swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                swapImages(cells[7][7], cells[7][5], 1);
            }
            else if(cells[i][n]->getID() == 3){
                clearGreenColors();
                swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                swapImages(cells[0][0], cells[0][3]);
            }
            else if(cells[i][n]->getID() == 7){
                clearGreenColors();
                swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                swapImages(cells[0][7], cells[0][5], 1);
            }
        }
    }
    if(name.contains("white")){
        whiteTurn = false;
        blackTurn = true;
        labelSetBlackTurn();
    }
    else if(name.contains("black")) {
        whiteTurn = true;
        blackTurn = false;
        labelSetWhiteTurn();
    }
    FigureMemory.clear();
}
void MainWindow::kingSetGreen(int i, int n, QString whichFigClicked){
    if(whichFigClicked == "white_king_peach" || whichFigClicked == "white_king_maroon"){
        // ВЕРХНЯЯ ЛИНИЯ
        if(i != 0){
            if(cells[i-1][n]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i-1][n]->getNameImage(), cells[i-1][n]->getID()));
                cells[i-1][n]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
            else if(!cells[i-1][n]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i-1][n]->getNameImage(), cells[i-1][n]->getID()));
                cells[i-1][n]->setImage(green, "green");
                isGreenHere = true;
            }
        }
        // НИЖНЯЯ ЛИНИЯ
        if(i != 7){
            if(cells[i+1][n]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i+1][n]->getNameImage(), cells[i+1][n]->getID()));
                cells[i+1][n]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
            else if(!cells[i+1][n]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i+1][n]->getNameImage(), cells[i+1][n]->getID()));
                cells[i+1][n]->setImage(green, "green");
                isGreenHere = true;
            }
        }
        // ЛЕВАЯ ЛИНИЯ
        if(n != 0){
            if(cells[i][n-1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i][n-1]->getNameImage(), cells[i][n-1]->getID()));
                cells[i][n-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
            else if(!cells[i][n-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i][n-1]->getNameImage(), cells[i][n-1]->getID()));
                cells[i][n-1]->setImage(green, "green");
                isGreenHere = true;
            }
        }
        // ПРАВАЯ ЛИНИЯ
        if(n != 7){
            if(cells[i][n+1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i][n+1]->getNameImage(), cells[i][n+1]->getID()));
                cells[i][n+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
            else if(!cells[i][n+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i][n+1]->getNameImage(), cells[i][n+1]->getID()));
                cells[i][n+1]->setImage(green, "green");
                isGreenHere = true;
            }
        }
       // ВЕРХНЯЯ ПРАВАЯ ДИАГОНАЛЬ
       if((i != 0) && (n != 7)){
            if(cells[i-1][n+1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i-1][n+1]->getNameImage(), cells[i-1][n+1]->getID()));
                cells[i-1][n+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
            else if(!cells[i-1][n+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i-1][n+1]->getNameImage(), cells[i-1][n+1]->getID()));
                cells[i-1][n+1]->setImage(green, "green");
                isGreenHere = true;
            }
       }
        // ВЕРХНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
        if((i != 0) && (n != 0)){
            if(cells[i-1][n-1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i-1][n-1]->getNameImage(), cells[i-1][n-1]->getID()));
                cells[i-1][n-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
            else if(!cells[i-1][n-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i-1][n-1]->getNameImage(), cells[i-1][n-1]->getID()));
                cells[i-1][n-1]->setImage(green, "green");
                isGreenHere = true;
            }
        }
        // НИЖНЯЯ ПРАВАЯ ДИАГОНАЛЬ
        if((i != 7) && (n != 7)){
            if(cells[i+1][n+1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i+1][n+1]->getNameImage(), cells[i+1][n+1]->getID()));
                cells[i+1][n+1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
            else if(!cells[i+1][n+1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i+1][n+1]->getNameImage(), cells[i+1][n+1]->getID()));
                cells[i+1][n+1]->setImage(green, "green");
                isGreenHere = true;
            }
        }
        // НИЖНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
        if((i != 7) && (n != 0)){
        if(cells[i+1][n-1]->isFigureBlack()){
                DarkGreenMemory.push_back(*new Container(cells[i+1][n-1]->getNameImage(), cells[i+1][n-1]->getID()));
                cells[i+1][n-1]->setImage(dark_green, "dark_green");
                isDarkGreenHere = true;
            }
            else if(!cells[i+1][n-1]->hasFigure()){
                GreenMemory.push_back(*new Container(cells[i+1][n-1]->getNameImage(), cells[i+1][n-1]->getID()));
                cells[i+1][n-1]->setImage(green, "green");
                isGreenHere = true;
            }
        }
        // РОКИРОВКА БЕЛОГО КОРОЛЯ ВПРАВО И ВЛЕВО
        if((i == 7) && (n == 4)){
            if(cells[7][7]->getNameImage() == "white_rook_peach" && !singleWhiteCastling){
                if(!cells[7][5]->hasFigure() && !cells[7][6]->hasFigure()){
                    YellowMemory.push_back(*new Container(cells[7][6]->getNameImage(), cells[7][6]->getID()));
                    cells[7][6]->setImage(yellow, "yellow");
                    isYellowHere = true;
                }
            }
            if(cells[7][0]->getNameImage() == "white_rook_maroon" && !singleWhiteCastling){
                if(!cells[7][1]->hasFigure() && !cells[7][2]->hasFigure() && !cells[7][3]->hasFigure()){
                    YellowMemory.push_back(*new Container(cells[7][2]->getNameImage(), cells[7][2]->getID()));
                    cells[7][2]->setImage(yellow, "yellow");
                    isYellowHere = true;
                }
            }
        }
    }
    else if(whichFigClicked == "black_king_peach" || whichFigClicked == "black_king_maroon"){
        // ВЕРХНЯЯ ЛИНИЯ
        if(i != 0){
            if(cells[i-1][n]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n]->getNameImage(), cells[i-1][n]->getID()));
                    cells[i-1][n]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
                else if(!cells[i-1][n]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-1][n]->getNameImage(), cells[i-1][n]->getID()));
                    cells[i-1][n]->setImage(green, "green");
                    isGreenHere = true;
                }
        }
        // НИЖНЯЯ ЛИНИЯ
        if(i != 7){
            if(cells[i+1][n]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i+1][n]->getNameImage(), cells[i+1][n]->getID()));
                    cells[i+1][n]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
                else if(!cells[i+1][n]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+1][n]->getNameImage(), cells[i+1][n]->getID()));
                    cells[i+1][n]->setImage(green, "green");
                    isGreenHere = true;
                }
         }
        // ЛЕВАЯ ЛИНИЯ
        if(n != 0){
            if(cells[i][n-1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i][n-1]->getNameImage(), cells[i][n-1]->getID()));
                    cells[i][n-1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
                else if(!cells[i][n-1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i][n-1]->getNameImage(), cells[i][n-1]->getID()));
                    cells[i][n-1]->setImage(green, "green");
                    isGreenHere = true;
                }
        }
        // ПРАВАЯ ЛИНИЯ
        if(n != 7){
            if(cells[i][n+1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i][n+1]->getNameImage(), cells[i][n+1]->getID()));
                    cells[i][n+1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
                else if(!cells[i][n+1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i][n+1]->getNameImage(), cells[i][n+1]->getID()));
                    cells[i][n+1]->setImage(green, "green");
                    isGreenHere = true;
                }
        }
        // ВЕРХНЯЯ ПРАВАЯ ДИАГОНАЛЬ
        if((i != 0) && (n != 7)){
            if(cells[i-1][n+1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n+1]->getNameImage(), cells[i-1][n+1]->getID()));
                    cells[i-1][n+1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
                else if(!cells[i-1][n+1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-1][n+1]->getNameImage(), cells[i-1][n+1]->getID()));
                    cells[i-1][n+1]->setImage(green, "green");
                    isGreenHere = true;
                }
        }
        // ВЕРХНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
        if((i != 0) && (n != 0)){
            if(cells[i-1][n-1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n-1]->getNameImage(), cells[i-1][n-1]->getID()));
                    cells[i-1][n-1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
                else if(!cells[i-1][n-1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-1][n-1]->getNameImage(), cells[i-1][n-1]->getID()));
                    cells[i-1][n-1]->setImage(green, "green");
                    isGreenHere = true;
                }
        }
        // НИЖНЯЯ ПРАВАЯ ДИАГОНАЛЬ
        if((i != 7) && (n != 7)){
            if(cells[i+1][n+1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i+1][n+1]->getNameImage(), cells[i+1][n+1]->getID()));
                    cells[i+1][n+1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
                else if(!cells[i+1][n+1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+1][n+1]->getNameImage(), cells[i+1][n+1]->getID()));
                    cells[i+1][n+1]->setImage(green, "green");
                    isGreenHere = true;
                }
        }
        // НИЖНЯЯ ЛЕВАЯ ДИАГОНАЛЬ
        if((i != 7) && (n != 0)){
            if(cells[i+1][n-1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i+1][n-1]->getNameImage(), cells[i+1][n-1]->getID()));
                    cells[i+1][n-1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
                else if(!cells[i+1][n-1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+1][n-1]->getNameImage(), cells[i+1][n-1]->getID()));
                    cells[i+1][n-1]->setImage(green, "green");
                    isGreenHere = true;
                }
        }
        // РОКИРОВКА ЧЁРНОГО КОРОЛЯ ВПРАВО И ВЛЕВО
        if((i == 0) && (n == 4)){
            if(cells[0][7]->getNameImage() == "black_rook_maroon" && !singleBlackCastling){
                if(!cells[0][5]->hasFigure() && !cells[0][6]->hasFigure()){
                    YellowMemory.push_back(*new Container(cells[0][6]->getNameImage(), cells[0][6]->getID()));
                    cells[0][6]->setImage(yellow, "yellow");
                    isYellowHere = true;
                }
            }
            if(cells[0][0]->getNameImage() == "black_rook_peach" && !singleBlackCastling){
                if(!cells[0][1]->hasFigure() && !cells[0][2]->hasFigure() && !cells[0][3]->hasFigure()){
                    YellowMemory.push_back(*new Container(cells[0][2]->getNameImage(), cells[0][2]->getID()));
                    cells[0][2]->setImage(yellow, "yellow");
                    isYellowHere = true;
                }
            }
        }
     }
}

void MainWindow::anyKnightTurn(int i, int n){
    QString name = FigureMemory[0].getNameImage();
    if(cells[i][n]->getNameImage() == "dark_green"){
        for (int j = 0; j < DarkGreenMemory.length(); j++) {
            if(cells[i][n]->getID() == DarkGreenMemory[j].getID()){
                if(DarkGreenMemory[j].getNameImage().contains("white")){
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutWhite->addWidget(button, whiteColumn, whiteRow);
                    whiteRow++;
                    if(whiteRow % 4 == 0){
                    whiteRow = 0;
                    whiteColumn++;
            }
                } else {
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutBlack->addWidget(button, blackColumn, blackRow);
                    blackRow++;
                    if(blackRow % 4 == 0){
                    blackRow = 0;
                    blackColumn++;
                    }
                }
                if(DarkGreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isPeach()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                    if(checkKingEaten(DarkGreenMemory[j].getNameImage())){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                        return;
                    }
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }

            }
        }
    }
    else if (cells[i][n]->getNameImage() == "green"){
            for (int j = 0; j < GreenMemory.length(); j++) {
                if(cells[i][n]->getID() == GreenMemory[j].getID()){
                    if(GreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                    }
                    else if(GreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                    else if(GreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isPeach()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                    }
                    else if(GreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                }
            }
        }
    if(name.contains("white")){
        whiteTurn = false;
        blackTurn = true;
        labelSetBlackTurn();
    }
    else if(name.contains("black")) {
        whiteTurn = true;
        blackTurn = false;
        labelSetWhiteTurn();
    }
    FigureMemory.clear();
}

void MainWindow::knightSetGreen(int i, int n, QString whichFigClicked){
    if(whichFigClicked == "white_knight_peach" || whichFigClicked == "white_knight_maroon"){
        if(i > 1){
            if(n > 0){
                if(!cells[i-2][n-1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-2][n-1]->getNameImage(), cells[i-2][n-1]->getID()));
                    cells[i-2][n-1]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i-2][n-1]->hasFigure() && cells[i-2][n-1]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i-2][n-1]->getNameImage(), cells[i-2][n-1]->getID()));
                    cells[i-2][n-1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            if(n < 7){
                if(!cells[i-2][n+1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-2][n+1]->getNameImage(), cells[i-2][n+1]->getID()));
                    cells[i-2][n+1]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i-2][n+1]->hasFigure() && cells[i-2][n+1]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i-2][n+1]->getNameImage(), cells[i-2][n+1]->getID()));
                    cells[i-2][n+1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
        }
        if(i < 6){
            if(n > 0){
                if(!cells[i+2][n-1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+2][n-1]->getNameImage(), cells[i+2][n-1]->getID()));
                    cells[i+2][n-1]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i+2][n-1]->hasFigure() && cells[i+2][n-1]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i+2][n-1]->getNameImage(), cells[i+2][n-1]->getID()));
                    cells[i+2][n-1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            if(n < 7){
                if(!cells[i+2][n+1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+2][n+1]->getNameImage(), cells[i+2][n+1]->getID()));
                    cells[i+2][n+1]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i+2][n+1]->hasFigure() && cells[i+2][n+1]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i+2][n+1]->getNameImage(), cells[i+2][n+1]->getID()));
                    cells[i+2][n+1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
        }
        if(n > 1){
            if(i > 0){
                if(!cells[i-1][n-2]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-1][n-2]->getNameImage(), cells[i-1][n-2]->getID()));
                    cells[i-1][n-2]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i-1][n-2]->hasFigure() && cells[i-1][n-2]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n-2]->getNameImage(), cells[i-1][n-2]->getID()));
                    cells[i-1][n-2]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            if(i < 7){
                if(!cells[i+1][n-2]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+1][n-2]->getNameImage(), cells[i+1][n-2]->getID()));
                    cells[i+1][n-2]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i+1][n-2]->hasFigure() && cells[i+1][n-2]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i+1][n-2]->getNameImage(), cells[i+1][n-2]->getID()));
                    cells[i+1][n-2]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
        }
        if(n < 6){
            if(i > 0){
                if(!cells[i-1][n+2]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-1][n+2]->getNameImage(), cells[i-1][n+2]->getID()));
                    cells[i-1][n+2]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i-1][n+2]->hasFigure() && cells[i-1][n+2]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n+2]->getNameImage(), cells[i-1][n+2]->getID()));
                    cells[i-1][n+2]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            if(i < 7){
                if(!cells[i+1][n+2]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+1][n+2]->getNameImage(), cells[i+1][n+2]->getID()));
                    cells[i+1][n+2]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i+1][n+2]->hasFigure() && cells[i+1][n+2]->isFigureBlack()){
                    DarkGreenMemory.push_back(*new Container(cells[i+1][n+2]->getNameImage(), cells[i+1][n+2]->getID()));
                    cells[i+1][n+2]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
        }
    }
    else if(whichFigClicked == "black_knight_peach" || whichFigClicked == "black_knight_maroon"){
        if(i > 1){
            if(n > 0){
                if(!cells[i-2][n-1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-2][n-1]->getNameImage(), cells[i-2][n-1]->getID()));
                    cells[i-2][n-1]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i-2][n-1]->hasFigure() && cells[i-2][n-1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i-2][n-1]->getNameImage(), cells[i-2][n-1]->getID()));
                    cells[i-2][n-1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            if(n < 7){
                if(!cells[i-2][n+1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-2][n+1]->getNameImage(), cells[i-2][n+1]->getID()));
                    cells[i-2][n+1]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i-2][n+1]->hasFigure() && cells[i-2][n+1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i-2][n+1]->getNameImage(), cells[i-2][n+1]->getID()));
                    cells[i-2][n+1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
        }
        if(i < 6){
            if(n > 0){
                if(!cells[i+2][n-1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+2][n-1]->getNameImage(), cells[i+2][n-1]->getID()));
                    cells[i+2][n-1]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i+2][n-1]->hasFigure() && cells[i+2][n-1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i+2][n-1]->getNameImage(), cells[i+2][n-1]->getID()));
                    cells[i+2][n-1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            if(n < 7){
                if(!cells[i+2][n+1]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+2][n+1]->getNameImage(), cells[i+2][n+1]->getID()));
                    cells[i+2][n+1]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i+2][n+1]->hasFigure() && cells[i+2][n+1]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i+2][n+1]->getNameImage(), cells[i+2][n+1]->getID()));
                    cells[i+2][n+1]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
        }
        if(n > 1){
            if(i > 0){
                if(!cells[i-1][n-2]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-1][n-2]->getNameImage(), cells[i-1][n-2]->getID()));
                    cells[i-1][n-2]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i-1][n-2]->hasFigure() && cells[i-1][n-2]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n-2]->getNameImage(), cells[i-1][n-2]->getID()));
                    cells[i-1][n-2]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            if(i < 7){
                if(!cells[i+1][n-2]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+1][n-2]->getNameImage(), cells[i+1][n-2]->getID()));
                    cells[i+1][n-2]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i+1][n-2]->hasFigure() && cells[i+1][n-2]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i+1][n-2]->getNameImage(), cells[i+1][n-2]->getID()));
                    cells[i+1][n-2]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
        }
        if(n < 6){
            if(i > 0){
                if(!cells[i-1][n+2]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i-1][n+2]->getNameImage(), cells[i-1][n+2]->getID()));
                    cells[i-1][n+2]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i-1][n+2]->hasFigure() && cells[i-1][n+2]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i-1][n+2]->getNameImage(), cells[i-1][n+2]->getID()));
                    cells[i-1][n+2]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
            if(i < 7){
                if(!cells[i+1][n+2]->hasFigure()){
                    GreenMemory.push_back(*new Container(cells[i+1][n+2]->getNameImage(), cells[i+1][n+2]->getID()));
                    cells[i+1][n+2]->setImage(green, "green");
                    isGreenHere = true;
                }
                if(cells[i+1][n+2]->hasFigure() && cells[i+1][n+2]->isFigureWhite()){
                    DarkGreenMemory.push_back(*new Container(cells[i+1][n+2]->getNameImage(), cells[i+1][n+2]->getID()));
                    cells[i+1][n+2]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                }
            }
        }

    }
}
void MainWindow::rookSetGreen(int i, int n, QString whichFigClicked)
{
    int x, y;

    if(whichFigClicked == "white_rook_peach" || whichFigClicked == "white_rook_maroon")
    {
        x = i;
        y = n;
        while(x != 0)
        {
            if(cells[x-1][y]->isFigureWhite())
            {
               // isGreenHere = false;
               // isDarkGreenHere = false;
                break;
            }
            else
            {
                if(cells[x-1][y]->isFigureBlack())
                {
                    DarkGreenMemory.push_back(*new Container(cells[x-1][y]->getNameImage(), cells[x-1][y]->getID()));
                    cells[x-1][y]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                    //isGreenHere = false;
                    break;
                }
                else if(!cells[x-1][n]->hasFigure())
                {
                        GreenMemory.push_back(*new Container(cells[x-1][y]->getNameImage(), cells[x-1][y]->getID()));
                        cells[x-1][y]->setImage(green, "green");
                        x--;
                        isGreenHere = true;
                        //isDarkGreenHere = false;
                    }

                }

         }
        x = i;
        y = n;
        while(x != 7)
        {
            if(cells[x+1][y]->isFigureWhite())
            {
                // isGreenHere = false;
                // isDarkGreenHere = false;
                break;
            }
            else
            {
                if(cells[x+1][y]->isFigureBlack())
                {
                    DarkGreenMemory.push_back(*new Container(cells[x+1][y]->getNameImage(), cells[x+1][y]->getID()));
                    cells[x+1][y]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                    //isGreenHere = false;
                    break;
                }
                else if(!cells[x+1][n]->hasFigure())
                {
                        GreenMemory.push_back(*new Container(cells[x+1][y]->getNameImage(), cells[x+1][y]->getID()));
                        cells[x+1][y]->setImage(green, "green");
                        x++;
                        isGreenHere = true;
                        //isDarkGreenHere = false;
                    }

            }

        }
        x = i;
        y = n;
        while(y!=0)
        {
            if(cells[x][y-1]->isFigureWhite())
            {
                // isGreenHere = false;
                // isDarkGreenHere = false;
                break;
            }
            else
            {
                if(cells[x][y-1]->isFigureBlack())
                  {
                  DarkGreenMemory.push_back(*new Container(cells[x][y-1]->getNameImage(), cells[x][y-1]->getID()));
                  cells[x][y-1]->setImage(dark_green, "dark_green");
                  isDarkGreenHere = true;
                //isGreenHere = false;
                                    break;
            }
            else if(!cells[x][y-1]->hasFigure())
                   {
                   GreenMemory.push_back(*new Container(cells[x][y-1]->getNameImage(), cells[x][y-1]->getID()));
                   cells[x][y-1]->setImage(green, "green");
                   y--;
                   isGreenHere = true;
                  //isDarkGreenHere = false;
                }
            }

        }
        x = i;
        y = n;
        while(y != 7)
        {
            if(cells[x][y+1]->isFigureWhite())
            {
                // isGreenHere = false;
                // isDarkGreenHere = false;
                break;
            }
            else
            {
                if(cells[x][y+1]->isFigureBlack())
                  {
                  DarkGreenMemory.push_back(*new Container(cells[x][y+1]->getNameImage(), cells[x][y+1]->getID()));
                  cells[x][y+1]->setImage(dark_green, "dark_green");
                  isDarkGreenHere = true;
                //isGreenHere = false;
                                    break;
            }
            else if(!cells[x][y+1]->hasFigure())
                   {
                   GreenMemory.push_back(*new Container(cells[x][y+1]->getNameImage(), cells[x][y+1]->getID()));
                   cells[x][y+1]->setImage(green, "green");
                   y++;
                   isGreenHere = true;
                  //isDarkGreenHere = false;
                }
            }
        }
     }
    else if(whichFigClicked == "black_rook_peach" || whichFigClicked == "black_rook_maroon")
    {

        x = i;
        y = n;
        while(x != 0)
        {
            if(cells[x-1][y]->isFigureBlack())
            {
               // isGreenHere = false;
               // isDarkGreenHere = false;
                break;
            }
            else
            {
                if(cells[x-1][y]->isFigureWhite())
                {
                    DarkGreenMemory.push_back(*new Container(cells[x-1][y]->getNameImage(), cells[x-1][y]->getID()));
                    cells[x-1][y]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                    //isGreenHere = false;
                    break;
                }
                else if(!cells[x-1][n]->hasFigure())
                {
                        GreenMemory.push_back(*new Container(cells[x-1][y]->getNameImage(), cells[x-1][y]->getID()));
                        cells[x-1][y]->setImage(green, "green");
                        x--;
                        isGreenHere = true;
                        //isDarkGreenHere = false;
                    }

                }

         }
        x = i;
        y = n;
        while(x != 7)
        {
            if(cells[x+1][y]->isFigureBlack())
            {
                // isGreenHere = false;
                // isDarkGreenHere = false;
                break;
            }
            else
            {
                if(cells[x+1][y]->isFigureWhite())
                {
                    DarkGreenMemory.push_back(*new Container(cells[x+1][y]->getNameImage(), cells[x+1][y]->getID()));
                    cells[x+1][y]->setImage(dark_green, "dark_green");
                    isDarkGreenHere = true;
                    //isGreenHere = false;
                    break;
                }
                else if(!cells[x+1][n]->hasFigure())
                {
                        GreenMemory.push_back(*new Container(cells[x+1][y]->getNameImage(), cells[x+1][y]->getID()));
                        cells[x+1][y]->setImage(green, "green");
                        x++;
                        isGreenHere = true;
                        //isDarkGreenHere = false;
                    }
            }
        }
        x = i;
        y = n;
        while(y!=0)
        {
            if(cells[x][y-1]->isFigureBlack())
            {
                // isGreenHere = false;
                // isDarkGreenHere = false;
                break;
            }
            else
            {
                if(cells[x][y-1]->isFigureWhite())
                  {
                  DarkGreenMemory.push_back(*new Container(cells[x][y-1]->getNameImage(), cells[x][y-1]->getID()));
                  cells[x][y-1]->setImage(dark_green, "dark_green");
                  isDarkGreenHere = true;
                //isGreenHere = false;
                                    break;
            }
            else if(!cells[x][y-1]->hasFigure())
                   {
                   GreenMemory.push_back(*new Container(cells[x][y-1]->getNameImage(), cells[x][y-1]->getID()));
                   cells[x][y-1]->setImage(green, "green");
                   y--;
                   isGreenHere = true;
                  //isDarkGreenHere = false;
                }
            }

        }
        x = i;
        y = n;
        while(y != 7)
        {
            if(cells[x][y+1]->isFigureBlack())
            {
                // isGreenHere = false;
                // isDarkGreenHere = false;
                break;
            }
            else
            {
                if(cells[x][y+1]->isFigureWhite())
                  {
                  DarkGreenMemory.push_back(*new Container(cells[x][y+1]->getNameImage(), cells[x][y+1]->getID()));
                  cells[x][y+1]->setImage(dark_green, "dark_green");
                  isDarkGreenHere = true;
                //isGreenHere = false;
                                    break;
            }
            else if(!cells[x][y+1]->hasFigure())
                   {
                   GreenMemory.push_back(*new Container(cells[x][y+1]->getNameImage(), cells[x][y+1]->getID()));
                   cells[x][y+1]->setImage(green, "green");
                   y++;
                   isGreenHere = true;
                  //isDarkGreenHere = false;
                }
            }
        }

    }
}

void MainWindow::anyRookTurn(int i, int n)
{
    QString name = FigureMemory[0].getNameImage();
    if(cells[i][n]->getNameImage() == "dark_green"){
        for (int j = 0; j < DarkGreenMemory.length(); j++) {
            if(cells[i][n]->getID() == DarkGreenMemory[j].getID()){
                if(DarkGreenMemory[j].getNameImage().contains("white")){
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutWhite->addWidget(button, whiteColumn, whiteRow);
                    whiteRow++;
                    if(whiteRow % 4 == 0){
                    whiteRow = 0;
                    whiteColumn++;
            }
                } else {
                    QIcon icon(findPathImage(DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    layoutBlack->addWidget(button, blackColumn, blackRow);
                    blackRow++;
                    if(blackRow % 4 == 0){
                    blackRow = 0;
                    blackColumn++;
                    }
                }
                if(DarkGreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isPeach()){
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                }
                else if(DarkGreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                    clearGreenColors();
                    swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                }
            }
        }
    }
    else if (cells[i][n]->getNameImage() == "green"){
            for (int j = 0; j < GreenMemory.length(); j++) {
                if(cells[i][n]->getID() == GreenMemory[j].getID()){
                    if(GreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                    }
                    else if(GreenMemory[j].getNameImage().contains("peach") && findCellByID(FigureMemory[0].getID())->isPeach()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                    else if(GreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isPeach()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n]);
                    }
                    else if(GreenMemory[j].getNameImage().contains("maroon") && findCellByID(FigureMemory[0].getID())->isMaroon()){
                        clearGreenColors();
                        swapImages(findCellByID(FigureMemory[0].getID()), cells[i][n], 1);
                    }
                }
            }
        }
    if(name.contains("white")){
        whiteTurn = false;
        blackTurn = true;
        labelSetBlackTurn();
    }
    else if(name.contains("black")) {
        whiteTurn = true;
        blackTurn = false;
        labelSetWhiteTurn();
    }
    FigureMemory.clear();
}
//--------------------------------------------------------------------------------------------------------------------

// ###################################################################################################################

//--------------------------------------------------------------------------------------------------------------------

// УНИВЕРСАЛЬНЫЕ ФУНКЦИИ

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

void MainWindow::swapFigureColor(Cell *cell){
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
        cell->setImage(black_knight_peach, "black_knight_peach");
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
    else if(cell->getNameImage() == "white_king_maroon"){
        cell->setImage(white_king_peach, "white_king_peach");
    }
    else if(cell->getNameImage() == "white_king_peach"){
        cell->setImage(white_king_maroon, "white_king_maroon");
    }
    else if(cell->getNameImage() == "black_king_maroon"){
        cell->setImage(black_king_peach, "black_king_peach");
    }
    else if(cell->getNameImage() == "black_king_peach"){
        cell->setImage(black_king_maroon, "black_king_maroon");
    }
    else if(cell->getNameImage() == "white_queen_maroon"){
        cell->setImage(white_queen_peach, "white_queen_peach");
    }
    else if(cell->getNameImage() == "white_queen_peach"){
        cell->setImage(white_queen_maroon, "white_queen_maroon");
    }
    else if(cell->getNameImage() == "black_queen_maroon"){
        cell->setImage(black_queen_peach, "black_queen_peach");
    }
    else if(cell->getNameImage() == "black_queen_peach"){
        cell->setImage(black_queen_maroon, "black_queen_maroon");
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

    else if(path == white_king_maroon) return "white_king_maroon";
    else if(path == white_king_peach) return "white_king_peach";
    else if(path == black_king_maroon) return "black_king_maroon";
    else if(path == black_king_peach) return "black_king_peach";

    else if(path == white_queen_maroon) return "white_queen_maroon";
    else if(path == white_queen_peach) return "white_queen_peach";
    else if(path == black_queen_maroon) return "black_queen_maroon";
    else if(path == black_queen_peach) return "black_queen_peach";

    else return "none";
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

    else if(nameImage == "white_king_maroon") return white_king_maroon;
    else if(nameImage == "white_king_peach") return white_king_peach;
    else if(nameImage == "black_king_maroon") return black_king_maroon;
    else if(nameImage == "black_king_peach") return black_king_peach;

    else if(nameImage == "white_queen_maroon") return white_queen_maroon;
    else if(nameImage == "white_queen_peach") return white_queen_peach;
    else if(nameImage == "black_queen_maroon") return black_queen_maroon;
    else if(nameImage == "black_queen_peach") return black_queen_peach;

    else return "none";
}

void MainWindow::clearGreenColors(){
    for (int j = 0; j < DarkGreenMemory.size(); j++) {
        int ID = DarkGreenMemory[j].getID();
        QString nameImage = DarkGreenMemory[j].getNameImage();
        for (int i = 0; i < 8; i++) {
            for (int n = 0; n < 8; n++) {
                if(cells[i][n]->getID() == ID){
                    cells[i][n]->setImage(findPathImage(nameImage), nameImage);
                }
            }
        }
    }
    DarkGreenMemory.clear();
    for (int j = 0; j < GreenMemory.size(); j++) {
        int ID = GreenMemory[j].getID();
        QString nameImage = GreenMemory[j].getNameImage();
        for (int i = 0; i < 8; i++) {
            for (int n = 0; n < 8; n++) {
                if(cells[i][n]->getID() == ID){
                    cells[i][n]->setImage(findPathImage(nameImage), nameImage);
                }
            }
        }
    }
    GreenMemory.clear();
    for (int j = 0; j < YellowMemory.size(); j++) {
        int ID = YellowMemory[j].getID();
        QString nameImage = YellowMemory[j].getNameImage();
        for (int i = 0; i < 8; i++) {
            for (int n = 0; n < 8; n++) {
                if(cells[i][n]->getID() == ID){
                    cells[i][n]->setImage(findPathImage(nameImage), nameImage);
                }
            }
        }
    }
    YellowMemory.clear();
    isDarkGreenHere = false;
    isGreenHere = false;
    isYellowHere = false;
}

Cell* MainWindow::findCellByID(int ID){
    for (int i = 0; i < 8; i++) {
        for (int n = 0; n < 8; n++) {
            if(cells[i][n]->getID() == ID){
                return cells[i][n];
            }
        }
    }
}

void MainWindow::labelSetBlackTurn(){
    information->setText("Ходят чёрные!");
}

void MainWindow::labelSetWhiteTurn(){
    information->setText("Ходят белые!");
}

bool MainWindow::checkKingEaten(QString nameImage){
    if(nameImage.contains("white_king")){
        QMessageBox::information(this, "Победа", "Победили чёрные!!!!!");
        information->setGeometry(70, 510, 380, 55);
        information->setText("ПОБЕДА ЧЁРНЫХ");
        whiteTurn = false;
        blackTurn = false;
        setButtonMainWindow();
        return true;
    }
    else if(nameImage.contains("black_king")){
        QMessageBox::information(this, "Победа", "Победили белые!!!!!");
        information->setText("ПОБЕДА БЕЛЫХ!");
        information->setGeometry(70, 510, 380, 55);
        whiteTurn = false;
        blackTurn = false;
        setButtonMainWindow();
        return true;
    }
    return false;
}

void MainWindow::resetGame(){
    setButtonBack();
    clearGreenColors();
    whiteRow = 0;
    whiteColumn = 0;
    blackRow = 0;
    blackColumn = 0;
    isGreenHere = false;
    isDarkGreenHere = false;
    isYellowHere = false;
    singleWhiteCastling = false;
    singleBlackCastling = false;
    blackTurn = false;
    whiteTurn = true;
    back->setGeometry(530, 520, 266, 55);
    back->setText("Назад");
    back->setStyleSheet(QString::fromUtf8("background-color: red; font-family: Times New Roman, Georgia, Serif; font-weight: bold;"
                                           "font-size: 40px; border: 4px solid black;"));
    labelSetWhiteTurn();
    int ID = 1;      // ЛОКАЛЬНАЯ ПЕРЕМЕННАЯ АЙДИ ДЛЯ ТОГО, ЧТОБЫ У КАЖДОГО ЭКЗЕМПЛЯРА CELL БЫЛ СВОЙ ID (ПОКА НЕ ЗНАЮ КАК ДАЛЬШЕ ЭТО ИСПОЛЬЗОВАТЬ)
    int colorConfiguration = 1;    // ПАРАМЕТР. НУЖЕН ДЛЯ ТОГО, ЧТОБЫ ЧЕРЕДОВАЛИСЬ ЦВЕТА
    for(int i = 0; i < 8; ++i) { // ЦИКЛ, В КОТОРОМ СОЗДАЕТСЯ КЛЕТЧАТАЯ ДОСКА (ПУСТАЯ)
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

            cells[i][n]->setImage(path, nameImage);
            ID++;
        }
        colorConfiguration++;
    }

    for(int i = 0; i < 4; ++i) {
        for (int n = 0; n < 4; n++) {
            QString path;
            QString nameImage;
            QIcon icon(yellow);
            QPushButton *button = new QPushButton;
            button->setIcon(icon);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setIconSize(QSize(64, 64));
            layoutWhite->addWidget(button, i, n); // ВЫВОД КНОПКИ НА ОБЛАСТЬ
        }
    }

    for(int i = 0; i < 4; ++i) {
        for (int n = 0; n < 4; n++) {
            QString path;
            QString nameImage;
            QIcon icon(yellow);
            QPushButton *button = new QPushButton;
            button->setIcon(icon);
            button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
            button->setIconSize(QSize(64, 64));
            layoutBlack->addWidget(button, i, n); // ВЫВОД КНОПКИ НА ОБЛАСТЬ
        }
    }
    cells[6][0]->setImage(white_pawn_peach, "white_pawn_peach");
    cells[6][2]->setImage(white_pawn_peach, "white_pawn_peach");
    cells[6][4]->setImage(white_pawn_peach, "white_pawn_peach");
    cells[6][6]->setImage(white_pawn_peach, "white_pawn_peach");
    cells[6][1]->setImage(white_pawn_maroon, "white_pawn_maroon");
    cells[6][3]->setImage(white_pawn_maroon, "white_pawn_maroon");
    cells[6][5]->setImage(white_pawn_maroon, "white_pawn_maroon");
    cells[6][7]->setImage(white_pawn_maroon, "white_pawn_maroon");
    cells[1][1]->setImage(black_pawn_peach, "black_pawn_peach");
    cells[1][3]->setImage(black_pawn_peach, "black_pawn_peach");
    cells[1][5]->setImage(black_pawn_peach, "black_pawn_peach");
    cells[1][7]->setImage(black_pawn_peach, "black_pawn_peach");
    cells[1][0]->setImage(black_pawn_maroon, "black_pawn_maroon");
    cells[1][2]->setImage(black_pawn_maroon, "black_pawn_maroon");
    cells[1][4]->setImage(black_pawn_maroon, "black_pawn_maroon");
    cells[1][6]->setImage(black_pawn_maroon, "black_pawn_maroon");
    cells[7][7]->setImage(white_rook_peach, "white_rook_peach");
    cells[7][0]->setImage(white_rook_maroon, "white_rook_maroon");
    cells[0][0]->setImage(black_rook_peach, "black_rook_peach");
    cells[0][7]->setImage(black_rook_maroon, "black_rook_maroon");
    cells[7][1]->setImage(white_knight_peach, "white_knight_peach");
    cells[7][6]->setImage(white_knight_maroon, "white_knight_maroon");
    cells[0][6]->setImage(black_knight_peach, "black_knight_peach");
    cells[0][1]->setImage(black_knight_maroon, "black_knight_maroon");
    cells[7][5]->setImage(white_bishop_peach, "white_bishop_peach");
    cells[7][2]->setImage(white_bishop_maroon, "white_bishop_maroon");
    cells[0][2]->setImage(black_bishop_peach, "black_bishop_peach");
    cells[0][5]->setImage(black_bishop_maroon, "black_bishop_maroon");
    cells[7][3]->setImage(white_queen_peach, "white_queen_peach");
    cells[0][3]->setImage(black_queen_maroon, "black_queen_maroon");
    cells[7][4]->setImage(white_king_maroon, "white_king_maroon");
    cells[0][4]->setImage(black_king_peach, "black_king_peach");
}


void MainWindow::setButtonBack(){
    back->setGeometry(530, 520, 266, 55);
    back->setText("Назад");
    back->setStyleSheet(QString::fromUtf8("background-color: red; font-family: Times New Roman, Georgia, Serif; font-weight: bold;"
                                           "font-size: 40px; border: 4px solid black;"));

}

void MainWindow::setButtonMainWindow(){
    back->setGeometry(530, 520, 266, 55);
    back->setText("Главное меню");
    back->setStyleSheet(QString::fromUtf8("background-color: green; font-family: Times New Roman, Georgia, Serif; font-weight: bold;"
                                           "font-size: 40px; border: 4px solid black;"));
}

//--------------------------------------------------------------------------------------------------------------------

// ###################################################################################################################

//--------------------------------------------------------------------------------------------------------------------

// СЛОТЫ И СИГНАЛЫ
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

void MainWindow::slotBack(){
    resetGame();
    emit signalFromButtonBack();
}

void MainWindow::closeWindow(){
    resetGame();
    emit signalShit();
    this->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}
//--------------------------------------------------------------------------------------------------------------------



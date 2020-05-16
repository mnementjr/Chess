#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QObject>
#include <QPushButton>
#include <QMap>
#include <QDir>
#include <QLabel>
#include "cell.h"
#include "container.h"
#include "menu.h"

// ТУТ НИЧЕГО НЕ ТРОГАЛ

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *menu, QWidget *parent = nullptr);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    Cell *cells[8][8];     // ПУСТОЙ МАССИВ ОБЪЕКТОВ КЛАССА CELLS, В КОТОРОМ ЕСТЬ САМА КНОПКА

    //--------------------------------------------------------------------------------------------------------------------
    // МЕТОДЫ, КОТОРЫЕ СВЯЗАНЫ С ХОДАМИ ФИГУР (СЮДА ИХ ДОБАВЛЯТЬ ПРИ РЕАЛИЗАЦИИ НОВЫХ ФИГУР)
    void whitePawnTurn(int i, int n);
    void blackPawnTurn(int i, int n);
    void pawnSetGreen(int i, int n, int ID, QString whichFigClicked);

    void anotherQueenTurn(int i, int n);
    void queenSetGreen(int i, int n, int ID, QString whichFigClicked);

    void anotherBishopTurn(int i, int n);
    void bishopSetGreen(int i, int n, int ID, QString whichFigClicked);

    void anotherKingTurn(int i, int n);
    void kingSetGreen(int i, int n, int ID, QString whichFigClicked);

    void anyKnightTurn(int i, int n);
    void knightSetGreen(int i, int n, int ID, QString whichFigClicked);


    //--------------------------------------------------------------------------------------------------------------------

    // ###################################################################################################################

    //--------------------------------------------------------------------------------------------------------------------
    // УНИВЕРСАЛЬНЫЕ ФУНКЦИИ, КОТОРЫЕ НЕ НАДО МЕНЯТЬ, НО НАДО ИСПОЛЬЗОВАТЬ В СОЗДАНИИ ФУНКЦИЙ ПО ХОДАМ ФИГУР
    void clearGreenColors(); // ОЧИЩАЕТ ВСЕ ЗЕЛЁНЫЕ И ТЕМНО-ЗЕЛЁНЫЕ КЛЕТКИ НА ДОСКЕ
    void swapImages(Cell *cell1, Cell *cell2, int configuration = 0);  // ПЕРЕМЕЩАЕТ ИЗОБРАЖЕНИЕ С КЛЕТКИ CELL1 В CELL2
    void swapFigureColor(Cell *cell);      // МЕНЯЕТ ФОН КЛЕТКИ CELL (С MAROON НА PEACH ИЛИ С PEACH НА MAROON)
    QString findPathImage(QString nameImage);      // ВОЗВРАЩАЕТ ПУТЬ К ИЗОБРАЖЕНИЮ ПО ИМЕНИ ИЗОБРАЖЕНИЯ
    QString findNameImage(QString path);           // ВОЗВРАЩЕТ ИМЯ ИЗОБРАЖЕНИЯ ПО ПУТЮ К ИЗОБРАЖЕНИЮ
    Cell* findCellByID(int ID);                    // ВОЗВРАЩАЕТ ССЫЛКУ НА КАКУЮ-ТО КНОПКУ ПО ID
    void labelSetWhiteTurn();                      // ПИШЕТ, ЧТО ХОДЯТ БЕЛЫЕ
    void labelSetBlackTurn();                      // ПИШЕТ, ЧТО ХОДЯТ ЧЕРНЫЙ
    bool checkKingEaten(QString nameImage);        // ПРОВЕРКА НА ПОБЕДУ
    //--------------------------------------------------------------------------------------------------------------------

    // ###################################################################################################################

    //--------------------------------------------------------------------------------------------------------------------
    // ПЕРЕМЕННЫЕ
    QWidget *field;
    bool whiteTurn;
    bool blackTurn;
    bool isGreenHere;     // ОТВЕЧАЕТ ЗА ПРИСУТСТВИЕ ЗЕЛЕНОГО ЦВЕТА НА ДОСКЕ
    bool isDarkGreenHere; // ОТВЕЧАЕТ ЗА ПРИСУТСТВИЕ ТЕМНО-ЗЕЛЕНОГО ЦВЕТА НА ДОСКЕ
    bool isYellowHere;     // ОТВЕЧАЕТ ЗА ПРИСУТСТВИЕ ЖЁДТОГО ЦВЕТА НА ДОСКЕ (ПРИ РОКИРОВКЕ)
    bool singleWhiteCastling;    // ОТВЕЧАЕТ ЗА ОДНОКРАТНОСТЬ БЕЛОЙ РОКИРОВКИ
    bool singleBlackCastling;    // ОТВЕЧАЕТ ЗА ОДНОКРАТНОСТЬ ЧЁРНОЙ РОКИРОВКИ
    QString whichFigureClicked;  // ЗАПОМИНАЕТ ИМЯ ИЗОБРАЖЕНИЯ КНОПКИ, НА КОТОРУЮ НАЖАЛИ
    QVector <Container> DarkGreenMemory;  // ХРАНИТ ИЗОБРАЖЕНИЯ КНОПОК, КОТОРЫЕ БЫЛИ ЗАМЕНЕНЫ ТЕМНО-ЗЕЛЕНЫМ ЦВЕТОМ
    QVector <Container> GreenMemory;      // ХРАНИТ ИЗОБРАЖЕНИЯ КНОПОК, КОТОРЫЕ БЫЛИ ЗАМЕНЕНЫ ЗЕЛЕНЫМ ЦВЕТОМ
    QVector <Container> YellowMemory;      // ХРАНИТ ИЗОБРАЖЕНИЯ КНОПОК, КОТОРЫЕ БЫЛИ ЗАМЕНЕНЫ ЖЁЛТЫМ ЦВЕТОМ
    QVector <Container> FigureMemory;     // ХРАНИТ ИЗОБРАЖЕНИЕ ФИГУРЫ, НА КОТОРУЮ НАЖАЛИ
    QLabel *information;                  // ИНОФРМАЦИЯ О ТОМ, КТО ХОДИТ
    QPushButton *back;
    //--------------------------------------------------------------------------------------------------------------------

    // ###################################################################################################################

    //--------------------------------------------------------------------------------------------------------------------
    // ЗДЕСЬ ИДЕТ СОЗДАНИЕ ПЕРЕМЕННЫХ, В КОТОРЫХ НАХОДЯТСЯ ПУТИ ДО ИЗОБРАЖЕНИЙ
    // ДЛЯ КАЖДОЙ ФИГУРЫ ДОЛЖНО БЫТЬ ПО 4 ИЗОБРАЖЕНИЯ
    // 1. ДЛЯ БЕЛЫХ ЦВЕТА MAROON
    // 2. ДЛЯ БЕЛЫХ ЦВЕТА PEACH
    // 3. ДЛЯ ЧЕРНЫХ ЦВЕТА MAROON
    // 4. ДЛЯ ЧЕРНЫХ ЦВЕТА PEACH
    // QDir::currentPath() --- УКАЗЫВАТЬ ОБЯЗАТЕЛЬНО. ОЗНАЧАЕТ, ЧТО МЫ НАХОДИМСЯ В ПАПКЕ, ИЗ КОТОРОЙ БЫЛ ЗАПУЩЕН ПРОЕКТ

    QString maroon = QDir::currentPath() + "/images/maroon.jpg";  // КЛЕТКА ЦВЕТОМ MAROON
    QString peach = QDir::currentPath() + "/images/peach.jpg";    // КЛЕТКА ЦВЕТОМ PEACH
    QString green = QDir::currentPath() + "/images/green.jpg";    // КЛЕТКА ЦВЕТОМ GREEN
    QString yellow = QDir::currentPath() + "/images/yellow.jpg";    // КЛЕТКА ЦВЕТОМ YELLOW
    QString dark_green = QDir::currentPath() + "/images/darkGreen.jpg";    // КЛЕТКА ЦВЕТОМ DARK GREEN

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

    // КОРОЛЕВА ИЛИ ФЕРЗЬ
    QString white_queen_maroon = QDir::currentPath() + "/images/white/queen_maroon.jpg";
    QString white_queen_peach = QDir::currentPath() + "/images/white/queen_peach.jpg";
    QString black_queen_maroon = QDir::currentPath() + "/images/black/queen_maroon.jpg";
    QString black_queen_peach = QDir::currentPath() + "/images/black/queen_peach.jpg";

    // КОРОЛЬ
    QString white_king_maroon = QDir::currentPath() + "/images/white/king_maroon.jpg";
    QString white_king_peach = QDir::currentPath() + "/images/white/king_peach.jpg";
    QString black_king_maroon = QDir::currentPath() + "/images/black/king_maroon.jpg";
    QString black_king_peach = QDir::currentPath() + "/images/black/king_peach.jpg";
    //--------------------------------------------------------------------------------------------------------------------

    // ###################################################################################################################

    //--------------------------------------------------------------------------------------------------------------------
    // СИГНАЛЫ И СЛОТЫ

signals:
    void signalFromButton(int ID);
    void signalFromButtonBack();
    void signalShit();

private slots:
    void changeImage(int ID);

    void closeWindow();
    void slotBack();

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
    //--------------------------------------------------------------------------------------------------------------------

};
#endif // MAINWINDOW_H

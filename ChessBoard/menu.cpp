#include "menu.h"
#include "ui_menu.h"

#include <QMessageBox>

Menu::Menu(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    this->resize(800, 600);
    this->setWindowTitle("Chess");  // НАЗВАНИЕ ПРОГРАММЫ
    this->setMinimumSize(QSize(800, 600));
    this->setMaximumSize(QSize(800, 600));

    start = new QPushButton(this);


    board = new MainWindow();

    //connect(board, &MainWindow::signalFromButtonBack, this, &Menu::show);

    QPalette pal;
    pal.setColor(QPalette::Background, "#efe4b0");
    board->setPalette(pal);



    start->setGeometry(200, 200, 400, 70);
    start->setText("Играть");
    start->setStyleSheet(QString::fromUtf8("background-color: rgb(255,242,0); font-family: Times New Roman, Georgia, Serif; font-weight: bold;"
                                           "font-stretch: expanded; font-size: 40px; border: 4px solid black;"));

    exit = new QPushButton(this);
    exit->setText("Выход");
    exit->setGeometry(200, 280, 400, 70);
    exit->setStyleSheet(QString::fromUtf8("background-color: rgb(255,242,0); font-family: Times New Roman, Georgia, Serif; font-weight: bold;"
                                            "font-stretch: expanded; font-size: 40px; border: 4px solid black;"));


    connect(start, SIGNAL(clicked()), this, SLOT(clickStart()));
    connect(exit, SIGNAL(clicked()), this, SLOT(clickExit()));
    connect(this, &Menu::signalFromButtonStart, this, &Menu::startGame);
    connect(this, &Menu::signalFromButtonExit, this, &Menu::exitGame);

}

void Menu::clickStart(){
    emit signalFromButtonStart();
}

void Menu::clickExit(){
    emit signalFromButtonExit();
}

void Menu::CreateGame(){
    /*
    field = new QWidget(window);
    field->setMaximumSize(QSize(512, 512));
    field->setMinimumSize(QSize(512, 512));
    board = new MainWindow(window, field);       // СОЗДАНИЕ ДОСКИ
    board->show();
    */
}

void Menu::startGame(){
    board->show();
    this->close();
}

void Menu::exitGame(){

    this->close();
}
Menu::~Menu()
{
    delete ui;
}

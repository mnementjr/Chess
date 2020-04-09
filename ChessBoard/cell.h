#ifndef CELL_H
#define CELL_H

#include <QPushButton>
#include <QString>

class Cell : public QWidget {

public:
    Cell(QWidget *parent = 0, int ID = 0);  // КОНСТРУКТОР
    int getID();         // ПОЛУЧАЕМ ID, ТАК КАК ОН PRIVATE
    QPushButton *getButton(); // ПОЛУЧАЕМ КНОПКУ, ТАК КАК ОНА В PRIVATE
    void setText(QString text); // ТЕСТОВЫЙ МЕТОД, КОТОРЫЙ УСТАНАВЛИВАЕТ ТЕКСТ НА КНОПКЕ
private:
    int ID;   // ЧТОБ МОЖНО БЫЛО НАЙТИ КНОПКУ
    QPushButton *button;  // САМА КНОПКА
};

#endif // CELL_H

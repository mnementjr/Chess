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

    void setImage(QString path, QString nameImage); // УСТАНОВКА ИЗОБРАЖЕНИЯ ПО ПУТИ К ИЗОБРАЖЕНИЮ И ИМЕНИ ИЗОБРАЖЕНИЯ
    bool isPeach();         // ПЕРСИКОВАЯ КЛЕТКА?? (ПОДХОДИТ И К ФИГУРАМ)
    bool isMaroon();        // БОРДОВАЯ КЛЕТКА?? (ПОДХОДИТ И К ФИГУРАМ)
    bool isFigureBlack();   // ЧЕРНАЯ ЛИ ФИГУРА??
    bool isFigureWhite();   // БЕЛАЯ ЛИ ФИГУРА??
    bool hasFigure();       // ИМЕЕТ ЛИ ФИГУРА?
    QString getNameImage(); // ВОЗВРАЩАЕТ ИМЯ ИЗОБРАЖЕНИЯ
private:
    int ID;   // ЧТОБ МОЖНО БЫЛО НАЙТИ КНОПКУ
    QString nameImage;    // ИМЯ ИЗОБРАЖЕНИЯ
    QPushButton *button;  // САМА КНОПКА
};

#endif // CELL_H

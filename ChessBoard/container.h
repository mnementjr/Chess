#ifndef CONTAINER_H
#define CONTAINER_H

#include <QString>



class Container
{
public:
    Container(QString nameImage, int ID);
    QString getNameImage();
    int getID();
private:
    QString nameImage;
    int ID;

};

#endif // CONTAINER_H

#include "container.h"

Container::Container(QString nameImage, int ID)
{
    this->nameImage = nameImage;
    this->ID = ID;
}
int Container::getID(){
    return ID;
}
QString Container::getNameImage(){
    return nameImage;
}

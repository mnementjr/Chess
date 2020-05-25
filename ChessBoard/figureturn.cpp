#include "figureturn.h"
FigureTurn::FigureTurn(MainWindow *mainT)
{
    this->mainT = mainT;
}
void FigureTurn::TurnFigure(int i, int n)
{
    QString name = mainT->FigureMemory[0].getNameImage();
    if(mainT->cells[i][n]->getNameImage() == "dark_green"){
        for (int j = 0; j < mainT->DarkGreenMemory.length(); j++) {
            if(mainT->cells[i][n]->getID() == mainT->DarkGreenMemory[j].getID()){
                if(mainT->DarkGreenMemory[j].getNameImage().contains("white")){
                    QIcon icon(mainT->findPathImage(mainT->DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    mainT->layoutWhite->addWidget(button, mainT->whiteColumn, mainT->whiteRow);
                    mainT->whiteRow++;
                    if(mainT->whiteRow % 4 == 0){
                    mainT->whiteRow = 0;
                    mainT->whiteColumn++;
            }
                } else {
                    QIcon icon(mainT->findPathImage(mainT->DarkGreenMemory[j].getNameImage()));
                    QPushButton *button = new QPushButton;
                    button->setIcon(icon);
                    button->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
                    button->setIconSize(QSize(64, 64));
                    mainT->layoutBlack->addWidget(button, mainT->blackColumn, mainT->blackRow);
                    mainT->blackRow++;
                    if(mainT->blackRow % 4 == 0){
                    mainT->blackRow = 0;
                    mainT->blackColumn++;
                    }
                }
                if(mainT->DarkGreenMemory[j].getNameImage().contains("peach") && mainT->findCellByID(mainT->FigureMemory[0].getID())->isMaroon()){
                    if(mainT->checkKingEaten(mainT->DarkGreenMemory[j].getNameImage())){
                        mainT->clearGreenColors();
                        mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n]);
                        return;
                    }
                    mainT->clearGreenColors();
                    mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n]);
                }
                else if(mainT->DarkGreenMemory[j].getNameImage().contains("peach") && mainT->findCellByID(mainT->FigureMemory[0].getID())->isPeach()){
                    if(mainT->checkKingEaten(mainT->DarkGreenMemory[j].getNameImage())){
                        mainT->clearGreenColors();
                        mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n]);
                        return;
                    }
                    mainT->clearGreenColors();
                    mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n], 1);
                }
                else if(mainT->DarkGreenMemory[j].getNameImage().contains("maroon") && mainT->findCellByID(mainT->FigureMemory[0].getID())->isPeach()){
                    if(mainT->checkKingEaten(mainT->DarkGreenMemory[j].getNameImage())){
                        mainT->clearGreenColors();
                        mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n]);
                        return;
                    }
                    mainT->clearGreenColors();
                    mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n]);
                }
                else if(mainT->DarkGreenMemory[j].getNameImage().contains("maroon") && mainT->findCellByID(mainT->FigureMemory[0].getID())->isMaroon()){
                    if(mainT->checkKingEaten(mainT->DarkGreenMemory[j].getNameImage())){
                        mainT->clearGreenColors();
                        mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n]);
                        return;
                    }
                    mainT->clearGreenColors();
                    mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n], 1);
                }
            }
        }
    }
    else if (mainT->cells[i][n]->getNameImage() == "green"){
            for (int j = 0; j < mainT->GreenMemory.length(); j++) {
                if(mainT->cells[i][n]->getID() == mainT->GreenMemory[j].getID()){
                    if(mainT->GreenMemory[j].getNameImage().contains("peach") && mainT->findCellByID(mainT->FigureMemory[0].getID())->isMaroon()){
                        mainT->clearGreenColors();
                        mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n]);
                    }
                    else if(mainT->GreenMemory[j].getNameImage().contains("peach") && mainT->findCellByID(mainT->FigureMemory[0].getID())->isPeach()){
                        mainT->clearGreenColors();
                        mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n], 1);
                    }
                    else if(mainT->GreenMemory[j].getNameImage().contains("maroon") && mainT->findCellByID(mainT->FigureMemory[0].getID())->isPeach()){
                        mainT->clearGreenColors();
                        mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n]);
                    }
                    else if(mainT->GreenMemory[j].getNameImage().contains("maroon") && mainT->findCellByID(mainT->FigureMemory[0].getID())->isMaroon()){
                        mainT->clearGreenColors();
                        mainT->swapImages(mainT->findCellByID(mainT->FigureMemory[0].getID()), mainT->cells[i][n], 1);
                    }
                }
            }
        }
    if(name.contains("white")){
        mainT->whiteTurn = false;
        mainT->blackTurn = true;
        mainT->labelSetBlackTurn();
    }
    else if(name.contains("black")) {
        mainT->whiteTurn = true;
        mainT->blackTurn = false;
        mainT->labelSetWhiteTurn();
    }
    mainT->FigureMemory.clear();
}

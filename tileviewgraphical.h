#ifndef TILEVIEWGRAPHICAL_H
#define TILEVIEWGRAPHICAL_H

#include "mainwindow.h"
#include "tilemodel.h"

#include <memory>

class TileViewGraphical //refactor this -> we need a subclass for graphical view
{
public:
    TileViewGraphical(MainWindow& mw, std::shared_ptr<TileModel> tm);
    void update(); //change this such that it only renders as the player walks!!!


private:
    MainWindow& mainWindow;
    std::shared_ptr<TileModel> tileModel;
};

#endif // TILEVIEWGRAPHICAL_H

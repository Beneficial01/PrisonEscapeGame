#include "graphicalgameview.h"
#include "healthpackviewgraphical.h"
#include "tileviewgraphical.h"
#include "protagonistviewgraphical.h"
#include "qapplication.h"
#include "qboxlayout.h"
#include "qgraphicsitem.h"
#include "qgraphicsview.h"


void GraphicalGameView::initializeMainWindow()
{
    mainWindow.setKeyboardEventsEnabled(true);
   //create health bar:
    healthBar = std::make_shared<HealthProgressBar>(&mainWindow);
    healthBar->setRange(0, 122);
    healthBar->setValue(24);
    healthBar->setTextVisible(true);
    healthBar->setStyleSheet(
        "QProgressBar { border: 2px solid grey; border-radius: 5px; background-color: grey; text-align: center; }"
        "QProgressBar::chunk { background-color: green; width: 10px; }"
        "QProgressBar::chunk:horizontal { margin: 0px; }"
        );

    energyBar = std::make_shared<EnergyProgressBar>(&mainWindow);
    energyBar->setRange(0, 122);
    energyBar->setValue(24);
    energyBar->setTextVisible(true);
    energyBar->setStyleSheet(
        "QProgressBar { border: 2px solid grey; border-radius: 5px; background-color: grey; text-align: center; color: white; }"
        "QProgressBar::chunk { background-color: blue; width: 10px; }"
        "QProgressBar::chunk:horizontal { margin: 0px; }"
        );

    if(auto pView = dynamic_cast<ProtagonistViewGraphical*>(protView.get())){
        pView->setHealthBar(healthBar);
        pView->setEnergyBar(energyBar);
    };



    if(scene == nullptr) scene = std::make_shared<QGraphicsScene>(&mainWindow);
    view =  std::make_shared<QGraphicsView>(scene.get());
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainWindow.setCentralWidget(view.get());
    mainLayout->addWidget(view.get());

    QHBoxLayout* barsLayout = new QHBoxLayout;
    barsLayout->addWidget(healthBar.get());
    barsLayout->addWidget(energyBar.get());

    mainLayout->addLayout(barsLayout);

    // Create a widget to hold the view
    widget = new QWidget(&mainWindow);

    widget->setFixedSize(800, 400);
    widget->setLayout(mainLayout);
    mainLayout->setAlignment(Qt::AlignTop);
    mainLayout->setContentsMargins(0, 0, 0, 0);


    mainWindow.setCentralWidget(widget);

    if(auto tView = dynamic_cast<TileViewGraphical*>(tileView.get())){
        tView->setScene(scene);
    };
    if(auto pView = dynamic_cast<ProtagonistViewGraphical*>(protView.get())){
        pView->setScene(scene);
    };
    if(auto hView = dynamic_cast<HealthPackViewGraphical*>(hpView.get())){
        hView->setScene(scene);
    };
    for(auto& eV: enemyView){
        if(auto eView = dynamic_cast<BaseEnemyView*>(eV.get())){
            eView->setScene(scene);
        };
    }
}

void GraphicalGameView::clearMainWindow()
{

    QList<QGraphicsItem*> itemsToRemove = scene->items();
    for (QGraphicsItem* item : itemsToRemove) {
        if (dynamic_cast<QGraphicsRectItem*>(item)) {
            scene->removeItem(item);
            delete item; // Free memory of deleted items
        }
    }
    QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
    // Update the view after removing items
    view->viewport()->update();


    tileView->clearView();
    hpView->clearView();
    protView->clearView();
    for(auto& eV: enemyView){
        eV->clearView();
    }


    QCoreApplication::processEvents(QEventLoop::AllEvents, 10);

//    scene->setParent(nullptr);

    view.reset();
    widget->setParent(nullptr);
    widget = nullptr;

    layout = nullptr;


        QCoreApplication::processEvents(QEventLoop::AllEvents, 10);

    healthBar.reset();
    energyBar.reset();

    QCoreApplication::processEvents(QEventLoop::AllEvents, 10);
}

#include "mainwindow.h"
#include "enemyviewgraphical.h"
#include "enemyviewtext.h"
#include "healthpackviewtext.h"
#include "penemyviewgraphical.h"
#include "penemyviewtext.h"
#include "protagonistviewtext.h"
#include "tileviewtext.h"
#include "ui_mainwindow.h"
#include "constants.h"
#include "gamecontroller.h"

#include <QHBoxLayout>
#include <QLabel>


#include "graphicalgameview.h"
#include "textgameview.h"

class TextGameView;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFocus();


    GraphicalGameView graphicalGameView(*this);
    std::unique_ptr<GameView> gameView = std::make_unique<GraphicalGameView>(graphicalGameView);

    //Add here all extra views. For these the views should be made already

    auto textView = getTextView();

    gameController = GameController::getInstance();
    gameController->addNewView(std::move(textView));
    gameController->startGame(std::move(gameView));
    //connect(gameController, SIGNAL(gameOverSignal()), *this, SLOT(disableKeyInputs()));



}

MainWindow::~MainWindow()
{
    delete ui;
}


std::unique_ptr<TextGameView> MainWindow::getTextView()
{
    auto gameView = std::make_unique<TextGameView>(*this);
    //make the views:
    gameView->setHpView(std::make_shared<HealthPackViewText>());
    gameView->setProtView(std::make_shared<ProtagonistViewText>());
    gameView->setTileView(std::make_shared<TileViewText>());
    //for each type of enemy view we make a view!!
    std::vector<std::shared_ptr<EnemyViewInterface>> enemyViews;
    auto pev = std::make_shared<PEnemyViewText>();
    enemyViews.push_back(pev);
    auto ev = std::make_shared<EnemyViewText>();
    enemyViews.push_back(ev);
    gameView->setEnemyView(enemyViews);

    return gameView;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(gameController->getIsInputDisabled()) return;
    switch (event->key()) {
    case Qt::Key_Left:
        gameController->input(ArrowDirection::Left);
        break;
    case Qt::Key_Right:
        gameController->input(ArrowDirection::Right);
        break;
    case Qt::Key_Up:
        gameController->input(ArrowDirection::Up);
        break;
    case Qt::Key_Down:
        gameController->input(ArrowDirection::Down);
        break;
    case Qt::Key_S:
        gameController->switchView();
        break;
    default:
        QWidget::keyPressEvent(event);
        break;
    }
}

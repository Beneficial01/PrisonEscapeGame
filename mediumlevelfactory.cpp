#include "mediumlevelfactory.h"

#include "protagonistcontroller.h"
#include "protagonistmodel.h"

#include "TileH/tilemodel.h"
#include "TileH/tilecontroller.h"

#include "mediumlevel.h"
#include "HealthPackH/healthpackmodel.h"
#include "HealthPackH/healthpackcontroller.h"


#include "enemymodel.h"
#include "penemymodel.h"
#include "enemycontroller.h"

MediumLevelFactory::MediumLevelFactory()
{

}

std::shared_ptr<Level> MediumLevelFactory::createWorld()
{
    World w;
    w.createWorld(":/worldmap.png", 100,100);

    //tile
    auto tm = std::make_shared<TileModel>();
    tm->populateTileMap(w.getRows(), w.getCols(), w.getTiles());
    auto tc = std::make_shared<TileController>(tm);

    //protagonist:
    std::unique_ptr<Protagonist> protagonistPtr = w.getProtagonist();
    auto pm = std::make_shared<ProtagonistModel>(std::move(protagonistPtr));
    auto pc = std::make_shared<ProtagonistController>(pm);

    //healthPacks
    auto hpm = std::make_shared<HealthPackModel>(w.getHealthPacks(), 10);
    auto hpc = std::make_shared<HealthPackController>(hpm);

    //enemies models
    auto em = std::make_shared<EnemyModel>();
    em->setEnemyType("Enemy");
    auto pem = std::make_shared<PEnemyModel>();
    pem->setEnemyType("PEnemy");

    for (auto& enemy : w.getEnemies()) {
        if (auto pEnemy = dynamic_cast<PEnemy*>(enemy.get())) {
            pem->addEnemy(std::move(enemy));
        } else {
            em->addEnemy(std::move(enemy));
        }
    }

    //enemy controller
    auto ec = std::make_shared<EnemyController>();
    ec->init();
    ec->addEnemyModel(em);
    ec->addEnemyModel(pem);

    return std::make_shared<MediumLevel>(tc,  pc, hpc, ec);
}

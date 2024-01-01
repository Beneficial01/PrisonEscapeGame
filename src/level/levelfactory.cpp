#include "levelfactory.h"

LevelFactory::LevelFactory()
{

}

std::tuple<std::shared_ptr<TileController>, 
            std::shared_ptr<ProtagonistController>, 
            std::shared_ptr<HealthPackController>,
            std::shared_ptr<EnemyController> > LevelFactory::basicControllers(Prison &p)
{
    //tile
    auto tm = std::make_shared<TileModel>();
    tm->populateTileMap(p.getRows(), p.getCols(), p.getTiles());
    auto tc = std::make_shared<TileController>(tm);

    //protagonist:
    std::unique_ptr<Protagonist> protagonistPtr = p.getProtagonist();
    auto pm = std::make_shared<ProtagonistModel>(std::move(protagonistPtr));
    auto pc = std::make_shared<ProtagonistController>(pm);

    //healthPacks
    auto hpm = std::make_shared<HealthPackModel>(p.getHealthPacks(), 10);
    auto hpc = std::make_shared<HealthPackController>(hpm);

    //enemy controller
    auto ec = EnemyController::create(p.getEnemies(), p.getRows(), p.getCols());

    return std::make_tuple(tc, pc, hpc, ec);
}

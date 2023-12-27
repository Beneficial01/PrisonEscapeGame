#ifndef PENEMYVIEWGRAPHICAL_H
#define PENEMYVIEWGRAPHICAL_H
#include <memory>
#include "enemyviewinterface.h"
#include "penemymodel.h"
#include "penemyview.h"


class PEnemyViewGraphical: public EnemyViewInterface, public PEnemyView
{
public:
    PEnemyViewGraphical();
    
    /***
     * @brief render
     * This method renders all PEnemies in the PEnemyModel.
    */
    void render() override;

    /***
     * @brief render
     * This method renders a single PEnemy in the PEnemyModel.
     * @param row
     * @param col
    */
    void render(int x, int y) override;

    void clearView() override;
    //void update(int row, int col, bool used = true) override;

    void setPEnemyModel(const std::shared_ptr<PEnemyModel> &newPenemyModel) override;

private:
    std::shared_ptr<PEnemyModel> penemyModel;

    float zValue {1};
    int tileDim {50};

    std::map<std::pair<int, int>, std::shared_ptr<QGraphicsPixmapItem>> penemiesDisplayed;
    void displayPEnemy(int x, int y, bool defeated);
};

#endif // PENEMYVIEWGRAPHICAL_H

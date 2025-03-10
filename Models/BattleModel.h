#ifndef BATTLEMODEL_H
#define BATTLEMODEL_H

#include "AllEntities.h"

class BattleModel {
public:
    EntityModel *playerEntityModel;
    EntityModel *compEntityModel;
    bool player_turn;  

    BattleModel(EntityModel* player, EntityModel* opponent, bool turn)
        : playerEntityModel(player), compEntityModel(opponent), player_turn(turn) {}
};


#endif // BATTLEMODEL_H

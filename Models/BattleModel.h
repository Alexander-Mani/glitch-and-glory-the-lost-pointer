#ifndef BATTLEMODEL_H
#define BATTLEMODEL_H

#include "AllEntities.h"


class BattleModel {
    public:
    EntityModel *playerEntityModel;
    EntityModel *compEntityModel;
    bool player_turn;  

    BattleModel(EntityModel* player, EntityModel* opponent, bool player_turn)
        : playerEntityModel(player), compEntityModel(opponent), player_turn(player_turn) {}

    
    EntityModel *get_attacker();
    EntityModel *get_defender();

};


#endif // BATTLEMODEL_H

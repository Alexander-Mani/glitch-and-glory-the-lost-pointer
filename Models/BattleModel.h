#ifndef BATTLEMODEL_H
#define BATTLEMODEL_H

#include "AllEntities.h"

class BattleModel {
public:
    EntityModel *playerEntityModel;
    EntityModel *compEntityModel;
    bool player_turn;  
};


#endif // BATTLEMODEL_H

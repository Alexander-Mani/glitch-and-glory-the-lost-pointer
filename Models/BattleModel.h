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

    std::vector<std::string> get_battle_actions() const {
        return {"A", "H", "F", "B", "S"};
    }
    // BattleModel(EntityModel* player, EntityModel* opponent, bool player_turn)
    //     : playerEntityModel(player), compEntityModel(opponent), player_turn(player_turn) {}

    
    EntityModel *get_attacker();

    EntityModel *get_defender();

    // bool is_finished();

    // string BattleModel::fetch_results();

};


#endif // BATTLEMODEL_H

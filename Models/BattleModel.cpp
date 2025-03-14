#include "BattleModel.h"



EntityModel* BattleModel::get_attacker() {
    return this->player_turn ? this->playerEntityModel : this->compEntityModel;
}

EntityModel* BattleModel::get_defender() {
    return this->player_turn ? this->compEntityModel : this->playerEntityModel;
}

// BattleLogic.h
#ifndef BATTLELOGIC_H
#define BATTLELOGIC_H

#include "../Models/BattleModel.h"

#include <iostream>

using namespace std;

class BattleLogic{
    public:
    void handle_battle_action(BattleModel* battle_model, string action);
    void handle_turn(BattleLogic* battle_model);
    void handle_computer_action(BattleModel* battle_model);
    bool battle_over(BattleLogic* battle_model);


};

#endif // BATTLELOGIC_H

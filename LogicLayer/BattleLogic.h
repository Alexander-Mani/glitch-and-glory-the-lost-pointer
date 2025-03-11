// BattleLogic.h
#ifndef BATTLELOGIC_H
#define BATTLELOGIC_H

#include "../Models/BattleModel.h"

#include <iostream>

using namespace std;

class BattleLogic{
    public:
    void handle_battle_action(BattleModel* battle_model, string action);

};

#endif // BATTLELOGIC_H

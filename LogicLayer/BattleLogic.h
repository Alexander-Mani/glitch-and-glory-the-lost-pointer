// BattleLogic.h
#ifndef BATTLELOGIC_H
#define BATTLELOGIC_H

#include <iostream>

#include "../Models/AllEntities.h"
#include "../Models/BattleModel.h"

using namespace std;

class BattleLogic{
public:
    vector<string> attack_options;

    BattleLogic();

    // bool perform_attack();
    int calculate_damage(EntityModel* attacker, EntityModel* defender);
    void perform_attack(EntityModel* attacker, EntityModel* defender);
};

#endif // BATTLELOGIC_H


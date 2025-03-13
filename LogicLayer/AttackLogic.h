#ifndef ATTACKLOGIC_H
#define ATTACKLOGIC_H

#include "../Models/BattleModel.h"

#include "EntityLogic.h"

class AttackLogic {
public:
    static constexpr int ATTACK_NORMAL = 1;
    static constexpr int ATTACK_HEAVY = 2;
    static constexpr int ATTACK_CRIT = 3;
    static constexpr int ATTACK_SPECIAL = 4;

    EntityLogic *entityLogic;

    AttackLogic(EntityLogic *entityLogic);

    // Performs a normal attack on the defender.
    int attack(BattleModel* battleModel, int attack_type);

    // Performs a heavy attack on the defender.
    int heavy_attack(BattleModel* battleModel);

    // Calculates the damage dealt during an attack.
    int calculate_damage(BattleModel* battleModel, int attack_type);

    // Checks if the attack hits based on the attacker's atk and defenders evade
    bool enemy_hit(BattleModel* battleModel, int attack_type);

    // Checks if the attack hits based on the attacker's weapon hit rate.
    bool enemy_crit_hit(BattleModel* battleModel, int attack_type);
};

#endif // ATTACKLOGIC_H
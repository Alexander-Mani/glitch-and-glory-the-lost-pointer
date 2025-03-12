#ifndef ATTACKLOGIC_H
#define ATTACKLOGIC_H

#include "../Models/BattleModel.h"

class AttackLogic {
public:
    // Performs a normal attack on the defender.
    int attack(BattleModel* battleModel);

    // Performs a heavy attack on the defender.
    int heavy_attack(BattleModel* battleModel);

    // Calculates the damage dealt during an attack.
    int calculate_damage(BattleModel* battleModel);

    // (Optional) You can also expose a method for weapon-specific damage.
    int calculate_weapon_damage(BattleModel* battleModel);

private:
    // Checks if the attack hits based on the attacker's weapon hit rate.
    bool enemy_hit(BattleModel* battleModel, int percentage_decrease = 0);
};

#endif // ATTACKLOGIC_H
#include "AttackLogic.h"
#include "../Models/BattleModel.h"
#include "../Models/AllEntities.h"  // For get_attacker() and get_defender()
#include <cstdlib>
#include <cassert>

int AttackLogic::attack(BattleModel* battleModel) {
    // Check if the attack hits
    if (!enemy_hit(battleModel)) {
        return 0; // Attack missed, no damage dealt.
    }
    
    int calc_damage = calculate_damage(battleModel);
    if (calc_damage == 0) {
        return 0;
    }
    
    // Decrease defender's HP.
    battleModel->get_defender()->decrease_hp(calc_damage);
    return calc_damage;
}

int AttackLogic::heavy_attack(BattleModel* battleModel) {
    // For heavy attacks, you might want to include additional logic (e.g. damage multiplier)
    if (!enemy_hit(battleModel)) {
        return 0;
    }
    
    int calc_damage = calculate_damage(battleModel);
    if (calc_damage == 0) {
        return 0;
    }
    
    battleModel->get_defender()->decrease_hp(calc_damage);
    return calc_damage;
}

int AttackLogic::calculate_damage(BattleModel* battleModel) {
    // Simple damage calculation: attacker's weapon damage minus defender's defence.
    auto attacker = battleModel->get_attacker();
    auto defender = battleModel->get_defender();
    int damage = (attacker->get_atk()) - defender->get_def();
    return (damage < 0) ? 0 : damage;
}

int AttackLogic::calculate_weapon_damage(BattleModel* battleModel) {
    // You could have an alternative calculation here; for now we use the same logic.
    return calculate_damage(battleModel);
}

bool AttackLogic::enemy_hit(BattleModel* battleModel, int percentage_decrease) {
    auto attacker = battleModel->get_attacker();
    auto weapon = attacker->get_weapon();
    int *weapon_hit_rate = weapon->get_hit_rate();
    
    // Generate a random number between 0 and 100.
    int random_num = rand() % 101;
    
    // Check if the hit rate (optionally modified by percentage_decrease) is met.
    return random_num <= (*weapon_hit_rate - percentage_decrease);
}

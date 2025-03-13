#include "AttackLogic.h"
#include "../Models/BattleModel.h"
#include "../Models/AllEntities.h"  // For get_attacker() and get_defender()
#include <cstdlib>
#include <cassert>

#include "../UILayer/IOHandler.h"

AttackLogic::AttackLogic(EntityLogic *entityLogic){
    this->entityLogic = entityLogic;
}

int AttackLogic::attack(BattleModel* battleModel, int attack_type) {
    // If attack_type 
    // if(this->enemy_crit_hit(battleModel, attack_type)){
    //     attack_type = this->ATTACK_CRIT;
    // }
    // Check if the attack hits
    if (!enemy_hit(battleModel, attack_type)) {
        return 0; // Attack missed, no damage dealt.
    }
    
    int calc_damage = calculate_damage(battleModel, attack_type);
    assert(calc_damage >= 0); // This should never be 0 or lower
    
    // Decrease defender's HP.
    battleModel->get_defender()->decrease_hp(calc_damage);
    return calc_damage;
}

int AttackLogic::calculate_damage(BattleModel* battleModel, int attack_type) {
    // Simple damage calculation: attacker's weapon damage minus defender's defence.
//<<<<<<< HEAD
//    auto attacker = battleModel->get_attacker();
//    auto defender = battleModel->get_defender();
//    int damage = (attacker->get_atk()) - defender->get_def();
//    return (damage < 0) ? 0 : damage;
//=======
    EntityModel*  attacker = battleModel->get_attacker();
    EntityModel*  defender = battleModel->get_defender();
    int dmg_dealt = attacker->get_atk() - defender->get_def();

    // Make sure damage doesn't become negative
    if (dmg_dealt > 0 && attack_type==this->ATTACK_HEAVY){
        dmg_dealt = dmg_dealt * 1.5;
    } else if (dmg_dealt > 0 && attack_type==this->ATTACK_CRIT){
        dmg_dealt = dmg_dealt * 2;
    }

    return dmg_dealt;
}

bool AttackLogic::enemy_hit(BattleModel* battleModel, int attack_type) {
    int hit_chance;

    if(attack_type == this->ATTACK_CRIT){
        return true;
    }
    
    // Ensure only Normal or Heavy attacks are used.
    assert(attack_type == this->ATTACK_NORMAL || attack_type == this->ATTACK_HEAVY);

    if(attack_type == this->ATTACK_NORMAL)
        hit_chance = this->entityLogic->get_hit_chance_normal(battleModel);
    else if(attack_type == this->ATTACK_HEAVY)
        hit_chance = this->entityLogic->get_hit_chance_heavy(battleModel);
    
    assert(hit_chance > 0); // The hit chance should never be 0 or less
    
    // Generate a random number between 0 and 100 (inclusive)
    int random_number = rand() % 101;
    
    // If the random number is lower than the hit chance, return true.
    return (random_number < hit_chance);
}

//<<<<<<< HEAD
//bool AttackLogic::enemy_hit(BattleModel* battleModel, int percentage_decrease) {
//    auto attacker = battleModel->get_attacker();
//    auto weapon = attacker->get_weapon();
//    int *weapon_hit_rate = weapon->get_hit_rate();
//    
//    // Generate a random number between 0 and 100.
//    int random_num = rand() % 101;
//    
//    // Check if the hit rate (optionally modified by percentage_decrease) is met.
//    return random_num <= (*weapon_hit_rate - percentage_decrease);
//}
//=======
bool AttackLogic::enemy_crit_hit(BattleModel* battleModel, int attack_type) {
    // Only allow normal or heavy attacks
    if (attack_type != ATTACK_NORMAL && attack_type != ATTACK_HEAVY)
        return false;

    EntityModel* attacker = battleModel->get_attacker();
    EntityModel* defender = battleModel->get_defender();

    // Base crit chance from the attacker's inherent stat
    int base_crit = attacker->get_crit();

    // Calculate hit chance similarly to enemy_hit()
    int atk = attacker->get_atk();
    int defender_evade = defender->get_evade();
    int hit_chance = (atk * 100) / (atk + defender_evade);

    // Use (hit_chance - 50) as a bonus or penalty.
    // If hit_chance > 50, attacker is relatively strong compared to defender,
    // which increases the crit chance. If below 50, it decreases the crit chance.
    int effective_crit = base_crit + (hit_chance - 50);

    // Clamp effective crit chance to be between 0 and 100.
    if (effective_crit < 0) effective_crit = 0;
    if (effective_crit > 100) effective_crit = 100;

    // Generate a random number from 0 to 100 (inclusive)
    int random_value = rand() % 101;

    // Return true if the random value is less than the effective crit chance.
    return (random_value < effective_crit);
}

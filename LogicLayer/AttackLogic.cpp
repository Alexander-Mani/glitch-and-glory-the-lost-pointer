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
    EntityModel*  attacker = battleModel->get_attacker();
    EntityModel*  defender = battleModel->get_defender();
    int dmg_dealt = attacker->get_atk() - defender->get_def();

    // Make sure damage doesn't become negative
    if (dmg_dealt > 0 && attack_type==this->ATTACK_HEAVY){
        dmg_dealt = dmg_dealt * 1.5;
    }

    return dmg_dealt;
}

bool AttackLogic::enemy_hit(BattleModel* battleModel, int attack_type) {
    int hit_chance;
    
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
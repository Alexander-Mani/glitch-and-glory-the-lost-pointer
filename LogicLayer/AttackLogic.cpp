#include "AttackLogic.h"
#include "../Models/BattleModel.h"
#include "../Models/AllEntities.h" // For get_attacker() and get_defender()
#include <cstdlib>
#include <cassert>

#include "../UILayer/IOHandler.h"

AttackLogic::AttackLogic(EntityLogic *entityLogic)
{
    this->entityLogic = entityLogic;
}

int AttackLogic::attack(BattleModel *battleModel, int attack_type)
{
    // Check if the attack hits
    if (!enemy_hit(battleModel, attack_type))
    {
        return 0; // Attack missed, no damage dealt.
    }

    int calc_damage = calculate_damage(battleModel, attack_type);

    // Decrease defender's HP.
    battleModel->get_defender()->decrease_hp(calc_damage);
    return calc_damage;
}

int AttackLogic::calculate_damage(BattleModel *battleModel, int attack_type)
{
    int attacker_atk;
    int defender_def;
    int defender_max_hp;
    EntityModel *attacker = battleModel->get_attacker();
    EntityModel *defender = battleModel->get_defender();

    attacker_atk = attacker->get_atk();
    defender_def = defender->get_def();
    defender_max_hp = defender->get_max_hp();

    int dmg_dealt = (attacker_atk * 50 / defender_def) * 0.3;

    // Make sure damage doesn't become negative
    if (dmg_dealt > 0 && attack_type == this->ATTACK_HEAVY)
    {
        dmg_dealt *= 1.5;
    }
    else if (dmg_dealt > 0 && attack_type == this->ATTACK_CRIT)
    {
        dmg_dealt *= 2;
    }

    if (dmg_dealt < 10)
    {
        dmg_dealt = 12 + (rand() % 7 - 3);
    }
    else if (dmg_dealt > (defender_max_hp * 0.8))
    {
        dmg_dealt = (defender_max_hp * 0.8) + (rand() % 7 - 3); // Generates a value in range [89, 95]
    }

    return dmg_dealt;
}

bool AttackLogic::enemy_hit(BattleModel *battleModel, int attack_type)
{
    int hit_chance;

    if (attack_type == this->ATTACK_CRIT)
    {
        return true;
    }

    // Ensure only Normal or Heavy attacks are used.
    assert(attack_type == this->ATTACK_NORMAL || attack_type == this->ATTACK_HEAVY);

    if (attack_type == this->ATTACK_NORMAL)
        hit_chance = this->entityLogic->get_hit_chance_normal(battleModel);
    else if (attack_type == this->ATTACK_HEAVY)
        hit_chance = this->entityLogic->get_hit_chance_heavy(battleModel);

    assert(hit_chance > 0); // The hit chance should never be 0 or less

    // Generate a random number between 0 and 100 (inclusive)
    int random_number = rand() % 101;

    // If the random number is lower than the hit chance, return true.
    return (random_number < hit_chance);
}

bool AttackLogic::enemy_crit_hit(BattleModel *battleModel, int attack_type)
{
    bool normal_attack_hit;
    // Only allow normal or heavy attacks
    if (attack_type == ATTACK_NORMAL || attack_type == ATTACK_HEAVY)
    {
        normal_attack_hit = this->enemy_hit(battleModel, attack_type);
    }
    if (!normal_attack_hit)
        return false;

    EntityModel *attacker = battleModel->get_attacker();

    int random_value = rand() % 101;

    return (random_value < attacker->get_crit());
}

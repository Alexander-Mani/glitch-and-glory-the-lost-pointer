#include "AttackLogic.h"
#include "../Models/BattleModel.h"
#include "../Models/AllEntities.h"  // For get_attacker() and get_defender()
#include <cstdlib>
#include <cassert>

#include "../UILayer/IOHandler.h"


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

// int AttackLogic::heavy_attack(BattleModel* battleModel) {
//     // For heavy attacks, you might want to include additional logic (e.g. damage multiplier)
//     if (!enemy_hit(battleModel, this->ATTACK_HEAVY)) {
//         return 0;
//     }
    
//     int calc_damage = calculate_heavy_damage(battleModel);
//     if (calc_damage == 0) {
//         return 0;
//     }
    
//     battleModel->get_defender()->decrease_hp(calc_damage);
//     return calc_damage;
// }

int AttackLogic::calculate_damage(BattleModel* battleModel, int attack_type) {
    int ret_dmg;
    // Simple damage calculation: attacker's weapon damage minus defender's defence.
    EntityModel*  attacker = battleModel->get_attacker();
    EntityModel*  defender = battleModel->get_defender();
    int damage = attacker->get_atk() - defender->get_def();

    // Make sure damage doesn't become negative
    (damage < 0) ? ret_dmg=0 : ret_dmg=damage;

    // cout << "\n\n|---- DAMAGE DEALT ----|\n" << endl;
    // (attack_type == this->ATTACK_NORMAL) ? cout << "|--   NORMAL ATTACK   --|\n" : cout << "|--  OTHER ATTACK   --|\n";
    // cout << ret_dmg << endl;
    // cout << "|----------------------|\n" << endl;

    // IOHandler::glitch_sleep_static(5);


    return ret_dmg;
}

// int AttackLogic::calculate_heavy_damage(BattleModel* battleModel) {
//     // Simple damage calculation: attacker's weapon damage minus defender's defence.
//     EntityModel*  attacker = battleModel->get_attacker();
//     EntityModel*  defender = battleModel->get_defender();
//     int damage = *(attacker->get_weapon()->get_damage()) - defender->get_def();
//     return (damage < 0) ? 0 : damage;
// }


bool AttackLogic::enemy_hit(BattleModel* battleModel, int attack_type) {
    EntityModel *attacker = battleModel->get_attacker();
    EntityModel *defender = battleModel->get_defender();
    int atk = attacker->get_atk();
    int def_evade = defender->get_evade();

    // Modify stats for heavy attacks.
    if (attack_type == this->ATTACK_HEAVY) {
        atk = static_cast<int>(atk * 1.5);
        def_evade = static_cast<int>(def_evade * 1.2);
    }
    

    // Calculate hit chance as a percentage.
    int hit_chance = (atk * 100) / (atk + def_evade);
    
    // Generate a random number from 0 to 99.
    int random_num = rand() % 100;

    cout << "\n\n|---- HIT CHANCE ----|\n" << endl;
    (attack_type == this->ATTACK_NORMAL) ? cout << "|--   NORMAL ATTACK   --|\n" : cout << "|--  OTHER ATTACK   --|\n";
    cout << "|-- hit_chance: " << hit_chance << endl;
    cout << "|-- random_num: " << random_num << endl;
    cout << "|----------------------|\n" << endl;

    IOHandler::glitch_sleep_static(2);
    
    return random_num < hit_chance;
}
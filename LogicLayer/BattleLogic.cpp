#include "BattleLogic.h"
#include <iostream>

#include <cstdlib>

#include <cassert>


BattleLogic::BattleLogic() {
    this->attack_options = {"weapon_attack", "rest"};
    // Constructor left empty for simplicity.
}

//======== PUBLIC METHODS ========//

string BattleLogic::perform_action(string action, BattleModel* battleModel) {
    // EntityModel *defender = battleModel->get_defender();
    
    if (action == "weapon_attack"){
        string msg;
        bool attack_successful = this->attack(battleModel);
        EntityModel *attacker = battleModel->get_attacker();
        WeaponModel *attacker_weapon = attacker->get_weapon();

        if(!attack_successful){
            this->toggle_turn(battleModel);
            return *attacker_weapon->get_fail_msg();
        } else {
            this->toggle_turn(battleModel);
            return *attacker_weapon->get_success_msg();
        }
    }
    else if (action == "rest"){
        this->toggle_turn(battleModel);
        return "Resting for one round";
    } else {
        cout << "Something went wrong in BattleLogic::perform_action...";
        assert(action != "weapon_attack" && action != "rest");
        return "Something went wrong in BattleLogic::perform_action...";
    }
}

void BattleLogic::toggle_turn(BattleModel* battleModel){
    battleModel->player_turn = !battleModel->player_turn;
}


//======== PRIVATE METHODS ========//

bool BattleLogic::attack(BattleModel* battleModel){
    bool enemy_hit;
    
    // Check if you will hit the enemy
    enemy_hit = this->_enemy_hit(battleModel);

    // If you did not hit the enemy, then return false, indicating that you missed
    if(!enemy_hit){ return false; }
    
    int calc_damage = this->calculate_damage(battleModel);
    if(calc_damage == 0){
        return false;
    }

    EntityModel *defender = battleModel->get_defender();
    
    //===================== DEBUG PRINTS START =====================//
    cout << "\n\n\n|---------------------------------|" << endl;
    cout << "|     -=-= BEFORE DAMAGE -=-=     |" << endl;
    cout << "|---------------------------------|" << endl;
    cout << "| Defender Defence: " << battleModel->get_defender()->get_def() << endl;
    cout << "| Attacker Atk: " << battleModel->get_attacker()->get_atk() << endl;
    cout << "| Attacker Weapon Atk: " << *battleModel->get_attacker()->get_weapon()->get_damage() << endl;
    cout << "| Attacker Weapon chance of hit: " << *battleModel->get_attacker()->get_weapon()->get_hit_rate() << "%" << endl;
    cout << "|---------------------------------|" << endl;

    defender->display_stats();

    //===================== DEBUG PRINTS STOP ======================//
    
    
    
    defender->take_damage(calc_damage);
    
    //===================== DEBUG PRINTS START =====================//
    cout << "\n\n\n|---------------------------------|" << endl;
    cout << "|     -=-= AFTER DAMAGE -=-=      |" << endl;
    cout << "|---------------------------------|" << endl;
    cout << "| Total damage this turn: " << calc_damage << endl;
    cout << "|---------------------------------|" << endl;
    
    defender->display_stats();
    //===================== DEBUG PRINTS STOP ======================//
    
    return true;
}

int BattleLogic::calculate_weapon_damage(BattleModel* battleModel) {
    // Fetch current attacker and defender
    EntityModel *attacker = battleModel->get_attacker();
    EntityModel *defender = battleModel->get_defender();
    
    // Simple damage calculation: attacker's attack minus defender's defense.
    int damage = *attacker->get_weapon()->get_damage() - defender->get_def();
    
    // Make sure damage is not negative.
    if (damage < 0) {
        damage = 0;
    }
    
    return damage;
}

int BattleLogic::calculate_damage(BattleModel* battleModel) {
    // Fetch current attacker and defender
    EntityModel *attacker = battleModel->get_attacker();
    EntityModel *defender = battleModel->get_defender();
    
    // Simple damage calculation: attacker's attack minus defender's defense.
    int damage = attacker->get_atk() - defender->get_def();
    
    // Make sure damage is not negative.
    if (damage < 0) {
        damage = 0;
    }
    
    return damage;
}

bool BattleLogic::_enemy_hit(BattleModel* battleModel){
    EntityModel *attacker = battleModel->get_attacker();
    WeaponModel *attacker_weapon = attacker->get_weapon();
    int *weapon_hit_rate = attacker_weapon->get_hit_rate();
    

    // Checks if random number from 0-100 is lower than or equal to the percentage (WeaponModel.hit_rate of the attacker's weapon)
    int random_num = rand() % 101;


    // Nice print for debugging purposes
    // cout << "\n\n|------- Print For Debug Start -------|\n|\n| random_num: " << random_num << "\n|\n| *weapon_hit_rate: " << *weapon_hit_rate << "\n|" << endl << "|------- Print For Debug Stop --------|" << endl;
    
    if (random_num <= *weapon_hit_rate){
        return true;
    }

    return false;
}
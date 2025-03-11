#include "BattleLogic.h"
#include "../Models/BattleModel.h"

#include <iostream>
#include <vector>
#include <random>

#include <cstdlib>

#include <cassert>

string BattleLogic::handle_battle_action(BattleModel* battleModel ,string action){
    string ret_msg;
    if (action == "A"){
        std::cout << "Performing Normal Attack" << std::endl;
        // string msg;
        bool attack_successful = this->attack(battleModel);
        EntityModel *attacker = battleModel->get_attacker();
        WeaponModel *attacker_weapon = attacker->get_weapon();

        if(!attack_successful){
            ret_msg = *attacker_weapon->get_fail_msg();
        } else {
            ret_msg = *attacker_weapon->get_success_msg();
        }
        // Implement normal attack logic here
        // Example: battle.playerEntityModel->attack(battle.compEntityModel);
       
    } else if (action == "H") {
        std::cout << "Heavy attack has yet to be implemented! Method will be called recursively for you to try again." << std::endl;
        return this->handle_battle_action(battleModel, action); // Temporary solution until feature has been implemented
        
        // Implement heavy attack logic here
        // Example: battle.playerEntityModel->heavyAttack(battle.compEntityModel);
        
    } else if (action == "F") {
        std::cout << "Fleeing has yet to be implemented! Method will be called recursively for you to try again." << std::endl;
        return this->handle_battle_action(battleModel, action); // Temporary solution until feature has been implemented
        
        // Implement flee logic here
        // Example: bool escaped = battle.playerEntityModel->attemptFlee();
        
    } else if (action == "B") {
        std::cout << "Bribing has yet to be implemented! Method will be called recursively for you to try again." << std::endl;
        return this->handle_battle_action(battleModel, action); // Temporary solution until feature has been implemented
        
        // Implement bribe logic here
        // Example: bool bribed = battle.playerEntityModel->attemptBribe(battle.compEntityModel);
        
    } else if (action == "S") {
        std::cout << "Special Ability has yet to be implemented! Method will be called recursively for you to try again." << std::endl;
        return this->handle_battle_action(battleModel, action); // Temporary solution until feature has been implemented
        
        // Implement special ability logic here
        // Example: battle.playerEntityModel->useSpecialAbility(battle.compEntityModel);
        
    } else {
        // This shouldn"t be reached due to the validation check above
        std::cout << "Unhandled action: " << action << std::endl;
        assert(false); // You fucked up, you should not be here.
    }
    this->toggle_turn(battleModel);
    return ret_msg;

}

void BattleLogic::handle_turn(BattleLogic* battleModel){
    (void)battleModel;
}

void BattleLogic::handle_computer_action(BattleModel* battleModel){
    (void)battleModel;
    vector<string> action_list = battleModel->get_battle_actions(); 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, action_list.size() - 1);
    
    int random_index = distr(gen);

    string action = action_list[random_index];
    if (action == "F") action = "A";
    this->handle_battle_action(battleModel, action);


} 

bool BattleLogic::battle_over(BattleLogic* battleModel){
    return true;
}
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
    // cout << "\n\n\n|---------------------------------|" << endl;
    // cout << "|     -=-= BEFORE DAMAGE -=-=     |" << endl;
    // cout << "|---------------------------------|" << endl;
    // cout << "| Defender Defence: " << battleModel->get_defender()->get_def() << endl;
    // cout << "| Attacker Atk: " << battleModel->get_attacker()->get_atk() << endl;
    // cout << "| Attacker Weapon Atk: " << *battleModel->get_attacker()->get_weapon()->get_damage() << endl;
    // cout << "| Attacker Weapon chance of hit: " << *battleModel->get_attacker()->get_weapon()->get_hit_rate() << "%" << endl;
    // cout << "|---------------------------------|" << endl;

    // defender->display_stats();
    //===================== DEBUG PRINTS STOP ======================//

    
    
    
    defender->take_damage(calc_damage);
    
    //===================== DEBUG PRINTS START =====================//
    // cout << "\n\n\n|---------------------------------|" << endl;
    // cout << "|     -=-= AFTER DAMAGE -=-=      |" << endl;
    // cout << "|---------------------------------|" << endl;
    // cout << "| Total damage this turn: " << calc_damage << endl;
    // cout << "|---------------------------------|" << endl;
    
    // defender->display_stats();
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
    int damage = *attacker->get_weapon()->get_damage() - defender->get_def();
    // int damage = attacker->get_atk() - defender->get_def();
    
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

bool BattleLogic::game_over(BattleModel* battleModel){
    EntityModel *attacker = battleModel->get_attacker();
    EntityModel *defender = battleModel->get_defender();

    int attacker_hp = attacker->get_hp();
    int defender_hp = defender->get_hp();

    if (attacker_hp == 0 || defender_hp == 0){
        return true;
    }
    return false;
}

string BattleLogic::game_over_msg(BattleModel* battleModel){
    EntityModel *player;
    EntityModel *opponent;
    if(battleModel->player_turn){
        player = battleModel->get_attacker();
        opponent = battleModel->get_defender();
    } else {
        opponent = battleModel->get_attacker();
        player = battleModel->get_defender();
    }
    

    int player_hp = player->get_hp();
    int opponent_hp = opponent->get_hp();

    if (player_hp == 0 && opponent_hp == 0){
        return "You heard it here first, its a tie somehow, should not be possible rly if u ask me.";
    } else if (player_hp == 0 && opponent_hp != 0){
        return "You lost homie, kind funny if u ask me ;)";
    } else if (player_hp != 0 && opponent_hp == 0){
        return "You got lucky...";
    } else {
        return "Error -1 in game_over_msg";
    }
    
}

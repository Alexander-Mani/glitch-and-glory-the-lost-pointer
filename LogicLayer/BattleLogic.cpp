#include "BattleLogic.h"
#include "AttackLogic.h"
#include "../Models/BattleModel.h"

#include <iostream>
#include <vector>
#include <random>

#include <cstdlib>

#include <cassert>



BattleLogic::BattleLogic(AttackLogic *attackLogic){
    this->attack_options = {"weapon_attack", "rest"};

    this->attackLogic = attackLogic;
}



string BattleLogic::handle_battle_action(BattleModel* battleModel ,string action){
    string ret_msg;

    if (action == "A"){
        // string msg;
        int damage_done = this->attackLogic->attack(battleModel, AttackLogic::ATTACK_NORMAL);
        if(damage_done == 0){
            battleModel->player_turn ? ret_msg = "You missed the enemy!" : ret_msg = "NORMAL ATTACK: The enemy missed, your HP was not affected.";
        } 
        else {
            battleModel->player_turn ? ret_msg = "You hit the enemy for " + to_string(damage_done) + "!" : ret_msg = ("NORMAL ATTACK: The hit you with a normal attack, you lost " + to_string(damage_done) + "HP");
        }
        
    } else if (action == "H") {
        int damage_done = this->attackLogic->attack(battleModel, AttackLogic::ATTACK_HEAVY);

        if(damage_done == 0){
            battleModel->player_turn ? ret_msg = "You missed the enemy!" : ret_msg = "HEAVY ATTACK: The enemy missed, your HP was not affected.";    
        } 
        else {
            battleModel->player_turn ? ret_msg = "You hit the enemy for " + to_string(damage_done) + "!" : ret_msg = ("HEAVY ATTACK: The hit you with a normal attack, you lost " + to_string(damage_done) + "HP");
        }

    } else if (action == "F") {
        return "Fleeing has yet to be implemented!";
    } 
    else if (action == "B") {
        return "Bribing has yet to be implemented!";
        
        // Implement bribe logic here
        // Example: bool bribed = battle.playerEntityModel->attemptBribe(battle.compEntityModel);
        
    } else if (action == "S") {
        EntityModel *attacker = battleModel->get_attacker();
        int atk_magic_pts = attacker->get_magic();
        if(atk_magic_pts < 10)
            return "You need 10 hacking points to perform a Special Ability Attack.";
        
        

        vector<string> random_actions = {"", ""};
        return "Special Ability has yet to be implemented!";
        
        // Implement special ability logic here
        // Example: battle.playerEntityModel->useSpecialAbility(battle.compEntityModel);
        
    } else {
        // This shouldn"t be reached due to the validation check above
        return "Unhandled action: " + action;
        assert(false); // You fucked up, you should not be here.
    }
    this->toggle_turn(battleModel);
    return ret_msg;

}

void BattleLogic::handle_turn(BattleLogic* battleModel){
    (void)battleModel;
}

string BattleLogic::handle_computer_action(BattleModel* battleModel){
    (void)battleModel;
    vector<string> action_list = battleModel->get_battle_actions(); 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, action_list.size() - 1);
    
    int random_index = distr(gen);

    string action = action_list[random_index];
    if (action == "F") action = "A";
    // this->handle_battle_action(battleModel, action);

    return action;    
} 

// bool BattleLogic::battle_over(BattleLogic* battleModel){
//     return true;
// }

//======== PUBLIC METHODS ========//

void BattleLogic::toggle_turn(BattleModel* battleModel){
    battleModel->player_turn = !battleModel->player_turn;
}


//======== PRIVATE METHODS ========//

// int BattleLogic::attack(BattleModel* battleModel){
//     bool enemy_hit;
    
//     // Check if you will hit the enemy
//     enemy_hit = this->_enemy_hit(battleModel);

//     // If you did not hit the enemy, then return false, indicating that you missed
//     if(!enemy_hit){ return false; }
    
//     int calc_damage = this->calculate_damage(battleModel);
//     if(calc_damage == 0){
//         return 0;
//     }
    
//     EntityModel *defender = battleModel->get_defender();
    

//     defender->decrease_hp(calc_damage);
    
//     return calc_damage;
// }

// int BattleLogic::heavy_attack(BattleModel* battleModel){
//     bool enemy_hit;
    
//     // Check if you will hit the enemy
//     enemy_hit = this->_enemy_hit(battleModel);

//     // If you did not hit the enemy, then return false, indicating that you missed
//     if(!enemy_hit){ return false; }
    
//     int calc_damage = this->calculate_damage(battleModel);
//     if(calc_damage == 0){
//         return 0;
//     }

//     EntityModel *defender = battleModel->get_defender();
    

//     defender->decrease_hp(calc_damage);
    
//     return calc_damage;
// }

// int BattleLogic::calculate_weapon_damage(BattleModel* battleModel) {
//     // Fetch current attacker and defender
//     EntityModel *attacker = battleModel->get_attacker();
//     EntityModel *defender = battleModel->get_defender();
    
//     // Simple damage calculation: attacker's attack minus defender's defense.
//     int damage = *attacker->get_weapon()->get_damage() - defender->get_def();
    
//     // Make sure damage is not negative.
//     if (damage < 0) {
//         damage = 0;
//     }
    
//     return damage;
// }

// int BattleLogic::calculate_damage(BattleModel* battleModel) {
//     // Fetch current attacker and defender
//     EntityModel *attacker = battleModel->get_attacker();
//     EntityModel *defender = battleModel->get_defender();
    
//     // Simple damage calculation: attacker's attack minus defender's defense.
//     int damage = *attacker->get_weapon()->get_damage() - defender->get_def();
//     // int damage = attacker->get_atk() - defender->get_def();
    
//     // Make sure damage is not negative.
//     if (damage < 0) {
//         damage = 0;
//     }
    
//     return damage;
// }

// bool BattleLogic::_enemy_hit(BattleModel* battleModel, int percentage_decrease){
//     EntityModel *attacker = battleModel->get_attacker();
//     WeaponModel *attacker_weapon = attacker->get_weapon();
//     int *weapon_hit_rate = attacker_weapon->get_hit_rate();
    

//     // Checks if random number from 0-100 is lower than or equal to the percentage (WeaponModel.hit_rate of the attacker's weapon)
//     int random_num = rand() % 101;


//     // Nice print for debugging purposes
//     // cout << "\n\n|------- Print For Debug Start -------|\n|\n| random_num: " << random_num << "\n|\n| *weapon_hit_rate: " << *weapon_hit_rate << "\n|" << endl << "|------- Print For Debug Stop --------|" << endl;
    
//     if (random_num <= *weapon_hit_rate){
//         return true;
//     }

//     return false;
// }

bool BattleLogic::battle_over(BattleModel* battleModel){
    EntityModel *attacker = battleModel->get_attacker();
    EntityModel *defender = battleModel->get_defender();

    int attacker_hp = attacker->get_hp();
    int defender_hp = defender->get_hp();

    if (attacker_hp == 0 || defender_hp == 0){
        return true;
    }
    return false;
}

string BattleLogic::battle_over_msg(BattleModel* battleModel){
    // Verify that the game has been won
    bool game_won = this->battle_over(battleModel);
    if(!game_won) return "You have not won yet...";

    // Generate game over message 
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
        return "Error -1 in battle_over_msg";
    }
    
}

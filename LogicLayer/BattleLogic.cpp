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
    int attack_type;

    if (action == "A"){
        string atk_prefix;

        // Check if attack will be crit (done in BattleLogic to get prefix str)
        bool crit_hit = this->attackLogic->enemy_crit_hit(battleModel, AttackLogic::ATTACK_NORMAL);

        // Assign attack_type to pass into attack method
        (crit_hit) ? attack_type = AttackLogic::ATTACK_CRIT : attack_type = AttackLogic::ATTACK_NORMAL;

        // Fetches damage from AttackLogic
        int damage_done = this->attackLogic->attack(battleModel, attack_type);

        if (crit_hit)
            atk_prefix = "CRITICAL HIT: ";
        else if (damage_done > 0)
            atk_prefix = "NORMAL ATTACK: ";
        else if (damage_done == 0)
            atk_prefix = "NORMAL ATTACK EVADED: ";
        else
            assert(false); // This should never be true


        
        // (crit_hit) ? atk_prefix = "CRITICAL HIT: " : atk_prefix = "NORMAL HIT:";

        ret_msg = atk_prefix;

        if(damage_done == 0){
            battleModel->player_turn ? ret_msg += "You missed the enemy!" : ret_msg += "The enemy missed, your HP was not affected.";
        } 
        else {
            battleModel->player_turn ? ret_msg += "You hit the enemy for " + to_string(damage_done) + "!" : ret_msg += ("The enemy hit you with a normal attack, you lost " + to_string(damage_done) + "HP");
        }
        
    } else if (action == "H") {
        string atk_prefix;

        // Check if attack will be crit (done in BattleLogic to get prefix str)
        bool crit_hit = this->attackLogic->enemy_crit_hit(battleModel, AttackLogic::ATTACK_NORMAL);

        // Assign attack_type to pass into attack method
        (crit_hit) ? attack_type = AttackLogic::ATTACK_CRIT : attack_type = AttackLogic::ATTACK_NORMAL;

        // Fetches damage from AttackLogic
        int damage_done = this->attackLogic->attack(battleModel, attack_type);

        if (crit_hit)
            atk_prefix = "CRITICAL HIT: ";
        else if (damage_done > 0)
            atk_prefix = "NORMAL ATTACK: ";
        else if (damage_done == 0)
            atk_prefix = "NORMAL ATTACK EVADED: ";
        else
            assert(false); // This should never be true


        if(damage_done == 0){
            battleModel->player_turn ? ret_msg = "You missed the enemy!" : ret_msg = "HEAVY ATTACK: The enemy missed, your HP was not affected.";    
        } 
        else {
            battleModel->player_turn ? ret_msg = "You hit the enemy for " + to_string(damage_done) + "!" : ret_msg = ("HEAVY ATTACK: The enemy hit you with a normal attack, you lost " + to_string(damage_done) + "HP");
        }

    } else if (action == "F") {
        return this->handle_battle_action(battleModel, "A");
        // return "Fleeing has yet to be implemented!";
    } 
    else if (action == "B") {
        return this->handle_battle_action(battleModel, "A");
        // return "Bribing has yet to be implemented!";
        
    } else if (action == "S") {
        EntityModel *attacker = battleModel->get_attacker();
        int atk_magic_pts = attacker->get_magic();
        if(atk_magic_pts < 10)
            return "You need 10 hacking points to perform a Special Ability Attack.";
        
        // Removing magic (hack points) that will be used
        attacker->decrease_magic(10);

        ret_msg = "HACK ATTACK: You hacked the enemy! Only messages found, you did no damage.";
        
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

    return action;    
} 

//======== PUBLIC METHODS ========//

void BattleLogic::toggle_turn(BattleModel* battleModel){
    battleModel->player_turn = !battleModel->player_turn;
}

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

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
    
    // NORMAL ATTACK
    if (action == "A"){

        // Check if attack will be crit (done in BattleLogic to get prefix str)
        bool crit_hit = this->attackLogic->enemy_crit_hit(battleModel, AttackLogic::ATTACK_NORMAL);

        // Assign attack_type to pass into attack method
        (crit_hit) ? attack_type = AttackLogic::ATTACK_CRIT : attack_type = AttackLogic::ATTACK_NORMAL;

        // Fetches damage from AttackLogic
        int damage_done = this->attackLogic->attack(battleModel, attack_type);

        if (crit_hit)
            ret_msg = "CRITICAL HIT: ";
        else if (damage_done > 0)
            ret_msg = "NORMAL ATTACK: ";
        else if (damage_done == 0)
            ret_msg = "NORMAL ATTACK [miss]: ";


        if(damage_done == 0){
            battleModel->player_turn ? ret_msg += "You missed the enemy!" : ret_msg += "The enemy missed, your HP was not affected.";
        } 
        else {
            battleModel->player_turn ? ret_msg += "You hit the enemy for " + to_string(damage_done) + "!" : ret_msg += ("The enemy hit you with a normal attack, you lost " + to_string(damage_done) + "HP");
        }
        
    } 
    // HEAVY ATTACK
    else if (action == "H") {

        // Check if attack will be crit (done in BattleLogic to get prefix str)
        bool crit_hit = this->attackLogic->enemy_crit_hit(battleModel, AttackLogic::ATTACK_HEAVY);

        // Assign attack_type to pass into attack method
        (crit_hit) ? attack_type = AttackLogic::ATTACK_CRIT : attack_type = AttackLogic::ATTACK_HEAVY;

        // Fetches damage from AttackLogic
        int damage_done = this->attackLogic->attack(battleModel, attack_type);

        if (crit_hit)
            ret_msg = "CRITICAL HIT: ";
        else if (damage_done > 0)
            ret_msg = "HEAVY ATTACK: ";
        else if (damage_done == 0)
            ret_msg = "HEAVY ATTACK [miss]: ";

        if(damage_done == 0){
            battleModel->player_turn ? ret_msg += "You missed the enemy!" : ret_msg += "The enemy missed, your HP was not affected.";    
        } 
        else {
            battleModel->player_turn ? ret_msg += "You hit the enemy for " + to_string(damage_done) + "!" : ret_msg += ("The enemy hit you with a normal attack, you lost " + to_string(damage_done) + "HP");
        }

    } 
    // FLEE
    else if (action == "F") {
        battleModel->flee();
        return "You have fled the scene";
        // return "Fleeing has yet to be implemented!";
    } 
    // BRIBE
    else if (action == "B") {
        string ret_msg;
        int bribe_amount = battleModel->add_bribe();

        ret_msg = "BRIBE TIME! Bribe for " + to_string(bribe_amount) + " moneys. ";

        if(rand() % 2){
            ret_msg += "Bribe successful";
            battleModel->bribify();
        } else {
            ret_msg += "Bribe was not successful";
        }

        return ret_msg;
    } 
    // HACK ATTACK
    else if (action == "S") {
        EntityModel *attacker = battleModel->get_attacker();
        EntityModel *defender = battleModel->get_defender();
        if (attacker->get_magic() < 10)
            return "You need 10 hacking points to perform a Special Ability Attack.";
    
        // Deduct 10 hacking points regardless of the ability chosen.
        attacker->decrease_magic(10);
    
        // Randomly choose one of the five abilities (0 to 4)
        int ability = rand() % 5;
        switch (ability) {
            case 0: { // DATA DRAIN: Drain 5 hacking points from the enemy.
                EntityModel *defender = battleModel->get_defender();
                int drainAmount = 5;
                if (defender->get_magic() < drainAmount)
                    drainAmount = defender->get_magic();
                defender->decrease_magic(drainAmount);
                ret_msg = "DATA DRAIN: Used 10 hacking pts and drained " + to_string(drainAmount) + " hacking points from your enemy!";
                break;
            }
            case 1: { // FIREWALL: Activate a digital shield for the next incoming attack.
                // battleModel->set_firewall_active(true);  // Assume this method sets a firewall status.
                ret_msg = "FIREWALL: Used 10 hacking pts to build a firewall! But you messed up, the firewall is on the wrong side, you gave the enemy 15 def...";
                defender->decrease_def(15);
                if(rand() % 2){
                } else {
                    ret_msg = "FIREWALL: Used 10 hacking pts to build a firewall! But you messed up, the firewall is on the wrong side, you gained 5 def...";
                    defender->increase_def(5);
                }
                break;
            }
            case 2: { // RAPID REBOOT: Restore 10 HP.
                int healAmount = 10;
                if(rand() % 2){
                    attacker->increase_hp(healAmount);  // Assume this method exists.
                } else {
                    ret_msg = "RAPID REBOOT: Used 10 hacking pts to reboot your system, restoring " + to_string(healAmount) + " HP!";
                }

                break;
            }
            case 3: { // ATTACKER: Remove 50hp of opponent
                ret_msg = "ATTACKER: Used 10 hacking pts to remove 50 HP from the opponent";
                defender->decrease_hp(50);
                break;
            }
            case 4: { // EMP BLAST: Temporarily disable the enemy's weapon systems.
                ret_msg = "EMP BLAST: Used 10 hacking pts to send an EMP pulse that took all your hacking pts!";
                attacker->zero_hack_points();
                break;
            }
            default: {
                ret_msg = "You used magic to lick a stone, lost 10 HP due to bacterial virus.";
                attacker->decrease_hp(10);
                break;
            }
        }
    }
    
    // else if (action == "S") {
    //     EntityModel *attacker = battleModel->get_attacker();
    //     int atk_magic_pts = attacker->get_magic();
    //     if(atk_magic_pts < 10)
    //         return "You need 10 hacking points to perform a Special Ability Attack.";
        
    //     // Removing magic (hack points) that will be used
    //     attacker->decrease_magic(10);

    //     ret_msg = "HACK ATTACK: You hacked the enemy! Only messages found, you did no damage.";
        
    // } 
    // Invalid action
    else {
        return "Invalid action: " + action;
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
    if (action == "B") action = "A";

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

bool BattleLogic::player_won(BattleModel* battleModel){
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

    // There should never be a tie
    assert(!(player_hp == 0 && opponent_hp == 0));

    // Player lost
    if (player_hp == 0 && opponent_hp != 0){
        return false;
    } 
    // Player won
    else if (player_hp != 0 && opponent_hp == 0){
        return true;
    } 
    // This should never happen
    else {
        assert(false); 
    }
}

string BattleLogic::battle_over_msg(BattleModel* battleModel){
    // Verify that the game has been won
    bool game_won = this->battle_over(battleModel);
    bool bribed = battleModel->bribed;
    bool fled = battleModel->fled;

    if(fled) return "You have fled the battle, you gained no XP or Eddies";
    if(bribed) return "You bribed your way out of this one!";
    if(!game_won) return "You have not won yet...";

    bool player_has_won = this->player_won(battleModel);


    if (player_has_won){
        return "You got lucky...";
    } else 
        return "You lost homie, kind funny if u ask me ;)";

}

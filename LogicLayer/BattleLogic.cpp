#include "BattleLogic.h"
#include "../Models/BattleModel.h"

#include <iostream>
#include <vector>
#include <random>

using namespace std;

void BattleLogic::handle_battle_action(BattleModel* battle_model ,string action){
    if (action == "A"){
        std::cout << "Performing Normal Attack" << std::endl;
        // Implement normal attack logic here
        // Example: battle.playerEntityModel->attack(battle.compEntityModel);
       
    } else if (action == "H") {
        std::cout << "Performing Heavy Attack" << std::endl;
        // Implement heavy attack logic here
        // Example: battle.playerEntityModel->heavyAttack(battle.compEntityModel);
        
    } else if (action == "F") {
        std::cout << "Attempting to Flee" << std::endl;
        // Implement flee logic here
        // Example: bool escaped = battle.playerEntityModel->attemptFlee();
        
    } else if (action == "B") {
        std::cout << "Attempting to Bribe" << std::endl;
        // Implement bribe logic here
        // Example: bool bribed = battle.playerEntityModel->attemptBribe(battle.compEntityModel);
        
    } else if (action == "S") {
        std::cout << "Using Special Ability" << std::endl;
        // Implement special ability logic here
        // Example: battle.playerEntityModel->useSpecialAbility(battle.compEntityModel);
        
    } else {
        // This shouldn"t be reached due to the validation check above
        std::cout << "Unhandled action: " << action << std::endl;
    }
}

void BattleLogic::handle_turn(BattleLogic* battle_model){
    (void)battle_model;
}

void BattleLogic::handle_computer_action(BattleModel* battle_model){
    (void)battle_model;
    vector<string> action_list = battle_model->get_battle_actions(); 
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, action_list.size() - 1);
    
    int random_index = distr(gen);

    string action = action_list[random_index];
    if (action == "F") action = "A";
    this->handle_battle_action(battle_model, action);


} 

bool BattleLogic::battle_over(BattleLogic* battle_model){
    return true;
}

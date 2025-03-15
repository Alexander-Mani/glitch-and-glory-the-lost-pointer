// BattleLogic.h
#ifndef BATTLELOGIC_H
#define BATTLELOGIC_H

#include "../Models/BattleModel.h"

#include <iostream>

#include "../Models/AllEntities.h"
#include "../Models/BattleModel.h"

#include "AttackLogic.h"
#include "EntityLogic.h"

using namespace std;

class BattleLogic{
public:
    string handle_battle_action(BattleModel* battleModel, string action);
    void handle_turn(BattleLogic* battleModel);
    string handle_computer_action(BattleModel* battleModel);

    vector<string> attack_options;

    AttackLogic *attackLogic;

    BattleLogic(AttackLogic *attackLogic);

    

    /*
     * @brief Performs an action in a battle AND TOGGLES_TURN AFTERWARDS :)
     * @param action The action name
     * @param Param-Placeholder
     * @returns A message indicating the outcome of the action, or "-1" if the action is invalid
     */
    string perform_action(string action, BattleModel* battleModel);


    void toggle_turn(BattleModel* battleModel);
    
    /*
     * @brief Checks if game is over by checking if any entity_hp is 0
     * @param instance of BattleModel
     * @retuns True if any entity has hp 0, otherwise false
     */
    bool battle_over(BattleModel* battleModel);
    
    
    /*
     * @brief Checks if game is over using HP of each Entity 
     * @param instance of BattleModel
     * @retuns True player won, otherwise false
     */
    bool player_won(BattleModel* battleModel);
    
    /*
     * @brief Generates battle_over message depending on the battleModel
     * @param instance of BattleModel
     * @retuns Game over message in string
     */
    string battle_over_msg(BattleModel* battleModel);

    
};

#endif // BATTLELOGIC_H

// BattleLogic.h
#ifndef BATTLELOGIC_H
#define BATTLELOGIC_H

#include "../Models/BattleModel.h"

#include <iostream>

#include "../Models/AllEntities.h"
#include "../Models/BattleModel.h"

using namespace std;

class BattleLogic{
public:
    string handle_battle_action(BattleModel* battleModel, string action);
    void handle_turn(BattleLogic* battleModel);
    void handle_computer_action(BattleModel* battleModel);

    vector<string> attack_options;

    BattleLogic();

    

    /*
     * @brief Performs an action in a battle AND TOGGLES_TURN AFTERWARDS :)
     * @param action The action name
     * @param Param-Placeholder
     * @returns A message indicating the outcome of the action, or "-1" if the action is invalid
     */
    // string perform_action(string action, EntityModel* attacker, EntityModel* defender, WeaponModel* weapon=nullptr);
    string perform_action(string action, BattleModel* battleModel);


    void toggle_turn(BattleModel* battleModel);
    
    /*
     * @brief Checks if game is over by checking if any entity_hp is 0
     * @param instance of BattleModel
     * @retuns True if any entity has hp 0, otherwise false
     */
    bool battle_over(BattleModel* battleModel);
    
    /*
     * @brief Generates battle_over message depending on the battleModel
     * @param instance of BattleModel
     * @retuns Game over message in string
     */
    string battle_over_msg(BattleModel* battleModel);

    
private:

    int calculate_damage(BattleModel* battleModel);

    int calculate_weapon_damage(BattleModel* battleModel);

    bool attack(BattleModel* battleModel);

    /*
     * @brief Calculates the chance of a hit
     * @param attacker The BattleModel of the active battle
     */
    bool _enemy_hit(BattleModel* battleModel);


    
};

#endif // BATTLELOGIC_H

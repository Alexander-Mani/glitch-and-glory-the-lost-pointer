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
    void handle_battle_action(BattleModel* battleModel, string action);
    void handle_turn(BattleLogic* battleModel);
    void handle_computer_action(BattleModel* battleModel);
    bool battle_over(BattleLogic* battleModel);

    vector<string> attack_options;
// public:

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
    
    // int calculate_damage(EntityModel* attacker, EntityModel* defender);
    // void perform_action(EntityModel* attacker, EntityModel* defender);
    
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

// BattleLogic.h
#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "../Models/OverworldModel.h"
#include <iostream>
#include <string>
using std::string;


class GameLogic{
    public:
    //GameLogic();
    //vector<string> get_accessible_locations(OverworldModel *overworldModel);
    void change_state(OverworldModel *overworldModel, string arg);
    string change_location(OverworldModel *overworldModel, string location);
    bool is_action(vector<string> actions, string option);
    string action_resolver(string action);
    unsigned int deligate_post_battle_xp(OverworldModel *overworldModel);
    bool can_level_up(OverworldModel *overworldModel);
    void level_up(OverworldModel *overworldModel, EntityModel* selected_party_member);
    unsigned int deligate_post_battle_money(OverworldModel *overworldModel);
    unsigned int get_random_from_range(unsigned int min, unsigned int max);
    void pay_for_night_and_heal(OverworldModel* overworldModel);
    unsigned int get_stay_night_price(OverworldModel* overworldModel);
    bool won_gamble(OverworldModel* overworldModel, int amount);
    bool check_game_over(OverworldModel* overworldModel);
    string change_map_location(OverworldModel* overworldModel ,string map, string location); 


    

};


#endif // GAMELOGIC_H

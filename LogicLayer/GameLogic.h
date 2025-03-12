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
    bool is_action(vector<string> locations, string option);
    string action_resolver(string action);


    

};


#endif // GAMELOGIC_H

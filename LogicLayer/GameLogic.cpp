#include "GameLogic.h"
#include "../Models/OverworldModel.h"

#include <iostream>
#include <vector>

#include <cstdlib>

#include <cassert>
#include <algorithm>

//vector<string> GameLogic::get_accessible_locations(OverworldModel *overworldModel){
//    if (overworldModel->get_curr_location() == overworldModel->get_hub()) {
//        vector<string> locations = overworldModel->get_locations();
//
//    } else if (overworldModel->get_curr_location() == overworldModel->get_final_zone()) {
//        cout << "yo" << endl;
//    } else{
//        cout << "yo" << endl;
//
//    }
//}

void GameLogic::change_state(OverworldModel* overworldModel, string arg){
        (void)overworldModel;
        (void)arg;
        cout << "yo" << endl;
}

string GameLogic::change_location(OverworldModel *overworldModel, string location){
    location = overworldModel->set_curr_location(location);
    //Place for random encounters
    return location;
}

bool GameLogic::is_action(vector<string> actions, string option){
    if (std::count(actions.begin(), actions.end(), option) > 0) return true;
    return false;
} 

string GameLogic::action_resolver(string action){
    if (action == "Duel"){
        return "Battle";
    }
    return action;
}

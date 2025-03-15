#include "GameLogic.h"
#include "../Models/OverworldModel.h"

#include <iostream>
#include <vector>

#include <cstdlib>

#include <cassert>
#include <algorithm>
#include <random>

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

unsigned int GameLogic::deligate_post_battle_xp(OverworldModel *overworldModel){
    unsigned int level_up_threshold = overworldModel->get_party_model()->get_level_threshold();
    unsigned int min = level_up_threshold * 0.4;
    unsigned int max = level_up_threshold * 0.8;

    unsigned int new_xp = this->get_random_from_range(min, max);
    overworldModel->get_party_model()->increase_xp(new_xp);
    return new_xp;
}

unsigned int GameLogic::deligate_post_battle_money(OverworldModel *overworldModel){
    unsigned int level = overworldModel->get_party_model()->get_level();
    unsigned int money = 125 * (level+1);
    unsigned int min = money * 0.8;
    unsigned int max = money * 1.2;
    money = this->get_random_from_range(min, max);
    overworldModel->get_party_model()->increase_money(money);
    return money;

}

bool GameLogic::can_level_up(OverworldModel *overworldModel){
    unsigned int xp_threshold = overworldModel->get_party_model()->get_level_threshold();
    unsigned int curr_xp = overworldModel->get_party_model()->get_xp();
    if ( curr_xp < xp_threshold) return false;
    return true;
}

void GameLogic::level_up(OverworldModel *overworldModel, EntityModel* selected_party_member){
    unsigned int xp_threshold = overworldModel->get_party_model()->get_level_threshold();
    unsigned int curr_xp = overworldModel->get_party_model()->get_xp();
    overworldModel->get_party_model()->set_xp(curr_xp - xp_threshold);
    
    overworldModel->get_party_model()->set_level_threshold(xp_threshold * 1.1);
    overworldModel->get_party_model()->increment_level();
    unsigned int level = overworldModel->get_party_model()->get_level();

    selected_party_member->level_up(level);

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
void GameLogic::pay_for_night_and_heal(OverworldModel* overworldModel){
    unsigned int money = overworldModel->get_party_model()->get_money();
    overworldModel->get_party_model()->decrease_money(money * 0.1);

    vector<EntityModel*> members = overworldModel->get_party_model()->get_party_members();
    for( EntityModel *member: members){
        member->set_hp(member->get_max_hp());
    };
    
}

unsigned int GameLogic::get_stay_night_price(OverworldModel* overworldModel){
    unsigned int money = overworldModel->get_party_model()->get_money();
    unsigned int price = money * 0.1;
    if (price < 100) price = 100;
    return price;
}

bool GameLogic::won_gamble(OverworldModel* overworldModel, int amount){
    int roll = get_random_from_range(0, 6);
    overworldModel->get_party_model()->decrease_money(amount);
    if (roll == 1){
        overworldModel->get_party_model()->increase_money(amount*2);
        return true;
    }
    return false;


}
bool GameLogic::check_game_over(OverworldModel* overworldModel) {
    vector<EntityModel*> party_members = overworldModel->get_party_model()->get_party_members();

    for (const auto* member : party_members) {
        if (member->get_hp() > 0) {
            return false;
        }
    }
    return true; 
}


unsigned int GameLogic::get_random_from_range(unsigned int min, unsigned int max){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
    
    }

#include "AllEntities.h"
#include "WeaponModel.h"

#include <cassert>


int *WeaponModel::get_hit_rate() {
    return &this->hit_rate;
};

string WeaponModel::get_success_msg(int damage_done, bool is_player){
    cout << "get_success_msg was called..." << endl;
    assert(damage_done > 0);
    
    string ret_str;
    // Depending on if the user is player, add msg to ret_str
    is_player ? ret_str = this->success_msg + " Hit for " + to_string(damage_done) + "HP." : "You were hit for " + to_string(damage_done) + "HP.";
    return ret_str;
};

string WeaponModel::get_fail_msg(bool is_player){
    cout << "get_fail_msg was called..." << endl;
    string ret_msg;
    
    // Depending on if the user is player, add msg to ret_str
    is_player ? this->fail_msg : "The enemy missed, no HP was lost.";
    return this->fail_msg;

};

int *WeaponModel::get_damage(){
    return &this->damage;
};

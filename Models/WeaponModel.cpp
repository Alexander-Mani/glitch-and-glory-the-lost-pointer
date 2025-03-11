#include "AllEntities.h"
#include "WeaponModel.h"

// void EntityModel::display_stats() const {
//     std::cout 
//         << name << "\n"
//         << "HP: " << hp << "\n"
//         << "ATK: " << atk << "\n"
//         << "DEF: " << def << "\n"
//         << "MAGIC: " << magic << "\n"
//         << "CRIT: " << crit << "\n"
//         << "EVADE: " << evade << "\n\n";
// }


int *WeaponModel::get_hit_rate(){
    return &this->hit_rate;
};

string *WeaponModel::get_success_msg(){
    return &this->success_msg;
};

string *WeaponModel::get_fail_msg(){
    return &this->fail_msg;
};

int *WeaponModel::get_damage(){
    return &this->damage;
};
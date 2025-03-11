#ifndef WEAPONMODEL_H
#define WEAPONMODEL_H


#include <iostream>
using namespace std;

// #include "AllEntities.h"

class WeaponModel {
private:
    string name;
    int damage;
    int hit_rate; // Chance will be calulated elsewhere [most likely BattleLogic.cpp]
    string success_msg;
    string fail_msg;

public:
    // WeaponModel(string name, int damage, int chance, string success_msg, string fail_msg) 
    //     : name(name), damage(damage), chance(chance), success_msg(success_msg), fail_msg(fail_msg) {}
    WeaponModel(string name, int damage, int hit_rate, string success_msg, string fail_msg) 
        : name(name), damage(damage), hit_rate(hit_rate), success_msg(success_msg), fail_msg(fail_msg) {}

    
    // int get_damage();

};


#endif // WEAPONMODEL_H


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

#ifndef WEAPONMODEL_H
#define WEAPONMODEL_H

#include <iostream>
using namespace std;


class WeaponModel {
private:
    string name;
    int damage;
    int hit_rate; // Chance will be calulated elsewhere [most likely BattleLogic.cpp]
    string success_msg;
    string fail_msg;

public:
    WeaponModel(string name, int damage, int hit_rate, string success_msg, string fail_msg) 
        : name(name), damage(damage), hit_rate(hit_rate), success_msg(success_msg), fail_msg(fail_msg) {}
    
    int *get_hit_rate();
    string get_success_msg(int damage_done, bool is_player);
    string get_fail_msg(bool is_player);
    int *get_damage();

};


#endif // WEAPONMODEL_H

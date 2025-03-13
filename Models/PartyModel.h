#ifndef PARTY_MODEL_H
#define PARTY_MODEL_H

#include <cstddef>
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "AllEntities.h"
#include "Entities/EntityModel.h"
using namespace std;



class PartyModel {
protected:
    EntityModel* party_member_1;
    EntityModel* party_member_2;
    EntityModel* party_member_3;
    size_t party_money;
    size_t level;
    size_t party_xp_level_up_threshold;
    size_t party_xp;
public:

    // Default Constructor
    PartyModel(EntityModel* party_member_1, EntityModel* party_member_2, EntityModel* party_member_3);

    virtual ~PartyModel() = default;

    
    EntityModel* get_party_member_1();
    EntityModel* get_party_member_2();
    EntityModel* get_party_member_3();

    vector<string> get_party_member_names();
    vector<EntityModel*> get_party_members();

    void display_party();
    void increase_money(int money) { this->party_money += money; } 
    void increase_xp(int xp){ this->party_xp += xp; } 
    //virtual void take_damage(int damage) {
    //    hp -= damage;
    //    if(hp < 0) hp = 0;
    //}

    /*
     * @brief Simply gets the weapon for Entity
     */


};
#endif // ENTITY_MODEL_H

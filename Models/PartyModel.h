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

    vector<string> display_party();
    size_t get_money() const { return this->party_money; }
    void increase_money(int money) { this->party_money += money; } 
    void decrease_money(int money) { this->party_money -= money; } 
    void increase_xp(int xp){ this->party_xp += xp; } 
    void set_xp(size_t xp) { this->party_xp =xp; } 
    void set_level_threshold(size_t level_threshold) {this->party_xp_level_up_threshold = level_threshold; }
    size_t get_xp() const { return this->party_xp; }
    size_t get_level() const { return this->level; }
    void increment_level(){this->level++; }
    size_t get_level_threshold() const { return this->party_xp_level_up_threshold; }

};
#endif // ENTITY_MODEL_H

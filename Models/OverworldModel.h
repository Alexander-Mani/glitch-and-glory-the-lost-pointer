#ifndef OVERWORLD_MODEL_H
#define OVERWORLD_MODEL_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include "Equipment/EquipmentFactory.h"
//#include "AllEquipment.h"

#include "PartyModel.h"

using namespace std;



class OverworldModel {
protected:
    string current_location;
    unsigned int ascii_location_pointer;
    string ascii_art;
    PartyModel* partyModel;

    //Other consts
    const string hub = "Streets";
    const string final_zone = "Fight Boss";

    unordered_map<string, vector<string>> location_map = {
        {"Streets", {"Arena", "Shop", "Ripper", "HQ", "Apartments", "Warehouse", "Club", "Union", "View Party"}},
        {"Arena", {"Duel", "Streets", "View Party"}},
        {"Shop", {"Browse Equipment", "Streets", "View Party"}},
        {"Ripper", {"Browse Implants", "Streets", "View Party"}},
        {"HQ", {"Fight Boss", "Streets", "View Party"}},
        {"Apartments", {"Stay Night", "Streets", "View Party"}},
        {"Warehouse", {"Attempt Rat Communication", "Streets", "View Party"}},
        {"Club", {"Gamble", "Streets", "View Party"}},
        {"Union", {"Apply For Job", "Streets", "View Party"}}
        //{"Boss", {"Win", "View Party"}}
    };
    unordered_map<string, int> index_map ={
        {"Streets", 484},
        {"Arena", 446},
        {"Shop", 133},
        {"Ripper", 740},
        {"HQ", 101},
        {"Apartments", 601},
        {"Warehouse", 677},
        {"Club", 711},
        {"Union",752},


   };

    vector<string> actions = {
        "View Party", 
        "Duel",
        "Browse Equipment",
        "Browse Implants",
        "Fight Boss",
        "Gamble",
        "Apply For Job",
        "Stay Night",
        "Attempt Rat Communication",

    };



    vector<string> locations = {
        "Streets",
        "Arena",
        "Shop",
        "Ripper",
        "HQ",
        "Apartments",
        "Warehouse",
        "Union",
        "Boss"
    };
    


public:
    EquipmentFactory* equipmentFactory;
    //OverworldModel(const std::string &current_location, unsigned int &ascii_location_pointer,const std::string &ascii_art);
    // OverworldModel(const std::string &current_location = "HUB", 
    // In OverworldModel.h
    // Default Constructor
    OverworldModel(PartyModel* partyModel);

    virtual ~OverworldModel() = default;

    // Default implementation prints the common stats.
    
    vector<string> get_locations();
    vector<string> get_actions();
    unsigned int get_ascii_location_pointer(string location);
    vector<string> get_routes(string location);

    
    const string& get_ascii() const { return ascii_art; }

    const string& get_curr_location() const { return current_location; }
    int get_curr_ascii_pointer() const { return ascii_location_pointer; }
    void set_curr_ascii_pointer(string location) { this->ascii_location_pointer = this->index_map[location]; }
    string get_hub() const { return hub; }
    string get_final_zone() const { return final_zone; }
    PartyModel* get_party_model();
    EquipmentFactory* get_equipment_factory();

    //set
    //const string& set_curr_location(const string& location){
    //    current_location = location;
    //    return get_curr_location();
    //}
    const string& set_curr_location(string location) {
        this->current_location = location;
        return this->get_curr_location();
    }

    
    //virtual void take_damage(int damage) {
    //    hp -= damage;
    //    if(hp < 0) hp = 0;
    //}

    /*
     * @brief Simply gets the weapon for Entity
     */


};

#endif // ENTITY_MODEL_H

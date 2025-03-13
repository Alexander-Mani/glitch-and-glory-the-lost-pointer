#include "OverworldModel.h"
#include "Equipment/EquipmentFactory.h"
#include "Equipment/EquipmentModel.h"
#include "PartyModel.h"
#include <iostream>
#include <vector>
#include <unordered_map>



//OverworldModel::OverworldModel(const std::string &current_location, unsigned int &ascii_location_pointer, const std::string &ascii_art)
//    : current_location(current_location), 
//      ascii_location_pointer(ascii_location_pointer), 
//      ascii_art(ascii_art) {
//    // You can put any additional initialization code here
//}
// Default constructor in case you want to initalize without params such as in the begining
OverworldModel::OverworldModel(PartyModel* partyModel)
    : current_location("Streets"), 
      ascii_location_pointer(0),  // Note: this assigns a value, not a reference
      ascii_art(""),
      partyModel(partyModel)
    {
    equipmentFactory = new EquipmentFactory();
    }

PartyModel* OverworldModel::get_party_model(){
    return this->partyModel;
}
EquipmentFactory* OverworldModel::get_equipment_factory(){
    return this->equipmentFactory;
}

vector<string> OverworldModel::get_locations(){
    return locations;
}
vector<string> OverworldModel::get_actions(){
    return actions;
}
vector<string> OverworldModel::get_routes(string location){
    return location_map[location];
    
}


unsigned int OverworldModel::get_ascii_location_pointer(string location) {
    return 3; //placeholder
    
}


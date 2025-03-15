#include "OverworldModel.h"
#include "Equipment/EquipmentFactory.h"
#include "Equipment/EquipmentModel.h"
#include "PartyModel.h"
#include <iostream>
#include <vector>
#include <unordered_map>


OverworldModel::OverworldModel(PartyModel* partyModel)
    : current_location("Streets"), 
      ascii_art(""),
      partyModel(partyModel)
    {
    this->equipmentFactory = new EquipmentFactory();
    this->ascii_location_pointer = this->index_map["Streets"];
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


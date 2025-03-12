#include "OverworldModel.h"

#include <iostream>
#include <vector>
#include <unordered_map>



OverworldModel::OverworldModel(const std::string &current_location, unsigned int &ascii_location_pointer, const std::string &ascii_art)
    : current_location(current_location), 
      ascii_location_pointer(ascii_location_pointer), 
      ascii_art(ascii_art) {
    // You can put any additional initialization code here
}
// Default constructor in case you want to initalize without params such as in the begining
OverworldModel::OverworldModel()
    : current_location("Streets"), 
      ascii_location_pointer(0),  // Note: this assigns a value, not a reference
      ascii_art("") {
    // Additional initialization code if needed
}

vector<string> OverworldModel::get_locations(){
    return locations;
}
vector<string> OverworldModel::get_routes(string location){
    return location_map[location];
    
}


unsigned int OverworldModel::get_ascii_location_pointer(string location) {
    return 3; //placeholder
    
}


// EquipmentFactory.h
#ifndef EQUIPMENT_FACTORY_H
#define EQUIPMENT_FACTORY_H

#include <vector>
#include <unordered_map>

#include "WeaponModel.h"
#include "ArmorModel.h"
#include "ImplantModel.h"

class EquipmentFactory {
private:
    vector<WeaponModel*> weapons;
    vector<ArmorModel*> armors;
    vector<ImplantModel*> implants;

    
    public:
    EquipmentFactory();
    ~EquipmentFactory();
    
    // Return pointers to the vector collections
    vector<WeaponModel*>* get_weapons();
    vector<ArmorModel*>* get_armors();
    vector<ImplantModel*>* get_implants();
    
    void show_cyber_augments();
    void show_combat_gear();
    
    
    
    
    // Shop Stuff
    vector<string> create_box(const string &title, const vector<string>& content, int width);
    vector<unordered_map<string, string>> get_weapon_attributes();
    void print_boxes_side_by_side(const vector<vector<string>> &boxes, int spacing = 4);

};

#endif // EQUIPMENT_FACTORY_H

// EquipmentFactory.h
#ifndef EQUIPMENT_FACTORY_H
#define EQUIPMENT_FACTORY_H

#include <vector>
#include "WeaponModel.h"
#include "ArmorModel.h"
#include "ImplantModel.h"

class EquipmentFactory {
private:
    std::vector<WeaponModel*> weapons;
    std::vector<ArmorModel*> armors;
    std::vector<ImplantModel*> implants;

public:
    EquipmentFactory();
    ~EquipmentFactory();

    // Return pointers to the vector collections
    std::vector<WeaponModel*>* get_weapons();
    std::vector<ArmorModel*>* get_armors();
    std::vector<ImplantModel*>* get_implants();
    
    void show_cyber_augments();
    void show_combat_gear();
};

#endif // EQUIPMENT_FACTORY_H

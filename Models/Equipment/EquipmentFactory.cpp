// EquipmentFactory.cpp
#include "EquipmentFactory.h"
#include <iostream>
#include <iomanip>
#include <string>

EquipmentFactory::EquipmentFactory() {
    // Create new weapon objects and store pointers to them
    weapons.push_back(new WeaponModel("Neons Edge", 0, 1, 0, 0, 0, 0, 400, true));
    weapons.push_back(new WeaponModel("Hyper Katana", 0, 2, 0, 0, 0, 0, 800, true));
    weapons.push_back(new WeaponModel("H&K 7000-a", 0, 4, 0, 0, 0, 0, 1600, true));
    weapons.push_back(new WeaponModel("Cyber Spike", 0, 8, 0, 0, 0, 0, 3200, true));
    weapons.push_back(new WeaponModel("Snow Eagle", 0, 16, 0, 0, 0, 0, 6400, true));

    // Create new armor objects and store pointers to them
    armors.push_back(new ArmorModel("Ballistic Vest", 0, 0, 3, 0, 0, 0, 500, true));
    armors.push_back(new ArmorModel("Samuraii Shoulders", 0, 0, 6, 0, 0, 0, 1000, true));
    armors.push_back(new ArmorModel("Combat Armor", 0, 0, 9, 0, 0, 0, 2000, true));
    armors.push_back(new ArmorModel("Titanium Suit", 0, 0, 12, 0, 0, 0, 4000, true));
    armors.push_back(new ArmorModel("Omega Boots", 0, 0, 15, 0, 0, 0, 8000, true));

    // Create new implant objects and store pointers to them
    implants.push_back(new ImplantModel("Mantis Blades", 0, 0, 0, 0, 5, 0, 1100, true));
    implants.push_back(new ImplantModel("Sandevistan", 0, 0, 0, 0, 10, 0, 2200, true));
    implants.push_back(new ImplantModel("Spinal Augmenter", 0, 0, 0, 0, 14, 0, 4400, true));
    implants.push_back(new ImplantModel("Reinforced Bones", 0, 0, 0, 0, 17, 0, 8800, true));
    implants.push_back(new ImplantModel("Hardened Nose", 0, 0, 0, 0, 20, 0, 17600, true));
}

EquipmentFactory::~EquipmentFactory() {
    // Clean up all allocated weapon objects
    for (WeaponModel* weapon : weapons) {
        delete weapon;
    }
    
    // Clean up all allocated armor objects
    for (ArmorModel* armor : armors) {
        delete armor;
    }
    
    // Clean up all allocated implant objects
    for (ImplantModel* implant : implants) {
        delete implant;
    }
}

std::vector<WeaponModel*>* EquipmentFactory::get_weapons() {
    return &weapons;
}

std::vector<ArmorModel*>* EquipmentFactory::get_armors() {
    return &armors;
}

std::vector<ImplantModel*>* EquipmentFactory::get_implants() {
    return &implants;
}

void EquipmentFactory::show_combat_gear() {
    std::cout << "=== Weapons ===\n";
    int ind = 1;
    for (const auto* weapon : this->weapons) {
        std::cout
            << ind++
            << ". Name: "   << weapon->get_name()
            << " | HP: "  << weapon->get_max_hp()
            << " | ATK: " << weapon->get_atk()
            << " | DEF: " << weapon->get_def()
            << " | MGK: " << weapon->get_magic()
            << " | CRIT: "<< weapon->get_crit()
            << " | EVA: " << weapon->get_evade()
            << " | Price: " << weapon->get_price()
            << "\n";
    }

    std::cout << "\n=== Armors ===\n";
    for (const auto* armor : this->armors) {
        std::cout
            << ind++
            << ". Name: "   << armor->get_name()
            << " | HP: "  << armor->get_max_hp()
            << " | ATK: " << armor->get_atk()
            << " | DEF: " << armor->get_def()
            << " | MGK: " << armor->get_magic()
            << " | CRIT: "<< armor->get_crit()
            << " | EVA: " << armor->get_evade()
            << " | Price: " << armor->get_price()
            << "\n";
    } 
    std::cout << to_string(ind++)+". " << "Leave" << endl;
    std::cout << std::endl;
}

void EquipmentFactory::show_cyber_augments() {
    std::cout << "=== Implants ===\n";
    int ind = 1;
    for (const auto* implant : this->implants) {
        std::cout
            << ind++
            << ". Name: "   << implant->get_name()
            << " | HP: "  << implant->get_max_hp()
            << " | ATK: " << implant->get_atk()
            << " | DEF: " << implant->get_def()
            << " | MGK: " << implant->get_magic()
            << " | CRIT: "<< implant->get_crit()
            << " | EVA: " << implant->get_evade()
            << " | Price: " << implant->get_price()
            << "\n";
    }
    std::cout << to_string(ind++)+". " << "Leave" << endl;
    std::cout << std::endl;
}

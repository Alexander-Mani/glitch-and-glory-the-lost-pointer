#include "EntityModel.h"

#include <iostream>
#include <vector>
using namespace std;
//#include "../AllEquipment.h"
//#include "../WeaponModel.h"

//EntityModel::EntityModel(const std::string &name, int hp, int atk, int def, int magic, int crit, int evade, vector<string> ascii_art, )
//    : name(name), hp(hp), atk(atk), def(def), magic(magic), crit(crit), evade(evade), ascii_art(move(ascii_art)), weapon(weapon) {}

EntityModel::EntityModel(const std::string &name, int max_hp, int hp, int atk, int def, int magic, int crit, int evade, vector<string> ascii_art)
    : name(name), max_hp(max_hp), hp(hp), atk(atk), def(def), magic(magic), crit(crit), evade(evade), ascii_art(move(ascii_art)) {
    // Initialize inventory with nullptrs
    inventory["Weapon"] = nullptr;
    inventory["Armor"] = nullptr;
    inventory["Implant"] = nullptr;
}


void EntityModel::display_ascii() const {
    for (const auto& line : ascii_art) {
        std::cout << line << std::endl;
        }
}


void EntityModel::display_stats() const {
    std::cout 
        << "\n\n|---------------------------------|\n"
        << "|----| Printing Entity Stats |----|\n"
        << "|---------------------------------|\n"
        << "|\n"
        << "| " << "-- "+name+" --" << "\n"
        << "| HP: " << hp << "\n"
        << "| ATK: " << atk << "\n"
        << "| DEF: " << def << "\n"
        << "| MAGIC: " << magic << "\n"
        << "| CRIT: " << crit << "\n"
        << "| EVADE: " << evade << "\n|\n"
        << "|---------------------------------|\n\n";
}
void EntityModel::equip_item(const std::string &slot, EquipmentModel *item) {
    if (inventory.find(slot) != inventory.end()) {
        if (inventory[slot]){
            cout << "You already have: " << inventory[slot]->get_name() << " In that slot." << endl;
            int confirm;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "Do you want to replace it: ";
            cin >> confirm; 
            if (confirm != 1){
                return;
            }
            this->max_hp -= inventory[slot]->get_max_hp();
            this->atk -= inventory[slot]->get_atk();
            this->def -= inventory[slot]->get_def();
            this->magic -= inventory[slot]->get_magic();
            this->crit -= inventory[slot]->get_magic();
            this->evade -= inventory[slot]->get_evade();
        }
        this->max_hp += item->get_max_hp();
        this->atk += item->get_atk();
        this->def += item->get_def();
        this->magic += item->get_magic();
        this->crit += item->get_magic();
        this->evade += item->get_evade();
        inventory[slot] = item;
    } else {
        cout << "Invalid equipment slot: " << slot << endl;
    }
}

// Retrieve an equipped item
EquipmentModel* EntityModel::get_equipped_item(const std::string &slot) const {
    auto it = inventory.find(slot);
    if (it != inventory.end()) {
        return it->second;
    }
    return nullptr;
}

//vector<int> EntityModel:: 

void EntityModel::display_inventory() const {
    cout << "\n|----------------------------|"
         << "\n|----| Inventory Items |----|"
         << "\n|----------------------------|\n";

    for (const auto &pair : inventory) {
        cout << "| " << pair.first << ": ";
        if (pair.second) {
            cout << pair.second->get_name();
            if (pair.second->get_max_hp())
                cout << " Max hp: +"<<pair.second->get_max_hp();
            if (pair.second->get_atk())
                cout << " | Attack: +"<<pair.second->get_atk();
            if (pair.second->get_def())
                cout << " | Defence: +"<<pair.second->get_def();
            if (pair.second->get_magic())
                cout << " | Hacking: +"<<pair.second->get_magic();
            if (pair.second->get_crit())
                cout << " | Critical: +"<<pair.second->get_crit();
            if (pair.second->get_evade()) 
                    cout << " | Evasion: +"<<pair.second->get_evade();
        } else {
            cout << "None";
        }
        cout << "\n";
    }

    cout << "|----------------------------|\n";
}

//WeaponModel *EntityModel::get_weapon(){
//    return this->weapon;
//}




    
//============================================//
//======= TOMMI OLD CODE FOR REFERENCE =======//
//============================================//

// #include "EntityParentModel.h"
// #include <iostream>

// // Constructor for base class Entity
// Entity::Entity(const std::string &name, int hp, int atk, int def, int magic, int crit, int evade)
//     : name(name), hp(hp), atk(atk), def(def), magic(magic), crit(crit), evade(evade) {}

// // TechnoOracle implementation
// TechnoOracle::TechnoOracle()
//     : Entity("Techno Oracle", 60, 10, 5, 70, 15, 10) {}

// void TechnoOracle::display_stats() const {
//     std::cout << name << "\n"
//               << "HP: " << hp << "\n"
//               << "ATK: " << atk << "\n"
//               << "DEF: " << def << "\n"
//               << "MAGIC: " << magic << "\n"
//               << "CRIT: " << crit << "\n"
//               << "EVADE: " << evade << "\n\n";
// }

// // CyberGladiator implementation
// CyberGladiator::CyberGladiator()
//     : Entity("Cyber Gladiator", 100, 50, 50, 5, 10, 10) {}

// void CyberGladiator::display_stats() const {
//     std::cout << name << "\n"
//               << "HP: " << hp << "\n"
//               << "ATK: " << atk << "\n"
//               << "DEF: " << def << "\n"
//               << "MAGIC: " << magic << "\n"
//               << "CRIT: " << crit << "\n"
//               << "EVADE: " << evade << "\n\n";
// }

// // BioEnhancedBerserker implementation
// BioEnhancedBerserker::BioEnhancedBerserker()
//     : Entity("Bio-Enhanced Berserker", 150, 30, 60, 5, 5, 5) {}

// void BioEnhancedBerserker::display_stats() const {
//     std::cout << name << "\n"
//               << "HP: " << hp << "\n"
//               << "ATK: " << atk << "\n"
//               << "DEF: " << def << "\n"
//               << "MAGIC: " << magic << "\n"
//               << "CRIT: " << crit << "\n"
//               << "EVADE: " << evade << "\n\n";
// }

#include "EntityModel.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//#include "../AllEquipment.h"
//#include "../WeaponModel.h"

#include <cassert> // For debuggin purposes


//EntityModel::EntityModel(const std::string &name, int hp, int atk, int def, int magic, int crit, int evade, vector<string> ascii_art, )
//    : name(name), hp(hp), atk(atk), def(def), magic(magic), crit(crit), evade(evade), ascii_art(move(ascii_art)), weapon(weapon) {}

EntityModel::EntityModel(const std::string &name, int max_hp, int hp, int atk, int def, int magic, int crit, int evade, int acc, vector<string> ascii_art)
    : name(name), max_hp(max_hp), hp(hp), atk(atk), def(def), magic(magic), crit(crit), evade(evade), acc(acc), ascii_art(move(ascii_art)) {
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
        << "| MAX HP: " << max_hp << "\n"
        << "| HP: " << hp << "\n"
        << "| ATK: " << atk << "\n"
        << "| DEF: " << def << "\n"
        << "| MAGIC: " << magic << "\n"
        << "| CRIT: " << crit << "\n"
        << "| EVADE: " << evade << "\n|\n"
        << "| ACC: " << acc << "\n|\n"
        << "|---------------------------------|\n\n";
}


vector<string> EntityModel::get_stats_lines() {
    vector<string> lines;
    string name_l = "| " + name + " |";
    int padding = name_l.size() - 1;

    string wrapper = string(name_l.size(), '-');
    string inner_wrapper = "| " + string(name_l.size()-4, '-') + " |";
    
    string hp_left = "| HP: " + to_string(hp);
    string hp_l = hp_left + string(padding - hp_left.size(), ' ') + "|";
    
    string atk_left = "| ATK: " + to_string(atk);
    string atk_l = atk_left + string(padding - atk_left.size(), ' ') + "|";

    string def_left = "| DEF: " + to_string(def);
    string def_l = def_left + string(padding - def_left.size(), ' ') + "|";
    
    // if(def_l.size() != name_l.size()){
    //     string def_l = atk_left + string(padding - (def_left.size() - 4), ' ') + "|";
    // }

    if(!(name_l.size() == hp_l.size() && name_l.size() == atk_l.size() && name_l.size() == def_l.size())){
        cout << "name_l.size() :" << name_l.size() << endl;  
        cout << "hp_l.size():" << hp_l.size() << endl;  
        cout << "atk_l.size():" << atk_l.size() << endl;  
        cout << "def_l.size():" << def_l.size() << endl; 
    }
    // assert(name_l.size() == hp_l.size() == atk_l.size() == def_l.size());


    lines.push_back(wrapper);
    lines.push_back(name_l);
    lines.push_back(inner_wrapper);
    lines.push_back(hp_l);
    lines.push_back(atk_l);
    lines.push_back(def_l);
    lines.push_back(wrapper);

    // lines.push_back("| HP: " + to_string(hp) + " |");
    // lines.push_back("| ATK: " + to_string(atk) + " |");
    // lines.push_back("| DEF: " + to_string(def) + " |");
    return lines;
}

bool EntityModel::equip_item(const std::string &slot, EquipmentModel *item) {
    if (inventory.find(slot) != inventory.end()) {
        if (inventory[slot]){
            cout << "You already have: " << inventory[slot]->get_name() << " In that slot." << endl;
            int confirm;
            cout << "1. Yes" << endl;
            cout << "2. No" << endl;
            cout << "Do you want to replace it: ";
            cin >> confirm; 
            if (confirm != 1){
                return false;
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
        return false;
    }
    return true;
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

vector<string> EntityModel::get_inventory() const {
    //cout << "\n|----------------------------|"
    //     << "\n|----| Inventory Items |----|"
    //     << "\n|----------------------------|\n";
    vector<string> inventory_vect;
    string item;
    for (const auto &pair : inventory) {
        item = "";
        item+= "| " + pair.first +": ";
        if (pair.second) {
            item+= pair.second->get_name();
            if (pair.second->get_max_hp())
                item+= " Max hp: +"+to_string(pair.second->get_max_hp());
            if (pair.second->get_atk())
                item+= " | Attack: +"+to_string(pair.second->get_atk());
            if (pair.second->get_def())
                item+= " | Defence: +"+to_string(pair.second->get_def());
            if (pair.second->get_magic())
                item+= " | Hacking: +"+to_string(pair.second->get_magic());
            if (pair.second->get_crit())
                item+= " | Critical: +"+to_string(pair.second->get_crit());
            if (pair.second->get_evade()) 
                item+= " | Evasion: +"+to_string(pair.second->get_evade());
        } else {
            item+= "None";
        }
        inventory_vect.push_back(item);
    }

return inventory_vect;
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

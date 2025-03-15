#include "EntityModel.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;


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
    

    if(!(name_l.size() == hp_l.size() && name_l.size() == atk_l.size() && name_l.size() == def_l.size())){
        cout << "name_l.size() :" << name_l.size() << endl;  
        cout << "hp_l.size():" << hp_l.size() << endl;  
        cout << "atk_l.size():" << atk_l.size() << endl;  
        cout << "def_l.size():" << def_l.size() << endl; 
    }


    lines.push_back(wrapper);
    lines.push_back(name_l);
    lines.push_back(inner_wrapper);
    lines.push_back(hp_l);
    lines.push_back(atk_l);
    lines.push_back(def_l);
    lines.push_back(wrapper);

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


vector<string> EntityModel::get_inventory_lines() {
    vector<string> item_lines;
    item_lines.reserve(inventory.size());

    for (const auto &pair : inventory) {
        string line = pair.first + ": ";
        if (pair.second) {
            line += pair.second->get_name();

            if (pair.second->get_max_hp())
                line += " | +HP: " + to_string(pair.second->get_max_hp());
            if (pair.second->get_atk())
                line += " | +ATK: " + to_string(pair.second->get_atk());
            if (pair.second->get_def())
                line += " | +DEF: " + to_string(pair.second->get_def());
            if (pair.second->get_magic())
                line += " | +MAG: " + to_string(pair.second->get_magic());
            if (pair.second->get_crit())
                line += " | +CRIT: " + to_string(pair.second->get_crit());
            if (pair.second->get_evade())
                line += " | +EVADE: " + to_string(pair.second->get_evade());
        } else {
            line += "None";
        }
        item_lines.push_back(line);
    }

    size_t max_len = 0;
    for (auto &ln : item_lines) {
        if (ln.size() > max_len) {
            max_len = ln.size();
        }
    }

    vector<string> inventory_view;

    string wrapper = string(max_len + 4, '-');
    string title = "| INVENTORY";
    if (max_len > 9) {
        title += string(max_len - 9, ' ');
    }
    title += " |";

    string inner_wrapper = "|" + string(wrapper.size() - 2, '-') + "|";

    inventory_view.push_back(wrapper);
    inventory_view.push_back(title);
    inventory_view.push_back(inner_wrapper);

    for (auto &ln : item_lines) {
        string padded_ln = "| " + ln;
        if (ln.size() < max_len) {
            padded_ln += string(max_len - ln.size(), ' ');
        }
        padded_ln += " |";
        inventory_view.push_back(padded_ln);
    }

    inventory_view.push_back(wrapper);

    return inventory_view;
}
#include "EntityModel.h"

#include <iostream>
#include <vector>
using namespace std;
#include "../WeaponModel.h"

EntityModel::EntityModel(const std::string &name, int hp, int atk, int def, int magic, int crit, int evade, vector<string> ascii_art, WeaponModel weapon)
    : name(name), hp(hp), atk(atk), def(def), magic(magic), crit(crit), evade(evade), ascii_art(move(ascii_art)), weapon(weapon) {}


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


WeaponModel *EntityModel::get_weapon(){
    return &this->weapon;
}




    
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

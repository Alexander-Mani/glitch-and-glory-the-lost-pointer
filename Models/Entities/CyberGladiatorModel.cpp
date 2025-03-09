#include "CyberGladiatorModel.h"
#include <iostream>

CyberGladiatorModel::CyberGladiatorModel()
    : EntityModel("Cyber Gladiator", 100, 50, 50, 5, 10, 10) {}

void CyberGladiatorModel::display_stats() const {
    std::cout 
        << name << "\n"
        << "HP: " << hp << "\n"
        << "ATK: " << atk << "\n"
        << "DEF: " << def << "\n"
        << "MAGIC: " << magic << "\n"
        << "CRIT: " << crit << "\n"
        << "EVADE: " << evade << "\n\n";
}

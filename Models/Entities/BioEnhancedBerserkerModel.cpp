#include "BioEnhancedBerserkerModel.h"
#include <iostream>

BioEnhancedBerserkerModel::BioEnhancedBerserkerModel()
    : EntityModel("Bio-Enhanced Berserker", 150, 30, 60, 5, 5, 5) {}

void BioEnhancedBerserkerModel::display_stats() const {
    std::cout 
        << name << "\n"
        << "HP: " << hp << "\n"
        << "ATK: " << atk << "\n"
        << "DEF: " << def << "\n"
        << "MAGIC: " << magic << "\n"
        << "CRIT: " << crit << "\n"
        << "EVADE: " << evade << "\n\n";
}

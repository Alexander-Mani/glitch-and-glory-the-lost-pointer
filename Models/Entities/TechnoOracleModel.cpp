#include "TechnoOracleModel.h"
#include <iostream>

TechnoOracleModel::TechnoOracleModel()
    : EntityModel("Techno Oracle", 60, 10, 5, 70, 15, 10) {}

void TechnoOracleModel::display_stats() const {
    std::cout 
        << name << "\n"
        << "HP: " << hp << "\n"
        << "ATK: " << atk << "\n"
        << "DEF: " << def << "\n"
        << "MAGIC: " << magic << "\n"
        << "CRIT: " << crit << "\n"
        << "EVADE: " << evade << "\n\n";
}

#include "EntityParentModel.h"
#include <iostream>

Entity::Entity(const std::string &name, int hp, int atk, int def, int magic, int crit, int evade)
    : name(name), hp(hp), atk(atk), def(def), magic(magic), crit(crit), evade(evade) {}

TechnoOracle::TechnoOracle()
    : Entity("Techno Oracle",
             /*hp=*/60,
             /*atk=*/10,
             /*def=*/5,
             /*magic=*/70,
             /*crit=*/15,
             /*evade=*/10) {}

void TechnoOracle::displayStats() const {
    std::cout << "" << name << "\n"
              << "HP: " << hp << "\n"
              << "ATK: " << atk << "\n"
              << "DEF: " << def << "\n"
              << "MAGIC: " << magic << "\n"
              << "CRIT: " << crit << "\n"
              << "EVADE: " << evade << "\n\n";
}

CyberGladiator::CyberGladiator()
    : Entity("Cyber Gladiator",
             /*hp=*/100,
             /*atk=*/50,
             /*def=*/50,
             /*magic=*/5,
             /*crit=*/10,
             /*evade=*/10) {}

void CyberGladiator::displayStats() const {
    std::cout << "" << name << "\n"
              << "HP: " << hp << "\n"
              << "ATK: " << atk << "\n"
              << "DEF: " << def << "\n"
              << "MAGIC: " << magic << "\n"
              << "CRIT: " << crit << "\n"
              << "EVADE: " << evade << "\n\n";
}

BioEnhancedBerserker::BioEnhancedBerserker()
    : Entity("Bio-Enhanced Berserker",
             /*hp=*/150,
             /*atk=*/30,
             /*def=*/60,
             /*magic=*/5,
             /*crit=*/5,
             /*evade=*/5) {}

void BioEnhancedBerserker::displayStats() const {
    std::cout << "" << name << "\n"
              << "HP: " << hp << "\n"
              << "ATK: " << atk << "\n"
              << "DEF: " << def << "\n"
              << "MAGIC: " << magic << "\n"
              << "CRIT: " << crit << "\n"
              << "EVADE: " << evade << "\n\n";
}

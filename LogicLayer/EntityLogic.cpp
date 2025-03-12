#include "EntityLogic.h"
#include "../Models/Entities/CyberGladiatorModel.h"
#include "../Models/Entities/TechnoOracleModel.h"
#include "../Models/Entities/BioEnhancedBerserkerModel.h"

#include <random>

std::vector<EntityModel*> EntityLogic::get_all_entities() {
    std::vector<EntityModel*> entities;
    entities.push_back(new CyberGladiatorModel());
    entities.push_back(new TechnoOracleModel());
    entities.push_back(new BioEnhancedBerserkerModel());
    return entities;
}

EntityModel* EntityLogic::get_random_entity() {
    std::vector<EntityModel*> all_entities = this->get_all_entities();  
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, all_entities.size() - 1);
    
    int random_index = distr(gen);
    return all_entities[random_index];
}

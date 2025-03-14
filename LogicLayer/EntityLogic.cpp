#include "EntityLogic.h"
#include "../Models/Entities/CyberGladiatorModel.h"
#include "../Models/Entities/TechnoOracleModel.h"
#include "../Models/Entities/BioEnhancedBerserkerModel.h"

#include <random>

#include <iostream>

using namespace std;


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


int EntityLogic::get_hit_chance_normal(BattleModel* battleModel) {
    int hit_chance;
    int attacker_acc; // Attacker accuracy
    int defender_evade; // Defender evade


    EntityModel *attacker = battleModel->get_attacker();
    EntityModel *defender = battleModel->get_defender();

    attacker_acc = attacker->get_acc();
    defender_evade = defender->get_evade();
    
    hit_chance = (attacker_acc - (defender_evade * 0.15));
    // cout << "\n\nattacker_acc: " << attacker_acc << endl;
    // cout << "defender_evade: " << defender_evade << endl;
    // cout << "hit_chance: " << hit_chance << endl;
    
    if (hit_chance < 35) {
        hit_chance = 35 + (rand() % 7 - 3); // Generates a value in range [32, 38]
    } else if (hit_chance > 95) {
        hit_chance = 92 + (rand() % 7 - 3); // Generates a value in range [89, 95]
    }

    return hit_chance;
}

int EntityLogic::get_hit_chance_heavy(BattleModel* battleModel) {
    return (this->get_hit_chance_normal(battleModel) * 0.75);
}

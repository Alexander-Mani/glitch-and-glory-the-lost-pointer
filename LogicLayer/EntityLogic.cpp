#include "EntityLogic.h"
#include "../Models/Entities/CyberGladiatorModel.h"
#include "../Models/Entities/TechnoOracleModel.h"
#include "../Models/Entities/BioEnhancedBerserkerModel.h"
#include "../Models/Entities/ElonoTronPhase1Model.h"
#include "../Models/Entities/ElonoTronPhase2Model.h"
#include "../Models/Entities/EnemyModel.h"
#include "GameLogic.h"

#include <random>

#include <iostream>

using namespace std;


EntityLogic::EntityLogic(GameLogic *gameLogic){
    this->gameLogic = gameLogic;
}


// Keep this for player entites
std::vector<EntityModel*> EntityLogic::get_all_entities() {
    std::vector<EntityModel*> entities;
    entities.push_back(new CyberGladiatorModel());
    entities.push_back(new TechnoOracleModel());
    entities.push_back(new BioEnhancedBerserkerModel());
    return entities;
}

EntityModel* EntityLogic::get_boss_entity_phase_1() {
    return new ElonoTronPhase1Model();
}

EntityModel* EntityLogic::get_boss_entity_phase_2() {
    return new ElonoTronPhase2Model();
}
EntityModel* EntityLogic::generate_enemy_entity(EntityModel *playerModel){
    int img_number = this->enemy_ascii_matrix.size();
    int rand_ascii_number = this->gameLogic->get_random_from_range(0, img_number-1); 
    vector<string> ascii_art = enemy_ascii_matrix[rand_ascii_number];

    vector<int> stats = playerModel->get_battle_stats();
    int rand_stat_index = this->gameLogic->get_random_from_range(0, stats.size()-1); 
    stats[rand_stat_index] *=2; 

    vector<string> names = enemy_names;
    int rand_name_index = this->gameLogic->get_random_from_range(0, names.size()-1); 

    for(int& stat : stats){
        stat = this->gameLogic->get_random_from_range(0.6*stat, 0.9*stat); 
    }
    int atk = playerModel->get_atk();
    atk = this->gameLogic->get_random_from_range(0.6*atk, 0.9*atk); 
    int max_hp = playerModel->get_max_hp();
    max_hp = this->gameLogic->get_random_from_range(0.6*max_hp, 0.9*max_hp); 
    int acc = playerModel->get_acc();
    int enemy_acc = this->gameLogic->get_random_from_range(acc * 0.6, acc * 0.9); 
    // acc > 100
    if (enemy_acc > 100) enemy_acc = 100;

    return new EnemyModel(names[rand_name_index], max_hp, max_hp, atk, stats[2], stats[3], stats[4], stats[5], enemy_acc, ascii_art);

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
    return (EntityLogic::get_hit_chance_normal(battleModel) * 0.75);
}

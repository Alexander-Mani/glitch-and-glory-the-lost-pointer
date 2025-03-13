#include "EntityLogic.h"
#include "../Models/Entities/CyberGladiatorModel.h"
#include "../Models/Entities/TechnoOracleModel.h"
#include "../Models/Entities/BioEnhancedBerserkerModel.h"

std::vector<EntityModel*> EntityLogic::get_all_entities() {
    std::vector<EntityModel*> entities;
    entities.push_back(new CyberGladiatorModel());
    entities.push_back(new TechnoOracleModel());
    entities.push_back(new BioEnhancedBerserkerModel());
    return entities;
}



int EntityLogic::get_hit_chance_normal(BattleModel* battleModel) {
    EntityModel *attacker = battleModel->get_attacker();
    EntityModel *defender = battleModel->get_defender();
    int atk = attacker->get_atk();
    int def_evade = defender->get_evade();
    int hit_chance = (atk * 100) / (atk + def_evade);
    return hit_chance;
}

int EntityLogic::get_hit_chance_heavy(BattleModel* battleModel) {
    EntityModel *attacker = battleModel->get_attacker();
    EntityModel *defender = battleModel->get_defender();
    // Adjust stats for heavy attack as in enemy_hit()
    int heavy_atk = static_cast<int>(attacker->get_atk() * 1.25);
    int heavy_evade = static_cast<int>(defender->get_evade() * 2);
    int hit_chance = (heavy_atk * 100) / (heavy_atk + heavy_evade);
    return hit_chance;
}
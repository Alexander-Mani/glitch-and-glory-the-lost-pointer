#ifndef ENTITYLOGIC_H
#define ENTITYLOGIC_H

#include <vector>
#include <string>
#include "../Models/Entities/EntityModel.h"
#include "../Models/BattleModel.h"

class EntityLogic {
public:
    /*
     * @brief Gets all Entity Models
     * @returns A vector of pointers to available entity models.
     */
    std::vector<EntityModel*> get_all_entities();
    
    // Calculates hit chance for normal attack
    int get_hit_chance_normal(BattleModel* battleModel);
    
    // Calculates hit chance for heavy attack
    int get_hit_chance_heavy(BattleModel* battleModel);
};

#endif // ENTITYLOGIC_H

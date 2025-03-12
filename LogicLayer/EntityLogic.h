#ifndef ENTITYLOGIC_H
#define ENTITYLOGIC_H

#include <vector>
#include <string>
#include "../Models/Entities/EntityModel.h"

class EntityLogic {
public:
    /*
     * @brief Gets all Entity Models
     * @returns A vector of pointers to available entity models.
     */
    std::vector<EntityModel*> get_all_entities();
    EntityModel* get_random_entity(); 
    
};

#endif // ENTITYLOGIC_H

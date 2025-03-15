#ifndef ENEMY_MODEL_H
#define ENEMY_MODEL_H

#include "EntityModel.h"
#include <vector>


class EnemyModel : public EntityModel {
public:
    EnemyModel(string name, int max_hp, int hp, int atk, int def, int magic, int crit, int evade, int acc, vector<string> ascii_art)
        : EntityModel(
            name,  // Name 
            max_hp,                        // max_hp
            hp,                 // hp         
            atk,                 // atk         
            def,                 // def         
            magic,                  // magic     
            crit,                 // crit         
            evade,                 // evade     
            acc,                 // acc (Accuracy)     
            ascii_art
        )
    { }
};

#endif // CYBER_GLADIATOR_MODEL_H


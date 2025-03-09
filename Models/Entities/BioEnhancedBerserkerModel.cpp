#include "BioEnhancedBerserkerModel.h"
#include <iostream>

BioEnhancedBerserkerModel::BioEnhancedBerserkerModel()
    : EntityModel(
        "Bio-Enhanced Berserker",   // Name
        150,                        // hp
        30,                         // atk
        60,                         // def
        5,                          // magic
        5,                          // crit
        5                           // evade
    ) {}


#include "CyberGladiatorModel.h"
#include <iostream>

CyberGladiatorModel::CyberGladiatorModel()
    : EntityModel(
        "Cyber Gladiator",  // Name 
        100,                // hp         
        50,                 // atk         
        50,                 // def         
        5,                  // magic     
        10,                 // crit         
        10                  // evade     
    ) {}


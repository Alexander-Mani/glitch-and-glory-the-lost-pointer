#include "TechnoOracleModel.h"
#include <iostream>

TechnoOracleModel::TechnoOracleModel()
    : EntityModel(
        "Techno Oracle",    // Name                    
        60,                 // hp        
        10,                 // atk        
        5,                  // def    
        70,                 // magic        
        15,                 // crit        
        10                  // evade    
    ) {}

#ifndef TECHNO_ORACLE_MODEL_H
#define TECHNO_ORACLE_MODEL_H

#include "EntityModel.h"

class TechnoOracleModel : public EntityModel {
public:
    TechnoOracleModel();

    // Provides the parent EntityModel the variables it needs from this Model
    void display_stats() const override;
};

#endif // TECHNO_ORACLE_MODEL_H

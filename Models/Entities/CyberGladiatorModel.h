#ifndef CYBER_GLADIATOR_MODEL_H
#define CYBER_GLADIATOR_MODEL_H

#include "EntityModel.h"

class CyberGladiatorModel : public EntityModel {
public:
    CyberGladiatorModel();

    // Provides the parent EntityModel the variables it needs from this Model
    void display_stats() const override;
};

#endif // CYBER_GLADIATOR_MODEL_H

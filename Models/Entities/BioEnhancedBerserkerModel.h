#ifndef BIO_ENHANCED_BERSERKER_MODEL_H
#define BIO_ENHANCED_BERSERKER_MODEL_H

#include "EntityModel.h"

class BioEnhancedBerserkerModel : public EntityModel {
public:
    BioEnhancedBerserkerModel();

    // Provides the parent EntityModel the variables it needs from this Model
    void display_stats() const override;
};

#endif // BIO_ENHANCED_BERSERKER_MODEL_H

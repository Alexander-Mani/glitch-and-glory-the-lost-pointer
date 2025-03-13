#ifndef IMPLANT_MODEL_H
#define IMPLANT_MODEL_H

#include "EquipmentModel.h"

class ImplantModel : public EquipmentModel {
public:
    ImplantModel(string name, int max_hp, int atk, int def, int magic, int crit, int evade, int price, bool can_drop = false)
        : EquipmentModel("Implant", name, max_hp, atk, def, magic, crit, evade, price, can_drop) {}

};

#endif // IMPLANT_MODEL_H


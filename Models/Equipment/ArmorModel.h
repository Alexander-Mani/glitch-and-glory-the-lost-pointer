#ifndef ARMOUR_MODEL_H
#define ARMOUR_MODEL_H

#include "EquipmentModel.h"

class ArmorModel : public EquipmentModel {
public:
    ArmorModel(string name, int max_hp, int atk, int def, int magic, int crit, int evade, int price, bool can_drop = false)
        : EquipmentModel("Armor", name, max_hp, atk, def, magic, crit, evade, price, can_drop) {}

};

#endif // ARMOUR_MODEL_H


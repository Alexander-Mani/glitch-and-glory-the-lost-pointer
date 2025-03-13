#ifndef WEAPON_MODEL_H
#define WEAPON_MODEL_H

#include "EquipmentModel.h"

class WeaponModel : public EquipmentModel {
public:
    WeaponModel(string name, int max_hp, int atk, int def, int magic, int crit, int evade, int price, bool can_drop = false)
        : EquipmentModel("Weapon", name, max_hp, atk, def, magic, crit, evade, price, can_drop) {}

};

#endif // WEAPON_MODEL_H


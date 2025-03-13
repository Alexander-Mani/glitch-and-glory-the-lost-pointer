#ifndef EQUIPMENT_MODEL_H
#define EQUIPMENT_MODEL_H

#include <string>
using namespace std;

class EquipmentModel {
protected:
    string type; // "weapon", "armor", or "implant"
    string name;
    int max_hp;
    int atk;
    int def;
    int magic;
    int crit;
    int evade;
    int price;
    bool can_drop;
public:
    EquipmentModel(string type, string name, int max_hp, int atk, int def, int magic, int crit, int evade, int price, bool can_drop = false)
        : type(type), name(name), max_hp(max_hp), atk(atk), def(def), magic(magic), crit(crit), evade(evade), price(price), can_drop(can_drop) {}

    virtual ~EquipmentModel() = default;

    string get_type() const { return type; }
    string get_name() const { return name; }
    int get_max_hp() const { return max_hp; }
    int get_atk() const { return atk; }
    int get_def() const { return def; }
    int get_magic() const { return magic; }
    int get_crit() const { return crit; }
    int get_evade() const { return evade; }
    int get_price() const { return price; }
    bool is_droppable() const { return can_drop; }
};

#endif // EQUIPMENT_H


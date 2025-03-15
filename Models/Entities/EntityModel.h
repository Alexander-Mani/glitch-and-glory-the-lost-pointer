#ifndef ENTITY_MODEL_H
#define ENTITY_MODEL_H

#include <string>
#include <vector>
#include <unordered_map>
#include "../AllEquipment.h"
//#include "../WeaponModel.h"

using std::string;

// Forward declaration of EntityModel due to circular import
//class WeaponModel;


class EntityModel {
protected:
    std::string name;
    int max_hp;
    int hp;
    int atk;
    int def;
    int magic;
    int crit;
    int evade;
    int acc; // Accuracy
    std::vector<std::string> ascii_art;
    //WeaponModel *weapon;
    
    unordered_map<string, EquipmentModel*> inventory;
    
public:
    EntityModel(const std::string &name, int max_hp, int hp, int atk, int def, int magic, int crit, int evade, int acc, std::vector<std::string> ascii_art);
    
    virtual ~EntityModel() = default;

    // Default implementation prints the common stats.
    virtual void display_stats() const;
    
    void display_ascii() const;

    virtual vector<string> get_stats_lines();
    
    const std::vector<std::string>& get_ascii() const { return ascii_art; }

    std::string get_name() const { return name; }
    int get_max_hp() const { return max_hp; }
    int get_hp() const { return hp; }
    int get_atk() const { return atk; }
    int get_def() const { return def; }
    int get_magic() const { return magic; }
    int get_crit() const { return crit; }
    int get_evade() const { return evade; }
    int get_acc() const { return acc; }

    // int get_crit_chance(BattleModel* battleModel);
    void set_hp(int val) { this->hp=val; }
    void set_atk(int val) { this->hp=val; }
    void set_def(int val) { this->hp=val; }
    void set_magic(int val) { this->hp=val; }
    void set_crit(int val) { this->hp=val; }
    void set_evade(int val) { this->hp=val; }

    std::vector<int> get_battle_stats() const {
        return {hp, atk, def, magic, crit, evade};
    }

    std::vector<std::string> get_battle_stat_names() const{
        return {"Health", "Attack", "Defence", "Hacking", "Critical", "Evasion"};
    }

    virtual void increase_hp(int amount) {
        this->hp += amount;
    }

    virtual void increase_def(int amount) {
        this->def += amount;
    }

    virtual void decrease_hp(int amount) {
        this->hp -= amount;
        if(hp < 0) hp = 0;
    }

    virtual void decrease_def(int amount) {
        this->def -= amount;
        if(def < 0) def = 0;
    }

    virtual void zero_hack_points() {
        this->magic = 0;
    }




    bool equip_item(const std::string &slot, EquipmentModel *item);
    EquipmentModel* get_equipped_item(const std::string &slot) const;
    vector<string> get_inventory() const;
    virtual void decrease_magic(int amount) {
        this->magic -= amount;
        if(magic < 0) magic = 0;
    }


    void level_up(unsigned int level) {
        this->max_hp+= (level*2);
        this->hp += level;
        this->atk += level;
        this->def += level;
        this->magic += level;
        this->crit += level;
        this->evade += level;
    
    }
};

#endif // ENTITY_MODEL_H

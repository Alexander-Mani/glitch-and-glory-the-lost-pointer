#ifndef ENTITY_MODEL_H
#define ENTITY_MODEL_H

#include <string>
#include <vector>
#include <unordered_map>

#include "../WeaponModel.h"

// Forward declaration of EntityModel due to circular import
class WeaponModel;


class EntityModel {
protected:
    std::string name;
    int hp;
    int atk;
    int def;
    int magic;
    int crit;
    int evade;
    std::vector<std::string> ascii_art;
    WeaponModel *weapon;

public:
    EntityModel(const std::string &name, int hp, int atk, int def, int magic, int crit, int evade, std::vector<std::string> ascii_art, WeaponModel *weapon);
    
    virtual ~EntityModel() = default;

    // Default implementation prints the common stats.
    virtual void display_stats() const;
    
    void display_ascii() const;
    
    const std::vector<std::string>& get_ascii() const { return ascii_art; }

    std::string get_name() const { return name; }
    int get_hp() const { return hp; }
    int get_atk() const { return atk; }
    int get_def() const { return def; }
    int get_magic() const { return magic; }
    int get_crit() const { return crit; }
    int get_evade() const { return evade; }

    std::vector<int> get_battle_stats() const {
        return {hp, atk, def, magic, crit, evade};
    }

    std::vector<std::string> get_battle_stat_names() const{
        return {"Health", "Attack", "Defence", "Magic", "Critical", "Evasion"};
    }

    virtual void decrease_hp(int damage) {
        this->hp -= damage;
        if(hp < 0) hp = 0;
    }

    virtual void decrease_magic(int amount) {
        this->magic -= amount;
        if(magic < 0) magic = 0;
    }

    /*
     * @brief Simply gets the weapon for Entity
     */
    WeaponModel *get_weapon();


};

#endif // ENTITY_MODEL_H






//============================================//
//======= TOMMI OLD CODE FOR REFERENCE =======//
//============================================//

// #ifndef ENTITYPARENTMODEL_H
// #define ENTITYPARENTMODEL_H

// #include <string>

// class Entity {
// protected:
//     std::string name;
//     int hp;
//     int atk;
//     int def;
//     int magic;
//     int crit;
//     int evade;

// public:
//     Entity(const std::string &name, int hp, int atk, int def, int magic, int crit, int evade);
//     virtual ~Entity() = default;

//     virtual void displayStats() const = 0;

//     std::string getName() const { return name; }
//     int getHP() const { return hp; }
//     int getATK() const { return atk; }
//     int getDEF() const { return def; }
//     int getMagic() const { return magic; }
//     int getCrit() const { return crit; }
//     int getEvade() const { return evade; }
// };

// class TechnoOracle : public Entity {
// public:
//     TechnoOracle();
//     void displayStats() const override;
// };

// class CyberGladiator : public Entity {
// public:
//     CyberGladiator();
//     void displayStats() const override;
// };

// class BioEnhancedBerserker : public Entity {
// public:
//     BioEnhancedBerserker();
//     void displayStats() const override;
// };

// #endif

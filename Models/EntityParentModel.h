#ifndef ENTITYPARENTMODEL_H
#define ENTITYPARENTMODEL_H

#include <string>

class Entity {
protected:
    std::string name;
    int hp;
    int atk;
    int def;
    int magic;
    int crit;
    int evade;

public:
    Entity(const std::string &name, int hp, int atk, int def, int magic, int crit, int evade);
    virtual ~Entity() = default;

    virtual void displayStats() const = 0;

    std::string getName() const { return name; }
    int getHP() const { return hp; }
    int getATK() const { return atk; }
    int getDEF() const { return def; }
    int getMagic() const { return magic; }
    int getCrit() const { return crit; }
    int getEvade() const { return evade; }
};

class TechnoOracle : public Entity {
public:
    TechnoOracle();
    void displayStats() const override;
};

class CyberGladiator : public Entity {
public:
    CyberGladiator();
    void displayStats() const override;
};

class BioEnhancedBerserker : public Entity {
public:
    BioEnhancedBerserker();
    void displayStats() const override;
};

#endif

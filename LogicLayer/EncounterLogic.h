#ifndef ENCOUNTERLOGIC_H
#define ENCOUNTERLOGIC_H

#include <string>
#include <vector>
#include <functional>
#include "../Models/Entities/EntityModel.h"


struct Encounter {
    std::string description;
    std::vector<std::string> options;

    std::vector<std::function<std::string(EntityModel*)>> outcomes;
};

class EncounterLogic {
public:
    EncounterLogic();
    // Returns a random encounter from the list.
    Encounter get_random_encounter();

private:
    std::vector<Encounter> encounters;
    void populate_encounters();
};

#endif // ENCOUNTERLOGIC_H

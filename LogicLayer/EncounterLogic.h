#ifndef ENCOUNTERLOGIC_H
#define ENCOUNTERLOGIC_H

#include <string>
#include <vector>
#include <functional>
#include "../Models/AllEntities.h"
#include "../Models/PartyModel.h"

struct Encounter {
    std::string description;
    std::vector<std::string> options;
    std::vector<std::function<std::string(PartyModel* partyModel, EntityModel* entityModel)>> outcomes;
};

class EncounterLogic {
public:
    EncounterLogic();
    Encounter get_random_encounter();
    bool will_get_encounter();

private:
    std::vector<Encounter> encounters;
    void populate_encounters();

    // Outcome methods for encounters
    static std::string cyber_beggar_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string cyber_beggar_option_2(PartyModel* partyModel, EntityModel* entityModel);

    static std::string cyber_sage_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string cyber_sage_option_2(PartyModel* partyModel, EntityModel* entityModel);

    static std::string biotech_elixir_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string biotech_elixir_option_2(PartyModel* partyModel, EntityModel* entityModel);

    static std::string holo_crossing_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string holo_crossing_option_2(PartyModel* partyModel, EntityModel* entityModel);

    static std::string digital_acrobatics_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string digital_acrobatics_option_2(PartyModel* partyModel, EntityModel* entityModel);

    static std::string neon_upgrade_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string neon_upgrade_option_2(PartyModel* partyModel, EntityModel* entityModel);

    static std::string rogue_ai_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string rogue_ai_option_2(PartyModel* partyModel, EntityModel* entityModel);

    static std::string rival_gladiator_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string rival_gladiator_option_2(PartyModel* partyModel, EntityModel* entityModel);

    static std::string glitched_vision_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string glitched_vision_option_2(PartyModel* partyModel, EntityModel* entityModel);

    static std::string nano_med_infusion_option_1(PartyModel* partyModel, EntityModel* entityModel);
    static std::string nano_med_infusion_option_2(PartyModel* partyModel, EntityModel* entityModel);
};

#endif // ENCOUNTERLOGIC_H


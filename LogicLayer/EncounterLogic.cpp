#include "EncounterLogic.h"
#include <random>

EncounterLogic::EncounterLogic() {
    populate_encounters();
}

void EncounterLogic::populate_encounters() {
    // Encounter 1: Cyber Beggar
    encounters.emplace_back(Encounter{
        "A scruffy cyber beggar, cloaked in neon grime, pleads for 10 eurodollar.",
        {"Give him 10 eurodollar", "Refuse and walk away"},
        { cyber_beggar_option_1, cyber_beggar_option_2 }
    });

    // Encounter 2: Cyber Sage Challenge
    encounters.emplace_back(Encounter{
        "A grizzled cyber sage, his eyes aglow with digital secrets, challenges you to a duel of wits.",
        {"Accept his challenge", "Decline politely"},
        { cyber_sage_option_1, cyber_sage_option_2 }
    });

    // Encounter 3: Biotech Elixir
    encounters.emplace_back(Encounter{
        "A slick data merchant under flickering neon offers you a mysterious biotech elixir.",
        {"Drink the potion", "Politely decline"},
        { biotech_elixir_option_1, biotech_elixir_option_2 }
    });

    // Encounter 4: Holo-Crossing Helper
    encounters.emplace_back(Encounter{
        "An elderly net-runner in worn cyber attire asks for help navigating a bustling holo-crossing.",
        {"Help her", "Ignore her"},
        { holo_crossing_option_1, holo_crossing_option_2 }
    });

    // Encounter 5: Digital Acrobatics
    encounters.emplace_back(Encounter{
        "A holographic street performer beckons you to a fast-paced contest of digital acrobatics.",
        {"Join the contest", "Watch quietly"},
        { digital_acrobatics_option_1, digital_acrobatics_option_2 }
    });

    // Encounter 6: Neon Upgrade
    encounters.emplace_back(Encounter{
        "A neon-lit street vendor hawks a sleek upgrade chip in a dark alley.",
        {"Install the chip", "Walk away"},
        { neon_upgrade_option_1, neon_upgrade_option_2 }
    });

    // Encounter 7: Rogue AI Dilemma
    encounters.emplace_back(Encounter{
        "A holographic projection of a rogue AI materializes, begging for help to overthrow a corrupt system.",
        {"Help the AI", "Shut it down"},
        { rogue_ai_option_1, rogue_ai_option_2 }
    });

    // Encounter 8: Rival Gladiator Challenge
    encounters.emplace_back(Encounter{
        "A rival cyber gladiator steps forward, challenging you to a quick hack-off in a rain-soaked arena.",
        {"Accept the challenge", "Decline"},
        { rival_gladiator_option_1, rival_gladiator_option_2 }
    });

    // Encounter 9: Glitched Vision
    encounters.emplace_back(Encounter{
        "A sudden glitch in the matrix distorts your vision under the buzzing neon lights.",
        {"Steady yourself", "Let the glitch take over"},
        { glitched_vision_option_1, glitched_vision_option_2 }
    });

    // Encounter 10: Nano-Med Infusion
    encounters.emplace_back(Encounter{
        "An underground medic offers you a nano-infusion amidst the neon chaos of the backstreets.",
        {"Take the infusion", "Refuse"},
        { nano_med_infusion_option_1, nano_med_infusion_option_2 }
    });
}
bool EncounterLogic::will_get_encounter(){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 6);
    if (dist(gen) == 1) return true;
    return false;
}

Encounter EncounterLogic::get_random_encounter() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, static_cast<int>(encounters.size() - 1));
    return encounters[distr(gen)];
}

// Outcome methods

// Encounter 1: Cyber Beggar
std::string EncounterLogic::cyber_beggar_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int current_atk = entityModel->get_atk();
    if (current_atk < 10) return "The begger runs off into the subway";
    entityModel->set_atk(current_atk - 5);
    return "You gave the beggar 10 eurodollar. Your attack will be reduced by 5 for the foreseeable future.";
}
std::string EncounterLogic::cyber_beggar_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    int current_def = entityModel->get_def();
    entityModel->set_def(current_def + 2);
    return "You refused to give money. Your defense will increase by 2 for the foreseeable future.";
}

// Encounter 2: Cyber Sage Challenge
std::string EncounterLogic::cyber_sage_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int current_atk = entityModel->get_atk();
    int current_def = entityModel->get_def();
    if (current_def < 20) return "He forgot something at home and runs off never to be seen again. (you defense is too low).";
    entityModel->set_atk(current_atk + 3);
    entityModel->set_def(current_def - 2);
    return "You accepted the challenge. Your attack increases by 3, but your defense decreases by 2.";
}
std::string EncounterLogic::cyber_sage_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    return "You declined the challenge. No changes to your stats.";
}

// Encounter 3: Biotech Elixir
std::string EncounterLogic::biotech_elixir_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int current_magic = entityModel->get_magic();
    entityModel->set_magic(current_magic + 5);
    return "You drink the potion. Your magic increases by 5.";
}
std::string EncounterLogic::biotech_elixir_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    return "You politely decline. No changes occur.";
}

// Encounter 4: Holo-Crossing Helper
std::string EncounterLogic::holo_crossing_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int current_def = entityModel->get_def();
    entityModel->set_def(current_def + 3);
    return "You help her navigate the crossing. Your defense increases by 3.";
}
std::string EncounterLogic::holo_crossing_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    return "You ignore her request. No changes occur.";
}

// Encounter 5: Digital Acrobatics
std::string EncounterLogic::digital_acrobatics_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int current_crit = entityModel->get_crit();
    entityModel->set_crit(current_crit + 2);
    return "You join the contest. Your critical hit chance increases by 2.";
}
std::string EncounterLogic::digital_acrobatics_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    return "You watch the contest. No changes occur.";
}

// Encounter 6: Neon Upgrade
std::string EncounterLogic::neon_upgrade_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int atk = entityModel->get_atk();
    entityModel->set_atk(atk + 4);
    return "You installed the upgrade chip. Your attack increases by 4.";
}
std::string EncounterLogic::neon_upgrade_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    return "You ignore the vendor and continue on your way. Nothing changes.";
}

// Encounter 7: Rogue AI Dilemma
std::string EncounterLogic::rogue_ai_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int current_magic = entityModel->get_magic();
    int current_crit = entityModel->get_crit();
    int current_def = entityModel->get_def();
    entityModel->set_magic(current_magic + 3);
    entityModel->set_crit(current_crit + 1);
    if (current_def >= 30) entityModel->set_def(current_def - 1);
    return "You assist the AI. Your magic increases by 3 and critical chance by 1, but your defense drops by 1.";
}
std::string EncounterLogic::rogue_ai_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    return "You shut the AI down. The system remains corrupt, but your stats remain unchanged.";
}

// Encounter 8: Rival Gladiator Challenge
std::string EncounterLogic::rival_gladiator_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int current_crit = entityModel->get_crit();
    int current_atk = entityModel->get_atk();
    entityModel->set_crit(current_crit + 2);
    entityModel->set_atk(current_atk + 2);
    return "You accept the challenge and win. Your critical chance increases by 2 and your attack by 2.";
}
std::string EncounterLogic::rival_gladiator_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    return "You decline the challenge. You avoid conflict, and your stats remain steady.";
}

// Encounter 9: Glitched Vision
std::string EncounterLogic::glitched_vision_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int current_evade = entityModel->get_evade();
    entityModel->set_evade(current_evade + 5);
    return "You steady your focus and overcome the distortion. Your evasion increases by 5.";
}
std::string EncounterLogic::glitched_vision_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    int atk = entityModel->get_atk();
    int current_magic = entityModel->get_magic();
    if (atk >= 30) entityModel->set_atk(atk - 2);
    entityModel->set_magic(current_magic + 2);
    return "You succumb to the glitch. Your attack drops by 2 but your magic rises by 2.";
}

// Encounter 10: Nano-Med Infusion
std::string EncounterLogic::nano_med_infusion_option_1(PartyModel* partyModel, EntityModel* entityModel) {
    int current_hp = entityModel->get_hp();
    int current_def = entityModel->get_def();
    entityModel->set_hp(current_hp + 20);
    if (current_def >= 30) entityModel->set_def(current_def - 1);
    return "You take the nano-infusion. Your HP increases by 20, but your defense drops by 1.";
}
std::string EncounterLogic::nano_med_infusion_option_2(PartyModel* partyModel, EntityModel* entityModel) {
    return "You refuse the infusion. You risk staying raw, but nothing changes.";
}


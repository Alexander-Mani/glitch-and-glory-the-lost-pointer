#include "EncounterLogic.h"
#include <random>
#include <iostream>

// // Static helper function to roll for an encounter (25% chance).
// static bool roll_for_encounter() {
//     static std::random_device rd;
//     static std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dist(1, 4);
//     return (dist(gen) == 1);
// } // if (roll_for_encounter()) {
//     //// Trigger encounter
//    // encounterHandler.initialize_encounter(player);
// //}

EncounterLogic::EncounterLogic() {
    populate_encounters();
}

void EncounterLogic::populate_encounters() {

    // Encounter 1: Cyber Beggar
    Encounter e1;
    e1.description = "A scruffy cyber beggar, cloaked in neon grime, pleads for 10 eurodollar.";
    e1.options = {"Give him 10 eurodollar", "Refuse and walk away"};
    e1.outcomes = {
        // Option 1: Give money → lower attack by 5 for next battle.
        [](EntityModel* player) -> std::string {
            int currentAtk = player->get_atk();
            player->set_atk(currentAtk - 5);
            return "You gave the beggar 10 eurodollar. Your attack will be reduced by 5 in the next battle.";
        },
        // Option 2: Refuse → increase defense by 2 for next battle.
        [](EntityModel* player) -> std::string {
            int currentDef = player->get_def();
            player->set_def(currentDef + 2);
            return "You refused to give money. Your defense will increase by 2 in the next battle.";
        }
    };
    encounters.push_back(e1);

    // Encounter 2: Cyber Sage Challenge
    Encounter e2;
    e2.description = "A grizzled cyber sage, his eyes aglow with digital secrets, challenges you to a duel of wits.";
    e2.options = {"Accept his challenge", "Decline politely"};
    e2.outcomes = {
        // Option 1: Accept challenge → increase attack by 3, but lower defense by 2.
        [](EntityModel* player) -> std::string {
            int currentAtk = player->get_atk();
            int currentDef = player->get_def();
            player->set_atk(currentAtk + 3);
            player->set_def(currentDef - 2);
            return "You accepted the challenge. Your attack increases by 3, but your defense decreases by 2 for the next battle.";
        },
        // Option 2: Decline → no stat change.
        [](EntityModel* player) -> std::string {
            return "You declined the challenge. No changes to your stats.";
        }
    };
    encounters.push_back(e2);

    // Encounter 3: Biotech Elixir
    Encounter e3;
    e3.description = "A slick data merchant under flickering neon offers you a mysterious biotech elixir.";
    e3.options = {"Drink the potion", "Politely decline"};
    e3.outcomes = {
        // Option 1: Drink the potion → increase magic by 5.
        [](EntityModel* player) -> std::string {
            int currentMagic = player->get_magic();
            player->set_magic(currentMagic + 5);
            return "You drink the potion. Your magic increases by 5 for the next battle.";
        },
        // Option 2: Decline → no change.
        [](EntityModel* player) -> std::string {
            return "You politely decline. No changes occur.";
        }
    };
    encounters.push_back(e3);

    // Encounter 4: Holo-Crossing Helper
    Encounter e4;
    e4.description = "An elderly net-runner in worn cyber attire asks for help navigating a bustling holo-crossing.";
    e4.options = {"Help her", "Ignore her"};
    e4.outcomes = {
        [](EntityModel* player) -> std::string {
            int currentDef = player->get_def();
            player->set_def(currentDef + 3);
            return "You help her navigate the crossing. Your defense increases by 3 for the next battle.";
        },
        [](EntityModel* player) -> std::string {
            return "You ignore her request. No changes occur.";
        }
    };
    encounters.push_back(e4);

    // Encounter 5: Digital Acrobatics
    Encounter e5;
    e5.description = "A holographic street performer beckons you to a fast-paced contest of digital acrobatics.";
    e5.options = {"Join the contest", "Watch quietly"};
    e5.outcomes = {
        [](EntityModel* player) -> std::string {
            int currentCrit = player->get_crit();
            player->set_crit(currentCrit + 2);
            return "You join the contest. Your critical hit chance increases by 2 for the next battle.";
        },
        [](EntityModel* player) -> std::string {
            return "You watch the contest. No changes occur.";
        }
    };
    encounters.push_back(e5);


    // Encounter 6: Neon Upgrade
    Encounter e6;
    e6.description = "A neon-lit street vendor hawks a sleek upgrade chip in a dark alley.";
    e6.options = {"Install the chip", "Walk away"};
    e6.outcomes = {
        // Option 1: Boost attack by 4.
        [](EntityModel* player) -> std::string {
            int atk = player->get_atk();
            player->set_atk(atk + 4);
            return "You installed the upgrade chip. Your attack increases by 4 for the next battle.";
        },
        // Option 2: No change.
        [](EntityModel* player) -> std::string {
            return "You ignore the vendor and continue on your way. Nothing changes.";
        }
    };
    encounters.push_back(e6);

    // Encounter 7: Rogue AI Dilemma
    Encounter e7;
    e7.description = "A holographic projection of a rogue AI materializes, begging for help to overthrow a corrupt system.";
    e7.options = {"Help the AI", "Shut it down"};
    e7.outcomes = {
        // Option 1: Increase magic by 3 and crit by 1, but lower defense by 1.
        [](EntityModel* player) -> std::string {
            int magic = player->get_magic();
            int crit = player->get_crit();
            int def = player->get_def();
            player->set_magic(magic + 3);
            player->set_crit(crit + 1);
            player->set_def(def - 1);
            return "You assist the AI. Your magic increases by 3 and critical chance by 1, but your defense drops by 1.";
        },
        // Option 2: No changes.
        [](EntityModel* player) -> std::string {
            return "You shut the AI down. The system remains corrupt, but your stats remain unchanged.";
        }
    };
    encounters.push_back(e7);

    // Encounter 8: Rival Gladiator Challenge
    Encounter e8;
    e8.description = "A rival cyber gladiator steps forward, challenging you to a quick hack-off in a rain-soaked arena.";
    e8.options = {"Accept the challenge", "Decline"};
    e8.outcomes = {
        // Option 1: Increase crit by 2 and attack by 2.
        [](EntityModel* player) -> std::string {
            int crit = player->get_crit();
            int atk = player->get_atk();
            player->set_crit(crit + 2);
            player->set_atk(atk + 2);
            return "You accept the challenge and win. Your critical chance increases by 2 and your attack by 2.";
        },
        // Option 2: No change.
        [](EntityModel* player) -> std::string {
            return "You decline the challenge. You avoid conflict, and your stats remain steady.";
        }
    };
    encounters.push_back(e8);

    // Encounter 9: Glitched Vision
    Encounter e9;
    e9.description = "A sudden glitch in the matrix distorts your vision under the buzzing neon lights.";
    e9.options = {"Steady yourself", "Let the glitch take over"};
    e9.outcomes = {
        // Option 1: Increase evade by 5.
        [](EntityModel* player) -> std::string {
            int evade = player->get_evade();
            player->set_evade(evade + 5);
            return "You steady your focus and overcome the distortion. Your evasion increases by 5.";
        },
        // Option 2: Lower attack by 2 but increase magic by 2.
        [](EntityModel* player) -> std::string {
            int atk = player->get_atk();
            int magic = player->get_magic();
            player->set_atk(atk - 2);
            player->set_magic(magic + 2);
            return "You succumb to the glitch. Your attack drops by 2 but your magic rises by 2.";
        }
    };
    encounters.push_back(e9);

    // Encounter 10: Nano-Med Infusion
    Encounter e10;
    e10.description = "An underground medic offers you a nano-infusion amidst the neon chaos of the backstreets.";
    e10.options = {"Take the infusion", "Refuse"};
    e10.outcomes = {
        // Option 1: Increase HP by 20 but decrease defense by 1.
        [](EntityModel* player) -> std::string {
            int hp = player->get_hp();
            int def = player->get_def();
            player->set_hp(hp + 20);
            player->set_def(def - 1);
            return "You take the nano-infusion. Your HP increases by 20, but your defense drops by 1.";
        },
        // Option 2: No change.
        [](EntityModel* player) -> std::string {
            return "You refuse the infusion. You risk staying raw, but nothing changes.";
        }
    };
    encounters.push_back(e10);


    // (Add more encounters up to 15 following the same pattern as desired.)
}

Encounter EncounterLogic::get_random_encounter() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, encounters.size() - 1);
    return encounters[distr(gen)];
}

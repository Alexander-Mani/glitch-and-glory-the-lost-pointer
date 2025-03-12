// UILayer/EncounterHandler.cpp
#include "EncounterHandler.h"
#include "../LogicLayer/EncounterLogic.h"
#include "../Models/Entities/EntityModel.h"
#include "../Models/Entities/CyberGladiatorModel.h"  // Example player entity
#include "IOHandler.h"
#include <iostream>

EncounterHandler::EncounterHandler() {
    // Initialization if needed.
}

void EncounterHandler::initialize_encounter(EntityModel* player) {
    if (!player) {
        player = new CyberGladiatorModel();
    } // test, create entity if no entity
    

    EncounterLogic encounterLogic;
    Encounter encounter = encounterLogic.get_random_encounter();

    ioHandler.output_title("Encounter");
    ioHandler.output_msg(encounter.description);
    ioHandler.output_options("Choose your action:", encounter.options);

    std::string selected = ioHandler.input_choose_option(encounter.options);
    int choiceIndex = 0;
    for (size_t i = 0; i < encounter.options.size(); ++i) {
        if (encounter.options[i] == selected) {
            choiceIndex = i;
            break;
        }
    }

    std::string outcomeMsg = encounter.outcomes[choiceIndex](player);
    ioHandler.output_battle_info(outcomeMsg);

} // use the one below lexi 
// void EncounterHandler::initialize_encounter(EntityModel* ) {
//     // Assume 'party' is an accessible party model that holds your three members.
//     std::vector<EntityModel*> partyMembers = party.getMembers();  // e.g., party.getMembers() returns your 3 members
//     std::vector<std::string> names;
//     for (auto member : partyMembers) {
//         names.push_back(member->get_name());
//     }
    
//     // Let the user pick a party member
//     std::string choice = ioHandler.input_choose_option(names);
    
//     // Find the index corresponding to the chosen name
//     int choiceIndex = 0;
//     for (size_t i = 0; i < names.size(); ++i) {
//         if (names[i] == choice) {
//             choiceIndex = static_cast<int>(i);
//             break;
//         }
//     }
//     // Use the chosen party member for the encounter.
//     EntityModel* chosenMember = partyMembers[choiceIndex];

//     // Generate a random encounter.
//     EncounterLogic encounterLogic;
//     Encounter encounter = encounterLogic.get_random_encounter();

//     ioHandler.output_title("Encounter");
//     ioHandler.output_msg(encounter.description);
//     ioHandler.output_options("Choose your action:", encounter.options);

//     std::string selected = ioHandler.input_choose_option(encounter.options);
//     int outcomeIndex = 0;
//     for (size_t i = 0; i < encounter.options.size(); ++i) {
//         if (encounter.options[i] == selected) {
//             outcomeIndex = static_cast<int>(i);
//             break;
//         }
//     }

//     // Apply the chosen outcome to the selected party member.
//     std::string outcomeMsg = encounter.outcomes[outcomeIndex](chosenMember);
//     ioHandler.output_battle_info(outcomeMsg);
// }

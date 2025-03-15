// UILayer/EncounterHandler.cpp
#include "EncounterHandler.h"
#include "../LogicLayer/EncounterLogic.h"
#include "../Models/Entities/EntityModel.h"
#include "../Models/Entities/CyberGladiatorModel.h"  // Example player entity
#include "IOHandler.h"
#include "AsciiHandler.h"
#include <cmath>
#include <iostream>

EncounterHandler::EncounterHandler(LogicWrapper *logicWrapper) {
    this->logicWrapper = logicWrapper;
}


void EncounterHandler::get_random_encounter(PartyModel* partyModel, EntityModel *entityModel){
    Encounter encounter = this->logicWrapper->encounterLogic->get_random_encounter();

    IOHandler::output_title("Encounter");
    IOHandler::output_msg(encounter.description);
    IOHandler::output_options("Choose your action:", encounter.options);

    std::string selected = IOHandler::input_choose_option(encounter.options);
    int choiceIndex = 0;
    for (size_t i = 0; i < encounter.options.size(); ++i) {
        if (encounter.options[i] == selected) {
            choiceIndex = i;
            break;
        }
    }

    std::string outcomeMsg = encounter.outcomes[choiceIndex](partyModel, entityModel);
    IOHandler::output_battle_info(outcomeMsg);



}


#include "EncounterHandler.h"
#include "../LogicLayer/EncounterLogic.h"
#include "../Models/Entities/EntityModel.h"
#include "../Models/Entities/CyberGladiatorModel.h"  
#include "IOHandler.h"
#include "AsciiHandler.h"
#include <cmath>
#include <iostream>

EncounterHandler::EncounterHandler(LogicWrapper *logicWrapper) {
    this->logicWrapper = logicWrapper;
}

#include <typeinfo> 
void EncounterHandler::get_random_encounter(PartyModel* partyModel, EntityModel *entityModel){
    
    
    size_t max_line_width = 100; 
    Encounter encounter = this->logicWrapper->encounterLogic->get_random_encounter();
    
    
    vector<string> description_lines;
    vector<string> description = IOHandler::wrap_text(encounter.description, max_line_width);
    
    description_lines.push_back("");
    description_lines.insert(description_lines.end(), description.begin(), description.end());
    description_lines.push_back("");
    
    
    IOHandler::clear_terminal();
    AsciiHandler::display_box_layout("Encounter", description_lines, "yellow", "yellow");
    
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

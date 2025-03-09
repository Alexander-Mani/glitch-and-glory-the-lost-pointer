#include "BattleHandler.h"
#include "IOHandler.h"
#include "../Models/AllEntities.h"      // For all entity models
#include "../LogicLayer/EntityLogic.h"    // For EntityLogic

BattleHandler::BattleHandler(LogicWrapper* logicWrapper)
    : logicWrapper(logicWrapper)
{
    this->ioHandler = IOHandler();
}

void BattleHandler::initialize_battle() {
    this->ioHandler.output_title("Welcome to battle arena!");
    
    
    //--- Selecting Entity For Player ---//
    EntityModel* player_entity = this->select_entity(true);
    
    //--- Selecting Entity For Opponent ---//
    EntityModel* opponent_entity = this->select_entity(false);

    
    (void) player_entity;
    (void) opponent_entity;
}


EntityModel* BattleHandler::select_entity(bool for_player) {

    string menu_msg;
    if(for_player)
        menu_msg = "Select an Entity for player";
    else
        menu_msg = "Select an Entity for opponent";


    // Use EntityLogic to get all entity models via their classes.
    vector<EntityModel*> entities = this->logicWrapper->entityLogic.get_all_entities();

    // Create a list of entity names for the menu in the same order as entities.
    vector<string> entity_options;
    for(auto entity : entities) {
        entity_options.push_back(entity->get_name());
    }

    // Display the menu of available entities with custom msg depending on for_player value
    this->ioHandler.output_options(menu_msg, entity_options);
    string selected = this->ioHandler.input_choose_option(entity_options);

    //--- Find the chosen entity ---//
    EntityModel* chosen_entity = nullptr;
    // For entity in entities
    for(EntityModel* entity : entities) {
        if(entity->get_name() == selected) {
            chosen_entity = entity;
            break;
        }
    }

    if(chosen_entity) {
        this->ioHandler.output_msg("You selected: " + chosen_entity->get_name());
        chosen_entity->display_stats();
        return chosen_entity;
    } else {
        this->ioHandler.output_msg("Entity not found.");
        // Since no entity was found, we recursively call the same function
        return select_entity(for_player);
    }
}



// TESTING
// // Create an instance of CyberGladiatorModel
// CyberGladiatorModel cyber_gladiator;

// // Call the display_stats method to print the entity's stats
// cyber_gladiator.display_stats();
#include "BattleHandler.h"
#include "AsciiHandler.h"
#include "IOHandler.h"
#include "../Models/AllEntities.h"      // For all entity models
#include "../Models/BattleModel.h"
#include "../LogicLayer/EntityLogic.h"    // For EntityLogic
#include <string>

#include <cassert>

BattleHandler::BattleHandler(LogicWrapper* logicWrapper, AsciiHandler* asciiHandler)
    : logicWrapper(logicWrapper), asciiHandler(asciiHandler)
{
    this->ioHandler = IOHandler();
    // vector<string> game_options;
    
}

void BattleHandler::initialize_battle() {
    this->ioHandler.output_title("Welcome to battle arena!");
    
    
    //--- Selecting Entity For Player ---//
    EntityModel* player_entity = this->select_entity(true);
    
    //--- Selecting Entity For Opponent ---//
    EntityModel* opponent_entity = this->select_entity(false);

    BattleModel* battleModel = new BattleModel(player_entity, opponent_entity, true);
    // Using evade as initave
    if (player_entity->get_evade() <= opponent_entity->get_evade()) battleModel->player_turn = false;
    // Start battle
    if (player_entity && opponent_entity && battleModel) this->start_battle(battleModel); 

    
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
        this->asciiHandler->display_ascii(chosen_entity->get_name());
        return chosen_entity;
    } else {
        this->ioHandler.output_msg("Entity not found.");
        // Since no entity was found, we recursively call the same function
        return select_entity(for_player);
    }

}
void BattleHandler::start_battle(BattleModel *battleModel) {
    this->asciiHandler->display_start_of_battle(battleModel);
    // bool battle_on = true;
    // int stub_ind = 0;
    string action;
    vector<string> action_list = battleModel->get_battle_actions(); 
    this->ioHandler.glitch_sleep(3);
    // while (battle_on) {
        //call some kind of divider or clear screen func
        
        
        
        // While goal state has not been reached
        while (!this->logicWrapper->battleLogic.game_over(battleModel)) {
            this->ioHandler.clear_terminal();

            this->asciiHandler->display_turn(battleModel);
            action = this->ioHandler.input_choose_option(action_list);

            string result = this->logicWrapper->battleLogic.handle_battle_action(battleModel, action);
            
            this->ioHandler.output_battle_info(result); // Mátt taka þetta í burtu ef þér finnst þetta vera hella slay
            
            //display round and stats
            this->asciiHandler->display_turn(battleModel);



            this->ioHandler.glitch_sleep(3);
        }
        
    // }
}

// TESTING
// // Create an instance of CyberGladiatorModel
// CyberGladiatorModel cyber_gladiator;

// // Call the display_stats method to print the entity's stats
// cyber_gladiator.display_stats();

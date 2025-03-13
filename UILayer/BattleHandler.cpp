#include "BattleHandler.h"
#include "AsciiHandler.h"
#include "IOHandler.h"
#include "../Models/AllEntities.h"      // For all entity models
#include "../Models/BattleModel.h"
#include "../LogicLayer/EntityLogic.h"    // For EntityLogic
#include <string>

#include <cassert>

BattleHandler::BattleHandler(LogicWrapper* logicWrapper, AsciiHandler* asciiHandler, IOHandler *ioHandler)
    : logicWrapper(logicWrapper), asciiHandler(asciiHandler), ioHandler(ioHandler)
{}


void BattleHandler::initialize_battle() {
    this->ioHandler->output_title("Welcome to battle arena!");
    
    
    //--- Selecting Entity For Player ---//
    EntityModel* player_entity = this->select_entity(true);
    
    //--- Selecting Entity For Opponent ---//
    EntityModel* opponent_entity = this->select_entity(false);

    BattleModel* battleModel = new BattleModel(player_entity, opponent_entity, true);
    // Using evade as initave
    
    if (player_entity && opponent_entity && battleModel) 
        this->start_battle(battleModel); 

}


EntityModel* BattleHandler::select_entity(bool for_player) {

    string menu_msg;
    if(for_player)
        menu_msg = "Select an Entity for player";
    else
        menu_msg = "Select an Entity for opponent";


    // Use EntityLogic to get all entity models via their classes.
    vector<EntityModel*> entities = this->logicWrapper->entityLogic->get_all_entities();

    // Create a list of entity names for the menu in the same order as entities.
    vector<string> entity_options;
    for(auto entity : entities) {
        entity_options.push_back(entity->get_name());
    }

    // Display the menu of available entities with custom msg depending on for_player value
    this->ioHandler->output_options(menu_msg, entity_options);
    string selected = this->ioHandler->input_choose_option(entity_options);

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
        this->ioHandler->output_msg("You selected: " + chosen_entity->get_name());
        chosen_entity->display_stats();
        this->asciiHandler->display_ascii(chosen_entity->get_name());
        return chosen_entity;
    } else {
        this->ioHandler->output_msg("Entity not found.");
        // Since no entity was found, we recursively call the same function
        return select_entity(for_player);
    }
}


void BattleHandler::start_battle(BattleModel *battleModel) {
    int terminal_length = this->asciiHandler->get_battle_width(battleModel);

    this->ioHandler->clear_terminal();
    this->asciiHandler->display_start_of_battle(battleModel);
    vector<string> action_list = battleModel->get_battle_actions();
    this->ioHandler->glitch_sleep(2);
    while (!this->logicWrapper->battleLogic->battle_over(battleModel)) {
        this->ioHandler->glitch_sleep(1);

        this->ioHandler->clear_terminal();
        this->asciiHandler->display_turn(battleModel);

        string action;

        if(!battleModel->player_turn){
            action = this->logicWrapper->battleLogic->handle_computer_action(battleModel);
            // continue;
        } else {
            action = this->ioHandler->input_choose_option(action_list);
        }
        // string 
        vector<string> hud_msg;
        if(!battleModel->player_turn){
            hud_msg.push_back("Computer Action");
        } else {
            hud_msg.push_back("Human Action");
        }
        
        hud_msg.push_back(this->logicWrapper->battleLogic->handle_battle_action(battleModel, action));
        
        
        // Display the results of the action that was taken
        this->ioHandler->clear_terminal();
        this->asciiHandler->display_battle_entities(battleModel);
        this->asciiHandler->display_battle_stats(battleModel);
        this->asciiHandler->display_hud(hud_msg, '*', terminal_length);
        this->ioHandler->glitch_sleep(3);

    }

    this->asciiHandler->display_end_of_battle(battleModel);


}


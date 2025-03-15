#include "BattleHandler.h"
#include "AsciiHandler.h"
#include "IOHandler.h"
#include "../Models/AllEntities.h"      // For all entity models
#include "../Models/BattleModel.h"
#include "../LogicLayer/EntityLogic.h"    // For EntityLogic
#include <string>

#include <cassert>

BattleHandler::BattleHandler(LogicWrapper* logicWrapper)
    : logicWrapper(logicWrapper)
{}


void BattleHandler::initialize_battle() {
    IOHandler::output_title("Welcome to battle arena!");
    
    //--- Selecting Entity For Player ---//
    EntityModel* player_entity = this->select_entity(true);
    
    //--- Selecting Entity For Opponent ---//
    EntityModel* opponent_entity = this->select_entity(false);

    BattleModel* battleModel = new BattleModel(player_entity, opponent_entity, true, 100000);
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
    IOHandler::output_options(menu_msg, entity_options);
    string selected = IOHandler::input_choose_option(entity_options);

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
        IOHandler::output_msg("You selected: " + chosen_entity->get_name());
        chosen_entity->display_stats();
        AsciiHandler::display_ascii(chosen_entity->get_name());
        return chosen_entity;
    } else {
        IOHandler::output_msg("Entity not found.");
        // Since no entity was found, we recursively call the same function
        return select_entity(for_player);
    }
}


void BattleHandler::start_battle(BattleModel *battleModel) {
    int terminal_length = AsciiHandler::get_battle_width(battleModel);

    IOHandler::clear_terminal();
    AsciiHandler::display_start_of_battle(battleModel);
    vector<string> action_list = battleModel->get_battle_actions();
    IOHandler::glitch_sleep(2);
    while (!this->logicWrapper->battleLogic->battle_over(battleModel) && !battleModel->fled && !battleModel->bribed) {
        
        IOHandler::clear_terminal();
        if(battleModel->player_turn){            
            AsciiHandler::display_turn(battleModel);
            IOHandler::glitch_sleep(2);
        }
        // if(!battleModel->player_turn){
            // IOHandler::input_continue();
        // }
        // IOHandler::input("continue...");

        string action;

        if(!battleModel->player_turn){
            action = this->logicWrapper->battleLogic->handle_computer_action(battleModel);
            // continue;
        } else {
            action = IOHandler::input_choose_option(action_list);
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

        IOHandler::clear_terminal();
        AsciiHandler::display_battle_entities(battleModel);
        AsciiHandler::display_battle_stats(battleModel);
        AsciiHandler::display_hud(hud_msg, '*', terminal_length);
        
        IOHandler::glitch_sleep(2);
        // cout << "NUMMIE 2!!!" << endl;
        // IOHandler::input_continue();

    }

    // AsciiHandler::display_end_of_battle(battleModel);


}


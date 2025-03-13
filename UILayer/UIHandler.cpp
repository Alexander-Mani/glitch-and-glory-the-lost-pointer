#include "UIHandler.h"
#include "AsciiHandler.h"
#include "EncounterHandler.h"
#include "IOHandler.h"
#include "BattleHandler.h"

#include "../LogicLayer/LogicWrapper.h"
#include "OverworldHandler.h"

#include <iostream>
#include <vector>

using namespace std;


UIHandler::UIHandler() 
    // : overworldHandler(&logicWrapper, &asciiHandler)
{
    this->logicWrapper = new LogicWrapper();
    this->asciiHandler = new AsciiHandler(this->logicWrapper);
    this->ioHandler = new IOHandler();
    this->battleHandler = new BattleHandler(this->logicWrapper, this->asciiHandler, this->ioHandler);
    this->encounterHandler = new EncounterHandler(this->logicWrapper, this->ioHandler);
    this->overworldHandler = new OverworldHandler(this->logicWrapper, this->asciiHandler, this->ioHandler, this->battleHandler, this->encounterHandler);
    
    // Set up menu options and actions
    // this->menu_options = {"Play Game [phase 2]", "Activate Battle", "Quit"};
    // this->menu_actions["Play Game [phase 2]"] = [this]() { play_game(); };
// UIHandler::UIHandler() 
//     : logicWrapper(), 
//       ioHandler(), 
//       asciiHandler(),
//       overworldHandler(&logicWrapper, &asciiHandler),
//       battleHandler(&logicWrapper, &asciiHandler)   // Initialize battleHandler here with the pointer
// {
    // Now you can set up your menu_options and menu_actions, etc.
    this->menu_options = {"Play Game", "Activate Battle", "Activate Encounter", "Quit"};
    this->menu_actions["Play Game"] = [this]() { play_game(); };
    this->menu_actions["Activate Battle"]     = [this]() { activate_battle(); };
    this->menu_actions["Activate Encounter"]  = [this]() { activate_encounter(); };
    this->menu_actions["Quit"]                = [this]() { quit(); };
}


void UIHandler::initialize_game() {
    
    this->ioHandler->output_title("Welcome to Glitch & Glory!");

    string options_title = "Main Menu Options";
    // vector<string> menu_options = {"Play Game [phase 2]", "Activate Battle", "Quit"};
    this->ioHandler->output_options(options_title, this->menu_options); 
    string selected = this->ioHandler->input_choose_option(this->menu_options);

    // Call the corresponding action from the unordered_map.
    menu_actions[selected]();
}

void UIHandler::activate_encounter() {
    EntityModel* player = new CyberGladiatorModel();
    // Use the persistent player for encounters.
    //this->encounterHandler->get_random_encounter(player);
    // Print the player's updated stats after the encounter.
    player->display_stats();
}

void UIHandler::play_game(){
    this->ioHandler->output_subtitle("Starting the game...");
    this->overworldHandler->initialize_overworld();
}


void UIHandler::activate_battle(){
    this->battleHandler->initialize_battle();
    
}

void UIHandler::quit(){
    this->ioHandler->output_subtitle("Exiting the game...");
    exit(0);
}

UIHandler::~UIHandler() {
    delete battleHandler;
    delete ioHandler;
    delete asciiHandler;
    delete logicWrapper;
}

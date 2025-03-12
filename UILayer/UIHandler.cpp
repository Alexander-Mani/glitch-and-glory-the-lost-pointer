// UILayer/UIHandler.cpp
#include "UIHandler.h"
#include "AsciiHandler.h"
#include "IOHandler.h"
#include "BattleHandler.h"
#include "EncounterHandler.h"
#include "../LogicLayer/LogicWrapper.h"
#include "../Models/Entities/CyberGladiatorModel.h"  // For our player

#include <iostream>
#include <vector>
using namespace std;

UIHandler::UIHandler() 
    : logicWrapper(), 
      ioHandler(), 
      asciiHandler(),
      battleHandler(&logicWrapper, &asciiHandler),
      encounterHandler() // Default constructed
{
    // Create a persistent player (CyberGladiator) at the start.
    player = new CyberGladiatorModel();

    // Setup menu options and actions.
    this->menu_options = {"Play Game [phase 2]", "Activate Battle", "Activate Encounter", "Quit"};
    this->menu_actions["Play Game [phase 2]"] = [this]() { play_game(); };
    this->menu_actions["Activate Battle"]     = [this]() { activate_battle(); };
    this->menu_actions["Activate Encounter"]  = [this]() { activate_encounter(); };
    this->menu_actions["Quit"]                = [this]() { quit(); };
}

void UIHandler::play_game(){
    this->ioHandler.output_subtitle("Starting the game... [phase 2]");
}

void UIHandler::activate_battle(){
    this->battleHandler.initialize_battle();
}

void UIHandler::activate_encounter() {
    // Use the persistent player for encounters.
    this->encounterHandler.initialize_encounter(player);
    // Print the player's updated stats after the encounter.
    player->display_stats();
}

void UIHandler::quit(){
    this->ioHandler.output_subtitle("Exiting the game...");
    exit(0);
}

void UIHandler::initialize_game() {
    this->ioHandler.output_title("Welcome to Glitch & Glory!");
    string options_title = "Main Menu Options";
    this->ioHandler.output_options(options_title, this->menu_options); 
    string selected = this->ioHandler.input_choose_option(this->menu_options);
    menu_actions[selected]();
}

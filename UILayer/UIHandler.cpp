#include "UIHandler.h"
#include "AsciiHandler.h"
#include "IOHandler.h"
#include "BattleHandler.h"

#include "../LogicLayer/LogicWrapper.h"

#include <iostream>
#include <vector>

using namespace std;


UIHandler::UIHandler() 
    : logicWrapper(), 
      ioHandler(), 
      asciiHandler(),
      battleHandler(&logicWrapper, &asciiHandler)   // Initialize battleHandler here with the pointer
{
    // Now you can set up your menu_options and menu_actions, etc.
    this->menu_options = {"Play Game [phase 2]", "Activate Battle", "Quit"};
    this->menu_actions["Play Game [phase 2]"] = [this]() { play_game(); };
    this->menu_actions["Activate Battle"]     = [this]() { activate_battle(); };
    this->menu_actions["Quit"]                = [this]() { quit(); };
}



void UIHandler::initialize_game() {
    
    this->ioHandler.output_title("Welcome to Glitch & Glory!");

    string options_title = "Main Menu Options";
    // vector<string> menu_options = {"Play Game [phase 2]", "Activate Battle", "Quit"};
    this->ioHandler.output_options(options_title, this->menu_options); 
    string selected = this->ioHandler.input_choose_option(this->menu_options);

    // Call the corresponding action from the unordered_map.
    menu_actions[selected]();
}


void UIHandler::play_game(){
    this->ioHandler.output_subtitle("Starting the game... [phase 2]");
}


void UIHandler::activate_battle(){
    this->battleHandler.initialize_battle();
    
}

void UIHandler::quit(){
    this->ioHandler.output_subtitle("Exiting the game...");
    exit(0);
}



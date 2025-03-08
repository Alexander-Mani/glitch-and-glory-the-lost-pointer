#include "UIHandler.h"
#include "IOHandler.h"
#include "../LogicLayer/LogicWrapper.h"

#include <iostream>

using namespace std;

UIHandler::UIHandler(){
    this->logicWrapper = LogicWrapper();
    this->ioHandler = IOHandler();
}

void UIHandler::initialize_game() {
    
    this->ioHandler.output_title("Welcome to Glitch & Glory!");
    this->ioHandler.output_subtitle("Would you like to start the game?");
}



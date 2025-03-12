#include "OverworldHandler.h"
#include "AsciiHandler.h"
#include "IOHandler.h"
#include "../Models/AllEntities.h"      // For all entity models
#include "../Models/BattleModel.h"
#include "../LogicLayer/EntityLogic.h"    // For EntityLogic
#include <iostream>
#include <ostream>
#include <string>

#include <cassert>
#include <chrono>
#include <thread>

OverworldHandler::OverworldHandler(LogicWrapper* logicWrapper, AsciiHandler* asciiHandler)
    : logicWrapper(logicWrapper), asciiHandler(asciiHandler)
{
    this->ioHandler = IOHandler();
    // vector<string> game_options;
    
}

void OverworldHandler::initialize_overworld() {
    this->ioHandler.clear_terminal();
    string city = this->asciiHandler->CITY;
    string map = this->asciiHandler->GAME_MAP;
    string title = this->asciiHandler->TITLE;
    string subtitle = this->asciiHandler->SUBTITLE;
    cout << title << endl;
    cout << subtitle << endl;
    cout << city << endl;
    cout << map << endl;
    const std::string boldRed = "\033[1;31m";
    const std::string reset = "\033[0m";
    string text = 
R"(Lorem Ipsum is simply dummy text of the printing and typesetting industry.
Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, 
when an unknown printer took a galley of type and scrambled it to make a type specimen book. 
It has survived not only five centuries, but also the leap into electronic typesetting, 
remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset 
sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like 
Aldus PageMaker including versions of Lorem Ipsum.)";
     for (const char c : text) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}


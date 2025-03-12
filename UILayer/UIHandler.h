// UILayer/UIHandler.h
#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <unordered_map>
#include <functional>
#include "../LogicLayer/LogicWrapper.h"
#include "IOHandler.h"
#include "AsciiHandler.h"
#include "BattleHandler.h"
#include "EncounterHandler.h"
#include "../Models/Entities/EntityModel.h"

class UIHandler {
public:
    LogicWrapper logicWrapper;
    IOHandler ioHandler;
    AsciiHandler asciiHandler; // AsciiHandler must come before BattleHandler
    BattleHandler battleHandler;
    EncounterHandler encounterHandler;
    
    // Add a persistent player pointer here:
    EntityModel* player;

    std::vector<std::string> menu_options;
    std::unordered_map<std::string, std::function<void()>> menu_actions;

    UIHandler(); // Constructor

    void initialize_game();

private:
    void play_game();
    void activate_battle();
    void activate_encounter();
    void quit();
};

#endif // UIHANDLER_H

#ifndef OVERWORLDHANDLER_H
#define OVERWORLDHANDLER_H

#include "IOHandler.h"
#include "../LogicLayer/LogicWrapper.h"  // Include LogicWrapper

#include "../Models/BattleModel.h"
#include "AsciiHandler.h"

#include <iostream>
#include <vector>




using namespace std;

class OverworldHandler {
public:
    IOHandler *ioHandler;
    LogicWrapper* logicWrapper; // Pointer to the LogicWrapper
    AsciiHandler* asciiHandler;


    // Pass a pointer to LogicWrapper so we can access EntityLogic
    OverworldHandler(LogicWrapper* logicWrapper, AsciiHandler* asciiHandler, IOHandler* ioHandler);

    /*
    * @brief Asks the user for Entity for player and for opponent. Then starts the battle.
    */
    void initialize_overworld();
    void move(OverworldModel *overworldModel,string location);
    void choose_party(OverworldHandler *overworldModel); 

    /*
    * @brief [in progress] Starts battle with provided parameters
    * @param BattleModel instance that contains the EntityModel for both the player and opponent
    */


};

#endif // BATTLEHANDLER_H

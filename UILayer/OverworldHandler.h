#ifndef OVERWORLDHANDLER_H
#define OVERWORLDHANDLER_H

#include "BattleHandler.h"
#include "IOHandler.h"
#include "../LogicLayer/LogicWrapper.h"  // Include LogicWrapper

#include "../Models/BattleModel.h"
#include "AsciiHandler.h"

#include <iostream>
#include <vector>




using namespace std;

class OverworldHandler {
public:
    LogicWrapper* logicWrapper; // Pointer to the LogicWrapper
    AsciiHandler* asciiHandler;
    IOHandler *ioHandler;
    BattleHandler *battleHandler;
    OverworldModel* overworldModel;


    // Pass a pointer to LogicWrapper so we can access EntityLogic
    OverworldHandler(LogicWrapper* logicWrapper, AsciiHandler* asciiHandler, IOHandler* ioHandler, BattleHandler* battleHandler);

    /*
    * @brief Asks the user for Entity for player and for opponent. Then starts the battle.
    */
    void initialize_overworld();
    void move(OverworldModel *overworldModel,string location);
    void do_action(OverworldModel *overworldModel, string action);

    /*
    * @brief [in progress] Starts battle with provided parameters
    * @param BattleModel instance that contains the EntityModel for both the player and opponent
    */
    protected:
    EntityModel* choose_party_member(OverworldModel *overworldModel);


};

#endif // BATTLEHANDLER_H

#ifndef BATTLEHANDLER_H
#define BATTLEHANDLER_H

#include "IOHandler.h"
#include "../LogicLayer/LogicWrapper.h"  // Include LogicWrapper

#include "../Models/BattleModel.h"
#include "AsciiHandler.h"

#include <iostream>
#include <vector>


using namespace std;

class BattleHandler {
public:
    LogicWrapper* logicWrapper; // Pointer to the LogicWrapper
    AsciiHandler* asciiHandler;
    IOHandler *ioHandler;


    // Pass a pointer to LogicWrapper so we can access EntityLogic
    BattleHandler(LogicWrapper* logicWrapper, AsciiHandler* asciiHandler, IOHandler *ioHandler);

    /*
    * @brief Asks the user for Entity for player and for opponent. Then starts the battle.
    */
    void initialize_battle();

    /*
    * @brief [in progress] Starts battle with provided parameters
    * @param BattleModel instance that contains the EntityModel for both the player and opponent
    */
    void start_battle(BattleModel *battleModel);


    EntityModel* select_entity(bool for_player);
};

#endif // BATTLEHANDLER_H

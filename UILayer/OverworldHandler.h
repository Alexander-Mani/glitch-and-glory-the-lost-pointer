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
    void handle_level_up(OverworldModel *overworldModel);

    /*
    * @brief [in progress] Starts battle with provided parameters
    * @param BattleModel instance that contains the EntityModel for both the player and opponent
    */
    protected:
    EntityModel* choose_party_member(OverworldModel *overworldModel);

    //    string text = 
//R"(Lorem Ipsum is simply dummy text of the printing and typesetting industry.
//Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, 
//when an unknown printer took a galley of type and scrambled it to make a type specimen book. 
//It has survived not only five centuries, but also the leap into electronic typesetting, 
//remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset 
//sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like 
//Aldus PageMaker including versions of Lorem Ipsum.)";
//     for (const char c : text) {
//        std::cout << c << std::flush;
//        std::this_thread::sleep_for(std::chrono::milliseconds(50));
//    }



};

#endif // BATTLEHANDLER_H

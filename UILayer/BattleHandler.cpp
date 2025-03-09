#include "BattleHandler.h"
#include "IOHandler.h"

#include "../Models/AllEntities.h"

BattleHandler::BattleHandler(){
    this->ioHandler = IOHandler();
}

void BattleHandler::initialize_battle(){
    this->ioHandler.output_title("Welcome to battle arena!");
    this->ioHandler.output_subtitle("Fetching all Entities from EntityLogic...");

    // Create an instance of CyberGladiatorModel
    CyberGladiatorModel cyber_gladiator;

    // Call the display_stats method to print the entity's stats
    cyber_gladiator.display_stats();

}

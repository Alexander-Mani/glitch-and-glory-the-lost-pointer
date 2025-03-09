
#include "BattleHandler.h"
#include "IOHandler.h"

BattleHandler::BattleHandler(){
    this->ioHandler = IOHandler();
}

void BattleHandler::initialize_battle(){
    this->ioHandler.output_title("Welcome to battle arena!");
    this->ioHandler.output_subtitle("Fetching all Entities from EntityLogic...");
}

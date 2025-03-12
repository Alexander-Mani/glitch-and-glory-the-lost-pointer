#include "LogicWrapper.h"

#include "BattleLogic.h"
#include "EntityLogic.h"
#include "GameLogic.h"


LogicWrapper::LogicWrapper(){
    this->battleLogic = new BattleLogic();
    this->entityLogic = new EntityLogic();
    this->gameLogic = new GameLogic();
}

vector<string> LogicWrapper::get_attack_options(){
    return this->battleLogic->attack_options;
}

// string LogicWrapper::perform_action(string action, BattleModel *battleModel){
//     return this->battleLogic->perform_action(action, battleModel);
// }

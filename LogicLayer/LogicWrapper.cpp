#include "LogicWrapper.h"

#include "BattleLogic.h"
#include "EntityLogic.h"
#include "GameLogic.h"


LogicWrapper::LogicWrapper(){
    this->battleLogic = BattleLogic();
    this->entityLogic = EntityLogic();
    this->gameLogic = GameLogic();
}


vector<string> LogicWrapper::get_attack_options(){
    return this->battleLogic.attack_options;
}

string LogicWrapper::perform_action(string action, BattleModel *battleModel){
    return this->battleLogic.perform_action(action, battleModel);
}

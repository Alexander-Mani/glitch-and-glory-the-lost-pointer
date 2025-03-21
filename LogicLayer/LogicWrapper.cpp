#include "LogicWrapper.h"

#include "BattleLogic.h"
#include "EncounterLogic.h"
#include "EntityLogic.h"
#include "GameLogic.h"
#include "AttackLogic.h"


LogicWrapper::LogicWrapper(){
    this->encounterLogic = new EncounterLogic();
    this->gameLogic = new GameLogic();
    this->entityLogic = new EntityLogic(this->gameLogic);
    this->attackLogic = new AttackLogic(this->entityLogic);
    this->battleLogic = new BattleLogic(this->attackLogic);
}

vector<string> LogicWrapper::get_attack_options(){
    return this->battleLogic->attack_options;
}

// string LogicWrapper::perform_action(string action, BattleModel *battleModel){
//     return this->battleLogic->perform_action(action, battleModel);
// }

#include "LogicWrapper.h"

#include "BattleLogic.h"
#include "EntityLogic.h"
#include "GameLogic.h"


LogicWrapper::LogicWrapper(){
    this->battleLogic = BattleLogic();
    this->entityLogic = EntityLogic();
    this->gameLogic = GameLogic();
}


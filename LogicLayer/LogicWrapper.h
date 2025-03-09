
// BattleLogic.h
#ifndef LOGICWRAPPER_H
#define LOGICWRAPPER_H


#include "BattleLogic.h"
#include "EntityLogic.h"
#include "GameLogic.h"


class LogicWrapper{
public:
    BattleLogic battleLogic;
    EntityLogic entityLogic;
    GameLogic gameLogic;

    LogicWrapper();

    // fetch_all_entities();
};

#endif // LOGICWRAPPER_H

// BattleLogic.h
#ifndef LOGICWRAPPER_H
#define LOGICWRAPPER_H


#include "BattleLogic.h"
#include "EntityLogic.h"
#include "GameLogic.h"
#include "AttackLogic.h"


class LogicWrapper{
public:
    BattleLogic *battleLogic;
    EntityLogic *entityLogic;
    GameLogic *gameLogic;
    AttackLogic *attackLogic;

    LogicWrapper();

    //---- Methods ----//

    /*
     * @brief [TODO] Get dynamic attack options
     * @details Currently it returns a static vector<string> of two actions
     */
    vector<string> get_attack_options();

   
    // string perform_action(string action, BattleModel *battleModel);
};

#endif // LOGICWRAPPER_H
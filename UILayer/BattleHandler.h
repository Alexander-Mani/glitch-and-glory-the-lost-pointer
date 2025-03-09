#ifndef BATTLEHANDLER_H
#define BATTLEHANDLER_H

#include "IOHandler.h"
#include "../LogicLayer/LogicWrapper.h"  // Include LogicWrapper

#include <iostream>
#include <vector>
using namespace std;

class BattleHandler {
public:
    IOHandler ioHandler;
    LogicWrapper* logicWrapper; // Pointer to the LogicWrapper

    // Pass a pointer to LogicWrapper so we can access EntityLogic
    BattleHandler(LogicWrapper* logicWrapper);

    void initialize_battle();

    EntityModel* select_entity(bool for_player);
};

#endif // BATTLEHANDLER_H

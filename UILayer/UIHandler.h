// BattleLogic.h
#ifndef UIHANDLER_H
#define UIHANDLER_H


#include "../LogicLayer/LogicWrapper.h"
#include "IOHandler.h"

class UIHandler{
public:
    LogicWrapper logicWrapper;
    IOHandler ioHandler;

    UIHandler(); // Declaring constructer to be used within the .cpp file

    void initialize_game();
};

#endif // UIHANDLER_H
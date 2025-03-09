#ifndef BATTLEHANDLER_H
#define BATTLEHANDLER_H

#include "IOHandler.h"

#include <iostream>
#include <vector>


using namespace std;

class BattleHandler{
public:
    IOHandler ioHandler;

    BattleHandler();

    void initialize_battle();


};


#endif // BATTLEHANDLER_H
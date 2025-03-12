// EncounterHandler.h
#ifndef ENCOUNTERHANDLER_H
#define ENCOUNTERHANDLER_H

#include "../Models/Entities/EntityModel.h"
#include "IOHandler.h"

class EncounterHandler {
public:
    EncounterHandler();
    // Updated declaration with a parameter
    void initialize_encounter(EntityModel* player);
private:
    IOHandler ioHandler;
};

#endif // ENCOUNTERHANDLER_H

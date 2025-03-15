// EncounterHandler.h
#ifndef ENCOUNTERHANDLER_H
#define ENCOUNTERHANDLER_H

#include "../Models/Entities/EntityModel.h"
#include "IOHandler.h"
#include "AsciiHandler.h"
#include "../LogicLayer/LogicWrapper.h"
#include "../Models/PartyModel.h"

class EncounterHandler {
public:
    LogicWrapper *logicWrapper;
    EncounterHandler(LogicWrapper *logicWrapper);

    // Updated declaration with a parameter
    //void initialize_encounter(PartyModel* partyModel);
    void get_random_encounter(PartyModel* partyModel, EntityModel *entityModel);
private:
};

#endif // ENCOUNTERHANDLER_H

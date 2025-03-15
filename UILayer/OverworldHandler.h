#ifndef OVERWORLDHANDLER_H
#define OVERWORLDHANDLER_H

#include "BattleHandler.h"
#include "EncounterHandler.h"
#include "IOHandler.h"
#include "../LogicLayer/LogicWrapper.h"  

#include "../Models/BattleModel.h"
#include "AsciiHandler.h"
#include "StoryHandler.h"

#include <iostream>
#include <vector>


using namespace std;



class OverworldHandler {
public:
    LogicWrapper *logicWrapper; 
    BattleHandler *battleHandler;
    OverworldModel *overworldModel;
    EncounterHandler* encounterHandler;


    // Pass a pointer to LogicWrapper so we can access EntityLogic
    OverworldHandler(LogicWrapper* logicWrapper, BattleHandler* battleHandler, EncounterHandler* encounterHandler);

    /*
    * @brief Asks the user for Entity for player and for opponent. Then starts the battle.
    */
    void initialize_overworld();
    void move(OverworldModel *overworldModel,string location);
    void do_action(OverworldModel *overworldModel, string action);
    void handle_level_up(OverworldModel *overworldModel);
    void handle_random_encounter(OverworldModel *overworldModel);
    bool battle(OverworldModel* overworldModel, EntityModel *playerModel, EntityModel *enemyModel, bool is_boss);

    /*
    * @brief [in progress] Starts battle with provided parameters
    * @param BattleModel instance that contains the EntityModel for both the player and opponent
    */
    protected:
    EntityModel* choose_party_member(OverworldModel *overworldModel);


string DENY_JOB_LETTER = R"([ACCESS DENIED] Application Status Update

Candidate ID: #4C-3D-12
Clearance Level: Insufficient

Dear Applicant,

Your profile has been processed through [SYNTH-RECRUIT v9.2], our autonomous candidate evaluation system. After cross-referencing your credentials with the operational directives of OmniTek Systems, we regret to inform you that your application for the Neural Systems Analyst position does not meet the precision parameters required for integration.

This is not an assessment of deficiency, but rather a mismatch with current system architecture. Your data remains archived in our talent grid for potential alignment with future protocols. Should recalibration of requirements occur, you may be contacted via an encrypted channel.

Until then, remain operational.

OmniTek Systems
Human-Cyber Resource Division
// END TRANSMISSION //)";

};

#endif // BATTLEHANDLER_H

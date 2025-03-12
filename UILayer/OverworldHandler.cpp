#include "OverworldHandler.h"
#include "AsciiHandler.h"
#include "BattleHandler.h"
#include "IOHandler.h"
#include "../Models/AllEntities.h"      // For all entity models
#include "../Models/BattleModel.h"
#include "../LogicLayer/EntityLogic.h"    // For EntityLogic
#include "../Models/OverworldModel.h"
#include "../Models/PartyModel.h"
#include <iostream>
#include <ostream>
#include <string>

#include <cassert>
#include <chrono>
#include <thread>
#include <vector>

OverworldHandler::OverworldHandler(LogicWrapper* logicWrapper, AsciiHandler* asciiHandler, IOHandler *ioHandler, BattleHandler *battleHandler)
    : logicWrapper(logicWrapper), asciiHandler(asciiHandler), ioHandler(ioHandler), battleHandler(battleHandler)
{
    // this->ioHandler = IOHandler();
    // vector<string> game_options;
    
}

void OverworldHandler::initialize_overworld() {
    this->ioHandler->clear_terminal();
    string city = this->asciiHandler->CITY;
    string map = this->asciiHandler->GAME_MAP;
    string title = this->asciiHandler->TITLE;
    string subtitle = this->asciiHandler->SUBTITLE;
    cout << title << endl;
    cout << subtitle << endl;
    cout << city << endl;
    cout << map << endl;
    const std::string boldRed = "\033[1;31m";
    const std::string reset = "\033[0m";
    // Fancy type effect for intro
//    string text = 
//R"(Lorem Ipsum is simply dummy text of the printing and typesetting industry.
//Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, 
//when an unknown printer took a galley of type and scrambled it to make a type specimen book. 
//It has survived not only five centuries, but also the leap into electronic typesetting, 
//remaining essentially unchanged. It was popularised in the 1960s with the release of Letraset 
//sheets containing Lorem Ipsum passages, and more recently with desktop publishing software like 
//Aldus PageMaker including versions of Lorem Ipsum.)";
//     for (const char c : text) {
//        std::cout << c << std::flush;
//        std::this_thread::sleep_for(std::chrono::milliseconds(50));
//    }


    //Initialize party model
    //Initialize overworld model
    vector<EntityModel*> entities = this->logicWrapper->entityLogic->get_all_entities();
    PartyModel* partyModel = new PartyModel(entities[0], entities[1], entities[2]);
    OverworldModel *overWorldModel = new OverworldModel(partyModel);
    string location = overWorldModel->get_curr_location();
    PartyModel *testPartyModel = overWorldModel->get_party_model();
    testPartyModel->get_party_member_1()->display_stats();
    testPartyModel->get_party_member_2()->display_stats();
    testPartyModel->get_party_member_3()->display_stats();
    this->move(overWorldModel, location);
    // display options for curr location initaly hub
}

void OverworldHandler::move(OverworldModel *overworldModel,string location){
     location = this->logicWrapper->gameLogic->change_location(overworldModel, location);
    //string new_location = overworldModel->set_curr_location(location);
    vector<string> locations = overworldModel->get_routes(location);
    this->ioHandler->output_options(location, locations);
    string option = this->ioHandler->input_choose_option(locations);
    vector<string> actions = overworldModel->get_actions();
    bool is_action = this->logicWrapper->gameLogic->is_action(actions, option);
    if (location == overworldModel->get_final_zone()){
        cout << "BOSS TIME!" << endl;
        return;
    }else if (is_action) {
        // option is not location so it must be action thus we call action handler
        string action = this->logicWrapper->gameLogic->action_resolver(option);
        return this->do_action(overworldModel, action);

    }
    return this->move(overworldModel,option);
}

void OverworldHandler::do_action(OverworldModel *overworldModel, string action){
    cout << "Action time" << endl;
    if (action == "Battle") {
        //Choose our dude to fight
        int ind = 0;
        vector<string> party_member_names = overworldModel->get_party_model()->get_party_member_names();
        vector<EntityModel*> party_members = overworldModel->get_party_model()->get_party_members();
        this->ioHandler->output_options("Choose from party", party_member_names);
        string option = this->ioHandler->input_choose_option({"A", "B", "C"});
        if (option == "A") ind = 0; 
        else if (option == "B") ind = 1; 
        else ind = 2; 
        // could be temp, might be in prod as the old song goes
        EntityModel* enemyModel = this->logicWrapper->entityLogic->get_random_entity();
       
        bool player_starts = true;
        if (enemyModel->get_evade() > party_members[ind]->get_evade()) player_starts = false;
        BattleModel* battleModel = new BattleModel(party_members[ind], enemyModel, player_starts);

        this->battleHandler->start_battle(battleModel);
        delete(battleModel);
        delete(enemyModel);
    } else if (action == "Browse Equipment") {
        cout << "Buy this, buy that, fuck off" << endl;
        this->ioHandler->glitch_sleep(2);
             
    } else if (action == "Browse Implants") {
        cout << "Buy this, buy that, fuck off" << endl;
        this->ioHandler->glitch_sleep(2);

    } else if (action == "Fight Boss") {
        cout << "Fight boss" << endl;
        return;
    } else if (action == "Gamble") {
        cout << "You see an underground gathering of scum and villany" << endl;
        cout << "You and the lads you and the lads can wreck them in rock, paper, scissors" << endl;
        this->ioHandler->glitch_sleep(3);

    } else if (action == "Apply For Job") {

    }

    
    return move(overworldModel, overworldModel->get_curr_location());
}

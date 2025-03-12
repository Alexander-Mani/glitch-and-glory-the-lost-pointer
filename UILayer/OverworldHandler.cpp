#include "OverworldHandler.h"
#include "AsciiHandler.h"
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

OverworldHandler::OverworldHandler(LogicWrapper* logicWrapper, AsciiHandler* asciiHandler)
    : logicWrapper(logicWrapper), asciiHandler(asciiHandler)
{
    this->ioHandler = IOHandler();
    // vector<string> game_options;
    
}

void OverworldHandler::initialize_overworld() {
    this->ioHandler.clear_terminal();
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
    this->ioHandler.output_options(location, locations);
    string option = this->ioHandler.input_choose_option(locations);
    bool is_action = this->logicWrapper->gameLogic->is_action(locations, option);
    if (location == overworldModel->get_final_zone()){
        cout << "BOSS TIME!" << endl;
        return;
    }else if (is_action) {
        // option is not location so it must be action thus we call action handler
        string action = this->logicWrapper->gameLogic->action_resolver(option);
    }
    return this->move(overworldModel,option);
}

void OverworldHandler::choose_party(OverworldHandler *overworldModel) {
    (void)overworldModel;
    // Create a list of entity names for the menu in the same order as entities.
}

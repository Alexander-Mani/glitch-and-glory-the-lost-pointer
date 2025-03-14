#include "OverworldHandler.h"
#include "AsciiHandler.h"
#include "BattleHandler.h"
#include "EncounterHandler.h"
#include "IOHandler.h"
#include "../Models/AllEntities.h"      // For all entity models
#include "../Models/BattleModel.h"
#include "../LogicLayer/EntityLogic.h"    // For EntityLogic
#include "../Models/OverworldModel.h"
#include "../Models/PartyModel.h"
#include "../Models/AllEquipment.h"
#include <iostream>
#include <ostream>
#include <string>

#include <cassert>
#include <vector>

OverworldHandler::OverworldHandler(LogicWrapper* logicWrapper, AsciiHandler* asciiHandler, IOHandler *ioHandler, BattleHandler *battleHandler, EncounterHandler* encounterHandler)
    : logicWrapper(logicWrapper), asciiHandler(asciiHandler), ioHandler(ioHandler), battleHandler(battleHandler), encounterHandler(encounterHandler)
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

    //Initialize party model
    //Initialize overworld model
    vector<EntityModel*> entities = this->logicWrapper->entityLogic->get_all_entities();
    PartyModel* partyModel = new PartyModel(entities[0], entities[1], entities[2]);

    this->overworldModel = new OverworldModel(partyModel);
    string location = overworldModel->get_curr_location();
    //PartyModel *testPartyModel = overworldModel->get_party_model();
    //testPartyModel->get_party_member_1()->display_stats();
    //testPartyModel->get_party_member_2()->display_stats();
    //testPartyModel->get_party_member_3()->display_stats();
    //this->overworldModel->get_party_model()->increase_money(900000);
    this->move(this->overworldModel, location);
    // display options for curr location initaly hub
}

void OverworldHandler::move(OverworldModel *overworldModel,string location){
    this->handle_random_encounter(overworldModel);
    this->handle_level_up(overworldModel);
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
    //if location != option call chance for encounter
    return this->move(overworldModel,option);
}

void OverworldHandler::do_action(OverworldModel *overworldModel, string action){
    this->handle_level_up(overworldModel);
    ioHandler->clear_terminal();
    cout << "Action time" << endl;
    if (action == "Battle") {
        //Choose our dude to fight
        EntityModel *character = this->choose_party_member(overworldModel);
        EntityModel* enemyModel = this->logicWrapper->entityLogic->get_random_entity();
       
        // bool player_starts = true;
        // if (enemyModel->get_evade() > character->get_evade()) player_starts = false;
        BattleModel* battleModel = new BattleModel(character, enemyModel, true, overworldModel->get_party_model()->get_money());

        // this->battleHandler->start_battle(battleModel);

        
        // BattleModel* battleModel = new BattleModel(character, enemyModel, true);
        unsigned int xp = 0;
        unsigned int money = 0;
        unsigned int bribe = 0;

        this->battleHandler->start_battle(battleModel);

        // Remove bribed money from party if 
        if(battleModel->bribed){
            bribe = battleModel->get_bribe_amount();
            overworldModel->get_party_model()->decrease_money(bribe);
            money -= bribe;
        }
        // If the player did not flee, then add xp and money
        if(!battleModel->fled){
            xp = this->logicWrapper->gameLogic->deligate_post_battle_xp(overworldModel);
            money = this->logicWrapper->gameLogic->deligate_post_battle_money(overworldModel);
        }   
        if(bribe > 0){
            cout << "You Recieved: " << xp << " xp and: " << money << " eddies and bribed for " << bribe << " eddies" << endl;    
        } 
        else {
            cout << "You Recieved: " << xp << " xp and: " << money << " eddies" << endl;
        }
        delete(battleModel);
        delete(enemyModel);
    } else if (action == "View Party") {

        overworldModel->get_party_model()->display_party();
        ioHandler->glitch_sleep(3);

    } else if (action == "Browse Equipment") {
        bool purchase;
        overworldModel->get_party_model()->display_party();
        vector<WeaponModel*>* weapons = overworldModel->get_equipment_factory()->get_weapons();
        vector<ArmorModel*>* armors = overworldModel->get_equipment_factory()->get_armors();
        overworldModel->get_equipment_factory()->show_combat_gear();
        unsigned int index = this->ioHandler->input_choose_index(weapons->size()+armors->size());
        if (index+1 <= weapons->size()){
            WeaponModel* weapon = (*weapons)[index];
            if ((unsigned int)weapon->get_price() > overworldModel->get_party_model()->get_money()) { 
                cout << "You can't afford that" << endl;
                this->ioHandler->glitch_sleep(1);
                return move(overworldModel, overworldModel->get_curr_location());
            }
            EntityModel* character = this->choose_party_member(overworldModel);
            purchase = character->equip_item("Weapon", weapon);
            
        }else{
            index %=5;
            ArmorModel* armor = (*armors)[index];
            if ((unsigned int)armor->get_price() > overworldModel->get_party_model()->get_money()) { 
                cout << "You can't afford that" << endl;
                this->ioHandler->glitch_sleep(1);
                return move(overworldModel, overworldModel->get_curr_location());
            }
            EntityModel* character = this->choose_party_member(overworldModel);
            purchase = character->equip_item("Armor", armor);
            if (purchase) overworldModel->get_party_model()->decrease_money(armor->get_price());
        } 
    } else if (action == "Browse Implants") {
        bool purchase;
        overworldModel->get_party_model()->display_party();
        vector<ImplantModel*>* implants = overworldModel->get_equipment_factory()->get_implants();
        overworldModel->get_equipment_factory()->show_cyber_augments();
        unsigned int index = this->ioHandler->input_choose_index(implants->size());
        ImplantModel* implant = (*implants)[index];
        if ((unsigned int)implant->get_price() > overworldModel->get_party_model()->get_money()) { 
            cout << "You can't afford that" << endl;
            this->ioHandler->glitch_sleep(1);
            return move(overworldModel, overworldModel->get_curr_location());
        }
        EntityModel* character = this->choose_party_member(overworldModel);
        purchase = character->equip_item("Implant", implant);
        if (purchase) overworldModel->get_party_model()->decrease_money(implant->get_price());

    } else if (action == "Fight Boss") {
        cout << "Fight boss" << endl;
        return;
    } else if (action == "Gamble") {
        cout << "You see an underground gathering of scum and villany" << endl;
        cout << "You and the lads think you wold wreck them in rock, paper, scissors" << endl;
        this->ioHandler->glitch_sleep(3);

    } else if (action == "Apply For Job") {
        cout << DENY_JOB_LETTER << endl;
    }

    
    return move(overworldModel, overworldModel->get_curr_location());
}

EntityModel* OverworldHandler::choose_party_member(OverworldModel *overworldModel){
        int ind = 0;
        vector<string> party_member_names = overworldModel->get_party_model()->get_party_member_names();
        vector<EntityModel*> party_members = overworldModel->get_party_model()->get_party_members();
        this->ioHandler->output_options("Choose party member", party_member_names);
        ind = this->ioHandler->input_choose_index(party_members.size());
        return party_members[ind];
    }

void OverworldHandler::handle_level_up(OverworldModel *overworldModel){
    if (!this->logicWrapper->gameLogic->can_level_up(overworldModel)) return;
    overworldModel->get_party_model()->display_party();
    this->ioHandler->output_title("You Leveled Up!");
    unsigned int new_level = this->overworldModel->get_party_model()->get_level()+1; 
    cout << "Your Party is Now Level: " << new_level << endl;
    cout << "Select One Character to Give a +"<< new_level <<" To Each Stat!" << endl;
    EntityModel* character = this->choose_party_member(overworldModel);
    this->logicWrapper->gameLogic->level_up(overworldModel, character);
    }

void OverworldHandler::handle_random_encounter(OverworldModel *overworldModel){
    bool encounter = this->logicWrapper->encounterLogic->will_get_encounter();
    if (encounter){ 
        cout << "You Hear something behind you..." << endl;
        cout << "Who responds?" << endl;
        EntityModel *entityModel = this->choose_party_member(overworldModel);
        this->encounterHandler->get_random_encounter(overworldModel->get_party_model(), entityModel);
    }
}

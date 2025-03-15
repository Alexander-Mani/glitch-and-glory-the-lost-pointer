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
#include "StoryHandler.h"
#include <iostream>
#include <ostream>
#include <string>

#include <cassert>
#include <vector>

OverworldHandler::OverworldHandler(LogicWrapper* logicWrapper, BattleHandler *battleHandler, EncounterHandler* encounterHandler)
    : logicWrapper(logicWrapper), battleHandler(battleHandler), encounterHandler(encounterHandler) {}

void OverworldHandler::initialize_overworld() {
    IOHandler::clear_terminal();
    IOHandler::write_dialoge(StoryHandler::PRE_INTRO);
    IOHandler::write_story(StoryHandler::INTRO_CONTENT_1);
    IOHandler::write_story(StoryHandler::INTRO_MISSION);
    IOHandler::output_options("Continue", {"Continue"});
    IOHandler::input_choose_option({"Continue"});
    IOHandler::clear_terminal();
    IOHandler::write_story(StoryHandler::HOW_TO_PLAY);
    IOHandler::output_options("Continue", {"Continue"});
    IOHandler::input_choose_option({"Continue"});
    IOHandler::clear_terminal();
    cout << AsciiHandler::CITY << endl;
    cout << AsciiHandler::TITLE << endl;
    cout << AsciiHandler::SUBTITLE << endl;

    vector<EntityModel*> entities = this->logicWrapper->entityLogic->get_all_entities();
    PartyModel* partyModel = new PartyModel(entities[0], entities[1], entities[2]);

    this->overworldModel = new OverworldModel(partyModel);
    this->move(this->overworldModel, overworldModel->get_curr_location());
}

void OverworldHandler::move(OverworldModel *overworldModel,string location){
    string map = this->logicWrapper->gameLogic->change_map_location(overworldModel, AsciiHandler::GAME_MAP, location);
    cout << map << endl;
    if (this->logicWrapper->gameLogic->check_game_over(overworldModel)){
        IOHandler::clear_terminal();
        vector<string> gameover_msg;
        gameover_msg.push_back("");
        gameover_msg.push_back("All Entities in your party have died.");
        gameover_msg.push_back("");
        gameover_msg.push_back("Thanks for playing!");
        gameover_msg.push_back("");


        AsciiHandler::display_box_layout("Game over", gameover_msg);
        return;
    } 
    this->handle_level_up(overworldModel);
    if (location != overworldModel->get_curr_location()){
        IOHandler::clear_terminal();
        this->handle_random_encounter(overworldModel);
    }
    location = this->logicWrapper->gameLogic->change_location(overworldModel, location);
    //string location = overworldModel->set_curr_location(location);
    vector<string> locations = overworldModel->get_routes(location);
    IOHandler::output_options(location, locations);
    string option = IOHandler::input_choose_option(locations);
    vector<string> actions = overworldModel->get_actions();
    bool is_action = this->logicWrapper->gameLogic->is_action(actions, option);
     if (is_action) {
        // option is not location so it must be action thus we call action handler
        string action = this->logicWrapper->gameLogic->action_resolver(option);
        return this->do_action(overworldModel, action);

    }
    //if location != option call chance for encounter
    return this->move(overworldModel,option);
}

void OverworldHandler::do_action(OverworldModel *overworldModel, string action){
    this->handle_level_up(overworldModel);
    IOHandler::clear_terminal();
    if (action == "Battle") {
        EntityModel *character = this->choose_party_member(overworldModel);
        //EntityModel* enemyModel = this->logicWrapper->entityLogic->get_random_entity();
        EntityModel* enemyModel = this->logicWrapper->entityLogic->generate_enemy_entity(character);
        cout << this->battle(overworldModel,character, enemyModel, false) << endl;

    } else if (action == "View Party") {

        AsciiHandler::display_hud(overworldModel->get_party_model()->display_party(), '|', 150);
        // overworldModel->get_party_model()->display_party();
        IOHandler::glitch_sleep(3);

    } else if (action == "Browse Equipment") {
        bool purchase;
        overworldModel->get_party_model()->display_party();
        vector<WeaponModel*>* weapons = overworldModel->get_equipment_factory()->get_weapons();
        vector<ArmorModel*>* armors = overworldModel->get_equipment_factory()->get_armors();
        overworldModel->get_equipment_factory()->show_combat_gear();
        unsigned int index = IOHandler::input_choose_index(weapons->size()+armors->size()+1);
        if (index+1 <= weapons->size()){
            WeaponModel* weapon = (*weapons)[index];
            if ((unsigned int)weapon->get_price() > overworldModel->get_party_model()->get_money()) { 
                cout << "You can't afford that" << endl;
                IOHandler::glitch_sleep(1);
                return move(overworldModel, overworldModel->get_curr_location());
            }
            EntityModel* character = this->choose_party_member(overworldModel);
            purchase = character->equip_item("Weapon", weapon);
            
        }else if (index != 10){
            index %=5;
            ArmorModel* armor = (*armors)[index];
            if ((unsigned int)armor->get_price() > overworldModel->get_party_model()->get_money()) { 
                cout << "You can't afford that" << endl;
                IOHandler::glitch_sleep(1);
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
        unsigned int index = IOHandler::input_choose_index(implants->size()+1);
        if(index == implants->size()) return move(overworldModel, overworldModel->get_curr_location());
        ImplantModel* implant = (*implants)[index];
        if ((unsigned int)implant->get_price() > overworldModel->get_party_model()->get_money()) { 
            cout << "You can't afford that" << endl;
            IOHandler::glitch_sleep(1);
            return move(overworldModel, overworldModel->get_curr_location());
        }
        EntityModel* character = this->choose_party_member(overworldModel);
        purchase = character->equip_item("Implant", implant);
        if (purchase) overworldModel->get_party_model()->decrease_money(implant->get_price());

    } else if (action == "Fight Boss") {
        IOHandler::clear_terminal();
        EntityModel* bossPhase1Model = this->logicWrapper->entityLogic->get_boss_entity_phase_1();
        IOHandler::write_story(StoryHandler::ELON_ATMO_1);
        IOHandler::write_dialoge(StoryHandler::ELON_DIALOGUE_1);
        IOHandler::write_story(StoryHandler::ELON_ATMO_2);
        EntityModel *character = this->choose_party_member(overworldModel);
        if (this->battle(overworldModel, character, bossPhase1Model, true)){
            EntityModel* bossPhase2Model = this->logicWrapper->entityLogic->get_boss_entity_phase_2();
            IOHandler::write_story(StoryHandler::ELON_ATMO_3);
            IOHandler::write_dialoge(StoryHandler::ELON_DIALOGUE_2);
            IOHandler::write_story(StoryHandler::ELON_ATMO_4);
            IOHandler::write_dialoge(StoryHandler::ELON_DIALOGUE_3);
            character = this->choose_party_member(overworldModel);
            if(this->battle(overworldModel,character, bossPhase2Model, true)){
                IOHandler::clear_terminal();
                IOHandler::write_story(StoryHandler::FINAL_LORE_DUMP);
                return;
            }
        }
    } else if (action == "Gamble") {
        vector<string> gamble_options = {"100", "200", "500", "1000", "5000", "10000", "Leave"};
        vector<int> gamble_amounts = {100, 200, 500, 1000, 5000, 10000};
        IOHandler::output_options("Want to Gamble like a Gamer?", gamble_options);
        unsigned int choice_ind = IOHandler::input_choose_index(gamble_options.size());
        if (choice_ind == gamble_amounts.size()) return move(overworldModel, overworldModel->get_curr_location());; 
        unsigned int gamble_amount = gamble_amounts[choice_ind];
        string status_msg = "";
        if (gamble_amount <= overworldModel->get_party_model()->get_money()){
            bool won = this->logicWrapper->gameLogic->won_gamble(overworldModel, gamble_amount);
            if (won) status_msg = "You won! " + to_string(gamble_amount);
            else status_msg = "You lost " + to_string(gamble_amount);
        }else status_msg = "You can't afford that";
        IOHandler::output_title(status_msg);
        IOHandler::glitch_sleep(3);

    } else if (action == "Apply For Job") {
        cout << DENY_JOB_LETTER << endl;
    } else if (action == "Stay Night"){
        int price = this->logicWrapper->gameLogic->get_stay_night_price(overworldModel); 
        string message = "Stay Night And Fully Heal Party For " + to_string(price);
        overworldModel->get_party_model()->display_party();
        vector<string> options = {"Stay Night", "Leave"};
        IOHandler::output_options(message, options);
        string choice = IOHandler::input_choose_option(options);
        if (choice == options[0]) this->logicWrapper->gameLogic->pay_for_night_and_heal(overworldModel);
    } else if (action == "Attempt Rat Communication"){
        int chance = logicWrapper->gameLogic->get_random_from_range(0, 6);
        
        if (chance == 1){
            cout << "You Succeed, You gain the mark of the rat!, gain one level!";
            // AsciiHandler::display_box_layout();
            int xp = overworldModel->get_party_model()->get_level_threshold();
            overworldModel->get_party_model()->increase_xp(xp);
            IOHandler::glitch_sleep(2);
        }else{
            cout << "You failed" << endl;
            cout << "A loyal member of the children of the rat aproaches you" << endl;
            cout << "Prepare to fight" << endl;
            IOHandler::glitch_sleep(2);
            EntityModel *character = this->choose_party_member(overworldModel);
            EntityModel* enemyModel = this->logicWrapper->entityLogic->generate_enemy_entity(character);
            cout << this->battle(overworldModel,character, enemyModel, false) << endl;
        }
    }

    
    return move(overworldModel, overworldModel->get_curr_location());
}

EntityModel* OverworldHandler::choose_party_member(OverworldModel *overworldModel){
        int ind = 0;
        vector<string> party_member_names = overworldModel->get_party_model()->get_party_member_names();
        vector<EntityModel*> party_members = overworldModel->get_party_model()->get_party_members();

        vector<string> filtered_member_names;
        vector<EntityModel*> filtered_members;
        for (size_t i = 0; i < party_members.size(); i++) {
            if (party_members[i]->get_hp() > 0) {
                filtered_members.push_back(party_members[i]);
                filtered_member_names.push_back(party_member_names[i]);
            }
        }


        IOHandler::output_options("Choose party member", filtered_member_names);
        ind = IOHandler::input_choose_index(filtered_members.size());
        return filtered_members[ind];
    }

void OverworldHandler::handle_level_up(OverworldModel *overworldModel){
    if (!this->logicWrapper->gameLogic->can_level_up(overworldModel)) return;
    overworldModel->get_party_model()->display_party();
    IOHandler::output_title("You Leveled Up!");
    unsigned int new_level = this->overworldModel->get_party_model()->get_level()+1; 
    cout << "Your Party is Now Level: " << new_level << endl;
    cout << "Select One Character to Give a +"<< new_level <<" To Each Stat!" << endl;
    EntityModel* character = this->choose_party_member(overworldModel);
    this->logicWrapper->gameLogic->level_up(overworldModel, character);
    }

void OverworldHandler::handle_random_encounter(OverworldModel *overworldModel){
    bool encounter = this->logicWrapper->encounterLogic->will_get_encounter();
    if (encounter){ 
        vector<string> description_lines;

        description_lines.push_back("");
        description_lines.push_back("You Hear something behind you...");
        description_lines.push_back("");
        description_lines.push_back("Who responds?");
        description_lines.push_back("");

        AsciiHandler::display_box_layout("Encounter", description_lines, "yellow", "yellow");

        // cout << "You Hear something behind you..." << endl;
        // cout << "Who responds?" << endl;
        EntityModel *entityModel = this->choose_party_member(overworldModel);
        //turn to bool will be battle, and make the guy fight you
        this->encounterHandler->get_random_encounter(overworldModel->get_party_model(), entityModel);
    }
}

bool OverworldHandler::battle(OverworldModel* overworldModel, EntityModel *playerModel, EntityModel *enemyModel, bool is_boss){
        //Choose our dude to fight
        bool status = false;
       
        // bool player_starts = true;
        // if (enemyModel->get_evade() > character->get_evade()) player_starts = false;
        BattleModel* battleModel = new BattleModel(playerModel, enemyModel, true, overworldModel->get_party_model()->get_money());

        // this->battleHandler->start_battle(battleModel);
        
        // BattleModel* battleModel = new BattleModel(character, enemyModel, true);
        unsigned int xp = 0;
        unsigned int money = 0;
        unsigned int bribe = 0;

        this->battleHandler->start_battle(battleModel);

        // BattleModel* battleModel = new BattleModel(character, enemyModel, true);
        // unsigned int xp = 0;
        // unsigned int money = 0;
        // unsigned int bribe = 0;

        // this->battleHandler->start_battle(battleModel);

        // Remove bribed money from party if 
        if(battleModel->bribed){
            bribe = battleModel->get_bribe_amount();
            overworldModel->get_party_model()->decrease_money(bribe);
            money -= bribe;
        }
        // If the player did not flee, then add xp and money
        // if(!battleModel->fled){
        //     xp = this->logicWrapper->gameLogic->deligate_post_battle_xp(overworldModel);
        //     money = this->logicWrapper->gameLogic->deligate_post_battle_money(overworldModel);
        // }   
        if((!battleModel->fled || !is_boss) && this->logicWrapper->battleLogic->player_won(battleModel)){
            xp = this->logicWrapper->gameLogic->deligate_post_battle_xp(overworldModel);
            money = this->logicWrapper->gameLogic->deligate_post_battle_money(overworldModel);
        }   
        // if(bribe > 0){
        //     cout << "You Recieved: " << xp << " xp and: " << money << " eddies and bribed for " << bribe << " eddies" << endl;    
        // } 
        // else {
        //     cout << "You Recieved: " << xp << " xp and: " << money << " eddies" << endl;
        // }
        if (!is_boss) AsciiHandler::display_end_of_battle(battleModel, xp, money);

        // delete(battleModel);
        // delete(enemyModel);
        if (this->logicWrapper->battleLogic->player_won(battleModel)) status = true;

        // // Remove bribed money from party if 
        // // if(battleModel->bribed){
        // //     bribe = battleModel->get_bribe_amount();
        // //     overworldModel->get_party_model()->decrease_money(bribe);
        // //     money -= bribe;
        // // }
        // // If the player did not flee, then add xp and money
        
        // if (bribe > 0) {
        //     ret_str = "You Received: +" + std::to_string(xp) + " xp and: +$" + std::to_string(money) + 
        //               " eddies and bribed for -$" + std::to_string(bribe) + " eddies";
        // } else {
        //     ret_str = "You Received: +" + std::to_string(xp) + " xp and: +$" + std::to_string(money) + " eddies";
        // }
        delete(battleModel);
        delete(enemyModel);
        return status;
}

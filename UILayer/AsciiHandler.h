#ifndef ASCIIHANDLER_H
#define ASCIIHANDLER_H

#include "../Models/BattleModel.h"
#include "../UILayer/IOHandler.h"
#include "../LogicLayer/LogicWrapper.h"


#include <cstddef>
#include <iostream>
#include <string>

using namespace std;

// Forward declaration to break circular dependency
class IOHandler;


class AsciiHandler {
public:
    LogicWrapper *logicWrapper;
    IOHandler *ioHandler;

    AsciiHandler(LogicWrapper *logicWrapper, IOHandler* ioHandler = nullptr);
    const size_t SPACES = 25;
    /*
    * @brief Displays ASCII art for a given entity name.
    * @param entity_name The name of the entity whose ASCII art is to be displayed.
    */
    void display_ascii(const string& entity_name);
    void display_character_selector(std::vector<EntityModel*>* entities);
    void display_start_of_battle(BattleModel* battleModel);
    void display_turn(BattleModel* battleModel);
    void display_end_of_battle(BattleModel* batlle_model);
    void display_battle_stats(BattleModel* battleModel);
    size_t calculate_max_stat_length(const std::vector<std::string>& stat_names, const std::vector<int>& stats);
    
    void display_hud(const vector<string> &custom_msg, char padding_symbol, size_t total_width);
    void display_attack_hud(BattleModel* battleModel);
};

#endif // ASCIIHANDLER_H


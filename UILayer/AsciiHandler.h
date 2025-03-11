#ifndef ASCIIHANDLER_H
#define ASCIIHANDLER_H

#include "../Models/BattleModel.h"

#include <cstddef>
#include <iostream>
#include <string>
#include <chrono> // for sleep
#include <thread> // don't worry not for advanced threading just for a universal way to sleep

using namespace std;

class AsciiHandler {
public:
    AsciiHandler();
    const size_t SPACES = 25;
    /*
    * @brief Displays ASCII art for a given entity name.
    * @param entity_name The name of the entity whose ASCII art is to be displayed.
    */
    void display_ascii(const string& entity_name);
    void display_character_selector(std::vector<EntityModel*>* entities);
    void display_start_of_battle(BattleModel* battle_model);
    void display_turn(BattleModel* battle_model);
    void display_end_of_battle(BattleModel* batlle_model);
    void display_battle_stats(BattleModel* battle_model);
    size_t calculate_max_stat_length(const std::vector<std::string>& stat_names, const std::vector<int>& stats);
    void display_attack_hud(BattleModel* battle_model);
};

#endif // ASCIIHANDLER_H


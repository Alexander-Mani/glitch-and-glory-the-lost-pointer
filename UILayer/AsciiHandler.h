#ifndef ASCIIHANDLER_H
#define ASCIIHANDLER_H

#include "../Models/BattleModel.h"

#include <iostream>
#include <string>

using namespace std;

class AsciiHandler {
public:
    AsciiHandler();
    const int SPACES = 30;
    /*
    * @brief Displays ASCII art for a given entity name.
    * @param entity_name The name of the entity whose ASCII art is to be displayed.
    */
    void display_ascii(const string& entity_name);
    void display_character_selector(std::vector<EntityModel*>* entities);
    void display_start_of_battle(BattleModel* battle_model);
    void display_turn(BattleModel* battle_model);
    void display_end_of_battle(BattleModel* batlle_model);
};

#endif // ASCIIHANDLER_H


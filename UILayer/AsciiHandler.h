#ifndef ASCIIHANDLER_H
#define ASCIIHANDLER_H

#include "../Models/BattleModel.h"

#include <cstddef>
#include <iostream>
#include <string>

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

    const string CITY =R"(
                       .|        ,       +
             *         | |      ((             *
                       |'|       `    ._____
         +     ___    |  |   *        |.   |' .---"|
       _    .-'   '-. |  |     .--'|  ||   | _|    |
    .-'|  _.|  |    ||   '-__  |   |  |    ||      |
    |' | |.    |    ||       | |   |  |    ||      |
 ___|  '-'     '    ""       '-'   '-.'    '`      |____
jgs~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
                   )";

const string GAME_MAP=R"(
===========================================.
                                           |
                                           |
===============.     .=====.  .========.   |
   SAMHERJI    |     | FIN |  | GUNS'N |   |
      HQ       |     |TECH9|  | VESTS  |   |
==============='     '====='  '========'   |
                                           |
         /=====\      .=========.   .===.  |
        /       \     |MEGABLOCK|   | C |  |
(YOU)   | ARENA |     |  SEVEN  |   | L |  |
        \       /     '====.    |   | U |  |
         \=====/           |    |   | B |  |
                           |    |   '==='  |
                           '===='          |
#*********#                                |
*ABONDEND *   .======.    .============.   |
*WAREHOUSE*   |RIPPER|    \ CORPORATE /    |
#*********#   '======'     \  UNION  /     |
                            \       /      |
                             '====='       |
    )";
const string TITLE = R"(
   ________    __________________  __   ___    _   ______     ________    ____  ______  __
  / ____/ /   /  _/_  __/ ____/ / / /  /   |  / | / / __ \   / ____/ /   / __ \/ __ \ \/ /
 / / __/ /    / /  / / / /   / /_/ /  / /| | /  |/ / / / /  / / __/ /   / / / / /_/ /\  / 
/ /_/ / /____/ /  / / / /___/ __  /  / ___ |/ /|  / /_/ /  / /_/ / /___/ /_/ / _, _/ / /  
\____/_____/___/ /_/  \____/_/ /_/  /_/  |_/_/ |_/_____/   \____/_____/\____/_/ |_| /_/   
)";

const string SUBTITLE= R"(
 _____ _  _ ___   _    ___  ___ _____   ___  ___ ___ _  _ _____ ___ ___ 
|_   _| || | __| | |  / _ \/ __|_   _| | _ \/ _ \_ _| \| |_   _| __| _ \
  | | | __ | _|  | |_| (_) \__ \ | |   |  _/ (_) | || .` | | | | _||   /
  |_| |_||_|___| |____\___/|___/ |_|   |_|  \___/___|_|\_| |_| |___|_|_\
)";
};

#endif // ASCIIHANDLER_H


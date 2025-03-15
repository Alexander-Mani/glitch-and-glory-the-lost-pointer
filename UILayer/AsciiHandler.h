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

    AsciiHandler(LogicWrapper *logicWrapper, IOHandler* ioHandler);
    const size_t SPACES = 25;
    /*
    * @brief Displays ASCII art for a given entity name.
    * @param entity_name The name of the entity whose ASCII art is to be displayed.
    */
    void display_ascii(const string& entity_name);
    void display_character_selector(std::vector<EntityModel*>* entities);
    void display_start_of_battle(BattleModel* battleModel);
    void display_turn(BattleModel* battleModel);
    void display_end_of_battle(BattleModel* batlle_model, unsigned int xp, unsigned int money);
    void display_battle_stats(BattleModel* battleModel);
    size_t calculate_max_stat_length(const std::vector<std::string>& stat_names, const std::vector<int>& stats);
    
    /*
     * @brief Prints a big HUD box for the screen, used in battle
     * @param custom_msg A vector<string> of messages to print within the box
     * @param padding_symbol The symbol that will be used in outlines
     * @param total_width The total with of the box
     */
    void display_hud(const vector<string> &custom_msg, char padding_symbol, size_t total_width);

    /*
     * @brief Collects relevant info within battleModel then calls this->display_hud method
     * @param battleModel Instance of active BattleModel
     */
    void display_attack_hud(BattleModel* battleModel);
    
    
    /*
     * @brief Displays Entities section in battles
     * @param battleModel Instance of active BattleModel
     */
    void display_battle_entities(BattleModel* battleModel);


    /*
     * @brief Calculates terminal width for hud display using one Entity for each side for battles
     * @param battleModel Instance of active BattleModel
     * @returns Battle Terminal width
     */
    int get_battle_width(BattleModel* battleModel);




    
    string get_color_for_char(char c);
    string colorize_line(string &line, string &neon_color);
    string get_gradient_color(char c, string &neon_color);
    string get_random_neon_color();
    
    
    string colorize_box(string text, string color);
    void display_box_layout(const std::string &title, const std::vector<std::string> &output, string outline_color="pink", string content_color="white");

    // void display_attack_hud(BattleModel* battle_model);

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
* * * * * * * * * * * * * * * * * * * * * * * *
*                                             *
*                                             *
* .===============.     .=====.  .========.   *
* |   SAMHERJI    |     | FIN |  | GUNS'N |   *
* |      HQ       |     |TECH9|  | VESTS  |   *
* '==============='     '====='  '========'   *
*                                             *
*           /=====\      .=========.   .===.  *
*          /       \     |MEGABLOCK|   | C |  *
*  (YOU)   | ARENA |     |  SEVEN  |   | L |  *
*          \       /     '====.    |   | U |  *
*           \=====/           |    |   | B |  *
*                             |    |   '==='  *
*                             '===='          *
*  #*********#                                *
*  |ABONDEND |   .======.    .============.   *
*  |WAREHOUSE|   |RIPPER|    \ CORPORATE /    *
*  #*********#   '======'     \  UNION  /     *
*                              \       /      *
*                               '====='       *
* * * * * * * * * * * * * * * * * * * * * * * *
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


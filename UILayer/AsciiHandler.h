#ifndef ASCIIHANDLER_H
#define ASCIIHANDLER_H

#include "../Models/BattleModel.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class AsciiHandler {
public:
    // Static constant used in several functions.
    static const size_t SPACES = 25;

    // Global ASCII art constants.
    static const string CITY;
    static const string GAME_MAP;
    static const string TITLE;
    static const string SUBTITLE;

    // Display functions.
    static void display_ascii(const string &entity_name);
    static void display_character_selector(const vector<string> &entity_names);
    static void display_start_of_battle(BattleModel* battleModel);
    static void display_turn(BattleModel* battleModel);
    static void display_end_of_battle(BattleModel* battleModel, unsigned int xp, unsigned int money);
    static void display_battle_stats(BattleModel* battleModel);
    static size_t calculate_max_stat_length(const vector<string> &stat_names, const vector<int> &stats);
    static void display_hud(const vector<string> &custom_msg, char padding_symbol, size_t total_width);
    static void display_attack_hud(BattleModel* battleModel);
    static void display_battle_entities(BattleModel* battleModel);
    static int get_battle_width(BattleModel* battleModel);

    // Color and formatting helper functions.
    static string get_color_for_char(char c);
    static string colorize_line(const string &line, string neon_color);
    static string get_gradient_color(char c, string neon_color);
    static string get_random_neon_color();
    static string colorize_box(const string &text, const string &color);
    static void display_box_layout(const string &title, const vector<string> &output,
                                   const string &outline_color = "pink",
                                   const string &content_color = "white");
};

#endif // ASCIIHANDLER_H


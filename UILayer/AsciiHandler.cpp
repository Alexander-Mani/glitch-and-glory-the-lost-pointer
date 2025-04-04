#include "AsciiHandler.h"
#include "../Models/BattleModel.h"
#include "../Models/AllEntities.h"
#include "../LogicLayer/EntityLogic.h"
#include "IOHandler.h"  
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <random>
#include <cassert>

using std::string;
using std::vector;
using std::cout;
using std::endl;

// Define static constants.
const string AsciiHandler::CITY = R"(
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

const string AsciiHandler::GAME_MAP = R"(
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
*          | ARENA |     |  SEVEN  |   | L |  *
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

const string AsciiHandler::TITLE = R"(
   ________    __________________  __   ___    _   ______     ________    ____  ______  __
  / ____/ /   /  _/_  __/ ____/ / / /  /   |  / | / / __ \   / ____/ /   / __ \/ __ \ \/ /
 / / __/ /    / /  / / / /   / /_/ /  / /| | /  |/ / / / /  / / __/ /   / / / / /_/ /\  / 
/ /_/ / /____/ /  / / / /___/ __  /  / ___ |/ /|  / /_/ /  / /_/ / /___/ /_/ / _, _/ / /  
\____/_____/___/ /_/  \____/_/ /_/  /_/  |_/_/ |_/_____/   \____/_____/\____/_/ |_| /_/   
)";

const string AsciiHandler::SUBTITLE = R"(
 _____ _  _ ___   _    ___  ___ _____   ___  ___ ___ _  _ _____ ___ ___ 
|_   _| || | __| | |  / _ \/ __|_   _| | _ \/ _ \_ _| \| |_   _| __| _ \
  | | | __ | _|  | |_| (_) \__ \ | |   |  _/ (_) | || .` | | | | _||   /
  |_| |_||_|___| |____\___/|___/ |_|   |_|  \___/___|_|\_| |_| |___|_|_\
)";

//---------------------------------------------------------
// Display functions
//---------------------------------------------------------

void AsciiHandler::display_ascii(const string &entity_name) {
    cout << "Displaying ASCII art for: " << entity_name << endl;
    // Placeholder: In a full implementation, this might load ASCII art from a file.
}


void AsciiHandler::display_character_selector(const vector<string> &entity_names) {
    cout << "Character Selector:" << endl;
    for (size_t i = 0; i < entity_names.size(); i++) {
        cout << "[" << (i + 1) << "] " << entity_names[i] << endl;
    }
}


void AsciiHandler::display_start_of_battle(BattleModel* battleModel) {
    vector<string> player_ascii = battleModel->playerEntityModel->get_ascii();
    vector<string> opponent_ascii = battleModel->compEntityModel->get_ascii();

    // Reverse the player's ASCII art.
    for (auto &line : player_ascii) {
        std::reverse(line.begin(), line.end());
    }

    string content;
    size_t max_length = std::max(player_ascii.size(), opponent_ascii.size());
    for (size_t i = 0; i < max_length; ++i) {
        string player_line = (i < player_ascii.size()) ? player_ascii[i] : "";
        string opponent_line = (i < opponent_ascii.size()) ? opponent_ascii[i] : "";
        if (i == 23)
            content = battleModel->playerEntityModel->get_name();
        else if (i == 24)
            content = "VS";
        else if (i == 25)
            content = battleModel->compEntityModel->get_name();
        else
            content = (i % 2 == 0) ? "\\" : "/";
        
        int total_padding = SPACES - static_cast<int>(content.length());
        if (total_padding < 0) {
            cout << "Content too long in display_start_of_battle." << endl;
            return;
        }
        int left_padding = total_padding / 2;
        int right_padding = total_padding - left_padding;
        cout << player_line 
             << string(left_padding, ' ') 
             << content 
             << string(right_padding, ' ') 
             << opponent_line << "\n";
    }
}


void AsciiHandler::display_turn(BattleModel* battleModel) {
    display_battle_entities(battleModel);
    display_battle_stats(battleModel);
    display_attack_hud(battleModel);
}


void AsciiHandler::display_end_of_battle(BattleModel* battleModel, unsigned int xp, unsigned int money) {
    IOHandler::clear_terminal();
    int bribe = battleModel->get_bribe_amount();
    string xp_info;
    if (bribe > 0)
        xp_info = "You Received: " + std::to_string(xp) + " xp and: $" + std::to_string(money) + " eddies and bribed for " + std::to_string(bribe) + " eddies";
    else
        xp_info = "You Received: " + std::to_string(xp) + " xp and: $" + std::to_string(money) + " eddies";
    
    vector<string> output;
    // In a complete game, you might call a function like battle_over_msg; here we use a placeholder.
    string battle_msg = "Battle Over";
    output.push_back("");
    output.push_back("");
    output.push_back(battle_msg);
    output.push_back("");
    output.push_back(xp_info);
    output.push_back("");
    output.push_back("");
    
    if(xp == 0){
        display_box_layout("BATTLE LOST", output, "pink");
    } else {
        display_box_layout("BATTLE WON", output, "green");
    }
    IOHandler::glitch_sleep(3);
    IOHandler::clear_terminal();
}


void AsciiHandler::display_battle_stats(BattleModel* battleModel){

    vector<int> player_stats = battleModel->playerEntityModel->get_battle_stats();
    vector<int> opponent_stats = battleModel->compEntityModel->get_battle_stats(); 


    vector<string> player_stat_names = battleModel->playerEntityModel->get_battle_stat_names();
    vector<string> opponent_stat_names = battleModel->compEntityModel->get_battle_stat_names();

    size_t player_width = battleModel->playerEntityModel->get_ascii()[0].size();
    size_t opponent_width = battleModel->compEntityModel->get_ascii()[0].size();

    size_t max_length = max(player_stats.size(), opponent_stats.size());

    string player_content, opponent_content, output_left, output_right;
    
    size_t left_total_padding, left_left_padding, left_right_padding;
    size_t right_total_padding, right_left_padding, right_right_padding;

    size_t p_stat_space = AsciiHandler::calculate_max_stat_length(player_stat_names, player_stats);
    size_t o_stat_space = AsciiHandler::calculate_max_stat_length(opponent_stat_names, opponent_stats);
    //string name_type;
    for (size_t i = 0; i < max_length; i++){
        player_content = "| " + player_stat_names[i] + ':'; 
        player_content += string(p_stat_space - (player_stat_names[i].size() + to_string(player_stats[i]).size()), ' '); 
        player_content += to_string(player_stats[i]) + " |";

        left_total_padding = player_width - player_content.size();
        left_left_padding = left_total_padding / 2;
        left_right_padding = left_total_padding - left_left_padding;
        if (i == 0){
            // cout << string(left_left_padding, ' ') << string(player_content.size(),'-') + string(left_right_padding, ' ');
            cout << IOHandler::apply_neon_colors(string(left_left_padding, ' ') + string(player_content.size(),'-') + string(left_right_padding, ' '));
        }
        output_left = string(left_left_padding, ' ') + player_content + string(left_right_padding, ' ');


        opponent_content = "| " + opponent_stat_names[i] + ':'; 
        opponent_content += string(o_stat_space - (opponent_stat_names[i].size() + to_string(opponent_stats[i]).size()), ' '); 
        opponent_content += to_string(opponent_stats[i]) + " |";

        right_total_padding = opponent_width - o_stat_space;
        right_left_padding = right_total_padding / 2;
        right_right_padding = right_total_padding - right_left_padding;
        output_right = string(right_left_padding, ' ') + opponent_content + string(right_right_padding, ' ');
        if (i == 0){
            cout << IOHandler::apply_neon_colors(string(SPACES, ' ') + string(right_left_padding, ' ') + string(opponent_content.size(),'-') + string(right_right_padding, ' ') + "\n");
        }

        cout << IOHandler::apply_neon_colors(output_left + string(SPACES, ' ') + output_right + "\n"); 
        if (i == max_length-1){
            cout << IOHandler::apply_neon_colors(string(left_left_padding, ' ') + string(player_content.size(),'-') + string(left_right_padding, ' '));
            cout << IOHandler::apply_neon_colors(string(SPACES, ' ') + string(right_left_padding, ' ') + string(opponent_content.size(),'-') + string(right_right_padding, ' ') + "\n");

        }
    }
}


size_t AsciiHandler::calculate_max_stat_length(const vector<string> &stat_names, const vector<int> &stats) {
    size_t max_length = 0;
    for (size_t i = 0; i < stat_names.size() && i < stats.size(); ++i) {
        size_t current_length = stat_names[i].size() + 3 + std::to_string(stats[i]).size();
        if (current_length > max_length)
            max_length = current_length;
    }
    return max_length;
}


void AsciiHandler::display_hud(const vector<string> &custom_msg, char padding_symbol, size_t total_width) {
    cout << IOHandler::apply_neon_colors(string(total_width, padding_symbol) + "\n");
    cout << IOHandler::apply_neon_colors(string(1, padding_symbol) + string(total_width - 2, ' ') + string(1, padding_symbol) + "\n");
    for (const string &msg : custom_msg) {
        int msg_total_padding = total_width - msg.size();
        int msg_left_padding = msg_total_padding / 2;
        int msg_right_padding = msg_total_padding - msg_left_padding;
        cout << IOHandler::apply_neon_colors(
                    string(1, padding_symbol) +
                    string(msg_left_padding - 1, ' ') +
                    msg +
                    string(msg_right_padding - 1, ' ') +
                    string(1, padding_symbol) +
                    "\n"
                );
    }
    cout << IOHandler::apply_neon_colors(string(1, padding_symbol) + string(total_width - 2, ' ') + string(1, padding_symbol) + "\n");
    cout << IOHandler::apply_neon_colors(string(total_width, padding_symbol) + "\n");
}


void AsciiHandler::display_attack_hud(BattleModel* battleModel) {
    // For simplicity, we derive chances from the attacker's accuracy.
    string normal_atk_chance = to_string(EntityLogic::get_hit_chance_normal(battleModel)) + "%";
    string heavy_atk_chance = to_string(EntityLogic::get_hit_chance_heavy(battleModel)) + "%";


    string turn, content;
    if(battleModel->player_turn) {
        turn = "----------------------------- Player Options -----------------------------";
        content = "| 1: Normal Attack (" + normal_atk_chance + ") | 2: Heavy (" + heavy_atk_chance + ") | 3: Flee | 4: Bribe | 5: Hack |";
    } else {
        turn = "-------------------------------- OPPONENT --------------------------------";
        content = "Opponent is deciding";
    }
    string spacing = "|" + string(72, ' ') + "|";
    string bottom = "--------------------------------------------------------------------------";
    vector<string> hud_msg = { turn, spacing, content, spacing, bottom };
    int total_width = get_battle_width(battleModel);
    display_hud(hud_msg, '*', total_width);
}


void AsciiHandler::display_battle_entities(BattleModel* battleModel) {
    vector<string> player_ascii = battleModel->playerEntityModel->get_ascii();
    vector<string> opponent_ascii = battleModel->compEntityModel->get_ascii();

    string player_color = "neon green";
    string opponent_color = "random";
    
    // If needed, reverse player ASCII art.
    for (auto &line : player_ascii) {
        reverse(line.begin(), line.end());
    }
    
    // Use your existing logic to determine layout.
    size_t stat_length = max(
        battleModel->playerEntityModel->get_battle_stats().size(),
        battleModel->compEntityModel->get_battle_stats().size()
    );
    size_t max_length = max(player_ascii.size(), opponent_ascii.size());
    if(max_length > stat_length + 5)
        max_length = max_length - stat_length - 5;
    
    for (size_t i = 0; i < max_length; ++i) {
         string player_line = (i < player_ascii.size()) ? player_ascii[i] : "";
         string opponent_line = (i < opponent_ascii.size()) ? opponent_ascii[i] : "";
         
         int total_padding = SPACES;
         if (total_padding < 0) {
              cout << "Some content being passed into ascii handler 'display_turn' is too long";
              return;
         }
         int left_padding = total_padding / 2;
         int right_padding = total_padding - left_padding;
         
         // Colorize lines using the provided neon color.
         string colored_player_line = colorize_line(player_line, player_color);
         string colored_opponent_line = colorize_line(opponent_line, opponent_color);
         
         cout << colored_player_line 
                   << string(left_padding, ' ')
                   << string(right_padding, ' ')
                   << colored_opponent_line
                   << "\n";
         
         if (i == max_length - 1) {
              cout << IOHandler::apply_neon_colors(string(left_padding + player_line.size(), '=') + string(right_padding + opponent_line.size(), '=') + "\n");
         }
    }
}


int AsciiHandler::get_battle_width(BattleModel* battleModel) {
    size_t player_width = battleModel->playerEntityModel->get_ascii()[0].size();
    size_t opponent_width = battleModel->compEntityModel->get_ascii()[0].size();
    size_t total_width = player_width + SPACES + opponent_width;
    return static_cast<int>(total_width);
}


//---------------------------------------------------------
// Color and formatting helper functions
//---------------------------------------------------------

string AsciiHandler::get_color_for_char(char c) {
    switch(c) {
        case '#': return "\033[1;37m";  // bright white
        case '*': return "\033[1;33m";  // bright yellow
        case '@': return "\033[1;35m";  // bright magenta
        case '%': return "\033[1;31m";  // bright red
        case '/': 
        case '\\': return "\033[1;36m"; // bright cyan
        case '-': return "\033[1;34m";  // bright blue
        case ':': return "\033[0;33m";  // dim yellow
        default:  return "\033[0m";      // reset
    }
}


string AsciiHandler::colorize_line(const string &line, string neon_color) {
    const string reset = "\033[0m";
    string colored;
    for (char c : line) {
        colored += get_gradient_color(c, neon_color) + string(1, c) + reset;
    }
    return colored;
}


string AsciiHandler::get_gradient_color(char c, string neon_color) {
    if (neon_color == "random")
        neon_color = get_random_neon_color();
    if (neon_color == "neon orange") {
        switch(c) {
            case '*': return "\033[38;2;255;235;200m";
            case '+': return "\033[38;2;255;220;180m";
            case '-': return "\033[38;2;255;205;160m";
            case '=': return "\033[38;2;255;190;140m";
            case '#': return "\033[38;2;255;175;120m";
            case '%': return "\033[38;2;255;160;100m";
            case '@': return "\033[38;2;255;145;80m";
            default:  return "\033[38;2;255;165;0m";
        }
    } else if (neon_color == "neon pink") {
        switch(c) {
            case '*': return "\033[38;2;255;200;220m";
            case '+': return "\033[38;2;255;185;205m";
            case '-': return "\033[38;2;255;170;190m";
            case '=': return "\033[38;2;255;155;175m";
            case '#': return "\033[38;2;255;140;160m";
            case '%': return "\033[38;2;255;125;145m";
            case '@': return "\033[38;2;255;110;130m";
            default:  return "\033[38;2;255;105;180m";
        }
    } else if (neon_color == "neon yellow") {
        switch(c) {
            case '*': return "\033[38;2;255;255;200m";
            case '+': return "\033[38;2;255;255;185m";
            case '-': return "\033[38;2;255;255;170m";
            case '=': return "\033[38;2;255;255;155m";
            case '#': return "\033[38;2;255;255;140m";
            case '%': return "\033[38;2;255;255;125m";
            case '@': return "\033[38;2;255;255;110m";
            default:  return "\033[38;2;255;255;0m";
        }
    } else if (neon_color == "neon green") {
        switch(c) {
            case '*': return "\033[38;2;200;255;200m";
            case '+': return "\033[38;2;180;255;180m";
            case '-': return "\033[38;2;160;255;160m";
            case '=': return "\033[38;2;140;255;140m";
            case '#': return "\033[38;2;120;255;120m";
            case '%': return "\033[38;2;100;255;100m";
            case '@': return "\033[38;2;80;255;80m";
            default:  return "\033[38;2;0;255;0m";
        }
    } else if (neon_color == "neon blue") {
        switch(c) {
            case '*': return "\033[38;2;200;230;255m";
            case '+': return "\033[38;2;180;210;255m";
            case '-': return "\033[38;2;160;190;255m";
            case '=': return "\033[38;2;140;170;255m";
            case '#': return "\033[38;2;120;150;255m";
            case '%': return "\033[38;2;100;130;255m";
            case '@': return "\033[38;2;80;110;255m";
            default:  return "\033[38;2;0;0;255m";
        }
    }
    // Fallback to neon orange gradient.
    switch(c) {
        case '*': return "\033[38;2;255;235;200m";
        case '+': return "\033[38;2;255;220;180m";
        case '-': return "\033[38;2;255;205;160m";
        case '=': return "\033[38;2;255;190;140m";
        case '#': return "\033[38;2;255;175;120m";
        case '%': return "\033[38;2;255;160;100m";
        case '@': return "\033[38;2;255;145;80m";
        default:  return "\033[38;2;255;165;0m";
    }
}


string AsciiHandler::get_random_neon_color() {
    vector<string> neonColors = {"neon pink", "neon yellow", "neon green", "neon blue", "neon orange"};
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0, neonColors.size() - 1);
    return neonColors[dist(gen)];
}


string AsciiHandler::colorize_box(string text, string color){
    string color_code;
    try{
        color_code = IOHandler::neon_colors.at(color); 
    }
    catch(const std::out_of_range &e) {
        color_code = "\033[38;2;255;165;0m";
    }

    return color_code + text + IOHandler::reset_code;
}


void AsciiHandler::display_box_layout(const string &title, const vector<string> &output, const string &outline_color, const string &content_color, int size) {
    const int inner_width = size; // Fixed inner width.
    string left_filler, right_filler, bottom_filler, mid_filler, top_border;
    string display_title = title;
    if ((int)display_title.size() > inner_width - 2)
    display_title = display_title.substr(0, inner_width - 2);
    int title_len = display_title.size();
    int total_filler = inner_width - (title_len + 2);
    int left_filler_count = total_filler / 2;
    int right_filler_count = total_filler - left_filler_count;
    
    for (int i = 0; i < left_filler_count; ++i)
        left_filler += u8"─";
    for (int i = 0; i < right_filler_count; ++i)
        right_filler += u8"─";
    for (int i = 0; i < inner_width; ++i)
        bottom_filler += u8"─";
    
    if(title != ""){
        top_border = colorize_box(u8"┌" + left_filler + " " + display_title + " " + right_filler + u8"┐", outline_color) + "\n";
        (void) mid_filler;
    } else {
        for (int i = 0; i < (total_filler - left_filler_count - right_filler_count + 2); ++i)
            mid_filler += u8"─";
        
        top_border = colorize_box(u8"┌" + left_filler + mid_filler + right_filler + u8"┐", outline_color) + "\n";
    }
    string content;
    for (const auto &line : output) {
        string adjusted_line = line;
        if ((int)adjusted_line.size() > inner_width)
            adjusted_line = adjusted_line.substr(0, inner_width);
        int pad_total = inner_width - adjusted_line.size();
        int pad_left = pad_total / 2;
        int pad_right = pad_total - pad_left;
        content += colorize_box(u8"│", outline_color) +
                   colorize_box(string(pad_left, ' ') + adjusted_line + string(pad_right, ' '), content_color) +
                   colorize_box(u8"│\n", outline_color);
    }
    string bottom_border = colorize_box(u8"└" + bottom_filler + u8"┘\n", outline_color);
    cout << "\n\n" << IOHandler::apply_neon_colors(top_border + content + bottom_border)
         << "\n" << IOHandler::reset_code;
}

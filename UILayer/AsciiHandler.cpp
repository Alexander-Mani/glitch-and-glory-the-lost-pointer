#include "AsciiHandler.h"
#include "../Models/BattleModel.h"
#include "../Models/AllEntities.h"
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <random>

#include <cassert> // For debuggin purposes

using std::string;
using std::endl;

AsciiHandler::AsciiHandler(LogicWrapper *logicWrapper, IOHandler* ioHandler)
    : logicWrapper(logicWrapper), ioHandler(ioHandler)
{}

void AsciiHandler::display_ascii(const string& entity_name) {
    cout << "Displaying ASCII art for: " << entity_name << endl;
    // Placeholder for actual ASCII art retrieval and rendering
}

void AsciiHandler::display_character_selector(vector<EntityModel*>* entities){
    (void) entities;

}


// Helper function to return a color code based on the character
string AsciiHandler::get_color_for_char(char c) {
    // Adjust these mappings as needed for your shadow/highlight effect.
    switch(c) {
        case '#': return "\033[1;37m";  // bright white for main structure
        case '*': return "\033[1;33m";  // bright yellow for highlights
        case '@': return "\033[1;35m";  // bright magenta for accents
        case '%': return "\033[1;31m";  // bright red for intensity
        case '/': 
        case '\\': return "\033[1;36m"; // bright cyan for edges
        case '-': return "\033[1;34m";  // bright blue for secondary lines
        case ':': return "\033[0;33m";  // dimmer yellow for shading
        default: return "\033[0m";      // reset/default for spaces or unrecognized symbols
    }
}


void AsciiHandler::display_start_of_battle(BattleModel* battleModel) {
    vector<string> player_ascii = battleModel->playerEntityModel->get_ascii();
    vector<string> opponent_ascii = battleModel->compEntityModel->get_ascii();
    for (auto &line : player_ascii) {
        reverse(line.begin(), line.end());
    }
    string content;
    size_t max_length = max(player_ascii.size(), opponent_ascii.size());
    int total_padding;
    for (size_t i = 0; i < max_length; ++i) {
        string player_line = (i < player_ascii.size()) ? player_ascii[i] : "";
        string opponent_line = (i < opponent_ascii.size()) ? opponent_ascii[i] : "";
        if (i == 23) content = battleModel->playerEntityModel->get_name();
        else if (i == 24) content = "VS";
        else if (i == 25) content = battleModel->compEntityModel->get_name();
        else{
            content = "/";
            if( i % 2 ==0) content = "\\";
        }// Compute total padding needed
        total_padding = SPACES - content.length();
        if (total_padding < 0){
            cout << "Some content being passed into ascii handler 'display_start_of_battle' is too long";
            return;
        }
        int left_padding = total_padding / 2;
        //cout << player_line;
        
        int right_padding = total_padding - left_padding;
        //cout << total_padding << " " << left_padding << " " << right_padding << "";
        cout << player_line << string(left_padding, ' ') << content << string(right_padding, ' ') << opponent_line << "\n";
    }
}

// void AsciiHandler::display_battle_entities(BattleModel* battleModel){
//     vector<string> player_ascii = battleModel->playerEntityModel->get_ascii();
//     vector<string> opponent_ascii = battleModel->compEntityModel->get_ascii();
//     size_t stat_length = max(battleModel->playerEntityModel->get_battle_stats().size(), battleModel->compEntityModel->get_battle_stats().size()); 
//     for (auto &line : player_ascii) {
//         reverse(line.begin(), line.end());
//     }
    
//     size_t max_length = max(player_ascii.size(), opponent_ascii.size());
//     max_length = max_length - stat_length - 5;
//     //minus max_length from size of stats then replace them
//     //after print stats so the appear in padding of width
//     for (size_t i = 0; i < max_length; ++i) {
//         string player_line = (i < player_ascii.size()) ? player_ascii[i] : "";
//         string opponent_line = (i < opponent_ascii.size()) ? opponent_ascii[i] : "";
    
//         int total_padding = SPACES;
//         if (total_padding < 0){
//             cout << "Some content being passed into ascii handler 'display_turn' is too long";
//             return; //if this happens increase the SPACES constant in AsciiHandler.h
//         }
//         int left_padding = total_padding / 2;
//         int right_padding = total_padding - left_padding;
    
//         cout << player_line << string(left_padding, ' ')  << string(right_padding, ' ') << opponent_line << '\n';
//         if(max_length-1 ==i){
//             cout << string(left_padding+player_line.size(), '=')  << string(right_padding+opponent_line.size(), '=')<< '\n';
//         }
//     }
// }

string AsciiHandler::get_random_neon_color() {
    vector<string> neonColors = {
        "neon pink", "neon yellow", "neon green", "neon blue", "neon orange"
    };

    // Randomly select a color
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, neonColors.size() - 1);
    
    return neonColors[dist(gen)];
}

// Helper: Returns an ANSI escape sequence based on the symbol and chosen neon color.
string AsciiHandler::get_gradient_color(char c, string &neon_color) {
    if (neon_color == "random") {
        neon_color = this->get_random_neon_color(); // Choose a random neon color
    }
    // For each neon color, we define a gradient mapping
    if (neon_color == "neon orange") {
        switch(c) {
            case '*': return "\033[38;2;255;235;200m"; // lightest
            case '+': return "\033[38;2;255;220;180m";
            case '-': return "\033[38;2;255;205;160m";
            case '=': return "\033[38;2;255;190;140m";
            case '#': return "\033[38;2;255;175;120m";
            case '%': return "\033[38;2;255;160;100m";
            case '@': return "\033[38;2;255;145;80m";  // darkest
            default:  return "\033[38;2;255;165;0m";   // fallback neon orange
        }
    } else if (neon_color == "neon pink") {
        switch(c) {
            case '*': return "\033[38;2;255;200;220m"; // very light neon pink
            case '+': return "\033[38;2;255;185;205m";
            case '-': return "\033[38;2;255;170;190m";
            case '=': return "\033[38;2;255;155;175m";
            case '#': return "\033[38;2;255;140;160m";
            case '%': return "\033[38;2;255;125;145m";
            case '@': return "\033[38;2;255;110;130m";  // darkest neon pink
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
    // Default fallback: neon orange gradient
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

// Helper: Colorizes a single line using the provided neon color name.
string AsciiHandler::colorize_line(string &line, string &neon_color) {
    const string reset = "\033[0m";
    string colored;
    for (char c : line) {
        colored += this->get_gradient_color(c, neon_color) + string(1, c) + reset;
    }
    return colored;
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
              cout << string(left_padding + player_line.size(), '=')  
                        << string(right_padding + opponent_line.size(), '=') 
                        << "\n";
         }
    }
}



void AsciiHandler::display_turn(BattleModel* battleModel){
    this->display_battle_entities(battleModel);
    this->display_battle_stats(battleModel);
    this->display_attack_hud(battleModel);
}

int AsciiHandler::get_battle_width(BattleModel* battleModel){
    // Fetch Entity sizes to determine total_width
    size_t player_width = battleModel->playerEntityModel->get_ascii()[0].size();
    size_t opponent_width = battleModel->compEntityModel->get_ascii()[0].size();
    size_t total_width = player_width+SPACES+opponent_width;

    return total_width;
}


// void AsciiHandler::display_hud(const vector<string> &custom_msg, char padding_symbol, size_t total_width){
//     cout << string(total_width, padding_symbol)<< endl;
//     cout << padding_symbol << string(total_width-2, ' ') << padding_symbol << endl;
//     for(string msg : custom_msg){
//         assert(msg.size() < total_width);

//         int msg_total_padding = total_width - msg.size();
//         int msg_left_padding = msg_total_padding / 2;
//         int msg_right_padding = msg_total_padding - msg_left_padding;

//         cout << padding_symbol << string(msg_left_padding-1, ' ') << msg << string(msg_right_padding-1, ' ') << padding_symbol << endl;
//     }
//     cout << padding_symbol << string(total_width-2, ' ') << padding_symbol << endl;
//     cout << string(total_width, padding_symbol)<< endl;
// }

void AsciiHandler::display_hud(const vector<string> &custom_msg, char padding_symbol, size_t total_width){
    // ANSI escape codes for neon color (bright cyan) and reset
    const string neon = "\033[1;36m"; // bright cyan
    const string reset = "\033[0m";

    // Top border in neon color
    cout << neon << string(total_width, padding_symbol) << reset << endl;

    // Top padding row
    cout << neon << padding_symbol << reset << string(total_width-2, ' ') 
         << neon << padding_symbol << reset << endl;

    // For each message, center it and print neon border on both sides
    for(const string &msg : custom_msg){
        assert(msg.size() < total_width);
        int msg_total_padding = total_width - msg.size();
        int msg_left_padding = msg_total_padding / 2;
        int msg_right_padding = msg_total_padding - msg_left_padding;
        cout << neon << padding_symbol << reset 
             << string(msg_left_padding-1, ' ') << msg 
             << string(msg_right_padding-1, ' ') 
             << neon << padding_symbol << reset << endl;
    }

    // Bottom padding row
    cout << neon << padding_symbol << reset << string(total_width-2, ' ') 
         << neon << padding_symbol << reset << endl;

    // Bottom border in neon color
    cout << neon << string(total_width, padding_symbol) << reset << endl;
}



void AsciiHandler::display_attack_hud(BattleModel* battleModel){
    string turn;
    string content;
    string spacing;
    string bottom;


    vector<string> hud_msg;

    string normal_atk_chance = to_string(this->logicWrapper->entityLogic->get_hit_chance_normal(battleModel)) + "%";
    string heavy_atk_chance = to_string(this->logicWrapper->entityLogic->get_hit_chance_heavy(battleModel)) + "%";
    
    // Generate turn and content based on the current player
    battleModel->player_turn ? turn = "----------------------------- Player Options -----------------------------" : turn = "-------------------------------- OPPONENT --------------------------------";
    // battleModel->player_turn ? turn = "1: Normal Attack (71%) | 2: Heavy (53%) | 3: Flee | 4: Bribe | 5: Hack " : turn = "1: Normal Attack (71%) | 2: Heavy (53%) | 3: Flee | 4: Bribe | 5: Hack ";
    battleModel->player_turn ? content = "| 1: Normal Attack (" + normal_atk_chance + ") | 2: Heavy (" + heavy_atk_chance + ") | 3: Flee | 4: Bribe | 5: Hack |" : content =  "Opponent is deciding";
            //   "| 1: Normal Attack (71%) | 2: Heavy (53%) | 3: Flee | 4: Bribe | 5: Hack |"
    spacing = "|                                                                        |";
    bottom = "--------------------------------------------------------------------------";

    // Insert turn an content to hud_msg 
    hud_msg.push_back(turn);
    hud_msg.push_back(spacing);
    hud_msg.push_back(content);
    hud_msg.push_back(spacing);
    hud_msg.push_back(bottom);

    // // Fetch Entity sizes to determine total_width
    int total_width = this->get_battle_width(battleModel);

    // Display the hud message
    this->display_hud(hud_msg, '*', total_width);
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

    size_t p_stat_space = this->calculate_max_stat_length(player_stat_names, player_stats);
    size_t o_stat_space = this->calculate_max_stat_length(opponent_stat_names, opponent_stats);
    //string name_type;
    for (size_t i = 0; i < max_length; i++){
        player_content = "| " + player_stat_names[i] + ':'; 
        player_content += string(p_stat_space - (player_stat_names[i].size() + to_string(player_stats[i]).size()), ' '); 
        player_content += to_string(player_stats[i]) + " |";

        left_total_padding = player_width - player_content.size();
        left_left_padding = left_total_padding / 2;
        left_right_padding = left_total_padding - left_left_padding;
        if (i == 0){
            cout << string(left_left_padding, ' ') << string(player_content.size(),'-') + string(left_right_padding, ' ');
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
            cout << string(SPACES, ' ') <<string(right_left_padding, ' ') << string(opponent_content.size(),'-') + string(right_right_padding, ' ') << endl;
        }

        cout << output_left << string(SPACES, ' ') << output_right << endl; 
        if (i == max_length-1){
            cout << string(left_left_padding, ' ') << string(player_content.size(),'-') + string(left_right_padding, ' ');
            cout << string(SPACES, ' ') <<string(right_left_padding, ' ') << string(opponent_content.size(),'-') + string(right_right_padding, ' ') << endl;

        }
    }
}

size_t AsciiHandler::calculate_max_stat_length(const vector<string>& stat_names, const vector<int>& stats) {
    size_t max_length = 0;
    for (size_t i = 0; i < stat_names.size() && i < stats.size(); ++i) {
        size_t current_length = stat_names[i].size() + 3 + to_string(stats[i]).size();
        max_length = max(max_length, current_length);
    }
    return max_length;
}

void AsciiHandler::display_end_of_battle(BattleModel* battleModel){
    (void)battleModel;
    string battle_msg = this->logicWrapper->battleLogic->battle_over_msg(battleModel);
    cout << "=== BATTLE OVER ===" << endl << battle_msg << endl;

}


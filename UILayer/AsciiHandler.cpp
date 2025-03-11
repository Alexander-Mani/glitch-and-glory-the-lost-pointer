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

using std::string;
using std::endl;

AsciiHandler::AsciiHandler() {}

void AsciiHandler::display_ascii(const string& entity_name) {
    cout << "Displaying ASCII art for: " << entity_name << endl;
    // Placeholder for actual ASCII art retrieval and rendering
}

void AsciiHandler::display_character_selector(std::vector<EntityModel*>* entities){
    (void) entities;

}

void AsciiHandler::display_start_of_battle(BattleModel* battle_model) {
    std::vector<std::string> player_ascii = battle_model->playerEntityModel->get_ascii();
    std::vector<std::string> opponent_ascii = battle_model->compEntityModel->get_ascii();
    for (auto &line : player_ascii) {
        std::reverse(line.begin(), line.end());
    }
    std::string content;
    size_t max_length = std::max(player_ascii.size(), opponent_ascii.size());
    int total_padding;
    for (size_t i = 0; i < max_length; ++i) {
        std::string player_line = (i < player_ascii.size()) ? player_ascii[i] : "";
        std::string opponent_line = (i < opponent_ascii.size()) ? opponent_ascii[i] : "";
        if (i == 23) content = battle_model->playerEntityModel->get_name();
        else if (i == 24) content = "VS";
        else if (i == 25) content = battle_model->compEntityModel->get_name();
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
        std::cout << player_line << std::string(left_padding, ' ') << content << std::string(right_padding, ' ') << opponent_line << "\n";
    }
}

void AsciiHandler::display_turn(BattleModel* battle_model){
    std::vector<std::string> player_ascii = battle_model->playerEntityModel->get_ascii();
    std::vector<std::string> opponent_ascii = battle_model->compEntityModel->get_ascii();
    size_t stat_length = max(battle_model->playerEntityModel->get_battle_stats().size(), battle_model->compEntityModel->get_battle_stats().size()); 
    for (auto &line : player_ascii) {
        std::reverse(line.begin(), line.end());
    }
    size_t max_length = std::max(player_ascii.size(), opponent_ascii.size());
    max_length = max_length - stat_length - 5;
    //minus max_length from size of stats then replace them
    //after print stats so the appear in padding of width
    for (size_t i = 0; i < max_length; ++i) {
        std::string player_line = (i < player_ascii.size()) ? player_ascii[i] : "";
        std::string opponent_line = (i < opponent_ascii.size()) ? opponent_ascii[i] : "";

        int total_padding = SPACES;
        if (total_padding < 0){
            cout << "Some content being passed into ascii handler 'display_turn' is too long";
            return; //if this happens increase the SPACES constant in AsciiHandler.h
        }
        int left_padding = total_padding / 2;
        int right_padding = total_padding - left_padding;

        std::cout << player_line << std::string(left_padding, ' ')  << std::string(right_padding, ' ') << opponent_line << '\n';
        if(max_length-1 ==i){
            std::cout << std::string(left_padding+player_line.size(), '=')  << std::string(right_padding+opponent_line.size(), '=')<< '\n';
        }

    }
    this->display_battle_stats(battle_model);
    this->display_attack_hud(battle_model);
}

void AsciiHandler::display_attack_hud(BattleModel* battle_model){
    size_t player_width = battle_model->playerEntityModel->get_ascii()[0].size();
    size_t opponent_width = battle_model->compEntityModel->get_ascii()[0].size();
    size_t total_width = player_width+SPACES+opponent_width;
    string turn = "OPPONENT'S TURN!";
    string content = "Opponent is deciding.";
    if(battle_model->player_turn){
    content = "1: Normal Attack | 2: Heavy | 3: Flee | 4: Bribe | 5: Special"; 
    turn = "YOU TURN!";
    }
    int turn_total_padding = total_width - turn.size();
    int turn_left_padding = turn_total_padding / 2;
    int turn_right_padding = turn_total_padding - turn_left_padding;

    int total_padding = total_width - content.size();
    int left_padding = total_padding / 2;
    int right_padding = total_padding - left_padding;
    cout << string(total_width, '*')<< endl;
    cout << '*' << string(total_width-2, ' ') << '*' << endl;
    cout << '*' << string(turn_left_padding-1, ' ') << turn << string(turn_right_padding-1, ' ') << '*' << endl;
    cout << '*' << string(left_padding-1, ' ') << content << string(right_padding-1, ' ') << '*' << endl;
    cout << '*' << string(total_width-2, ' ') << '*' << endl;
    cout << string(total_width, '*')<< endl;

    

}

void AsciiHandler::display_battle_stats(BattleModel* battle_model){

    std::vector<int> player_stats = battle_model->playerEntityModel->get_battle_stats();
    std::vector<int> opponent_stats = battle_model->compEntityModel->get_battle_stats(); 


    std::vector<std::string> player_stat_names = battle_model->playerEntityModel->get_battle_stat_names();
    std::vector<std::string> opponent_stat_names = battle_model->compEntityModel->get_battle_stat_names();

    size_t player_width = battle_model->playerEntityModel->get_ascii()[0].size();
    size_t opponent_width = battle_model->compEntityModel->get_ascii()[0].size();

    size_t max_length = max(player_stats.size(), opponent_stats.size());

    std::string player_content, opponent_content, output_left, output_right;
    
    size_t left_total_padding, left_left_padding, left_right_padding;
    size_t right_total_padding, right_left_padding, right_right_padding;

    size_t p_stat_space = this->calculate_max_stat_length(player_stat_names, player_stats);
    size_t o_stat_space = this->calculate_max_stat_length(opponent_stat_names, opponent_stats);
    //string name_type;
    for (size_t i = 0; i < max_length; i++){
        player_content = "| " + player_stat_names[i] + ':'; 
        player_content += string(p_stat_space - (player_stat_names[i].size() + std::to_string(player_stats[i]).size()), ' '); 
        player_content += std::to_string(player_stats[i]) + " |";

        left_total_padding = player_width - player_content.size();
        left_left_padding = left_total_padding / 2;
        left_right_padding = left_total_padding - left_left_padding;
        if (i == 0){
            cout << string(left_left_padding, ' ') << string(player_content.size(),'-') + string(left_right_padding, ' ');
        }
        output_left = string(left_left_padding, ' ') + player_content + string(left_right_padding, ' ');


        opponent_content = "| " + opponent_stat_names[i] + ':'; 
        opponent_content += string(o_stat_space - (opponent_stat_names[i].size() + std::to_string(opponent_stats[i]).size()), ' '); 
        opponent_content += std::to_string(opponent_stats[i]) + " |";

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
size_t AsciiHandler::calculate_max_stat_length(const std::vector<std::string>& stat_names, const std::vector<int>& stats) {
    size_t max_length = 0;
    for (size_t i = 0; i < stat_names.size() && i < stats.size(); ++i) {
        size_t current_length = stat_names[i].size() + 3 + std::to_string(stats[i]).size();
        max_length = std::max(max_length, current_length);
    }
    return max_length;
}

void AsciiHandler::display_end_of_battle(BattleModel* batlle_model){
    (void)batlle_model;

}


#include "AsciiHandler.h"
#include "../Models/BattleModel.h"
#include "../Models/AllEntities.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

AsciiHandler::AsciiHandler() {}

void AsciiHandler::display_ascii(const string& entity_name) {
    cout << "Displaying ASCII art for: " << entity_name << endl;
    // Placeholder for actual ASCII art retrieval and rendering
}

void AsciiHandler::display_character_selector(std::vector<EntityModel*>* entities){
    (void) entities;

}

void AsciiHandler::display_start_of_battle(BattleModel* battle_model) {
    std::vector<std::string> reversedLines1 = battle_model->playerEntityModel->get_ascii();
    std::vector<std::string> lines2 = battle_model->compEntityModel->get_ascii();
    for (auto &line : reversedLines1) {
        std::reverse(line.begin(), line.end());
    }
    std::string content;
    size_t maxSize = std::max(reversedLines1.size(), lines2.size());
    for (size_t i = 0; i < maxSize; ++i) {
        std::string line1 = (i < reversedLines1.size()) ? reversedLines1[i] : "";
        std::string line2 = (i < lines2.size()) ? lines2[i] : "";
        if (i == 23) content = battle_model->playerEntityModel->get_name();
        else if (i == 24) content = "VS";
        else if (i == 25) content = battle_model->compEntityModel->get_name();
        else{
            content = "/";
            if( i % 2 ==0) content = "\\";
        }// Compute total padding needed
        int total_padding = SPACES - content.length();
        if (total_padding < 0){
            cout << "Some content being passed into ascii handler 'display_start_of_battle' is too long";
            return;
        }
        int left_padding = total_padding / 2;
        int right_padding = total_padding - left_padding;

        std::cout << line1 << std::string(left_padding, ' ') << content << std::string(right_padding, ' ') << line2 << '\n';
    }

}

void AsciiHandler::display_turn(BattleModel* battle_model){
    std::vector<std::string> reversedLines1 = battle_model->playerEntityModel->get_ascii();
    std::vector<std::string> lines2 = battle_model->compEntityModel->get_ascii();
    for (auto &line : reversedLines1) {
        std::reverse(line.begin(), line.end());
    }
    std::string content = "get r3kt";
    size_t maxSize = std::max(reversedLines1.size(), lines2.size());
    for (size_t i = 0; i < maxSize; ++i) {
        std::string line1 = (i < reversedLines1.size()) ? reversedLines1[i] : "";
        std::string line2 = (i < lines2.size()) ? lines2[i] : "";

            
        int total_padding = SPACES - content.length();
        if (total_padding < 0){
            cout << "Some content being passed into ascii handler 'display_turn' is too long";
            return;
        }
        int left_padding = total_padding / 2;
        int right_padding = total_padding - left_padding;

        std::cout << line1 << std::string(left_padding, ' ') << content << std::string(right_padding, ' ') << line2 << '\n';
    }


}

void AsciiHandler::display_end_of_battle(BattleModel* batlle_model){
    (void)batlle_model;

}


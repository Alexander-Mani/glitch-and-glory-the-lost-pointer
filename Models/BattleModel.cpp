#include "BattleModel.h"



EntityModel* BattleModel::get_attacker() {
    return this->player_turn ? this->playerEntityModel : this->compEntityModel;
}

EntityModel* BattleModel::get_defender() {
    return this->player_turn ? this->compEntityModel : this->playerEntityModel;
}

// bool BattleModel::is_finished(){
//     EntityModel *player = this->get_attacker();
//     EntityModel *computer = this->get_attacker();
// }

// string BattleModel::fetch_results(){
    // string ret_str;
    // ret_str = "\n===============================================\n";
    // ret_str = "===       BattleModel.fetch_results()       ===\n";
    // ret_str = "===============================================\n";
    // EntityModel *player;
    // EntityModel *computer;
    
    // if(this->player_turn){
    //     player = this->get_attacker();
    //     computer = this->get_defender();
    // } else {
    //     computer = this->get_attacker();
    //     player = this->get_defender();
    // }
    
    // if(computer->get_hp() == 0 && player->get_hp() != 0){
    //     ret_str = "===                                         ===\n";
    //     ret_str = "===           !!! PLAYER WON !!!            ===\n";
    //     ret_str = "===                                         ===\n";
    // } else if (computer->get_hp() == 0 && player->get_hp() != 0){
    //     ret_str = "===                                         ===\n";
    //     ret_str = "===          !!! COMPUTER WON !!!           ===\n";
    //     ret_str = "===                                         ===\n";

    // }


    // ret_str += "===============================================\n\n";

// }
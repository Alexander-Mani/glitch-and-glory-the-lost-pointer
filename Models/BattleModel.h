#ifndef BATTLEMODEL_H
#define BATTLEMODEL_H

#include "AllEntities.h"


class BattleModel {
public:
    EntityModel *playerEntityModel;
    EntityModel *compEntityModel;
    bool player_turn;  
    int total_party_money;
    bool fled;
    int bribe_amount;
    bool bribed;

    BattleModel(EntityModel* player, EntityModel* opponent, bool turn, int total_party_money , bool fled=false, int bribe_amount=0, int bribed=false)
        : playerEntityModel(player), compEntityModel(opponent), player_turn(turn), total_party_money(total_party_money), fled(fled), bribe_amount(bribe_amount), bribed(bribed) {}

    std::vector<std::string> get_battle_actions() const {
        return {"A", "H", "F", "B", "S"};
    }
    
    EntityModel *get_attacker();

    EntityModel *get_defender();

    void flee(){this->fled=true;}

    int add_bribe(){ 
        this->bribe_amount =+ this->total_party_money * 0.05; 
        return this->total_party_money * 0.05;
    }

    void bribify(){this->bribed = true;}
    
    int get_bribe_amount(){return this->bribe_amount;}


};


#endif // BATTLEMODEL_H

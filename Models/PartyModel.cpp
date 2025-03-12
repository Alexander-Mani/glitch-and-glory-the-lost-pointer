#include "PartyModel.h"
#include "AllEntities.h"
#include "Entities/BioEnhancedBerserkerModel.h"
#include "Entities/CyberGladiatorModel.h"
#include "Entities/TechnoOracleModel.h"

#include <iostream>
#include <vector>
#include <unordered_map>



// Default constructor in case you want to initalize without params such as in the begining
PartyModel::PartyModel(EntityModel* party_member_1, EntityModel* party_member_2, EntityModel* party_member_3)
    :   party_member_1(party_member_1), 
        party_member_2(party_member_2),
        party_member_3(party_member_3),
        party_money(0),
        level(0),
        party_xp_level_up_threshold(50),
        party_xp(0) {
        // Additional initialization code if needed
}

EntityModel* PartyModel::get_party_member_1() {
   return this->party_member_1; 
}

EntityModel* PartyModel::get_party_member_2() {
   return this->party_member_2; 

}

EntityModel* PartyModel::get_party_member_3() {
   return this->party_member_3; 

}


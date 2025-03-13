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

vector<string> PartyModel::get_party_member_names(){
      return {this->party_member_1->get_name(), this->party_member_2->get_name(), this->party_member_3->get_name()};
}

vector<EntityModel*> PartyModel::get_party_members(){
      return {this->party_member_1, this->party_member_2, this->party_member_3};
}

void PartyModel::display_party() {
   vector<EntityModel*> members = this->get_party_members();
   cout << "Your Party: " << endl;
   cout << "Eddies: " << party_money << endl;
   cout << "Level: " << level << " | Next level: [" << party_xp <<"/" << party_xp_level_up_threshold << "xp] " << endl;
   for (EntityModel* member: members){
      member->display_stats();
      member->display_inventory();
   }
   cout << "Eddies: " << party_money << endl;
   cout << "Level: " << level << " | Next level: [" << party_xp <<"/" << party_xp_level_up_threshold << "xp] " << endl;

}


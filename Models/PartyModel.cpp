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

vector<string> PartyModel::display_party() {
    vector<string> output;
    output.push_back("Your Party:");
    output.push_back("Eddies: $" + to_string(party_money));
    output.push_back("Level: " + to_string(level) + " | Next level: [" +
                     to_string(party_xp) + "/" + to_string(party_xp_level_up_threshold) + "xp]");

    vector<vector<string>> combinedLinesPerMember;
    int maxLines = 0;

    for (auto member : get_party_members()) {
        vector<string> stats = member->get_stats_lines();
        vector<string> inventory = member->get_inventory_lines();
        vector<string> combined = stats;
        combined.insert(combined.end(), inventory.begin(), inventory.end());
        maxLines = max(maxLines, static_cast<int>(combined.size()));
        combinedLinesPerMember.push_back(combined);
    }

    for (int line = 0; line < maxLines; ++line) {
        string combinedLine;
        for (size_t mem = 0; mem < combinedLinesPerMember.size(); ++mem) {
            if (line < static_cast<int>(combinedLinesPerMember[mem].size())) {
                combinedLine += combinedLinesPerMember[mem][line] + "    ";
            } else {
                combinedLine += string(20, ' ') + "\t";
            }
        }
        output.push_back(combinedLine);
    }

    return output;
}

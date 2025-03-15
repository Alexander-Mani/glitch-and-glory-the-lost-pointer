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

// void PartyModel::display_party() {
//    vector<EntityModel*> members = this->get_party_members();
//    cout << "Your Party: " << endl;
//    cout << "Eddies: " << party_money << endl;
//    cout << "Level: " << level << " | Next level: [" << party_xp <<"/" << party_xp_level_up_threshold << "xp] " << endl;
//    for (EntityModel* member: members){
//       member->display_stats();
//       member->display_inventory();
//    }
//    cout << "Eddies: " << party_money << endl;
//    cout << "Level: " << level << " | Next level: [" << party_xp <<"/" << party_xp_level_up_threshold << "xp] " << endl;
// }

// vector<string> PartyModel::display_party() {
//     vector<string> output;

//     // Gather party information header
//     output.push_back("Your Party:");
//     output.push_back("Eddies: " + to_string(party_money));
//     output.push_back("Level: " + to_string(level) + " | Next level: [" + to_string(party_xp) + "/" + to_string(party_xp_level_up_threshold) + "xp]");
 
//     // Get the stats lines for each party member
//     vector<EntityModel*> members = this->get_party_members();
//     vector<vector<string>> statsLines;
//     int maxLines = 0;
//     for (auto member : members) {
//         vector<string> lines = member->get_stats_lines();
//         maxLines = max(maxLines, static_cast<int>(lines.size()));
//         statsLines.push_back(lines);
//     }
 
//     // Print each line of each member side by side
//     for (size_t line = 0; line < maxLines; line++) {
//         for (size_t mem = 0; mem < statsLines.size(); mem++) {
//             if (line < statsLines[mem].size())
//                 cout << statsLines[mem][line] << "\t"; // tab for spacing
//             else
//                 cout << string(20, ' ') << "\t";  // if a member has fewer lines, add blank space
//         }
//         cout << endl;
//     }

    
//  }

//vector<string> PartyModel::display_inventories(){
//    vector<string> output;
//    for (auto member : members) {
//
//        //member->display_inventory();
//    }
//
//}

vector<string> PartyModel::display_party() {
    vector<string> output;

    // Add header lines
    output.push_back("Your Party:");
    output.push_back("Eddies: $" + to_string(party_money));
    output.push_back("Level: " + to_string(level) + " | Next level: [" +
                     to_string(party_xp) + "/" + to_string(party_xp_level_up_threshold) + "xp]");

    // Get the stats lines for each party member
    vector<EntityModel*> members = this->get_party_members();
    vector<vector<string>> statsLines;
    int maxLines = 0;
    for (auto member : members) {
        vector<string> lines = member->get_stats_lines();
        maxLines = max(maxLines, static_cast<int>(lines.size()));
        statsLines.push_back(lines);
        //member->display_inventory();
    }

    // Build each line of member stats side by side
    for (size_t line = 0; line < static_cast<size_t>(maxLines); line++) {
        string combinedLine;
        for (size_t mem = 0; mem < statsLines.size(); mem++) {
            if (line < statsLines[mem].size())
                combinedLine += statsLines[mem][line] + "    "; // add a tab for spacing
            else
                combinedLine += string(20, ' ') + "\t"; // add blank space if no line available
        }
        output.push_back(combinedLine);
    }

    return output;
}

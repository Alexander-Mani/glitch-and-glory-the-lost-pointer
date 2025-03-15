// EquipmentFactory.cpp
#include "EquipmentFactory.h"
#include "../../UILayer/IOHandler.h"
#include "../../UILayer/AsciiHandler.h"
#include <iostream>
#include <iomanip>
#include <string>

EquipmentFactory::EquipmentFactory() {
    // Create new weapon objects and store pointers to them
    weapons.push_back(new WeaponModel("Neons Edge", 0, 1, 0, 0, 0, 0, 400, true));
    weapons.push_back(new WeaponModel("Hyper Katana", 0, 2, 0, 0, 0, 0, 800, true));
    weapons.push_back(new WeaponModel("H&K 7000-a", 0, 4, 0, 0, 0, 0, 1600, true));
    weapons.push_back(new WeaponModel("Cyber Spike", 0, 8, 0, 0, 0, 0, 3200, true));
    weapons.push_back(new WeaponModel("Snow Eagle", 0, 16, 0, 0, 0, 0, 6400, true));

    // Create new armor objects and store pointers to them
    armors.push_back(new ArmorModel("Ballistic Vest", 0, 0, 3, 0, 0, 0, 500, true));
    armors.push_back(new ArmorModel("Samuraii Shoulders", 0, 0, 6, 0, 0, 0, 1000, true));
    armors.push_back(new ArmorModel("Combat Armor", 0, 0, 9, 0, 0, 0, 2000, true));
    armors.push_back(new ArmorModel("Titanium Suit", 0, 0, 12, 0, 0, 0, 4000, true));
    armors.push_back(new ArmorModel("Omega Boots", 0, 0, 15, 0, 0, 0, 8000, true));

    // Create new implant objects and store pointers to them
    implants.push_back(new ImplantModel("Mantis Blades", 0, 0, 0, 0, 5, 0, 1100, true));
    implants.push_back(new ImplantModel("Sandevistan", 0, 0, 0, 0, 10, 0, 2200, true));
    implants.push_back(new ImplantModel("Spinal Augmenter", 0, 0, 0, 0, 14, 0, 4400, true));
    implants.push_back(new ImplantModel("Reinforced Bones", 0, 0, 0, 0, 17, 0, 8800, true));
    implants.push_back(new ImplantModel("Hardened Nose", 0, 0, 0, 0, 20, 0, 17600, true));
}

EquipmentFactory::~EquipmentFactory() {
    // Clean up all allocated weapon objects
    for (WeaponModel* weapon : weapons) {
        delete weapon;
    }
    
    // Clean up all allocated armor objects
    for (ArmorModel* armor : armors) {
        delete armor;
    }
    
    // Clean up all allocated implant objects
    for (ImplantModel* implant : implants) {
        delete implant;
    }
}

vector<WeaponModel*>* EquipmentFactory::get_weapons() {
    return &weapons;
}

vector<ArmorModel*>* EquipmentFactory::get_armors() {
    return &armors;
}

vector<ImplantModel*>* EquipmentFactory::get_implants() {
    return &implants;
}



void EquipmentFactory::show_combat_gear() {
    const int box_width = 30; 
    int option = 1;           

    // --- Weapons ---
    vector<vector<string>> weapon_boxes;
    for (auto weapon : weapons) {
        vector<string> content;
        content.push_back("ATK: " + to_string(weapon->get_atk()));
        content.push_back("DEF: " + to_string(weapon->get_def()));
        content.push_back("MGK: " + to_string(weapon->get_magic()));
        content.push_back("CRIT: " + to_string(weapon->get_crit()));
        content.push_back("EVA: " + to_string(weapon->get_evade()));
        content.push_back("Price: " + to_string(weapon->get_price()));
        // Prepend the numeric option to the title
        string title = to_string(option++) + ". " + weapon->get_name();
        weapon_boxes.push_back(create_box(title, content, box_width));
    }
    IOHandler::output_subtitle("Weapons", "pink");
    print_boxes_side_by_side(weapon_boxes, 4);

    // --- Armors ---
    vector<vector<string>> armor_boxes;
    for (auto armor : armors) {
        vector<string> content;
        content.push_back("DEF: " + to_string(armor->get_def()));
        content.push_back("MGK: " + to_string(armor->get_magic()));
        content.push_back("CRIT: " + to_string(armor->get_crit()));
        content.push_back("EVA: " + to_string(armor->get_evade()));
        content.push_back("Price: " + to_string(armor->get_price()));
        // Continue numbering from weapons
        string title = to_string(option++) + ". " + armor->get_name();
        armor_boxes.push_back(create_box(title, content, box_width));
    }
    IOHandler::output_subtitle("Armors", "pink");
    print_boxes_side_by_side(armor_boxes, 4);

    // --- Go Back Option ---
    string go_back_title = to_string(option++) + ". Go Back";
    IOHandler::output_subtitle(go_back_title, "blue");

}


// void EquipmentFactory::show_cyber_augments() {
//     cout << "=== Implants ===\n";
//     int ind = 1;
//     for (const auto* implant : this->implants) {
//         cout
//             << ind++
//             << ". Name: "   << implant->get_name()
//             << " | HP: "  << implant->get_max_hp()
//             << " | ATK: " << implant->get_atk()
//             << " | DEF: " << implant->get_def()
//             << " | MGK: " << implant->get_magic()
//             << " | CRIT: "<< implant->get_crit()
//             << " | EVA: " << implant->get_evade()
//             << " | Price: " << implant->get_price()
//             << "\n";
//     }
//     cout << to_string(ind++)+". " << "Leave" << endl;
//     cout << endl;
// }

void EquipmentFactory::show_cyber_augments() {
    const int box_width = 30;
    int option = 1;
    
    // --- Implants ---
    vector<vector<string>> implant_boxes;
    for (auto implant : implants) {
        vector<string> content;
        content.push_back("MGK: " + to_string(implant->get_magic()));
        content.push_back("CRIT: " + to_string(implant->get_crit()));
        content.push_back("Price: " + to_string(implant->get_price()));
        // Prepend the numeric option to the title
        string title = to_string(option++) + ". " + implant->get_name();
        implant_boxes.push_back(create_box(title, content, box_width));
    }
    IOHandler::output_subtitle("Implants", "pink");
    print_boxes_side_by_side(implant_boxes, 4);
    
    // --- Go Back Option (without divider) ---
    string go_back_title = to_string(option++) + ". Go Back";
    int pad = box_width - 2 - go_back_title.size();
    int pad_left = pad / 2;
    int pad_right = pad - pad_left;
    // string top_border = "┌" + string(box_width - 2, '─') + "┐";
    string top_border;
    string bottom_border;
    string mid_border_line;
    for (int i = 0; i < box_width - 2; ++i) {
        mid_border_line += "─";
    }
    top_border = "┌" + mid_border_line + "┐";
    
    string title_line = "│" + string(pad_left, ' ') + go_back_title + string(pad_right, ' ') + "│";
    

    bottom_border = "└" + mid_border_line + "┘";
    
    
    
    // string bottom_border = "└" + string(box_width - 2, '─') + "┘";
    
    vector<string> go_back_box;
    go_back_box.push_back(top_border);
    go_back_box.push_back(title_line);
    go_back_box.push_back(bottom_border);
    
    vector<vector<string>> go_back_boxes;
    go_back_boxes.push_back(go_back_box);
    // IOHandler::output_subtitle("");
    print_boxes_side_by_side(go_back_boxes, 4);
}




vector<string> EquipmentFactory::create_box(const string &title, const vector<string>& content, int width) {
    string box_color = "blue";
    // Create the top and bottom borders
    string top = "┌";
    string bottom = "└";
    for (int i = 0; i < width - 2; ++i) {
        top += "─";
    }
    top += "┐";
    for (int i = 0; i < width - 2; ++i) {
        bottom += "─";
    }
    bottom += "┘";

    top = AsciiHandler::colorize_box(top, box_color);
    bottom = AsciiHandler::colorize_box(bottom, box_color);
    // string bottom = "└" + string(width - 2, '─') + "┘";
    vector<string> box;
    box.push_back(top);

    // If a title is provided, center it and add a separator.
    if(!title.empty()){
        int pad = width - 2 - title.size();
        int pad_left = pad / 2;
        int pad_right = pad - pad_left;
        string title_line = AsciiHandler::colorize_box("│" + string(pad_left, ' '),box_color) + title + AsciiHandler::colorize_box(string(pad_right, ' ') + "│",box_color);
        box.push_back(title_line);
        string box_divider = "├";
        for (int i = 0; i < width - 2; ++i) {
            box_divider += "─";
        }
        box_divider += "┤";
        box.push_back(box_divider);
    }

    // For each content line, center the line within the available width.
    for(auto line : content) {
        if((int)line.size() > width - 2){
            line = line.substr(0, width - 2);
        }
        int pad = width - 2 - line.size();
        int pad_left = pad / 2;
        int pad_right = pad - pad_left;
        box.push_back(AsciiHandler::colorize_box("│", box_color) + string(pad_left, ' ') + line + string(pad_right, ' ') + AsciiHandler::colorize_box("│", box_color));
    }
    box.push_back(bottom);
    return box;
}


// Helper function that prints several boxes (each as a vector<string>) side by side.
void EquipmentFactory::print_boxes_side_by_side(const vector<vector<string>> &boxes, int spacing) {
    // First, determine the maximum number of lines among all boxes and record each box’s width.
    size_t max_lines = 0;
    vector<size_t> widths;
    for (const auto &box : boxes) {
        max_lines = max(max_lines, box.size());
        // Assume all lines in a box are the same width.
        if (!box.empty()) {
            widths.push_back(box[0].size());
        } else {
            widths.push_back(0);
        }
    }
    
    // For each line index, print that line from each box side by side.
    for (size_t i = 0; i < max_lines; i++) {
        for (size_t b = 0; b < boxes.size(); b++) {
            if (i < boxes[b].size()) {
                cout << boxes[b][i];
            } else {
                cout << string(widths[b], ' ');
            }
            // Print a spacer between boxes.
            cout << string(spacing, ' ');
        }
        cout << endl;
    }
}

// Suppose you already have a method that returns the weapon attributes as a vector of unordered maps.
vector<unordered_map<string, string>> EquipmentFactory::get_weapon_attributes() {
    vector<unordered_map<string, string>> weaponData;

    // For example, we simulate five weapons.
    weaponData.push_back({
        {"name", "Neons Edge"},
        {"max_hp", "0"},
        {"atk", "1"},
        {"def", "0"},
        {"magic", "0"},
        {"crit", "0"},
        {"evade", "0"},
        {"price", "400"}
    });
    weaponData.push_back({
        {"name", "Hyper Katana"},
        {"max_hp", "0"},
        {"atk", "2"},
        {"def", "0"},
        {"magic", "0"},
        {"crit", "0"},
        {"evade", "0"},
        {"price", "800"}
    });
    weaponData.push_back({
        {"name", "H&K 7000-a"},
        {"max_hp", "0"},
        {"atk", "4"},
        {"def", "0"},
        {"magic", "0"},
        {"crit", "0"},
        {"evade", "0"},
        {"price", "1600"}
    });
    // … add more as needed

    return weaponData;
}
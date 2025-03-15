#include "IOHandler.h"
#include <limits>
#include <cstdlib>
#include <chrono>
#include <thread>

// Define static members
const string IOHandler::reset_code = "\033[0m";
const unordered_map<string, string> IOHandler::neon_colors = {
    {"orange", "\033[38;2;255;165;0m"},
    {"pink",   "\033[38;2;255;105;180m"},
    {"yellow", "\033[38;2;255;255;0m"},
    {"green",  "\033[38;2;0;255;0m"},
    {"blue", "\033[38;2;0;191;255m"},
    {"white",  "\033[38;2;255;255;255m"}
};
unordered_map<char, string> IOHandler::neon_color_map = {
    {'|', IOHandler::neon_colors.at("pink")},
    {'-', IOHandler::neon_colors.at("pink")},
    {'=', IOHandler::neon_colors.at("orange")},
    {'*', IOHandler::neon_colors.at("blue")}
};

int IOHandler::title_max_len = 70;
int IOHandler::subtitle_max_len = 50;
int IOHandler::msg_padding_len = 5;

// OUTPUT METHODS

void IOHandler::clear_terminal() {
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}

void IOHandler::glitch_sleep(unsigned int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void IOHandler::glitch_sleep_static(unsigned int seconds) {
    std::this_thread::sleep_for(std::chrono::seconds(seconds));
}

void IOHandler::output_title(const string &title) {
    


    int max_len = (title_max_len - 4 >= (int)title.length()) ? title_max_len : (int)title.length() + 4;
    string wrapper(max_len, '=');
    string title_padded = " " + title + " ";
    int symbol_len = max_len - title_padded.length();
    string symbols(symbol_len / 2, '=');
    std::cout << "\n" << wrapper << "\n";
    std::cout << symbols + title_padded + symbols << "\n";
    std::cout << wrapper << "\n\n";
}

void IOHandler::output_subtitle(const string &subtitle) {
    int max_len = (subtitle_max_len - 4 >= (int)subtitle.length()) ? subtitle_max_len : (int)subtitle.length() + 4;
    string wrapper(max_len, '-');
    string subtitle_padded = " " + subtitle + " ";
    int symbol_len = max_len - subtitle_padded.length();
    string symbols(symbol_len / 2, '-');
    std::cout << wrapper << "\n";
    std::cout << symbols + subtitle_padded + symbols << "\n";
    std::cout << wrapper << "\n\n";
}
void IOHandler::write_dialoge(string dialog){
     for (const char c : dialog) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }
}

void IOHandler::write_story(string dialog){
     for (const char c : dialog) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(25));
    }
}

void IOHandler::output_msg(const string &msg) {
    string msg_padded = " " + msg + " ";
    string symbols(msg_padding_len, '-');
    std::cout << symbols + msg_padded + symbols << "\n";
}

void IOHandler::output_options(const string &options_title, const vector<string> &options_list) {
    IOHandler::output_subtitle(options_title);
    for (size_t i = 0; i < options_list.size(); i++) {
        std::cout << "[" << (i + 1) << "] " << options_list[i] << "\n";
    }
    std::cout << "\n";
}

void IOHandler::output_battle_info(const string &info) {
    int max_len = (title_max_len - 4 >= (int)info.length()) ? title_max_len : (int)info.length() + 4;
    string wrapper(max_len, '*');
    string info_padded = " " + info + " ";
    int symbol_len = max_len - info_padded.length();
    string symbols(symbol_len / 2, '*');
    std::cout << "\n" << wrapper << "\n";
    std::cout << symbols + info_padded + symbols << "\n";
    std::cout << wrapper << "\n\n";
}

// INPUT METHODS

int IOHandler::input_choose_index(int size) {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    int user_input;
    std::cout << "Select option: ";
    std::cin >> user_input;
    if (validate_index_input(user_input, size)) {
        std::cout << "\n";
        return user_input - 1; // convert to 0-based index
    } else {
        return input_choose_index(size);
    }
}

string IOHandler::input_choose_option(const vector<string> &options_list) {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    int user_input;
    std::cout << "Select option: ";
    std::cin >> user_input;
    if (validate_option_input(user_input, options_list)) {
        std::cout << "\n";
        return options_list[user_input - 1];
    } else {
        return input_choose_option(options_list);
    }
}

void IOHandler::input_continue() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

// COLOR METHODS

string IOHandler::apply_neon_colors(const string &text) {
    string result;
    for (char c : text) {
        if (neon_color_map.find(c) != neon_color_map.end()) {
            result += neon_color_map[c] + string(1, c) + reset_code;
        } else {
            result.push_back(c);
        }
    }
    return result;
}

void IOHandler::set_neon_color_for_char(char key, const string &ansi_code) {
    neon_color_map[key] = ansi_code;
}

// Additional static method

void IOHandler::clear_terminal_static() {
    clear_terminal();
}

// VALIDATION METHODS

bool IOHandler::validate_option_input(int user_input, const vector<string> &options_list) {
    if ((1 <= user_input && user_input <= (int)options_list.size()) && (!std::cin.fail())) {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input, enter a number between 1 and " << options_list.size() << "\n\n";
    return false;
}

bool IOHandler::validate_index_input(int user_input, int size) {
    if ((1 <= user_input && user_input <= size) && !std::cin.fail()) {
        return true;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Invalid input, enter a number between 1 and " << size << "\n\n";
    return false;
}


// #include "IOHandler.h"


// #include <iostream>
// #include <vector>


// #include <limits> // We need this to discard the int input to prevent infinite loopies!
// #include <cstdlib>
// #include <chrono> // for sleep
// #include <thread> // don't worry not for advanced threading just for a universal way to sleep


// using namespace std;

// //=========== CONSTRUCTER METHODS ===========//
// IOHandler::IOHandler(){
//     neon_color_map['|'] = neon_colors.at("pink"); 
//     neon_color_map['-'] = neon_colors.at("pink"); 
//     neon_color_map['='] = neon_colors.at("orange"); 
//     neon_color_map['*'] = neon_colors.at("blue"); 
// }


// //=========== OUTPUT METHODS ===========//

// void IOHandler::glitch_sleep(unsigned int seconds){
//     std::this_thread::sleep_for(std::chrono::seconds(seconds));
// }

// void IOHandler::glitch_sleep_static(unsigned int seconds){
//     std::this_thread::sleep_for(std::chrono::seconds(seconds));
// }

// void IOHandler::clear_terminal() {
//     #ifdef _WIN32
//         std::system("cls");
//     #else
//         std::system("clear");
//     #endif
// }


// void IOHandler::output_title(string title){
//     int max_len;
//     // Assign max_len depending on string length, if it's too long then enlarge title_max_len
//     this->title_max_len-4 >= (int)title.length() ? max_len = this->title_max_len : max_len = (int)title.length() + 4;

//     string wrapper(this->title_max_len, '=');


//     string title_padded = " " + title + " ";
//     int symbol_len = this->title_max_len - title_padded.length();
//     string symbols(symbol_len/2, '=');

//     cout << endl << wrapper << endl;
//     cout << symbols + title_padded + symbols << endl;
//     cout << wrapper << endl << endl;
// }


// void IOHandler::output_subtitle(string subtitle){
//     int max_len;
//     // Assign max_len depending on string length, if it's too long then enlarge title_max_len
//     this->subtitle_max_len-4 >= (int)subtitle.length() ? max_len = this->subtitle_max_len : max_len = (int)subtitle.length() + 4;

//     string wrapper(max_len, '-');

//     string subtitle_padded = " " + subtitle + " ";
//     int symbol_len = max_len - subtitle_padded.length();
//     string symbols(symbol_len/2, '-');

//     cout << wrapper << endl;
//     cout << symbols + subtitle_padded + symbols << endl;
//     cout << wrapper << endl << endl;
// }



// void IOHandler::output_msg(string msg){
//     string msg_padded = " " + msg + " ";
//     string symbols(this->msg_padding_len, '-');

//     cout << symbols + msg_padded + symbols << endl;
// }


// void IOHandler::output_options(string options_title, vector<string> options_list){
//     this->output_subtitle(options_title);
//     for (int i=0; i < (int)options_list.size(); i++){
//         cout << "[" << (i+1) <<"] " << options_list[i] << endl; 
//     }
//     cout << endl;
// }


// void IOHandler::output_battle_info(string info){
//     int max_len;
//     // Assign max_len depending on string length, if it's too long then enlarge title_max_len
//     this->title_max_len-4 >= (int)info.length() ? max_len = this->title_max_len : max_len = (int)info.length() + 4;


//     string wrapper(max_len, '*');

//     string info_padded = " " + info + " ";
//     int symbol_len = max_len - info_padded.length();
//     string symbols(symbol_len/2, '*');

//     cout << endl << wrapper << endl;
//     cout << symbols + info_padded + symbols << endl;
//     cout << wrapper << endl << endl;
// }



// //=========== INPUT METHODS ===========//

// string IOHandler::input_choose_option(vector<string> options_list){
    
//     // In case there is a need for flush before asking for input
//     if (cin.fail()) {  
//         cin.clear();  
//         cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
//     }
    
//     int user_input;
//     cout << "Select option: "; 
//     cin >> user_input;
//     bool input_valid = this->validate_option_input(user_input, options_list);
    
    
//     if(input_valid){
//         cout << endl; 
//         return options_list[user_input-1];
//     } else{
//         return input_choose_option(options_list);  // Recursively call again
//     }
// }

// int IOHandler::input_choose_index(int size) {
//     if (cin.fail()) {  
//         cin.clear();  
//         cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
//     }
    
//     int user_input;
//     cout << "Select option: "; 
//     cin >> user_input;
    
//     if (this->validate_index_input(user_input, size)) {
//         cout << endl; 
//         return user_input - 1; // Convert to 0-based index
//     } else {
//         return input_choose_index(size);  // Recursively call again
//     }
// }

// //=========== COLOR METHODS ===========//
// std::string IOHandler::apply_neon_colors(const std::string &text) {
//     std::string result;
//     // Process each character.
//     // std::cout << "neon_color_map size: " << neon_color_map.size() << std::endl;
//     for (char c : text) {
//         // If the character is one we want to colorize...
//         if (neon_color_map.find(c) != neon_color_map.end()) {
//             result += neon_color_map[c] + std::string(1, c) + reset_code;
//         } else {
//             result.push_back(c);
//         }
//     }
//     return result;
// }

// void IOHandler::set_neon_color_for_char(char key, const std::string &ansi_code) {
//     neon_color_map[key] = ansi_code;
// }


// //=========== VALIDATION METHODS ===========//

// bool IOHandler::validate_option_input(int user_input, vector<string> options_list){
//     // If the input is out of range || is not an integer
//     if((1 <= user_input && user_input <= (int)options_list.size()) && (!cin.fail())){
//         return true;
//     }

//     // Clear terminal for next input
//     cin.clear();  
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');  
//     cout << "Invalid input, enter a number between 1-" << (int)options_list.size()+1 << endl << endl;

//     return false;
// }


// bool IOHandler::validate_index_input(int user_input, int size) {
//     if (1 <= user_input && user_input <= size && !cin.fail()) {
//         return true;
//     }

//     cin.clear();  
//     cin.ignore(numeric_limits<streamsize>::max(), '\n');  
//     cout << "Invalid input, enter a number between 1-" << size << endl << endl;

//     return false;
// }

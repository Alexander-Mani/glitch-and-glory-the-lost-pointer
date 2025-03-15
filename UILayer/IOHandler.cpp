#include "IOHandler.h"
#include "AsciiHandler.h"
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
    system("cls");
#else
    system("clear");
#endif
}

void IOHandler::glitch_sleep(unsigned int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

void IOHandler::glitch_sleep_static(unsigned int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

void IOHandler::output_title(const string &title, string color) {
    IOHandler::clear_terminal();
    vector<string> content;

    content.push_back(" ");
    content.push_back(title);
    content.push_back(" ");


    AsciiHandler::display_box_layout("", content, color);
}

void IOHandler::output_subtitle(const string &subtitle, string color) {
    vector<string> content;
    content.push_back(subtitle);

    AsciiHandler::display_box_layout("", content, color, "white", 50);

}
void IOHandler::write_dialoge(string dialog){
     for (const char c : dialog) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void IOHandler::write_story(string dialog){
     for (const char c : dialog) {
        std::cout << c << std::flush;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void IOHandler::output_msg(const string &msg) {
    string msg_padded = " " + msg + " ";
    string symbols(msg_padding_len, '-');
    cout << symbols + msg_padded + symbols << "\n";
}

void IOHandler::output_options(const string &options_title, const vector<string> &options_list) {
    IOHandler::output_subtitle(options_title);
    for (size_t i = 0; i < options_list.size(); i++) {
        cout << "[" << (i + 1) << "] " << options_list[i] << "\n";
    }
    cout << "\n";
}

void IOHandler::output_battle_info(const string &info) {
    int max_len = (title_max_len - 4 >= (int)info.length()) ? title_max_len : (int)info.length() + 4;
    string wrapper(max_len, '*');
    string info_padded = " " + info + " ";
    int symbol_len = max_len - info_padded.length();
    string symbols(symbol_len / 2, '*');
    cout << "\n" << wrapper << "\n";
    cout << symbols + info_padded + symbols << "\n";
    cout << wrapper << "\n\n";
}

// INPUT METHODS

int IOHandler::input_choose_index(int size) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int user_input;
    cout << "Select option: ";
    cin >> user_input;
    if (validate_index_input(user_input, size)) {
        cout << "\n";
        return user_input - 1; // convert to 0-based index
    } else {
        return input_choose_index(size);
    }
}

string IOHandler::input_choose_option(const vector<string> &options_list) {
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int user_input;
    cout << "Select option: ";
    cin >> user_input;
    if (validate_option_input(user_input, options_list)) {
        cout << "\n";
        return options_list[user_input - 1];
    } else {
        return input_choose_option(options_list);
    }
}

void IOHandler::input_continue() {
    cout << "Press Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
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
    if ((1 <= user_input && user_input <= (int)options_list.size()) && (!cin.fail())) {
        return true;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input, enter a number between 1 and " << options_list.size() << "\n\n";
    return false;
}

bool IOHandler::validate_index_input(int user_input, int size) {
    if ((1 <= user_input && user_input <= size) && !cin.fail()) {
        return true;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Invalid input, enter a number between 1 and " << size << "\n\n";
    return false;
}



vector<string> IOHandler::wrap_text(const string &text, size_t max_width) {
    vector<string> lines;
    vector<string> words;
    
    // Manually split text into words.
    size_t i = 0;
    while (i < text.length()) {
        // Skip any whitespace characters.
        while (i < text.length() && isspace(text[i])) {
            ++i;
        }
        if (i >= text.length())
            break;
        // Mark the start of the word.
        size_t start = i;
        // Move to the end of the word.
        while (i < text.length() && !isspace(text[i])) {
            ++i;
        }
        words.push_back(text.substr(start, i - start));
    }
    
    // Build lines by adding words until the max_width is exceeded.
    string line;
    for (const string &word : words) {
        // If the current line is empty.
        if (line.empty()) {
            // If the word itself is longer than max_width, split the word.
            if (word.size() > max_width) {
                size_t pos = 0;
                while (pos < word.size()) {
                    lines.push_back(word.substr(pos, max_width));
                    pos += max_width;
                }
            } else {
                line = word;
            }
        } else {
            // Check if adding the word (with a space) would exceed max_width.
            if (line.size() + 1 + word.size() > max_width) {
                lines.push_back(line);
                // If the new word is too long for a single line, break it up.
                if (word.size() > max_width) {
                    size_t pos = 0;
                    while (pos < word.size()) {
                        lines.push_back(word.substr(pos, max_width));
                        pos += max_width;
                    }
                    line = "";
                } else {
                    line = word;
                }
            } else {
                line += " " + word;
            }
        }
    }
    
    // Add any remaining text as the last line.
    if (!line.empty()) {
        lines.push_back(line);
    }
    
    return lines;
}


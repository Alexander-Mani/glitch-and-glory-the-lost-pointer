// BattleLogic.h
#ifndef IOHANDLER_H
#define IOHANDLER_H


#include <iostream>
#include <vector>
#include <unordered_map>

#include "../Models/BattleModel.h"
#include "../Models/AllEntities.h"

using namespace std;

class IOHandler{
public:
    // Mapping of characters to their ANSI escape color codes.
    std::unordered_map<char, std::string> neon_color_map;
    // ANSI reset code.
    const std::string reset_code = "\033[0m";

    // Constant mapping of all available neon colors.
    const unordered_map<std::string, std::string> neon_colors = {
        {"orange", "\033[38;2;255;165;0m"},
        {"pink",   "\033[38;2;255;105;180m"},
        {"yellow", "\033[38;2;255;255;0m"},
        {"green",  "\033[38;2;0;255;0m"},
        {"blue",   "\033[38;2;0;0;255m"},
        {"white",  "\033[38;2;255;255;255m"}
   };

   

    int title_max_len = 70;     // Assigned here since it's a constant value
    int subtitle_max_len = 50;  // Assigned here since it's a constant value
    int msg_padding_len = 5;    // Assigned here since it's a constant value

    

    // IOHandler(AsciiHandler *asciiHandler); // Declaring constructer to be used within the .cpp file
    IOHandler();

    //==== OUTPUT METHODS ====//
    
    void clear_terminal();
    void glitch_sleep(unsigned int seconds);

    
    static void glitch_sleep_static(unsigned int seconds);

    /*
    * @param title: Takes in a string title  
    * @brief Prints subtitle with padded "="
    * @detail Padding can be modified by modifying the `title_max_len` value
    */
    void output_title(string title);
    void write_dialoge(string dialog);
    void write_story(string dialog);
    
    /*
    * @param subtitle: Takes in a string subtitle  
    * @brief Prints subtitle with padded "-"
    * @detail Padding can be modified by modifying the `subtitle_max_len` value
    */
    void output_subtitle(string subtitle);
    
    /*
    * @brief Prints out messages for the user
    * @param msg: Takes in a string with the message
    * @detail Padding can be modified by modifying the `msg_padding_len` value
    */
    void output_msg(string msg);
    
    /*
    * @param options_title: Takes in a string containing the title for the options
    * @param options_list: Takes in a vector<string> list of options  
    * @brief Prints title and then options in numeric order
    * @details Also includes an option to go back / quit
    */
    void output_options(string options_title, vector<string> options_list);
    
    void output_battle_info(string info);

    /*
    * @brief Displays battle info in HUD Ascii
    * @param BattleModel instance 
    */
    // void display_attack_hud(BattleModel *battleModel);
    

    
    //==== INPUT METHODS ====//
    /*
    * @param options_list: Takes in a vector<string> list of options  
    * @brief Asks user for a numeric input to select an option
    * @returns string: Selected choice 
    */
    int input_choose_index(int size);
    
   string input_choose_option(vector<string> options_list);


    /*
     * @brief Displays a prompt and waits for the user to press Enter.
     * @param prompt: The message displayed to the user (e.g., "continue...")
     */
    void input_continue();
    

    
    //==== COLOR METHODS ====//

    // Applies neon color mapping to the input text.
    string apply_neon_colors(const string &text);

    // Optionally, a setter to change the mapping at runtime.
    void set_neon_color_for_char(char key, const string &ansi_code);
   
   
    //==== STATIC METHODS ====//
    static void clear_terminal_static();



private:
    //==== VALIDATION METHODS ====//

    /*
     * @brief Validates the user's input choice.
     * 
     * @details This function checks if the user input is a valid option within the given list.
     * 
     * @param user_input The numeric choice entered by the user.
     * @param options_list The list of available options to validate against.
     * @returns Returns `true` if the input is valid, otherwise `false`.
     */
    bool validate_option_input(int user_input, vector<string> options_list);
    bool validate_index_input(int user_input, int size);
};


#endif // IOHANDLER_H

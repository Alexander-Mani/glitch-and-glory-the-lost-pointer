// BattleLogic.h
#ifndef IOHANDLER_H
#define IOHANDLER_H


#include <iostream>
#include <vector>


using namespace std;

class IOHandler{
public:
    int title_max_len = 70; // Assigned here since it's a constant value
    int subtitle_max_len = 50; // Assigned here since it's a constant value
    int msg_padding_len = 5; // Assigned here since it's a constant value

    // IOHandler(); // Declaring constructer to be used within the .cpp file

    //==== OUTPUT METHODS ====//
    
    /*
    * @param title: Takes in a string title  
    * @brief Prints subtitle with padded "="
    */
    void output_title(string title);
    
    /*
    * @param subtitle: Takes in a string subtitle  
    * @brief Prints subtitle with padded "-"
    */
    void output_subtitle(string subtitle);
    
    /*
    * @brief Prints out messages for the user
    * @param msg: Takes in a string with the message
    */
    void output_msg(string msg);
    
    /*
    * @param options_list: Takes in a vector<string> list of options  
    * @brief Prints options in numeric order
    * @details Also includes an option to go back
    */
    void output_options(string options_title, vector<string> options_list);
    
    
    //==== INPUT METHODS ====//
    /*
    * @param options_list: Takes in a vector<string> list of options  
    * @brief Asks user for a numeric input to select an option
    * @returns string: Selected choice 
    */
    string input_choose_option(vector<string> options_list);


private:
    //==== VALIDATION METHODS ====//

    /*
     * @brief Validates the user's input choice.
     * 
     * @details This function checks if the user input is a valid option within the given list.
     * 
     * @param int user_input The numeric choice entered by the user.
     * @param vector<string> options_list The list of available options to validate against.
     * @returns bool Returns `true` if the input is valid, otherwise `false`.
     */
    bool validate_option_input(int user_input, vector<string> options_list);
};


#endif // IOHANDLER_H
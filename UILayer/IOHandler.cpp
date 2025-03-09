#include "IOHandler.h"

#include <iostream>
#include <vector>


#include <limits> // We need this to discard the int input to prevent infinite loopies!


using namespace std;


//=========== OUTPUT METHODS ===========//

void IOHandler::output_title(string title){
    string wrapper(this->title_max_len, '=');


    string title_padded = " " + title + " ";
    int symbol_len = this->title_max_len - title_padded.length();
    string symbols(symbol_len/2, '=');

    cout << endl << wrapper << endl;
    cout << symbols + title_padded + symbols << endl;
    cout << wrapper << endl << endl;
}


void IOHandler::output_subtitle(string subtitle){
    string wrapper(this->subtitle_max_len, '-');

    string subtitle_padded = " " + subtitle + " ";
    int symbol_len = this->subtitle_max_len - subtitle_padded.length();
    string symbols(symbol_len/2, '-');

    cout << endl << wrapper << endl;
    cout << symbols + subtitle_padded + symbols << endl;
    cout << wrapper << endl << endl;
}



void IOHandler::output_msg(string msg){
    string msg_padded = " " + msg + " ";
    string symbols(this->msg_padding_len, '-');

    cout << symbols + msg_padded + symbols << endl;
}


void IOHandler::output_options(string options_title, vector<string> options_list){
    this->output_subtitle(options_title);
    for (int i=0; i < (int)options_list.size()+1; i++){
        // Print the enumeration
        
        // If the enumeration is within the list size
        if (i < (int)options_list.size())
            cout << "[" << (i+1) <<"] " << options_list[i] << endl; 
        // Otherwise we are outside the list, therefore printing the "Go back" option
        else if (options_list[i-1] != "Quit")
            cout << "[" << (i+1) <<"] " << "Go back" << endl;
        else
            cout << endl;
            
    }
}


//=========== INPUT METHODS ===========//

string IOHandler::input_choose_option(vector<string> options_list){
    int user_input;
    cout << "Select option: "; 
    cin >> user_input;
    bool input_valid = this->validate_option_input(user_input, options_list);


    if(input_valid){
        cout << endl << "You selected: " << user_input << endl; 
        return options_list[user_input-1];
    } else{
        return input_choose_option(options_list);  // Recursively call again
    }
}



//=========== VALIDATION METHODS ===========//

bool IOHandler::validate_option_input(int user_input, vector<string> options_list){
    // If the input is out of range || is not an integer
    if((1 <= user_input && user_input <= (int)options_list.size()) && (!cin.fail())){
        return true;
    }

    // Clear terminal for next input
    cin.clear();  
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  
    cout << "Invalid input, enter a number between 1-" << (int)options_list.size()+1 << endl << endl;

    return false;
}

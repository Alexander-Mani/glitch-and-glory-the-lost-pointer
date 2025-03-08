#include <iostream>

#include "IOHandler.h"

using namespace std;


void IOHandler::output_title(string msg){
    string msg_padded = " " + msg + " ";
    int symbol_len = this->title_max_len - msg_padded.length();
    string symbols(symbol_len/2, '=');
    cout << endl << symbols + msg_padded + symbols << endl << endl;
}

void IOHandler::output_subtitle(string msg){
    string msg_padded = " " + msg + " ";
    int symbol_len = this->subtitle_max_len - msg_padded.length();
    string symbols(symbol_len/2, '-');
    cout << endl << symbols + msg_padded + symbols << endl << endl;
}


void IOHandler::output_msg(string msg){
    string print_msg(10, '-');
    cout << print_msg + msg;
}

// BattleLogic.h
#ifndef IOHANDLER_H
#define IOHANDLER_H


#include <iostream>

using namespace std;

class IOHandler{
public:
    int title_max_len = 70; // Assigned here since it's a constant value
    int subtitle_max_len = 70; // Assigned here since it's a constant value

    // IOHandler(); // Declaring constructer to be used within the .cpp file

    void output_title(string msg);
    
    void output_subtitle(string msg);

    void output_msg(string msg);
};


#endif // IOHANDLER_H
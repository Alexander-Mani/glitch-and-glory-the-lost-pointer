// BattleLogic.h
#ifndef UIHANDLER_H
#define UIHANDLER_H



#include <unordered_map>    // To create dictionary like objects
#include <functional>       // To store functions within unordered maps

#include "../LogicLayer/LogicWrapper.h"
#include "IOHandler.h"
#include "BattleHandler.h"


class UIHandler{
public:
    LogicWrapper logicWrapper;
    IOHandler ioHandler;
    BattleHandler battleHandler;
    
    // We will have the menu options in a vector<string> simply to control the order within the manu_actions
    vector<string> menu_options;
    // menu_actions will act similarly to a dictionary. For keys it will store menu option, for value it will store the function for that menu option.
    unordered_map<string, function<void()>> menu_actions;


    UIHandler(); // Declaring constructer to be used within the .cpp file


    /*
     * @brief Starts the game and displays the main menu.
     * 
     * @details This function prints the game title and presents the user with a set of options.
     * The user selects an option, which is then printed.
     */
    void initialize_game();


private:
    /*
     * @brief Starts the game and displays the main menu.
     * 
     * @details This function prints the game title and presents the user with a set of options.
     * The user selects an option, which is then printed.
     */
    void play_game();

    /*
     * @brief Starts the game logic.
     * 
     * @details This function is executed when the player selects "Play Game".
     * In the final implementation, this will trigger game-related logic.
     */
    void activate_battle();


    /*
     * @brief Exits the game.
     * 
     * @details This function is triggered when the player selects "Quit".
     * It prints a message and terminates the program.
     */
    void quit();
};

#endif // UIHANDLER_H
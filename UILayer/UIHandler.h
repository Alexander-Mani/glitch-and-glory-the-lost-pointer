// BattleLogic.h
#ifndef UIHANDLER_H
#define UIHANDLER_H



#include <unordered_map>    // To create dictionary like objects
#include <functional>       // To store functions within unordered maps

#include "../LogicLayer/LogicWrapper.h"
#include "IOHandler.h"
#include "AsciiHandler.h"
#include "BattleHandler.h"


class UIHandler{
public:
    LogicWrapper *logicWrapper;
    AsciiHandler *asciiHandler; //AsciiHandler must come before BattleHandler
    IOHandler *ioHandler;
    BattleHandler *battleHandler;

    // We will have the menu options in a vector<string> simply to control the order within the manu_actions
    vector<string> menu_options;
    // menu_actions will act similarly to a dictionary. For keys it will store menu option, for value it will store the function for that menu option.
    unordered_map<string, function<void()>> menu_actions;


    UIHandler();

    ~UIHandler();

    /*
     * @brief Initializes the game and displays the main menu.
     * 
     * @details This function prints the game title and presents the user with a set of options.
     * The user selects an option, which is then printed.
     */
    void initialize_game();


private:
    /*
     * @brief Starts the game and displays the main menu.
     */
    void play_game();

    /*
     * @brief Triggers GameHandler to start a battle.
     */
    void activate_battle();

    /*
     * @brief Triggers HUD function to test.
     */
    void test_hud();


    /*
     * @brief Exits the game.
     */
    void quit();
};

#endif // UIHANDLER_H

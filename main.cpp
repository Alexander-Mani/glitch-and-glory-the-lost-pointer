#include <iostream>
#include "debug.h"

/*--- HEADER FILES ---*/
#include "UILayer/UIHandler.h"
#include "UILayer/IOHandler.h"

using namespace std;


int main(){
    disable_stdout(); // Disable prints when using gdb
    
    UIHandler uiHandler = UIHandler();

    uiHandler.initialize_game();

    // IOHandler ioHandler = IOHandler();




    // BattleLogic battleLogic = uiHandler.logicWrapper.battleLogic;

    // (void) battleLogic;

    // cout << battleLogic.example_method("testing stuff\n");
    // ioHandler.output_title("testing stuff");
    // ioHandler.output_subtitle("testing stuff");

    // cout << uiHandler.logicWrapper.battleLogic;
    // string test = uiHandler.logicWrapper.battleLogic.example_method("hi there!");
    // cout << uiHandler.logicWrapper->battleLogic;

    cout << "\n\n\n============= GAME OVER MSG HERE PLZZZ !;)! =============\n";

    return 0;
}
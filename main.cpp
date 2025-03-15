#include <iostream>
#include "debug.h"

/*--- HEADER FILES ---*/
#include "UILayer/UIHandler.h"
#include "UILayer/IOHandler.h"

using namespace std;


int main(){
    // disable_stdout(); // Disable prints when using gdb
    
    UIHandler uiHandler = UIHandler();

    uiHandler.initialize_game();

    return 0;
}
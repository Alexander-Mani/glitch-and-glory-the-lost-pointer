// main.cpp
#include <iostream>
#include "UILayer/UIHandler.h"

using namespace std;

int main() {
    UIHandler uiHandler;
    
    // Recursively (or repeatedly) open the main menu.
    while (true) {
        uiHandler.initialize_game();
    }
    
    return 0;
}

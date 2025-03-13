#ifndef CYBER_GLADIATOR_MODEL_H
#define CYBER_GLADIATOR_MODEL_H

#include "EntityModel.h"
//#include "../WeaponModel.h"

class CyberGladiatorModel : public EntityModel {
public:
    CyberGladiatorModel()
        : EntityModel(
            "Cyber Gladiator",  // Name 
            150,                        // max_hp
            150,                 // hp         
            50,                 // atk         
            10,                 // def         
            5,                  // magic     
            10,                 // crit         
            50,                 // evade     
            {
                "                                                                          ", 
                "                                                                          ", 
                "                                                                          ", 
                "                                                                          ", 
                "                                                                          ", 
                "                                  ..........                              ", 
                "                                ..-%%%%%%%##+=-:..                        ", 
                "                                .-@@@@@@@@@@@@@@=.                        ", 
                "                               .*@@@@@@@@@@@@@%-.                         ", 
                "                            ..-@@@@@@@@@@@@@#-=*%@%*+*%#=-::......        ", 
                "                          ...*@@@@@@@@@@@@@@@@#@%#:-*%@@@@@@@@@@@-        ", 
                "                          .-@@@@@@@@@@@@@@@@@@@@@@%=...-%@@@@@@@@#.       ", 
                "                          .:+*##*+*%*@@@@@@@@@@@@@@@%:   ...:*@@@@=.      ", 
                "                                ..-%@@@@@@@@@@@@@@@@@-       ...+%@-.     ", 
                "                                ..@@@@@@@@@@@@@@@@@@@%..         ..==.    ", 
                "                                .*@@@@@@@@@@@@@@@@@@@@@..                 ", 
                "                                .@@@@@@@@@@@@@@@@@@+%@@@-                 ", 
                "                               .-@@@@@@@@@@@@@@@@@@::@@:.                 ", 
                "                               .*@@@@@@@@@@@@@@@@@@..*-.                  ", 
                "                               -@@@@@@@@@@@@@@@@@@@...-.                  ", 
                "                               .*@@@@@@@@@@@@@@@@@@%.                     ", 
                "                             ..+@@@@@@@@@@@@@@@@@@@=.                     ", 
                "                             ..%@@@@@@@@@@@@@@@@@@=.                      ", 
                "                               -@@@@@@@@@@@@@@@@%.                        ", 
                "                              .@@@@@@@@@@@@@@@@#.                         ", 
                "                             .+@@@@@@@@@@@@@@@@@*.                        ", 
                "                             .=@@@@@@@@@@@@@@@@@@:                        ", 
                "                          ...-@@@@@@@@@@@@@@@@@@@+..                      ", 
                "                          ..=@@@@@@@@@@@@@@@@@@@@@%:.                     ", 
                "                         ..*@@@@@@@@@@@@@@@@@@@@@=@@%-..                  ", 
                "                       ..:@@@@@@@@@@@@@@@@@@@@@@@..+@@@:.                 ", 
                "                      ..#@@+@@@@@@@@@@@@@@@@@@@@@.  .-@@@+..              ", 
                "                    ..:@@#.#@@@@@@@@@@@@@@@@@@@@@.     .#@@%..            ", 
                "                   ..*@@:.+@@@@@@@@@@@@@@@@@@@@@@%..   ...+@@#-..         ", 
                "                  .-@@=..-@@@@@@@@@@@@@@@@@@@@@@@@+.        .#@@*...      ", 
                "                ..#@*...=@@@@@@@@@@@@@@@@@@@@@@@@@%:.        ..=@@%-.     ", 
                "             ...+@%:...-@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%+.        .:#@@#... ", 
                "            ..=@@=....+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@+           ...=%@@*:",
                "          ...#@*.  .+@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%:                .-%%", 
                "         ..*@#.    .:*@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#+                     ", 
                "      ...-@@:.      .-+*@@@@@@@@@@@@@@@@@@@@@@@@@@=.                      ", 
                "     ..:%@=.             .++:..:#@@@@@@=@@@%*@@@@@-.                      ", 
                "   ..:%%-.                .    .*@@@@@.:*=. .#@@@@..                      ", 
                "  .-%%-.                     ..-@@@@*....   .*@@@@..                      ", 
                ".:%@:..                  ...-#@@@@@@%..    .=@@@@@=.                      ", 
                "-+-..                    .+@@@@%+==*@=.   ..%@@@@@+.                      ", 
                "                             ..    ....    ..-=+=:..                      ", 
                "                                               .                          " 
            }
            //new WeaponModel(
            //    "Titan Protocol",               // Weapon Name
            //    50,                             // Weapon Damage
            //    100,                            // Hit Rate
            //    "You have hit the enemy!",      // Hit message
            //    "You missed the enemy homie!"   // Miss message
            //)
        )
    { }
};

#endif // CYBER_GLADIATOR_MODEL_H


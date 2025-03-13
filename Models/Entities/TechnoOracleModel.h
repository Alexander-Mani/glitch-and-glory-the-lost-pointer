#ifndef TECHNO_ORACLE_MODEL_H
#define TECHNO_ORACLE_MODEL_H

#include "EntityModel.h"
//#include "../WeaponModel.h"

class TechnoOracleModel : public EntityModel {
public:
    TechnoOracleModel()
        : EntityModel(
            "Techno Oracle",    // Name
            100,                // max_hp
            100,                // hp
            20,                 // atk
            15,                 // def
            70,                 // magic
            15,                 // crit
            10,                 // evade
            {
                "                                 ", 
                "                                 ", 
                "                                 ", 
                "                                 ", 
                "                                 ", 
                "            :.:-+++*=            ", 
                "           :=#%%**#%#*           ", 
                "          :*@@@%@#@@*#           ", 
                "          -#@@#%%@%%#            ", 
                "           #%#%@%#%%             ", 
                "           ##%%%@@@%#=   *       ", 
                "            ###%%%#*+=#=====+%   ", 
                "           ==-=*+:::+@=@@@@@@%   ", 
                "       :+-:--==+*###%@@@@+@@@%*  ", 
                "      =#+:=.:###%@%@@@@@%@*@@%#  ", 
                "      ##+%-:*@@@@@@@@@@@@@%%@@%  ", 
                "       =#@+#@@@@@#@@@@@##@@##%%# ", 
                "       #@#+%@@%@@@@%%### %@@@%%* ", 
                "      =@%*%%@@@%@@%%*#%   %@%@%= ", 
                "      *@##%#@%@@@@#%%      %*-#%%",
                "     +*@@%%*#@@@@@@%      #+#+%%*",
                "    =-#@%*##@@@@%%%#@%    ++##@@@",
                "   ==*%#*+*+*%@@@#@@%%    +##@@@ ", 
                "   -###*@#**@@@@@@@@%##   *==%@  ", 
                "  =*%**=@@#%%@@@@#@+*#-* +=@@@@  ", 
                " =+%%#-+@@@##%@@#=#@@%%%#*#@@%@  ", 
                " *%%#*+##@@@@%%%+@@@@%@#%%@@@%   ", 
                "*#%% %#@@@@@@%#%%@@@@@%%%###%    ", 
                "*#%% *%@@@@@@@% %%@@@@@@%#%#+    ", 
                "%#++ *%%@@@@@@% %%@@@@@@%%%      ", 
                "  %# %%%%%%@@%# %#%%%@@@@        ", 
                "      ##%%%#%#   %%%%%@@%        ", 
                "      %%%%#*#*    %@%@@%#        ", 
                "      %%@@%##@    #%%@@@%@       ", 
                "      %%%%%@%%    ##%%@@@%       ", 
                "      *#%%%%@@@    #%%%@@%%      ", 
                "       #%@%%%%%     %%@@@@@%     ", 
                "        %%%%%%%%    #%@@@@@@     ", 
                "        %%%%####    %#%%%%%%     ", 
                "        #%%%##*     ##%%%%%#     ", 
                "        #%%###        #%%%%#     ", 
                "        *%%%@%        #%@@%#     ", 
                "       *+@@@@%        +**%%#     ", 
                "      ##@%%%%*        *@%%@@     ", 
                "     ***%@@%%#*      +@%@@%%     ", 
                "  ##+%%@%%%@@%#       ###%@#     ", 
                " %#%@@@@@@@@         #%%#%%%     ", 
                "                    %*%%%@%      " 
            }
            //new WeaponModel(
            //    "Singularity Codex",            // Weapon Name
            //    100,                             // Weapon Damage
            //    90,                             // Hit Rate
            //    "You have hit the enemy!",      // Hit message
            //    "You missed the enemy homie!"   // Miss message
            //)
        )
    { }
};

#endif // TECHNO_ORACLE_MODEL_H

// #ifndef TECHNO_ORACLE_MODEL_H
// #define TECHNO_ORACLE_MODEL_H

// #include "EntityModel.h"
// #include "../WeaponModel.h"

// class TechnoOracleModel : public EntityModel {
// public:
//     TechnoOracleModel();
// };

// #endif // TECHNO_ORACLE_MODEL_H

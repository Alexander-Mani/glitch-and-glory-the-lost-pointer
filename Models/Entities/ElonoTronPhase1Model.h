#ifndef ELONO_TRON_PHASE_1_MODEL_H
#define ELONO_TRON_PHASE_1_MODEL_H

#include "EntityModel.h"
//#include "../WeaponModel.h"

class ElonoTronPhase1Model : public EntityModel {
public:
    ElonoTronPhase1Model()
        : EntityModel(
            "Elono Tron Mk I",    // Name
            100,                // max_hp
            300,                // hp
            100,                // atk
            15,                 // def
            70,                 // magic
            15,                 // crit
            10,                 // evade
            70,                 // acc (Accuracy)
            {
"       %@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@%%%%@@@@@@@@@@@@     ", 
"      @@@@@@@@@@@@@%%%%%@@@@@@@@@@@@@@@@@@@@@@@%%%@@@@@@@@@@@%     ", 
"     %%@@@@@@@%****++++***###*##%@%@@@@@@@@@@@@@@@@@@@@@@@@@@%%    ", 
"  %%%@@@@@@@#++====---=--=========+++++**#%@@@@@@@@@@@@@@@@@%%%%   ", 
"@@@@@%%%*+====------- .-=*###########*=-.=+**%%@@@@@@@@@@@@@@%%    ", 
" %@@%%##*++====----###*+++++=.   .=+++++*###-++*#%@@@@@@@@@@@%%%   ", 
"  @@@@%*++====-----:*#########= =#########*:===++*#%@@@@@@%%%@@%#  ", 
"%@@@%*++====--------.+#-   .#######.   -#+.=====++++#@@@%@@@%@@@@# ", 
"@@@%*++======---------------+#####+---===========++++##%@@@@@%%@@@@", 
"@@%*+=========---------------#####:----==========++++*#%%%@@@@@@@@@", 
"@@#+=========--------------:.#####.-----=======++++++*#%%@@@@@@@@@ ", 
"@@%++========--------------::=###+-----=-========+++*##%%@@@@@@@@@ ", 
"@@*++=====----------------:--:###:------=========+++*##%@@@@@@@@@% ", 
"@#++=====----------:-:------:-###-------=---=====++**#%%@@@@@@@@@% ", 
"@+++====------------::---:::--=#=----===--=======++*##%%@@@@@@@@@  ", 
"@++****#**+==-----------------:#:---------=======+**#%%%%@@@@@@@   ", 
"@+**#***#%%%#*==---------------=---------========++*#%@@@@@@@@@@   ", 
"@+***+======+**+====----=========+++===---=======+++++#%@@@@@@@@@  ", 
"@+****#%%%#**=+**++=--====++*##%%%#**++++=====+==++++++*%@@@@@@@   ", 
"@+++#%#**%@@%##***=----=+**+==---====++**+*++++++++++++*%%@@@@@@   ", 
"@==+++========*+*+-----=+*+*******+====++***+++++=++++*#%%%@@@@    ", 
"@=-==+**++++++===----==++*****+=#@@@%#*++++++++++=++++*#%%%%@@     ", 
"@=====-=+++====+=---============+*#*+###+++++====+++++*%%%%%%#+=+  ", 
"@==-----------==---======-=+++==--======++=====+++++**#%%%%#**+**  ", 
"@=----------===---==+====----====+++==---=====++++****#%%%#*#%%%#  ", 
"@-----------===---==++===----------======--===+++*****#%###*+***   ", 
"@--------==++=---==+++===--------------=======++******##%%#*+***   ", 
"@=----======+=---==++==+=-------------========++*****#***#+=++*    ", 
"@====+++=+*##+==++++====+==------------======++********+++==**     ", 
"@*****++++*#%##***%@@%*++====----------=====+++*******+++=-=*      ", 
"@%%%#**+++++*#%%%#**++**+--====-----=-=====++++**++*+*++==+*       ", 
"@##*+++++++++*##**+====--===+===========++++++***+++++==+**        ", 
"@=**#*++====---===--==--=====+++====+++++***+***++++++====*        ", 
"@-=+*#@%%##*+=--------=======++**+++*******++**+++***=-=-=         ", 
"@=-=++*%@%########**=====+++++++*********++++++++****+++*          ", 
"@===+++**#@#+=====+*#%%%#*****++++++++++++++++++*****%             ", 
"@+=====+*++*%%@@@%@@@@@@@@@@%#+=====++++++++++***#**##             ", 
"@*+====+++=====+*+*+++*++++=====-===++=++++****###****             ", 
"@*+====+**++====----=+*++======-===++++++***######***              ", 
"@**+====++******+++++++++========++*+++***##########               ", 
"@**+=======+++*+*+**+++========+****++**###########                ", 
" ##*+=============++==========+***+++*#####%%%%##                  ", 
"  ##*+=====------============+++++++**#*#%%%%%#                    ", 
"   %#*++======---------=====+++++++**##%%%##%                      ", 
"    %%**++=======---======+***+++**###%####                        ", 
"      %%##*+++++==+===++********####%#%                            ", 
"        @@@%%##*****###%%###***##                                  ", 
"           @@@@@@@@@@@%%%##                                        ", 

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

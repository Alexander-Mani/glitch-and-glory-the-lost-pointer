#include "BioEnhancedBerserkerModel.h"
#include <iostream>

BioEnhancedBerserkerModel::BioEnhancedBerserkerModel()
    : EntityModel(
        "Bio-Enhanced Berserker",   // Name
        150,                        // hp
        30,                         // atk
        7,                         // def
        5,                          // magic
        5,                          // crit
        5,                          // evade
        {                           // ascii_art
        "           +=*++#*                                      ", 
        "        +######%%%###*+==-                              ", 
        "      +***#%%%%%%%###*+======-=====                     ", 
        "     ***##%%%%%%##**+---=--=========+++                 ", 
        "    =*###%%%%%#*#***+**+==-------===+*++*+              ", 
        "    *#**+=+*+++*#***++*#***+====---==+*+++++=           ", 
        "     #*++##++#++*##*+###%%##****+=+===+=-===+*+         ", 
        "     +*#@%#%#*++#%%#%#*+*####*+----===+=-===++*+        ", 
        "       =#*+***##%@%%*####+=-+*#+=-=+=====-=+++*#=       ", 
        "        *##%%%%@@@@@%*+=====++++=--==-=====+=+*#***     ", 
        "          #%%%%*%%%@%+==--=====**+======++=+++##++**==  ", 
        "         =+++=+*##%%*+=------==++++++++++******==++**   ", 
        "         ++*===*##%*===---==++++*#*******####*+==+***+  ", 
        "        =+**==+**##+==----====+*###%%%%%#*##**===+#***  ", 
        "         -*#++++*##====+=++**###%%@@@%*=-=++++=-++*#%#* ", 
        "         ==*++++###+=+++**##%%%%%%@@@#+====+*+==+==*#** ", 
        "        =+++###**+++++*#%%%%%%%%%%@@@%*++++***++=-=+*#*+",
        "       =++=+*#+=+*+=====++***##%%##%@@%**####+=--=+*##*+",
        "     ==+*++*#%*+**=====++++**####%%#%@@@%%%@%+--=++#%#**",
        "     =+*%###%%#*##*******##%##%#####%%%@@@%%#====+*###*+",
        "    =++*%%%%@%*+++=+++***##**#####%%##%@@%*++===+**+*%#+",
        "    =+*#%%@%%%#***++*++*###*####%%%*#%%#%%#++++**==+#%#*",
        "   :+**#%@%#%%%##########*+*#%%#%%##%#%%%%*==+++=++##%%*",
        "   =++*%%#*#%%*++**++*+++++**#%%%##%###%%%#*=+==+*#%#%#=",
        "   =*####*%%%*++**#*+++++***##%%%#%#***#%%##**+++*##%#*-",
        "  ++*##%%%#=+ =*####*#####%%%@@%%#%**+=+#%%###+***##%%+ ", 
        " =+++#%%#*-:: **#%%%%%%%%%%%@@%%%#**+++++#%@#*+***#%%#  ", 
        " =+++#%%*   =*##*#%%%%%%%@@@@%%%%###+*++**#*++***##%%#  ", 
        "+++##%%%*   +*##*###%%%%%@@@@%%####***#%%#*++=++**#%%#* ", 
        "***%@%%#+= *+****+**#%%%%@@@@%**+*##*##%####*++*###%%#* ", 
        "=*#%%#*#+ +++*+++##*#%%%%@@@@%##**#*+*+**#%#*+*##*#%#%# ", 
        " **##**+  ++*#++###*#%%%%%%##%##*+*#*++*##%%%*%%%%%%%%* ", 
        "  #**#*+  +*#**#**+*#%%%%%#=++##*#*##*###%%%%*#@%%#*    ", 
        "          =*#**+*#*#%@%%##*:==+*####%##%%%%%@@%*        ", 
        "         =+#++**###%@%%#*= ===-+##**#%#**#%@%%#*        ", 
        "         +*#######%%@%*++       +###%#****#%%%#+        ", 
        "         +*#%%@%%#%%#+  =        *###%####%%%%%#+       ", 
        "          *##%%%#%%%*+= .         +%%@@%###%%@%%%*+     ", 
        "         :+%%%#*#*+*#*+ .           *#%%%%%%@%%%%#*=    ", 
        "        ::+#%%##*+**%#*+.           =##%%%%#%%%%%#*+    ", 
        "         --+%###**####**            *#*#####%%%%%%#*    ", 
        "          -+*#%%%%%%%#*             +###%###%%%%%%#*    ", 
        "          :+####%%%%#+              -+#%#%##%%%%%%#=    ", 
        "           *##%##%%#+                 +######%%%%#=     ", 
        "         =*####%%%%#=                 =+%###%#%%%+=     ", 
        "        +++**#**#%%#+                   #%#####%#===+   ", 
        "      #*****###%%%##                  %%%%%%%%%%%=+     ", 
        "=+*%%%%%%%%%%%%%%%%%%%%              %%%%%%%%%%%%%%%%   " 
        },
        new WeaponModel(
            "Ragnarök Strain",              // Weapon Name
            7,                              // Weapon Damage
            50,                             // Hit Rate
            "You have hit the enemy!",      // Hit message
            "You missed the enemy homie!"   // Miss message
        )
    ) {}


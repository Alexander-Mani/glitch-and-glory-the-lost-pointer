#ifndef STORYHANDLER_H
#define STORYHANDLER_H

#include <string>

class StoryHandler {
public:
    // Pre-intro setup
    static const std::string PRE_INTRO;

    // Intro content
    static const std::string INTRO_CONTENT_1;
    static const std::string INTRO_MISSION;
    static const std::string HOW_TO_PLAY;

    // Phase 1 - Elontron (Human)
    static const std::string ELON_ATMO_1;
    static const std::string ELON_DIALOGUE_1;
    static const std::string ELON_ATMO_2;

    // Phase 2 - Elontron Prime (Starship Form)
    static const std::string ELON_ATMO_3;
    static const std::string ELON_DIALOGUE_2;
    static const std::string ELON_ATMO_4;
    static const std::string ELON_DIALOGUE_3;

    // Final Lore Dump
    static const std::string FINAL_LORE_DUMP;
};

#endif // STORYHANDLER_H


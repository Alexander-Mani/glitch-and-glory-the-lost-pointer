CXX = g++
CXXFLAGS = -Wall -std=c++17
CXXDEBUGFLAGS = -ggdb -fsanitize=address -fsanitize=undefined
# CXXFILES = main.cpp
MODELFILES = \
	Models/Entities/EntityModel.cpp \
	Models/Entities/BioEnhancedBerserkerModel.cpp \
	Models/Entities/CyberGladiatorModel.cpp \
	Models/Entities/TechnoOracleModel.cpp \
	Models/BattleModel.cpp \
	Models/WeaponModel.cpp 

LOGICFILES = \
	LogicLayer/EntityLogic.cpp \
	LogicLayer/GameLogic.cpp \
	LogicLayer/BattleLogic.cpp \
	LogicLayer/LogicWrapper.cpp \
	LogicLayer/EncounterLogic.cpp   # Add this if you have it

UIFILES = \
	UILayer/UIHandler.cpp \
	UILayer/IOHandler.cpp \
	UILayer/BattleHandler.cpp \
	UILayer/AsciiHandler.cpp \
	UILayer/EncounterHandler.cpp

# Combine all source files
CXXFILES = main.cpp $(MODELFILES) $(LOGICFILES) $(UIFILES)


TARGETS = debug main

.PHONY: all fresh clean

main:
	$(info Building $@)
	$(CXX) $(CXXFLAGS) -o glitch-and-glory.out $(CXXFILES)

debug:clean
	$(info Building debug $@)
	$(CXX) $(CXXFLAGS) $(CXXDEBUGFLAGS) -ggdb -o $@.out $(CXXFILES)
	gdb ./debug.out

run:
	$(CXX) $(CXXFLAGS) -o glitch-and-glory.out $(CXXFILES)
	./glitch-and-glory.out

fast:
	./glitch-and-glory.out

clean: 
	rm -f ./glitch-and-glory.out ./debug.out
	$(info Cleaned project)


fresh:
	clean all



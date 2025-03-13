CXX = g++
CXXFLAGS = -Wall -std=c++17
CXXDEBUGFLAGS = -ggdb -fsanitize=address -fsanitize=undefined

MODELFILES = \
	Models/Entities/EntityModel.cpp \
	Models/BattleModel.cpp \
	Models/Equipment/EquipmentFactory.cpp \
	Models/OverworldModel.cpp \
	Models/PartyModel.cpp

LOGICFILES = \
	LogicLayer/EntityLogic.cpp \
	LogicLayer/GameLogic.cpp \
	LogicLayer/BattleLogic.cpp \
	LogicLayer/AttackLogic.cpp \
	LogicLayer/LogicWrapper.cpp \
	LogicLayer/EncounterLogic.cpp

UIFILES = \
	UILayer/UIHandler.cpp \
	UILayer/IOHandler.cpp \
	UILayer/BattleHandler.cpp \
	UILayer/AsciiHandler.cpp \
	UILayer/OverworldHandler.cpp \
	UILayer/EncounterHandler.cpp

# Combine all source files
CXXFILES = main.cpp $(MODELFILES) $(LOGICFILES) $(UIFILES)

TARGETS = debug main

.PHONY: all fresh clean

all: main

main:
	$(info Building $@)
	$(CXX) $(CXXFLAGS) -o glitch-and-glory.out $(CXXFILES)

debug: clean
	$(info Building debug $@)
	$(CXX) $(CXXFLAGS) $(CXXDEBUGFLAGS) -o debug.out $(CXXFILES)
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
	$(MAKE) clean
	$(MAKE) all

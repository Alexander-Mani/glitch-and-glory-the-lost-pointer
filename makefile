CXX = g++
CXXFLAGS = -Wall -std=c++17
CXXDEBUGFLAGS = -ggdb -fsanitize=address -fsanitize=undefined

# Source files
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
# Create corresponding object file names
OBJFILES = $(CXXFILES:.cpp=.o)

.PHONY: all short main debug run fast deb clean fresh

# Default target – a full rebuild
all: main

# Full rebuild target (recompiles all sources)
main:
	$(info Building main target: full rebuild)
	$(CXX) $(CXXFLAGS) -o glitch-and-glory.out $(CXXFILES)

# "short" target: incremental build that compiles only changed source files
short: $(OBJFILES)
	$(info Linking object files to create executable)
	$(CXX) $(CXXFLAGS) -o glitch-and-glory.out $(OBJFILES)
	./glitch-and-glory.out

debug: clean
	$(info Building debug target: full rebuild with debug flags)
	$(CXX) $(CXXFLAGS) $(CXXDEBUGFLAGS) -o debug.out $(CXXFILES)
	gdb ./debug.out

run: clean
	$(CXX) $(CXXFLAGS) -o glitch-and-glory.out $(CXXFILES)
	./glitch-and-glory.out

fast:
	./glitch-and-glory.out

deb:
	gdb ./debug.out

clean:
	rm -f $(OBJFILES) glitch-and-glory.out debug.out
	$(info Cleaned project)

fresh:
	$(MAKE) clean
	$(MAKE) all

# Pattern rule: compile a .cpp file to a .o file if it’s newer than the .o
%.o: %.cpp
	$(info Compiling $<)
	$(CXX) $(CXXFLAGS) -c $< -o $@
